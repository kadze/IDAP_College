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
#import "SAPItemsQueue.h"
#import "SAPWorker.h"
#import "SAPWasher.h"
#import "SAPAccountant.h"
#import "SAPBoss.h"
#import "SAPCar.h"

static NSUInteger const kSAPWashersCount = 3;

@interface SAPEnterprise ()
@property (nonatomic, retain) NSMutableArray *mutableStaff;
@property (nonatomic, retain) SAPItemsQueue *carsQueue;

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
        self.carsQueue = [SAPItemsQueue object];
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
        //hiring washers
        [self hireWorker:washer];
        
        //setting accountant as an observer for each washer
        [washer addObserver:accountant];
        
        //setting Enterprise as an observer for each washer to observe when isReadyToWork
        [washer addObserver:self];
    }
    
    //boss observes the accountant
    [accountant addObserver:boss];
}

- (void)dismissStaff {
    for (SAPWorker *worker in self.staff) {
        [worker removeAllObservers];
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
