//
//  main.m
//  ObjectiveC
//
//  Created by S A P on 11/18/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPCreatureTests.h"
#import "SAPStringExtentionsTests.h"


#import "SAPEnterprise.h"
#import "SAPCar.h"
#import "SAPWasher.h"
#import "SAPWorker.h"
#import "SAPBoss.h"
#import "SAPAccountant.h"

NSUInteger const kInitialCarMoney = 50;
NSUInteger const kAnnualAmountOfCars = 100000;
NSUInteger const kWashPrice = 50;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
//        [SAPCreatureTests performSAPCreatureTests];
//        [SAPStringExtentionsTests performSAPStringExtentionsTests];
        
       
        
        
        ///////////car wash life
        
        SAPEnterprise *carWashEnterprise = [[[SAPEnterprise alloc] init] autorelease];
        [carWashEnterprise initialSetup];
        
        NSMutableArray *cars = [NSMutableArray array];
        for (NSUInteger carCounter = 0; carCounter < kAnnualAmountOfCars; carCounter++) {
            SAPCar *car = [[[SAPCar alloc] init] autorelease];
            car.money = kInitialCarMoney;
            [cars addObject:car];            
        }
        
        [carWashEnterprise washCars:cars];
        
        SAPBoss *boss = [carWashEnterprise workersOfClass:[SAPBoss class]].firstObject;
        
        NSLog(@"%lu", (unsigned long)boss.money);
        
    }
    
    return 0;
}
