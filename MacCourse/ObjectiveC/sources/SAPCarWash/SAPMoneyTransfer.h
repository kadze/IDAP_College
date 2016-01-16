//
//  MoneyTransfer.h
//  MacCourse
//
//  Created by S A P on 12/9/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//


@protocol SAPMoneyTransfer
@property (nonatomic, assign) NSUInteger money;

- (void)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient;
- (void)takeMoney:(NSUInteger)sum fromSender:(id<SAPMoneyTransfer>)sender;
- (void)addMoney:(NSUInteger)sum;
- (void)substractMoney:(NSUInteger)sum;

@end
