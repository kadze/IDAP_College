//
//  SAPAccountant.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAccountant.h"

@implementation SAPAccountant

#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)washer {
    while (kSAPWorkerIsReadyToWork != self.state) {
        //wait
    }
    self.state = kSAPWorkerIsBusy;
    [self performSelectorInBackground:@selector(performBackgroundWorkWithObject:) withObject:washer];
}

#pragma mark-
#pragma mark Private Methods

- (void)performBackgroundWorkWithObject:(id)object {
    @synchronized(self) {
        [self collectMoneyFromWasher:object];
        [self performSelectorOnMainThread:@selector(finishedWorkForMainThreadWithObject:) withObject:object waitUntilDone:NO];
    }
}

- (void)finishedWorkForMainThreadWithObject:(id)object {
   [object setState:kSAPWorkerIsReadyToWork];
    self.state = kSAPWorkerFinishedWork;
}

- (void)collectMoneyFromWasher:(SAPWorker *)washer {
    [self takeAllMoneyFromSender:washer];
}
@end
