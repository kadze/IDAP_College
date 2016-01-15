//
//  SAPWasher.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWasher.h"
#import "SAPCar.h"
#import "SAPQueue.h"

static NSUInteger   const kSAPWashPrise = 50;
static BOOL         const kSAPRandomDelayEnabled = YES;

@implementation SAPWasher

#pragma mark-
#pragma mark Public Methods

- (void)processObject:(SAPCar *)car {
    if (kSAPRandomDelayEnabled) {
        usleep(arc4random_uniform(10) * 1000);
    }
    
    [self takeMoney:kSAPWashPrise fromSender:car];
    car.clean = YES;
}

- (void)completeProcessingObject:(id)object {
    //nothing to do with car
}

@end
