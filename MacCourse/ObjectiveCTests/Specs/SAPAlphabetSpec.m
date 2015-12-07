//
//  SAPAlphabetSpec.m
//  MacCourse
//
//  Created by Andrey Shevtsov on 12/5/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#import "Kiwi.h"
#import "SAPAlphabet.h"
#import "SAPArrayAlphabet.h"
#import "SAPStringAlphabet.h"
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
//    - (instancetype)initAlphabetWithUnicodeRange:(NSRange) range;
//    - (NSArray *)arrayOfLetters;
//    - (NSString *)letterAtIndex:(NSUInteger) index;
//    - (NSUInteger)count;
//    - (NSString *)objectAtIndexSubscript:(NSUInteger)idx;
    
    context(@"when initialized with + alphabetWithUnicodeRange: with range a - c", ^{
        beforeAll(^{
            alphabet = [SAPAlphabet alphabetWithUnicodeRange:SAPMakeAlphabetRange('a', 'c')];
        });
        
        it(@"should be of class SAPAlphabet", ^{
            [[alphabet should] beKindOfClass:[SAPAlphabet class]];
        });
        
        it(@"should be of count 3", ^{
            [[theValue([alphabet count]) should] equal:@(3)];
            [[alphabet shouldNot] haveCountOf:62];
        });
        
        it(@"should contain a at index = 0", ^{
            [[[alphabet letterAtIndex:0] should] equal:@"a"];
        });

        it(@"should contain c at index = 2", ^{
            [[alphabet[2] should] equal:@"c"];
        });
        
        it(@"should throw exception, when requesting object at index 3", ^{
            [[theBlock(^{
                [alphabet letterAtIndex:3];
                id obj = alphabet[3];
            }) should] raise ];
        });
        
        it(@"should retunrn @\"abc\" from -string", ^{
            [[[alphabet string] should] equal:@"abc"];
        });
    });
    
    context(@"when initialized with - initAlphabetWithUnicodeRange: with range a - z", ^{
        beforeAll(^{
            alphabet = [[SAPAlphabet alloc ] initAlphabetWithUnicodeRange:NSMakeRange('a', 'z' - 'a')];
        });
        
        it(@"should be of class SAPAlphabet", ^{
            [[alphabet should] beKindOfClass:[SAPAlphabet class]];
        });
    });
    
    context(@"when initialized with + alphabetWithUnicodeRange: with range A - z , when enumerated" , ^{
        NSRange range = SAPMakeAlphabetRange('A', 'z');
        beforeAll(^{
            alphabet = [SAPAlphabet alphabetWithUnicodeRange:range];
        });
        
        it(@"shouldn't raise", ^{
            [[theBlock(^{
                for (id symbol in alphabet) {
                    [symbol description];
                }
            }) shouldNot ] raise];
        });
        
        it(@"should return symbols in range 'A' - 'z'", ^{
            unichar character = 'A';
            for (NSString *symbol in alphabet) {
                [[symbol should] equal:[NSString stringWithFormat:@"%C", character]];
                character++;
            }
        });
        
        it(@"should return count of symbols equal to 'A' - 'z' range length", ^{
            NSUInteger count = 0;
            for (NSString *symbol in alphabet) {
                [symbol description];
                count++;
            }
            
            [[theValue(count) should] equal:@(range.length)];
        });
    });
});

SPEC_END