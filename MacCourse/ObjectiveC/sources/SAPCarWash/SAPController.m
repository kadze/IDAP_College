//
//  Controller.m
//  MacCourse
//
//  Created by S A P on 1/16/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPController.h"
#import "SAPEnterprise.h"
#import "NSObject+SAPObject.h"
#import "SAPCar.h"

NSUInteger const kSAPAnnualAmountOfCars = 1000;
NSTimeInterval const kSAPTimeInterval = 6.0;

@interface SAPController ()
@property (nonatomic, retain) SAPEnterprise *enterprise;
@property (nonatomic, retain) NSTimer       *timer;

- (void)startBackgroundWork;
- (void)performWork;
- (void)performWorkWithObject:(id)object;

@end

@implementation SAPController

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.enterprise = nil;
    self.timer = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.enterprise = [SAPEnterprise object];
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (void)setWorking:(BOOL)working {
    if (_working != working) {
        _working = working;
        if (working) {
            self.timer = [NSTimer scheduledTimerWithTimeInterval:kSAPTimeInterval
                                                          target:self
                                                        selector:@selector(startBackgroundWork)
                                                        userInfo:nil
                                                         repeats:YES];
        } else {
            self.timer = nil;
        }
    }
}

- (void)setTimer:(NSTimer *)timer {
    if (timer != _timer) {
        [timer retain];
        [_timer invalidate];
        [_timer release];
        _timer = timer;
    }
}

#pragma mark-
#pragma mark Private Methods

- (void)startBackgroundWork {
    [self performSelectorInBackground:@selector(performWork) withObject:nil];
}

- (void)performWork {
    @autoreleasepool {
        NSArray *cars = [SAPCar objectsWithCount:kSAPAnnualAmountOfCars];
        for (SAPCar *car in cars) {
            [self performWorkWithObject:car];
        }
    }
}

- (void)performWorkWithObject:(id)object {
    [self.enterprise washCar:object];
}

@end
