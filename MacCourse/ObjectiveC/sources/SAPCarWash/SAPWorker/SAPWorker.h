//
//  SAPWorker.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPMoneyTransfer.h"
#import "SAPObservableObject.h"

@class SAPRoom;

@interface SAPWorker : SAPObservableObject <SAPMoneyTransfer>

@property (nonatomic, retain)   SAPWorker   *moneyRecipient;
@property (nonatomic, assign)   NSUInteger  salary;
@property (nonatomic, assign)   NSUInteger  yearsOfExperience;
@property (nonatomic, assign)   SAPRoom     *currentWorkingPlace;

- (void)makeJob;
- (void)giveAllMoneyToRecipient;
- (void)takeAllMoneyFromSender:(SAPWorker *)sender;

@end
