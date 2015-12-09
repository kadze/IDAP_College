//
//  SAPWorker.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWorker.h"

@implementation SAPWorker

- (void)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient {
    if (self.money >= sum && (recipient)) {
        self.money      -= sum;
        recipient.money += sum;
    }
}

- (void)takeMoney:(NSUInteger)sum fromSender:(id<SAPMoneyTransfer>)sender {
    if (sender) {
        [sender giveMoney:sum toRecipient:self];
    }
    
}

- (void)makeJob {
    //to override
}

@end
