//
//  SAPWasher.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWasher.h"
#import "SAPCar.h"

static NSUInteger const kWashPrise = 50;

@implementation SAPWasher

#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)car {
    if (car) {
        [self makeJobWithObjectInBackground:car];
    }
}

#pragma mark-
#pragma mark Accessors

- (void)setState:(SAPWorkerState)state {
    [super setState:state];
    if (kSAPFinishedWork == state) {
        [self notifyObserversWithSelector:@selector(makeJobWithObject:) withObject:self];
    } else if (kSAPIsReadyToWork == state) {
        [self notifyObserversWithSelector:@selector(washNextCarWithWasher:) withObject:self];
    }
}

#pragma mark-
#pragma mark Private Methods

- (void)washCar:(SAPCar *)car {
    if (!car) {
        return;
    }
    
    if ([self takeMoney:kWashPrise fromSender:car]) {
        [car setClean:YES];
    }
}

- (void)makeJobWithObjectInBackground:(id)car {
    self.state = kSAPIsBusy;
    NSUInteger moneyBefore = self.money;
    [self washCar:car];
    if (self.money > moneyBefore) {
        self.state = kSAPFinishedWork;
    }
    
    self.state = kSAPIsReadyToWork;
}
@end
