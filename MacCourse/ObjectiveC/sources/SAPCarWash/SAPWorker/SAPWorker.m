//
//  SAPWorker.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWorker.h"
//
//@interface SAPWorker()
//
//@property (nonatomic, assign, readwrite)     SAPWorkerState          state;
//
//@end

@implementation SAPWorker

@synthesize money = _money;

#pragma mark-
#pragma mark Class Methods

- (SEL) selectorForState:(SAPWorkerState)state {
    SEL result = nil;
    switch (state) {
        case kSAPIsBusy:
            result = nil;
            break;
        case kSAPFinishedWork:
            result = @selector(notifyWorkFinished);
            break;
        case kSAPIsReadyToWork:
            result = @selector(notifyIsReadyToWork);
            break;
        default:
            nil;
            break;
    }
    
    return result;
}

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    
    [super dealloc];
}

#pragma mark-
#pragma mark Accessors

- (void)setState:(SAPWorkerState)state {
    if (_state != state) {
        _state = state;
        SEL selectorToPerform = [self selectorForState:state];
        if (selectorToPerform) {
            [self performSelectorOnMainThread:selectorToPerform withObject:nil waitUntilDone:YES];
        }
    }
}

#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

- (void)makeJobWithObjectInBackground:(id)object {
    if (object) {
        NSLog(@"%@ is busy with %@", self, object);
        [self performSelectorInBackground:@selector(makeJobWithObject:) withObject:object];
    }
}

- (void)takeAllMoneyFromSender:(SAPWorker *)sender {
    [sender giveMoney:sender.money toRecipient:self];
}

#pragma mark-
#pragma mark Private Methods

- (void)start {
    self.state = kSAPIsBusy;
    [self makeJobWithObjectInBackground:self.object];
}

- (void)finish {
    self.state = kSAPFinishedWork;
}

- (void)becomeFree {
    self.state = kSAPIsReadyToWork;
}

- (void)notifyWorkFinished {
    NSLog(@"%@ finised work", self);
    
    [self notifyObserversWithSelector:@selector(finisedWorkObservableWorker:) withObject:self];
}

- (void)notifyIsReadyToWork {
    NSLog(@"%@ is ready to work", self);
    
    [self notifyObserversWithSelector:@selector(isReadyToWorkObservableWorker:) withObject:self];
}

#pragma mark-
#pragma mark SAPMoneyTransfer

- (BOOL)giveMoney:(NSUInteger)sum toRecipient:(id<SAPMoneyTransfer>)recipient {
    if (self.money >= sum && (recipient)) {
        self.money      -= sum;
        recipient.money += sum;
        
        return YES;
    }
    
    return NO;
}

- (BOOL)takeMoney:(NSUInteger)sum fromSender:(id<SAPMoneyTransfer>)sender {
    return [sender giveMoney:sum toRecipient:self]; //if sender nil anyway return nil, hence NO
    
    return NO;
}

#pragma mark-
#pragma mark SAPWorkerObservingProtocol

- (void)finisedWorkObservableWorker:(SAPWorker *)worker {
    NSLog(@"%@ is busy with %@", self, worker);
    self.object = worker;
    [self start];
}

@end

