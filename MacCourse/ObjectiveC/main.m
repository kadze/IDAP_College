//
//  main.m
//  ObjectiveC
//
//  Created by S A P on 11/18/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSObject+SAPObject.h"
#import "SAPController.h"

NSUInteger const kAnnualAmountOfCars = 100;
NSUInteger const kWashPrice = 50;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        //=====CAR WASH=====
        
        SAPController *controller = [SAPController object];
        [controller startWork];
        [[NSRunLoop currentRunLoop] run];
        
    }
    
    return 0;
}
