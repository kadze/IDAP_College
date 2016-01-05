//
//  SAPWasher.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWasher.h"
#import "SAPCar.h"

static NSUInteger const kSAPWashPrise = 50;
static BOOL const kSAPturnOnDelay = YES;

@implementation SAPWasher

#pragma mark-
#pragma mark Public Methods

- (void)makeJobWithObject:(id)car {
    @autoreleasepool {
        if (kSAPturnOnDelay) {
            usleep(arc4random_uniform(10) * 1000); //random delay by tech task
        }
        @synchronized(self) {
            NSUInteger moneyBefore = self.money;
            [self washCar:car];
            if (self.money > moneyBefore) {
                [self finish];
            }
        }
        [self becomeFree];
    }
}

#pragma mark-
#pragma mark Private Methods

- (void)washCar:(SAPCar *)car {
    if ([self takeMoney:kSAPWashPrise fromSender:car]) {
        [car setClean:YES];
    }
}

@end
