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

- (void)processObject:(id)washer {
    [self takeAllMoneyFromSender:washer];
}
@end
