//
//  SAPWasher.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWasher.h"
#import "SAPCar.h"
#import "SAPQueue.h"
#import "NSObject+SAPObject.h"
#import "SAPWorker_Private.h"

static NSUInteger   const kSAPWashPrise = 50;
static BOOL         const kSAPRandomDelayEnabled = YES;

@implementation SAPWasher
@synthesize objectsQueue;

#pragma mark-
#pragma mark Private Methods

- (void)finishProcessingOnMainThreadWithObject:(SAPObservableObject *)object {
    self.state = kSAPWorkerFinishedWork;
    self.state = kSAPWorkerIsReadyToWork;
}

- (void)processObject:(SAPCar *)car {
    if (kSAPRandomDelayEnabled) {
        usleep(arc4random_uniform(10) * 1000);
    }
    
    SAPQueue *carsQueue = self.objectsQueue;
    while (car) {
        [self takeMoney:kSAPWashPrise fromSender:car];
        car.clean = YES;
        car = [carsQueue dequeue];
    }
}

@end
