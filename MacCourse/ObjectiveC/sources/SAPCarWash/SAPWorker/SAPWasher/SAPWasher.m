//
//  SAPWasher.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWasher.h"
#import "SAPCar.h"
#import "SAPItemsContainer.h"
#import "NSObject+SAPObject.h"

static NSUInteger   const kSAPWashPrise = 50;
static BOOL         const kSAPRandomDelayEnabled = YES;

@interface SAPWasher ()

@property(nonatomic) SAPItemsContainer *carsQueue;

@end

@implementation SAPWasher

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.carsQueue = nil;
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.carsQueue = [SAPItemsContainer object];
    }
    
    return self;
}
#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)car {
    @synchronized(self) {
        if (kSAPIsReadyToWork == self.state) {
            self.state = kSAPIsBusy;
        }
        
        [self.carsQueue addItem:car];
        [self performSelectorInBackground:@selector(washCars) withObject:nil];
    }
}

#pragma mark-
#pragma mark Private Methods

- (void)washCars {
    @autoreleasepool {
        @synchronized(self) {
            if (kSAPRandomDelayEnabled) {
                usleep(arc4random_uniform(10) * 1000);
            }
            SAPItemsContainer *carsQueue = self.carsQueue;
            SAPCar *car = [carsQueue dequeue];
            while (car) {
                if ([self takeMoney:kSAPWashPrise fromSender:car]) {
                    [car setClean:YES];
                }
                
                car = [carsQueue dequeue];
            }
            
            self.state = kSAPFinishedWork;
        }
    }
}

@end
