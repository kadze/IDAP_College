//
//  SAPCarsGenerator.m
//  MacCourse
//
//  Created by S A P on 12/25/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCarsGenerator.h"
#import "SAPEnterprise.h"
#import "SAPCar.h"
#import "NSObject+SAPObject.h"

static NSUInteger const kSAPInitialCarMoney1 = 50;
static NSUInteger const kSAPcarsCount = 100;

@implementation SAPCarsGenerator

- (void)sendCarsToCarWash:(SAPEnterprise *)enterprise {
    
        NSUInteger carsCount = kSAPcarsCount; //temporary testing decision
        NSLog(@"%lu cars", carsCount);
        
        NSMutableArray *cars = [NSMutableArray array];
        for (NSUInteger carCounter = 0; carCounter < carsCount; carCounter++) {
            SAPCar *car = [SAPCar object];
            car.money = kSAPInitialCarMoney1;
            [cars addObject:car];
        }
        
        NSArray *resultCars = [[cars copy] autorelease];
        [enterprise addCarsToQueue:resultCars];
}

- (void)sendCarsAndWashByCarWash:(SAPEnterprise *)enterprise {
    
    @autoreleasepool {
        [self sendCarsToCarWash:enterprise];
        [enterprise washCars];
    }
}

@end
