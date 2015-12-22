//
//  SAPAccountant.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAccountant.h"
#import "SAPWasher.h"

static NSUInteger const kMaximumCashLimit = 1000;

@implementation SAPAccountant

#pragma mark-
#pragma mark Accessors


#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)boss {
    [self takeAllMoneyFromSender:boss];
    if (kMaximumCashLimit <= self.money) {
        [self notifyObserversWithSelector:@selector(makeJobWithObject:) withObject:self];
    }
}

@end
