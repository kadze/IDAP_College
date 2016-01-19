//
//  SAPWorker.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWorker.h"
#import "SAPQueue.h"
#import "NSObject+SAPObject.h"

@interface SAPWorker()

- (void)performBackgroundWorkWithObject:(id)object;
- (void)finishProcessingOnMainThreadWithObject:(SAPObservableObject *)object;

@end

@implementation SAPWorker

@synthesize money = _money;

#pragma mark -
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.state = kSAPWorkerIsReadyToWork;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)performWorkWithObject:(id)object {
    [self performSelectorInBackground:@selector(performBackgroundWorkWithObject:) withObject:object];
}

- (void)processObject:(id)object {
    [self takeAllMoneyFromSender:object];
}

- (void)takeAllMoneyFromSender:(SAPWorker *)sender {
    [sender giveMoney:sender.money toRecipient:self];
}

- (void)cleanupAfterProcessing {
    @synchronized(self) {
        self.state = kSAPWorkerFinishedWork;
    }
}

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case kSAPWorkerIsBusy:
            return @selector(workerDidStartWork:);
            
        case kSAPWorkerFinishedWork:
            return @selector(workerDidFinishWork:);
            
        case kSAPWorkerIsReadyToWork:
            return @selector(workerDidBecomeReadyToWork:);
            
        default:
            return [super selectorForState:state];
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)performBackgroundWorkWithObject:(id)object {
    @autoreleasepool {
        [self processObject:object];
        [self performSelectorOnMainThread:@selector(finishProcessingOnMainThreadWithObject:) withObject:object waitUntilDone:NO];
    }
}

- (void)finishProcessingOnMainThreadWithObject:(SAPObservableObject *)object {
    [self completeProcessingObject:object];
    [self cleanupAfterProcessing];
}

- (void)completeProcessingObject:(SAPObservableObject *)object {
    @synchronized(object) {
        object.state = kSAPWorkerIsReadyToWork;
    }
}

#pragma mark -
#pragma mark SAPMoneyTransfer

- (void)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient {
    [self substractMoney:sum];
    [recipient addMoney:sum];
}

- (void)takeMoney:(NSUInteger)sum fromSender:(id<SAPMoneyTransfer>)sender {
    [sender giveMoney:sum toRecipient:self]; //if sender nil anyway return nil, hence NO
}

- (void)addMoney:(NSUInteger)sum {
    @synchronized(self) {
        self.money +=sum;
    }
}

- (void)substractMoney:(NSUInteger)sum {
    @synchronized(self) {
        self.money -=sum;
    }
}

#pragma mark -
#pragma mark SAPWorkerObservingProtocol

- (void)workerDidFinishWork:(SAPWorker *)worker {
    [self performWorkWithObject:worker];
}

@end

