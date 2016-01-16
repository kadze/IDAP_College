//
//  SAPEnterprise.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "NSObject+SAPObject.h"
#import "NSArray+SAPExtentions.h"
#import "SAPEnterprise.h"
#import "SAPQueue.h"
#import "SAPWorker.h"
#import "SAPWasher.h"
#import "SAPAccountant.h"
#import "SAPBoss.h"
#import "SAPCar.h"

static NSUInteger const kSAPWashersCount = 3;

@interface SAPEnterprise ()
@property (nonatomic, retain) NSMutableArray *mutableStaff;
@property (nonatomic, retain) SAPQueue *carsQueue;

- (void)hireWorker:(SAPWorker *)worker;
- (void)hireStaff;
- (void)dismissStaff;
- (NSArray *)workersOfClass:(Class)aClass;
- (id)freeWorkerOfClass:(Class)aClass;
- (void)washNextCarWithWasher:(SAPWasher *)washer;

@end

@implementation SAPEnterprise

@dynamic staff;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    [self dismissStaff];
    self.mutableStaff = nil;
    self.carsQueue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    [self initWithStaff];
    
    return self;
}

- (instancetype)initWithStaff {
    self = [super init];
    if (self) {
        self.mutableStaff = [NSMutableArray object];
        self.carsQueue = [SAPQueue object];
        [self hireStaff];
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)staff {
    return [[self.mutableStaff copy] autorelease];
}


#pragma mark-
#pragma mark Public Methods

- (void)washCar:(SAPCar *)car {
    SAPWasher *washer = [self freeWorkerOfClass:[SAPWasher class]];
    if (washer) {
        [washer performWorkWithObject:car];
    } else {
        [self.carsQueue enqueue:car];
    }    
}

#pragma mark-
#pragma mark Private Methods

- (void)hireWorker:(SAPWorker *)worker {
    [self.mutableStaff addObject:worker];
}

- (void)hireStaff {
    
    //carWash has 1 accountant and 1 boss
    
    SAPAccountant *accountant = [SAPAccountant object];
    SAPBoss *boss = [SAPBoss object];
    
    [self hireWorker:accountant];
    [self hireWorker:boss];
    
    NSLog(@"%lu washers", kSAPWashersCount);
    NSArray *washers = [SAPWasher objectsWithCount:kSAPWashersCount];
    for (SAPWasher *washer in washers) {
        [self hireWorker:washer];
        [washer addObserver:accountant];
        [washer addObserver:self];
    }
    
    [accountant addObserver:boss];
}

- (void)dismissStaff {
    for (SAPWorker *worker in self.staff) {
        [worker removeObserver:self];
        for (SAPWorker *observer in self.mutableStaff) {
            [worker removeObserver:observer];
        }
    }
    
    [self.mutableStaff removeAllObjects];
}

- (NSArray *)workersOfClass:(Class)workerClass {
    return [self.mutableStaff objectsOfClass:workerClass];
}

- (id)freeWorkerOfClass:(Class)class {
    for (SAPWorker *worker in [self workersOfClass:class]) {
        if (kSAPWorkerIsReadyToWork == worker.state) {
            return worker;
        }
    }
    
    return nil;
}

- (void)washNextCarWithWasher:(SAPWasher *)washer {
    SAPCar *car = [[self carsQueue] dequeue];
    if (car) {
        [washer performWorkWithObject:car];
    }
}

#pragma mark-
#pragma mark SAPWorkerObservingProtocol

- (void)workerDidBecomeReadyToWork:(SAPWasher *)worker {
    [self washNextCarWithWasher:worker];
}

@end
