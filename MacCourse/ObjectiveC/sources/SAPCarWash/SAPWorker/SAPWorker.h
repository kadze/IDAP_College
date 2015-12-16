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

typedef NS_ENUM (NSUInteger, SAPWorkerState) {
    kSAPIsReadyToWork,
    kSAPIsBusy
};

@interface SAPWorker : SAPObservableObject <SAPMoneyTransfer>

@property (nonatomic, assign)   NSUInteger              salary;
@property (nonatomic, assign)   NSUInteger              experienceLevel;
@property (nonatomic, assign)   SAPWorkerState          state;

- (void)makeJobWithObject:(id)object;
- (void)giveAllMoneyToRecipient:(id<SAPMoneyTransfer>)recipient;
- (void)takeAllMoneyFromSender:(id<SAPMoneyTransfer>)sender;

@end
