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
        [self performSelectorOnMainThread:@selector(notifyWorkFinished) withObject:nil waitUntilDone:YES];
    } else if (kSAPIsReadyToWork == state) {
        [self performSelectorOnMainThread:@selector(notifyIsReadyToWork) withObject:nil waitUntilDone:YES];
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
    usleep(arc4random_uniform(10) * 1000);
    [self performSelectorInBackground:@selector(performAllJobWithCar:) withObject:car];
}

- (void)performAllJobWithCar:(SAPCar *)car {
    self.state = kSAPIsBusy;
    NSLog(@"%@ is busy with %@", self, car);
    NSUInteger moneyBefore = self.money;
    [self washCar:car];
    if (self.money > moneyBefore) {
        self.state = kSAPFinishedWork;
    }
    
    self.state = kSAPIsReadyToWork;
}

- (void)notifyWorkFinished {
    [self notifyObserversWithSelector:@selector(makeJobWithObject:) withObject:self];
}

- (void)notifyIsReadyToWork {
    [self notifyObserversWithSelector:@selector(washNextCarWithWasher:) withObject:self];
}

@end
