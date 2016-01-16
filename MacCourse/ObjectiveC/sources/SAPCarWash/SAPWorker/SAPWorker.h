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

typedef NS_ENUM (NSUInteger, SAPWorkerState) {
    kSAPWorkerStateStart,
    kSAPWorkerIsReadyToWork,
    kSAPWorkerIsBusy,
    kSAPWorkerFinishedWork,
    kSAPWorkerStateEnd,
    kSAPWorkerStateCount = kSAPWorkerStateEnd - kSAPWorkerStateStart - 1
};

@interface SAPWorker : SAPObservableObject <SAPMoneyTransfer, SAPWorkerObservingProtocol>

- (void)performWorkWithObject:(id)object;
- (void)processObject:(id)object;
- (void)takeAllMoneyFromSender:(SAPWorker *)sender;
- (void)cleanupAfterProcessing;
- (void)completeProcessingObject:(SAPObservableObject *)object;

@end
