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

@property (nonatomic, assign)       SAPWorkerState          state;
@property (nonatomic, retain)       id                      object;

- (void)makeJobWithObject:(id)object;
- (void)takeAllMoneyFromSender:(SAPWorker *)sender;

@end
