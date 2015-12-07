//
//  SAPStringExtentionsTests.m
//  MacCourse
//
//  Created by Andrey Shevtsov on 11/28/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//
//
#import <Kiwi/Kiwi.h>
#import "NSString+SAPStringExtentions.h"
#import "SAPAlphabet.h"

//NSString *createUnicharAlphabet(unichar firstLetter, unichar lastLetter) {
//    unichar alphabetSize = lastLetter - firstLetter + 1;
//    unichar alphabetArray[alphabetSize];
//    for (unichar index = 0; index < alphabetSize; index++) {
//        alphabetArray[index] = firstLetter + index;
//    }
//    
//    return [NSString stringWithCharacters:alphabetArray length:alphabetSize];
//}

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
    
    context(@"sap_generateRandomStringWithAlphabet:size: tests", ^{
        NSString *alphabetString = [NSString alphanumericAlphabet];
        SAPAlphabet *alphabet = (SAPAlphabet*)[SAPAlphabet alphabetWithString:alphabetString];
        int testArraySize = 20;
        NSString *resultString = [NSString sap_generateRandomStringWithAlphabet:alphabet ofSize:testArraySize];
        NSLog(@"%@", resultString);
        it(@"result string's length should be 20", ^{
            [[theValue(resultString.length) should] equal:theValue(testArraySize)];
        });
        
        NSMutableArray *arr = [NSMutableArray arrayWithObject:resultString];
        uint16_t testMutableArraySize = 10000;
        for (uint16_t counter = 0; counter < testMutableArraySize; counter++) {
            [arr addObject:[NSString sap_generateRandomStringWithAlphabet:alphabet ofSize:testArraySize]];
        };
        
        NSSet *set = [NSSet setWithArray:arr];
        it(@"method should generate not equal values in small ranges", ^{
            [[theValue(arr.count) should] equal:theValue(set.count)];
        });
    });
//
//    context(@"sap_generateRandomStringOfSize: tests", ^{
//        NSString *sourceString = @"HelloWorld";
//        NSUInteger resultLength = 20;
//        NSString *resultString = [sourceString sap_generateRandomStringOfSize:resultLength];
//        NSLog(@"%@", resultString);
//        it(@"result string's length should be 20", ^{
//            [[theValue(resultString.length) should] equal:theValue(resultLength)];
//        });
//        
//        NSMutableArray *arr = [NSMutableArray arrayWithObject:resultString];
//        uint16_t testMutableArraySize = 10000;
//        for (uint16_t counter = 0; counter < testMutableArraySize; counter++) {
//            [arr addObject:[sourceString sap_generateRandomStringOfSize:resultLength]];
//        };
//        
//        NSSet *set = [NSSet setWithArray:arr];
//        it(@"method should generate not equal values in small ranges", ^{
//            [[theValue(arr.count) should] equal:theValue(set.count)];
//        });
//    });
});

SPEC_END