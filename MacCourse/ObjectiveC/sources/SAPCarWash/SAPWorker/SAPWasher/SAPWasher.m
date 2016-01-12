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
#import "SAPWorker_Private.h"

static NSUInteger   const kSAPWashPrise = 50;
static BOOL         const kSAPRandomDelayEnabled = YES;

@implementation SAPWasher
@synthesize objectsQueue;

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



#pragma mark-
#pragma mark Private Methods

- (void)finishProcessingOnMainThreadWithObject:(SAPObservableObject *)object {
    self.state = kSAPWorkerFinishedWork;
    self.state = kSAPWorkerIsReadyToWork;
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
