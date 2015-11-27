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

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        [SAPCreatureTests performSAPCreatureTests];
        [SAPStringExtentionsTests performSAPStringExtentionsTests];
    }    
    
    return 0;
}
