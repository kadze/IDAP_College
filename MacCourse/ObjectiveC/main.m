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

NSUInteger const kAnnualAmountOfCars = 100;
NSUInteger const kWashPrice = 50;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        //=====CAR WASH=====
        
        SAPEnterprise *carWashEnterprise = [SAPEnterprise object];
        NSArray *cars = [SAPCar carsWithCount:kAnnualAmountOfCars];
        for (SAPCar *car in cars) {
            [carWashEnterprise washCar:car];
        }
        
        [[NSRunLoop currentRunLoop] run];
        
        carWashEnterprise = nil;
    }
    
    return 0;
}
