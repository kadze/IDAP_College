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
    @synchronized(self) {
        while (kSAPIsReadyToWork != self.state) {
            //wait
        }
        self.state = kSAPIsBusy;
        [self performSelectorInBackground:@selector(collectMoneyFromWasher:) withObject:washer];
    }
}

- (void)collectMoneyFromWasher:(SAPWorker *)washer {
    [self takeAllMoneyFromSender:washer];
    [washer setState:kSAPIsReadyToWork];
    self.state = kSAPFinishedWork;
}
@end
