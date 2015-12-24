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
        [self performAllJobWithCar:car];
    }
}

#pragma mark-
#pragma mark Private Methods

- (void)washCar:(SAPCar *)car {
    if ([self takeMoney:kWashPrise fromSender:car]) {
        [car setClean:YES];
    }
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

- (void)notifyIsReadyToWork {
    [self notifyObserversWithSelector:@selector(washNextCarWithWasher:) withObject:self];
}

- (void)notifyWorkFinished {
    [self notifyObserversWithSelector:@selector(makeJobWithObject:) withObject:self];
}

@end
