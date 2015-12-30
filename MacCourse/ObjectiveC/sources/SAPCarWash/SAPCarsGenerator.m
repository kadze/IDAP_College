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

NSUInteger const kInitialCarMoney1 = 50;

@implementation SAPCarsGenerator

- (void)sendCarsToCarWash:(SAPEnterprise *)enterprise {
        
//        NSUInteger carsCount = arc4random_uniform(100);
        NSUInteger carsCount = 100; //temporary testing decision
        NSLog(@"%lu cars", carsCount);
        
        NSMutableArray *cars = [NSMutableArray array];
        for (NSUInteger carCounter = 0; carCounter < carsCount; carCounter++) {
            SAPCar *car = [SAPCar object];
            car.money = kInitialCarMoney1;
            [cars addObject:car];
        }
        
        NSArray *resultCars = [[cars copy] autorelease];
        [enterprise addCarsToQueue:resultCars];
}

- (void)sendCarsAndWashByCarWash:(SAPEnterprise *)enterprise { //the copy of previous method exept last row
    
    [self sendCarsToCarWash:enterprise];
    [enterprise performSelectorOnMainThread:@selector(washCars) withObject:nil waitUntilDone:YES];

}


@end
