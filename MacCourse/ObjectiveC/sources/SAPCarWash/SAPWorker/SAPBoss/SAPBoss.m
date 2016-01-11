//
//  SAPBoss.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPBoss.h"

@implementation SAPBoss

#pragma mark-
#pragma mark Public Methods

-(void)makeJobWithObject:(id)accountant {
    self.state = kSAPWorkerIsBusy;
    [self performSelectorInBackground:@selector(performBackgroundWorkWithObject:) withObject:accountant];
}

#pragma mark-
#pragma mark Private Methods

- (void)performBackgroundWorkWithObject:(id)object {
    @synchronized(self) {
        [self profitWithWorker:object];
        [self performSelectorOnMainThread:@selector(finishedWorkForMainThreadWithObject:) withObject:object waitUntilDone:NO];
    }
}

- (void)finishedWorkForMainThreadWithObject:(id)object {
    [object setState:kSAPWorkerIsReadyToWork];
    self.state = kSAPWorkerFinishedWork;
}

-(void)profitWithWorker:(SAPWorker *)worker {
    [self takeAllMoneyFromSender:worker];
    NSLog(@"now boss has %lu", self.money);
}

@end
