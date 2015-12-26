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

#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)washer {
    @synchronized(self) {
        [self takeAllMoneyFromSender:washer];
        if (kMaximumCashLimit <= self.money) {
            self.state = kSAPFinishedWork;
        }
        
        self.state = kSAPIsReadyToWork;
    }
}

@end
