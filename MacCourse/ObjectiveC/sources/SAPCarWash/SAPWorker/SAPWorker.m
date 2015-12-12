//
//  SAPWorker.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWorker.h"

@implementation SAPWorker

@synthesize money = _money;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.moneyRecipient = nil;
    
    [super dealloc];
}

#pragma mark-
#pragma mark Public Methods

- (void)makeJob {
    //to override
}

- (void)giveAllMoneyToRecipient {
    [self giveMoney:self.money toRecipient:self.moneyRecipient];
}

- (void)takeAllMoneyFromSender:(SAPWorker *)sender {
    [sender giveMoney:sender.money toRecipient:self];
}

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
    return [sender giveMoney:sum toRecipient:self]; //if sender nil anyway return nil, hence NO
    
    return NO;
}

@end
