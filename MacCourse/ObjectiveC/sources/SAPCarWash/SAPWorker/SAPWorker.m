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
    
    [super dealloc];
}

#pragma mark-
#pragma mark Accessors

- (void)setState:(SAPWorkerState)state {
    if (kSAPFinishedWork == state) {
        [self performSelectorOnMainThread:@selector(notifyWorkFinished) withObject:nil waitUntilDone:YES];
        NSLog(@"%@ finised work", self);
    } else if (kSAPIsReadyToWork == state) {
        [self performSelectorOnMainThread:@selector(notifyIsReadyToWork) withObject:nil waitUntilDone:YES];
        NSLog(@"%@ is ready to work", self);
    }
}

#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

- (void)giveAllMoneyToRecipient:(id<SAPMoneyTransfer>)recipient {
    [self giveMoney:self.money toRecipient:recipient];
}

- (void)takeAllMoneyFromSender:(SAPWorker *)sender {
    [sender giveMoney:sender.money toRecipient:self];
}

- (void)notifyWorkFinished {
    
}

- (void)notifyIsReadyToWork {
    
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
