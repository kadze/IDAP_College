//
//  SAPAccountant.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAccountant.h"
#import "SAPWasher.h"

static NSUInteger const kMaximumCashLimit = 200;

@implementation SAPAccountant

//#pragma mark-
//#pragma mark Accessors
//
//- (void)setState:(SAPWorkerState)state {
//    [super setState:state];
//    if (kSAPFinishedWork == state) {
//        [self notifyObserversWithSelector:@selector(makeJobWithObject:) withObject:self];
//    }
//}

#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)washer {
    @synchronized(self) {
        self.state = kSAPIsBusy;
        
        NSLog(@"%@ is busy with %@", self, washer);
        
        [self takeAllMoneyFromSender:washer];
        if (kMaximumCashLimit <= self.money) {
            self.state = kSAPFinishedWork;
        }
        
        self.state = kSAPIsReadyToWork;
    }
}

- (void)notifyWorkFinished {
    [self notifyObserversWithSelector:@selector(makeJobWithObject:) withObject:self];
}

@end
