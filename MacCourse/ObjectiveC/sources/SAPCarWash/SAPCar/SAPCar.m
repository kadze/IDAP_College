//
//  SAPCar.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCar.h"

NSUInteger const kSAPInitialCarMoney = 50;

@implementation SAPCar

@synthesize money = _money;

#pragma mark-
#pragma mark Initializations and Deallocations

- (instancetype)init {
    self = [super init];
    if (self) {
        self.money = kSAPInitialCarMoney;
    }
        
    return self;
}

#pragma mark-
#pragma mark SAPMoneyTransfer

- (void)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient {
    [self substractMoney:sum];
    [recipient addMoney:sum];
}

- (void)takeMoney:(NSUInteger)sum fromSender:(id<SAPMoneyTransfer>)sender {
    [sender giveMoney:sum toRecipient:self]; //if sender nil anyway return nil, hence NO
}


- (void)addMoney:(NSUInteger)sum {
    @synchronized(self) {
        self.money +=sum;
    }
}

- (void)substractMoney:(NSUInteger)sum {
    @synchronized(self) {
        self.money -=sum;
    }
}

@end
