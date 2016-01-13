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
    kSAPWorkerStateStart = 1,
    kSAPWorkerIsReadyToWork,
    kSAPWorkerIsBusy,
    kSAPWorkerFinishedWork,
    kSAPWorkerStateEnd,
    kSAPWorkerStateCount = kSAPWorkerStateEnd - kSAPWorkerStateStart
};

@interface SAPWorker : SAPObservableObject <SAPMoneyTransfer, SAPWorkerObservingProtocol>

- (void)performWorkWithObject:(id)object;

//this method should be overrided in subclasses
- (void)processObject:(id)object;

- (void)takeAllMoneyFromSender:(SAPWorker *)sender;

@end
