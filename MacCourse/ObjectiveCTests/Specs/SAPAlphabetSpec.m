//
//  SAPAlphabetSpec.m
//  MacCourse
//
//  Created by Andrey Shevtsov on 12/5/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#import "Kiwi.h"
#import "SAPAlphabet.h"
#import "SAPUnicodeRangeAlphabet.h"

SPEC_BEGIN(SAPAlphabetSpec)

describe(@"SAPAplhabet", ^{
    __block SAPAlphabet *alphabet = nil;
//    + (SAPArrayAlphabet *)alphabetWithArray:(NSArray *) array;
//    + (SAPStringAlphabet *)alphabetWithString:(NSString *) string;
//    + (SAPUnicodeRangeAlphabet *)alphabetWithUnicodeRange:(NSRange) range;
//    
//    - (SAPArrayAlphabet *)initAlphabetWithArray:(NSArray *) array;
//    - (SAPStringAlphabet *)initAlphabetWithString:(NSString *) string;
//    - (NSArray *)arrayOfLetters;
//    - (NSString *)letterAtIndex:(NSUInteger) index;
//    - (NSUInteger)count;
//    - (NSString *)objectAtIndexSubscript:(NSUInteger)idx;
    
    context(@"when initialized with + alphabetWithUnicodeRange: with range a - z", ^{
        beforeAll(^{
            alphabet = [SAPAlphabet alphabetWithUnicodeRange:NSMakeRange('a', 'z' - 'a')];
        });
        
        afterAll(^{ // Occurs once
            alphabet = nil;
        });
        
        beforeEach(^{ // Occurs before each enclosed "it"
        });
        
        afterEach(^{ // Occurs after each enclosed "it"
        });
        
        it(@"should be of class SAPAlphabet", ^{
            [[alphabet should] beKindOfClass:[SAPAlphabet class]];
        });
        
        it(@"should be of count 26", ^{
            [[theValue([alphabet count]) should] equal:@(26)];
            [[alphabet shouldNot] haveCountOf:62];
        });
        
        it(@"should contain a at index 0", ^{
            [[[alphabet letterAtIndex:0] should] equal:@"a"];
        });

        it(@"should contain z at index 25", ^{
            [[alphabet[25] should] equal:@"z"];
        });
        
    });
});

SPEC_END