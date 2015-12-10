//
//  SAPWorker.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPMoneyTransfer.h"

@class SAPRoom;

@interface SAPWorker : NSObject <SAPMoneyTransfer>

@property (nonatomic, assign)   NSUInteger  money;
@property (nonatomic, assign)   NSUInteger  salary;
@property (nonatomic, assign)   NSUInteger  yearsOfExperience;
//@property (nonatomic, copy)     NSString    *duties;
@property (nonatomic, assign)   SAPRoom     *currentWorkingPlace;
@property (nonatomic, retain)   SAPWorker<SAPMoneyTransfer>   *moneyRecipient;

- (void)makeJob;
- (void)giveAllMoneyToRecipient;

@end
