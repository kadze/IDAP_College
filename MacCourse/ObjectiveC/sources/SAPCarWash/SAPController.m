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

NSUInteger const kSAPAnnualAmountOfCars = 100;

@interface SAPController ()
@property (nonatomic, retain) SAPEnterprise *enterprise;
@property (nonatomic, retain) NSTimer *timer;

@end

@implementation SAPController

@dynamic working;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.enterprise = nil;
    self.timer = nil;
    
    [super dealloc];
}

- (instancetype)init {
    return [self initWithEnterprise];
}

- (instancetype)initWithEnterprise {
    self = [super init];
    if (self) {
        self.enterprise = [SAPEnterprise object];
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (BOOL)isWorking {
    return self.timer;
}

#pragma mark- 
#pragma mark Public Methods

- (void)startWork {
    self.timer = [NSTimer scheduledTimerWithTimeInterval:5.0
                                                  target:self
                                                selector:@selector(startBackgroundWork)
                                                userInfo:nil
                                                 repeats:YES];
}

- (void)stopWork {
    [self.timer invalidate];
}

#pragma mark-
#pragma mark Private Methods

- (void)startBackgroundWork {
    [self performSelectorInBackground:@selector(performWork) withObject:nil];
}

- (void)performWork {
    NSArray *cars = [SAPCar objectsWithCount:kSAPAnnualAmountOfCars];
    for (SAPCar *car in cars) {
        [self performWorkWithObject:car];
    }
}

- (void)performWorkWithObject:(id)object {
    [self.enterprise washCar:object];
}

@end
