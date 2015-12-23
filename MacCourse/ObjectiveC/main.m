//
//  main.m
//  ObjectiveC
//
//  Created by S A P on 11/18/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "SAPCreatureTests.h"
//#import "SAPStringExtentionsTests.h"

#import "NSObject+SAPObject.h"

#import "SAPEnterprise.h"
#import "SAPCar.h"
#import "SAPWasher.h"
#import "SAPWorker.h"
#import "SAPBoss.h"
#import "SAPAccountant.h"

NSUInteger const kInitialCarMoney = 50;
NSUInteger const kAnnualAmountOfCars = 8;
NSUInteger const kWashPrice = 50;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        [SAPCreatureTests performSAPCreatureTests];
//        [SAPStringExtentionsTests performSAPStringExtentionsTests];
        
        //=====CAR WASH=====
        
        NSLog(@"%lu cars", kAnnualAmountOfCars);
        
        SAPEnterprise *carWashEnterprise = [SAPEnterprise object];
        [carWashEnterprise hireStaff];
        
        NSMutableArray *cars = [NSMutableArray array];
        for (NSUInteger carCounter = 0; carCounter < kAnnualAmountOfCars; carCounter++) {
            SAPCar *car = [SAPCar object];
            car.money = kInitialCarMoney;
            [cars addObject:car];            
        }
        
        [carWashEnterprise washCars:cars];
        
        SAPBoss *boss = nil;
        NSUInteger bossCounter = 1;
        for (boss in [carWashEnterprise workersOfClass:[SAPBoss class]]) {
            NSLog(@"Boss %lu : %lu", bossCounter, (unsigned long)boss.money);
            bossCounter++;
        }
        
        [[NSRunLoop currentRunLoop] run];
        
        cars = nil;
        carWashEnterprise = nil;
        
    }
    
    return 0;
}
