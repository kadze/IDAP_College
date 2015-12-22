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

static NSUInteger const maxWashersCount = 100;

@interface SAPEnterprise()

@property (nonatomic, retain) SAPItemsContainer *staffContainter;

@end


@implementation SAPEnterprise

@dynamic staff;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.staffContainter = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    self.staffContainter = [SAPItemsContainer object];
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)staff {
    return self.staffContainter.items;
}

#pragma mark Public Methods

- (void)hireWorker:(SAPWorker *)worker {
    [self.staffContainter extendWithItem:worker];
}

- (void)dismissWorker:(SAPWorker *)worker {
    [self.staffContainter removeItemShrinkCapacity:worker];
}

-(NSArray *)workersOfClass:(Class)workerClass {
    return [self.staffContainter itemsOfClass:workerClass];
}

- (void)initialSetup {
    
    //hire staff
    
    //carWash has 1 accountant and 1 boss
    
    SAPAccountant *accountant = [SAPAccountant object];
    SAPBoss *boss = [SAPBoss object];
    
    [self hireWorker:accountant];
    [self hireWorker:boss];
    
    //car washing has random count of washers
    NSUInteger washersCount = arc4random_uniform(maxWashersCount);
    while (washersCount > 0) {
        SAPWasher *washer =[SAPWasher object];
        
        //hiring washers
        [self hireWorker:washer];
        
        //setting accountant as an observer for each washer
        [washer addObserver:accountant];
        
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
            SAPWasher *washer = [self findFreeWasher];
            if (washer) {
                [washer makeJobWithObject:car];
            }
        }
//    }
}

-(SAPWasher *)findFreeWasher {
    SAPWasher *washer= nil;
    for (washer in [self workersOfClass:[SAPWasher class]]) {
        if (kSAPIsReadyToWork == washer.state) {
            
            break;
        }
    }
    
    return washer;
}


@end
