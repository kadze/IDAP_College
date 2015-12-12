//
//  SAPStringExtentionsTests.m
//  MacCourse
//
//  Created by Student 111 on 11/27/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#import "SAPStringExtentionsTests.h"
#import "NSString+SAPStringExtentions.h"

@implementation SAPStringExtentionsTests

+ (void)performSAPStringExtentionsTests {
    [SAPStringExtentionsTests performSap_separateWithSpaces];
}

+ (void)performSap_separateWithSpaces {
    NSString *start = @"lalalalalala";
    NSString *finish = [start sap_separateWithSpaces];
    NSAssert([finish isEqualToString:@"l a l a l a l a l a l a"], @"result of separation with spaces isn't right");
}

@end
