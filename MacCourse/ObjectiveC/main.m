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
#import "SAPCarsGenerator.h"

NSUInteger const kInitialCarMoney = 50;
NSUInteger const kAnnualAmountOfCars = 100;
NSUInteger const kWashPrice = 50;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        //=====CAR WASH=====
        
        SAPEnterprise *carWashEnterprise = [SAPEnterprise object];
        [carWashEnterprise hireStaff];
        
        
        //try. doesn't work
//        [NSThread detachNewThreadSelector:@selector(sendCarsToCarWash:)
//                                 toTarget:[SAPCarsGenerator class]
//                               withObject:carWashEnterprise];
        
        
        
        //new try. doesn't work
//        
//        SAPCarsGenerator *carsGenerator = [SAPCarsGenerator object];
//        [carsGenerator performSelectorInBackground:@selector(sendCarsAndWashByCarWash:) withObject:carWashEnterprise];

        
        // works with instance method of generator
        
//        [[SAPCarsGenerator object] sendCarsToCarWash:carWashEnterprise];
//        [carWashEnterprise washCars];
        
        
        //works with class method of generator
        
        [SAPCarsGenerator sendCarsToCarWash:carWashEnterprise];
        [carWashEnterprise washCars];
        
        
        
        [[NSRunLoop currentRunLoop] run];
        
//        cars = nil;
        carWashEnterprise = nil;
        
    }
    
    return 0;
}
