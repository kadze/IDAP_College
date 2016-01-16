//
//  SAPStringAdditions.m
//  MacCourse
//
//  Created by S A P on 11/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "NSString+SAPStringExtentions.h"

static const unichar kSAPFirstLowerCaseLetter = 'a';
static const unichar kSAPLastLowerCaseLetter = 'z';
static const unichar kSAPFirstCapitalLetter = 'A';
static const unichar kSAPLastCapitalLetter = 'Z';
static const unichar kSAPFirstNumberSign = '0';
static const unichar kSAPLastNumberSign = '9';

@implementation NSString (SAPStringExtentions)

#pragma mark-
#pragma mark Class Methods

//alphabets
+ (NSString *)alphanumericAlphabet {
    NSMutableString *result = [NSMutableString stringWithString:[self numericAlphabet]];
    [result appendString:[self letterAlphabet]];
    
    return [self stringWithString:result];
}

+ (NSString *)numericAlphabet {
    return [self alphabetWithUnicodeRange:NSMakeRange(kSAPFirstNumberSign,
                                                      kSAPLastNumberSign - kSAPFirstNumberSign)];
}

+ (NSString *)letterAlphabet {
    NSMutableString *result = [NSMutableString stringWithString:[self lowerCaseLetterAlphabet]];
    [result appendString:[self capitalizedCaseLetterAlphabet]];
    
    return [self stringWithString:result];
}

+ (NSString *)lowerCaseLetterAlphabet {
    return [self alphabetWithUnicodeRange:NSMakeRange(kSAPFirstLowerCaseLetter,
                                                      kSAPLastLowerCaseLetter - kSAPFirstLowerCaseLetter)];
}

+ (NSString *)capitalizedCaseLetterAlphabet {
    return [self alphabetWithUnicodeRange:NSMakeRange(kSAPFirstCapitalLetter,
                                                      kSAPLastCapitalLetter - kSAPFirstCapitalLetter)];
}

+ (NSString *)alphabetWithUnicodeRange:(NSRange)range {
    NSMutableString *result = [NSMutableString string];
    for (unichar symbol = range.location; symbol <= NSMaxRange(range); symbol++) {
        [result appendFormat:@"%c", symbol];
    }
    
    return [self stringWithString:result];
}

//random strings
+ (NSString *)generateRandomStringWithAlphabetString:(NSString *)alphabet ofSize:(NSUInteger)size {
    int alphabetLength = (int)alphabet.length;
    unichar unichars[size];
    for (uint index = 0; index < size; index++) {
        unichars[index] = [alphabet characterAtIndex:arc4random_uniform(alphabetLength)];
    }
    
    return [self stringWithCharacters:unichars length:size];
}

+ (NSString *)generateRandomStringWithAlphabet:(SAPAlphabet *)alphabet ofSize:(NSUInteger)size {
    int alphabetLength = (int)alphabet.count;
    NSMutableString *mutableResult = [NSMutableString string];
    for (NSUInteger index = 0; index < size; index++) {
        [mutableResult appendString:[alphabet letterAtIndex:arc4random_uniform(alphabetLength)]];
    }
    
    return [self stringWithString:mutableResult];
}

#pragma mark-
#pragma mark Public Methods

- (instancetype)separateWithSpaces {
    //the final capacity must be twice larger than initial capacity because of adding the same amount of spaces
    int capacityMultiplicator = 2;
    //final capacity is double initial capacity - 1 because of absense of the space at the end of string
    int decreaseOnOne = 1;
    
    NSUInteger initialLength = [self length];
    NSMutableString *mutableResult = [NSMutableString stringWithCapacity:(initialLength) * capacityMultiplicator - decreaseOnOne];
    NSString *formatSpecifier;
    for (NSUInteger index = 0; index < initialLength; index++) {
        if ( 0 == index) {
            formatSpecifier = @"%c";
        } else {
            formatSpecifier = @" %c";
        }
        
        NSString *tempString = [NSString stringWithFormat:formatSpecifier, [self characterAtIndex:index]];
        [mutableResult appendString:tempString];
    }
    
    return [[mutableResult copy] autorelease];
}

- (NSString *)generateRandomStringFromSelfOfSize:(NSUInteger)size {
    return [[self class] generateRandomStringWithAlphabetString:self ofSize:size];
}

- (NSArray *)symbols {
    NSUInteger length = self.length;
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:length];
    for (NSUInteger index = 0; index < length; index++) {
        unichar symbol = [self characterAtIndex:(index)];
        [result addObject:[NSString stringWithFormat:@"%C", symbol]];
    }
    
    return [[result copy] autorelease];
}

@end
