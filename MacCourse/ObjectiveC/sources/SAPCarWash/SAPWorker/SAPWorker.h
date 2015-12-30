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
#import "SAPWorkerObservingProtocol.h"

@class SAPRoom;

typedef NS_ENUM (NSUInteger, SAPWorkerState) {
    kSAPIsReadyToWork,
    kSAPIsBusy,
    kSAPFinishedWork
};

@interface SAPWorker : SAPObservableObject <SAPMoneyTransfer, SAPWorkerObservingProtocol>

@property (nonatomic, assign)               NSUInteger              salary;
@property (nonatomic, assign)               NSUInteger              experienceLevel;
//@property (nonatomic, assign, readonly)     SAPWorkerState          state;
@property (nonatomic, assign)     SAPWorkerState          state;

- (void)makeJobWithObject:(id)object;
- (void)makeJobWithObjectInBackground:(id)object;
- (void)takeAllMoneyFromSender:(SAPWorker *)sender;

@end
