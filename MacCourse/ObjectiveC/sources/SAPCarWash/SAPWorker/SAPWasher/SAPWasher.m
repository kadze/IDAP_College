//
//  SAPWasher.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWasher.h"
#import "SAPCar.h"
#import "SAPCarWashRoom.h"

static NSUInteger const kWashPrise = 50;

@implementation SAPWasher

#pragma mark-
#pragma mark Public Methods

- (void)makeJob {
    SAPRoom *currentWorkingPlace = self.currentWorkingPlace;
    NSUInteger moneyBefore = self.money;
    if ([currentWorkingPlace isKindOfClass:[SAPCarWashRoom class]]) {
        [self washAllCarsInCarWashRoom:(SAPCarWashRoom *)currentWorkingPlace];
    }
    if (self.money > moneyBefore) {
        [self notifyObserversWithSelector:@selector(carWashedByWasher:) withObject:self];
    }
}

#pragma mark-
#pragma mark Private Methods

- (void)washAllCarsInCarWashRoom:(SAPCarWashRoom *)carWashRoom {
    if (!carWashRoom) {
        return;
    }
    
    for (SAPCar *car in carWashRoom.cars) {
        if ([self takeMoney:kWashPrise fromSender:car]) {
            [car setClean:YES];
        }
    }
}

@end
