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

static NSUInteger const kSAPMaxWashersCount = 3; //will be incremented so as to avoid zero value

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
#pragma mark SAPWorkerObservingProtocol

- (void)isReadyToWorkObservableWorker:(SAPWorker *)worker {
    [self washNextCarWithWasher:(SAPWasher*)worker];
}

#pragma mark-
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
    NSUInteger washersCount = 1 + arc4random_uniform(kSAPMaxWashersCount) ;
//    NSUInteger washersCount = 3;
    
    NSLog(@"%lu washers", washersCount);
    
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
    SAPItemsContainer *carsQueue = self.carsQueue;
    @synchronized(carsQueue) {
        for (SAPCar *car in cars) {
            [carsQueue addItem:car];
        }
        
        for (SAPWasher *washer in [self workersOfClass:[SAPWasher class]]) {
            [self washNextCarWithWasher:washer];
        }
    }
}


-(void)washCars {
    for (SAPWasher *washer in [self workersOfClass:[SAPWasher class]]) {
        [self washNextCarWithWasher:washer];
    }
}

-(void)addCarsToQueue:(NSArray *)cars {
    SAPItemsContainer *carsQueue = self.carsQueue;
    for (SAPCar *car in cars) {
        [carsQueue addItem:car];
    }
}

-(void)washNextCarWithWasher:(SAPWasher *)washer {
    washer.object = [[self carsQueue] dequeue];
    [washer start];
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
