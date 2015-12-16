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

- (void)setMoney:(NSUInteger)money {
    if (money > self.money && kMaximumCashLimit <= self.money) {
        [self notifyObserversWithSelector:@selector(makeJobWithObject:) withObject:self];
    }
    
}

#pragma mark-
#pragma mark Public Methods

//- (void)makeJobWithObject:(id)boss {
//    [self giveAllMoneyToRecipient:boss];
//}

- (void)subjectGotMoney:(id<SAPMoneyTransfer>)subject {
    [self takeAllMoneyFromSender:subject];
}

@end
