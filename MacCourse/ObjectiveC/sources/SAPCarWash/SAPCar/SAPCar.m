//
//  SAPCar.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCar.h"

@implementation SAPCar

#pragma mark-
#pragma mark SAPMoneyTransfer

- (BOOL)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient {
    if (self.money >= sum && (recipient)) {
        self.money      -= sum;
        recipient.money += sum;
        
        return YES;
    }
    
    return NO;
}

- (BOOL)takeMoney:(NSUInteger)sum fromSender:(id<SAPMoneyTransfer>)sender {
    if (sender) {
        return [sender giveMoney:sum toRecipient:self];
    }
    
    return NO;
}

@end
