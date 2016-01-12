//
//  SAPWorker.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "NSObject+SAPObject.h"
#import "SAPWorker.h"
#import "SAPWorker_Private.h"
#import "SAPItemsQueue.h"

@implementation SAPWorker

@synthesize money = _money;
@synthesize state = _state;
@synthesize objectsQueue = _objectsQueue;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.objectsQueue = nil;
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.state = kSAPWorkerIsReadyToWork;
        self.objectsQueue = [SAPItemsQueue object];
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (void)setState:(NSUInteger)state {
    if (self.state != state) {
        _state = state;
        SEL selector = [self selectorForState:state];
        if (selector) {
            [self notifyObserversWithSelector:selector withObject:self];
        }
    }
}

#pragma mark-
#pragma mark Public Methods

- (void)performWorkWithObject:(id)object {
    if (kSAPWorkerIsReadyToWork == self.state) {
        self.state = kSAPWorkerIsBusy;
        [self performSelectorInBackground:@selector(performBackgroundWorkWithObject:) withObject:object];
    } else {
        [self.objectsQueue enqueue:object];
    }
}

- (void)performBackgroundWorkWithObject:(id)object {
    @synchronized(self) {
        [self processObject:object];
        [self performSelectorOnMainThread:@selector(finishProcessingOnMainThreadWithObject:) withObject:object waitUntilDone:NO];
    }
}

- (void)processObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

- (void)takeAllMoneyFromSender:(SAPWorker *)sender {
    [sender giveMoney:sender.money toRecipient:self];
}

#pragma mark-
#pragma mark Private Implementations

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case kSAPWorkerIsBusy:
            return @selector(workerDidStartWork:);
            break;
        case kSAPWorkerFinishedWork:
            return @selector(workerDidFinishWork:);
            break;
        case kSAPWorkerIsReadyToWork:
            return @selector(workerDidBecomeReadyToWork:);
            break;
        default:
            return NULL;
            break;
    }
}

- (void)finishProcessingOnMainThreadWithObject:(SAPObservableObject *)object {
    self.state = kSAPWorkerFinishedWork;
    self.state = kSAPWorkerIsReadyToWork;
}

#pragma mark-
#pragma mark SAPMoneyTransfer

- (BOOL)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient {
    if (recipient && self.money >= sum) {
        [self substractMoney:sum];
        [recipient addMoney:sum];
        
        return YES;
    }
    
    return NO;
}

- (BOOL)takeMoney:(NSUInteger)sum fromSender:(id<SAPMoneyTransfer>)sender {
    return [sender giveMoney:sum toRecipient:self]; //if sender nil anyway return nil, hence NO
}

- (void)addMoney:(NSUInteger)sum {
    @synchronized(self) {
        _money +=sum;
    }
}

- (void)substractMoney:(NSUInteger)sum {
    @synchronized(self) {
        _money -=sum;
    }
}

#pragma mark-
#pragma mark SAPWorkerObservingProtocol

- (void)workerDidFinishWork:(SAPWorker *)worker {
    [self performWorkWithObject:worker];
}

- (void)workerDidStartWork:(SAPWorker *)worker {
    
}

@end

