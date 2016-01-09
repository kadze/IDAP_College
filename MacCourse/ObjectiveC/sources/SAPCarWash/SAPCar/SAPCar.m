//
//  SAPCar.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCar.h"
#import "NSObject+SAPObject.h"

@implementation SAPCar

@synthesize money = _money;

#pragma mark-
#pragma mark Class Methods

+ (NSArray *)carsWithCount:(NSUInteger)count {
    return [SAPCar objectsWithCount:count];
}

#pragma mark-
#pragma mark SAPMoneyTransfer

- (BOOL)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient {
    if (recipient && self.money >= sum) {
        [self substractMoney:sum];
        [recipient addMoney:sum];
        
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

- (void)addMoney:(NSUInteger)sum {
    _money +=sum;
}

- (void)substractMoney:(NSUInteger)sum {
    _money -=sum;
}

@end
