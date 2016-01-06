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

static NSUInteger const kSAPInitialCarMoney = 50;
static NSUInteger const kSAPcarsCount = 100;

@implementation SAPCarsGenerator

- (NSArray *)generateCars {
    NSUInteger carsCount = kSAPcarsCount;
    
    NSLog(@"%lu cars", carsCount);
    
    NSMutableArray *cars = [NSMutableArray array];
    for (NSUInteger carCounter = 0; carCounter < carsCount; carCounter++) {
        SAPCar *car = [SAPCar object];
        car.money = kSAPInitialCarMoney;
        [cars addObject:car];
    }
    
    return [[cars copy] autorelease];
}

@end
