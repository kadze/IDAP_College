//
//  SAPWasher.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWasher.h"
#import "SAPCar.h"
#import "SAPItemsQueue.h"
#import "NSObject+SAPObject.h"

static NSUInteger   const kSAPWashPrise = 50;
static BOOL         const kSAPRandomDelayEnabled = YES;

@interface SAPWasher ()
@property(nonatomic, retain) SAPItemsQueue *carsQueue;

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
        self.carsQueue = [SAPItemsQueue object];
    }
    
    return self;
}
#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)car {
    if (kSAPWorkerIsReadyToWork == self.state) {
        self.state = kSAPWorkerIsBusy;
    }
    
    [self.carsQueue enqueue:car];
    [self performSelectorInBackground:@selector(performBackgroundWorkWithObject:) withObject:nil];
}

#pragma mark-
#pragma mark Private Methods

- (void)finishedWorkForMainThreadWithObject:(id)object {
    self.state = kSAPWorkerFinishedWork;
}

- (void)processObject:(id)object {
    if (kSAPRandomDelayEnabled) {
        usleep(arc4random_uniform(10) * 1000);
    }
    SAPItemsQueue *carsQueue = self.carsQueue;
    SAPCar *car = [carsQueue dequeue];
    while (car) {
        if ([self takeMoney:kSAPWashPrise fromSender:car]) {
            car.clean = YES;
        }
        
        car = [carsQueue dequeue];
    }
}

@end
