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
@property(nonatomic, retain) SAPItemsQueue *objectsQueue;

@end

@implementation SAPWasher

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.objectsQueue = nil;
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.objectsQueue = [SAPItemsQueue object];
    }
    
    return self;
}
#pragma mark-
#pragma mark Public Methods

- (void)performWorkWithObject:(id)car {
    if (kSAPWorkerIsReadyToWork == self.state) {
        self.state = kSAPWorkerIsBusy;
        [self performSelectorInBackground:@selector(performBackgroundWorkWithObject:) withObject:car];
    } else {
        [self.objectsQueue enqueue:car];
    }
}

#pragma mark-
#pragma mark Private Methods

- (void)finishProcessingOnMainThreadWithObject:(SAPObservableObject *)object {
    self.state = kSAPWorkerFinishedWork;
}

- (void)processObject:(id)car {
    if (kSAPRandomDelayEnabled) {
        usleep(arc4random_uniform(10) * 1000);
    }
    
    SAPItemsQueue *carsQueue = self.objectsQueue;
    while (car) {
        [self takeMoney:kSAPWashPrise fromSender:car];
        ((SAPCar *)car).clean = YES;
        car = [carsQueue dequeue];
    }
}

@end
