//
//  SAPBoss.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPBoss.h"
#import "SAPQueue.h"

@implementation SAPBoss

#pragma mark-
#pragma mark Private Methods

-(void)processObject:(SAPWorker *)worker {
    [self takeAllMoneyFromSender:worker];
    NSLog(@"now boss has %lu", self.money);
}

- (void)cleanupAfterProcessing {
    @synchronized(self) {
        self.state = kSAPWorkerIsReadyToWork;
    }
}

@end
