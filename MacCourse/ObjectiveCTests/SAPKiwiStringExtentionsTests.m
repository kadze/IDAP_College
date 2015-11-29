//
//  SAPStringExtentionsTests.m
//  MacCourse
//
//  Created by Andrey Shevtsov on 11/28/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//
//
#import <Kiwi/Kiwi.h>
#import "SAPStringExtentions.h"

SPEC_BEGIN(SAPStringExtentionsSpec)

describe(@"SAPStringExtentions testing", ^{
    context(@"sap_separateWithSpaces", ^{
        NSString *sourceString = @"lalalalalala";
        NSString *resultString = [sourceString sap_separateWithSpaces];
        it(@"result string's value should be the source string separated with spaces: l a l a l a l a l a l a", ^{
            [[resultString should] equal:@"l a l a l a l a l a l a"];
        });
        it(@"result should be of class NSString", ^{
            [[resultString should] beKindOfClass:[NSString class]];
        });
    });
});

SPEC_END