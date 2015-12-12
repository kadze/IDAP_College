//
//  MoneyTransfer.h
//  MacCourse
//
//  Created by S A P on 12/9/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//


@protocol SAPMoneyTransfer

@property (nonatomic, assign) NSUInteger money;

- (BOOL)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient;
- (BOOL)takeMoney:(NSUInteger)sum fromSender:(id<SAPMoneyTransfer>)sender;


@end
