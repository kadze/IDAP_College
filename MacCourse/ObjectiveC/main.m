//
//  main.m
//  ObjectiveC
//
//  Created by S A P on 11/18/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSObject+SAPObject.h"

#import "SAPEnterprise.h"
#import "SAPCar.h"
#import "SAPWasher.h"
#import "SAPWorker.h"
#import "SAPBoss.h"
#import "SAPAccountant.h"
#import "SAPCarsGenerator.h"

NSUInteger const kInitialCarMoney = 50;
NSUInteger const kAnnualAmountOfCars = 100;
NSUInteger const kWashPrice = 50;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        //=====CAR WASH=====
        
        SAPEnterprise *carWashEnterprise = [SAPEnterprise object];
        
        //car wash gets cars from different threads
        SAPCarsGenerator *carsGenerator = [SAPCarsGenerator object];
        [carsGenerator performSelectorInBackground:@selector(sendCarsAndWashByCarWash:) withObject:carWashEnterprise];
        
        [carsGenerator performSelectorInBackground:@selector(sendCarsAndWashByCarWash:) withObject:carWashEnterprise];

        
        [[NSRunLoop currentRunLoop] run];
        
        carWashEnterprise = nil;
    }
    
    return 0;
}
