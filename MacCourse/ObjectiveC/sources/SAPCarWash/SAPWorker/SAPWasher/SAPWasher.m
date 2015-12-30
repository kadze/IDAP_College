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
    usleep(arc4random_uniform(10) * 1000); //random delay by tech task
    NSUInteger moneyBefore = self.money;
    [self washCar:car];
    if (self.money > moneyBefore) {
        self.state = kSAPFinishedWork;
    }
    
    self.state = kSAPIsReadyToWork;
}

#pragma mark-
#pragma mark Private Methods

- (void)washCar:(SAPCar *)car {
    if ([self takeMoney:kWashPrise fromSender:car]) {
        [car setClean:YES];
    }
}

@end
