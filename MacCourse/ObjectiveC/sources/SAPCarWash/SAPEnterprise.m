//
//  SAPEnterprise.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "NSObject+SAPObject.h"
#import "SAPEnterprise.h"
#import "SAPItemsContainer.h"
#import "SAPWorker.h"
#import "SAPWasher.h"
#import "SAPAccountant.h"
#import "SAPBoss.h"
#import "SAPCar.h"

static NSUInteger const kSAPMaxWashersCount = 10;

@interface SAPEnterprise()

@property (nonatomic, retain) SAPItemsContainer *staffContainter;
@property (nonatomic, retain) SAPItemsContainer *carsQueue;

@end


@implementation SAPEnterprise

@dynamic staff;


#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.staffContainter = nil;
    self.carsQueue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    self.staffContainter = [SAPItemsContainer object];
    self.carsQueue = [SAPItemsContainer object];
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)staff {
    return self.staffContainter.items;
}

#pragma mark-
#pragma mark Private Methods

//-(SAPCar *)carsDequeue {
//    SAPCar *result = nil;
//    SAPItemsContainer *carsQueue = [self carsQueue];
//    if (0 != carsQueue.items.count) {
//        result = carsQueue.dequeue;
//        
//    }
//    
//    return result;
//}

#pragma mark Public Methods

- (void)hireWorker:(SAPWorker *)worker {
    [self.staffContainter addItem:worker];
}

- (void)dismissWorker:(SAPWorker *)worker {
    [self.staffContainter removeItem:worker];
}

-(NSArray *)workersOfClass:(Class)workerClass {
    return [self.staffContainter itemsOfClass:workerClass];
}

- (void)hireStaff {
        
    //carWash has 1 accountant and 1 boss
    
    SAPAccountant *accountant = [SAPAccountant object];
    SAPBoss *boss = [SAPBoss object];
    
    [self hireWorker:accountant];
    [self hireWorker:boss];
    
    //car washing has random count of washers
    NSUInteger washersCount = arc4random_uniform(kSAPMaxWashersCount);
    while (washersCount > 0) {
        SAPWasher *washer =[SAPWasher object];
        
        //hiring washers
        [self hireWorker:washer];
        
        //setting accountant as an observer for each washer
        [washer addObserver:accountant];
        
        //setting Enterprise as an observer for each washer to observe when isReadyToWork
        [washer addObserver:self];
        
        washersCount--;
    }
    
    //boss observes the accountant
    [accountant addObserver:boss];
    
}

-(void)washCars:(NSArray *)cars {
//    while (true) {
//        if (0 == cars.count) {
//            break;
//        }
    
        for (SAPCar *car in cars) {
//            SAPWasher *washer = [self freeWasher];
//            if (washer) {
//                [washer makeJobWithObject:car];
//            }
            [self.carsQueue addItem:car];
        }
    for (SAPWasher *washer in [self workersOfClass:[SAPWasher class]]) {
        [washer setState:kSAPIsReadyToWork];
    }
//    }
}

-(void)washNextCarWithWasher:(SAPWasher *)washer {
    [washer makeJobWithObject:[[self carsQueue] dequeue]];
}

-(SAPWasher *)freeWasher {
    return (SAPWasher*)[self freeWorkerOfClass:[SAPWasher class]];
}

-(SAPWorker *)freeWorkerOfClass:(Class)class {
    for (SAPWorker *worker in [self workersOfClass:class]) {
        if (kSAPIsReadyToWork == worker.state) {
            return worker;
        }
    }
    
    return nil;
}

@end
