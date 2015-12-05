//
//  SAPAlphabet.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SAPStringAlphabet;
@class SAPArrayAlphabet;
@class SAPUnicodeRangeAlphabet;

@interface SAPAlphabet : NSObject <NSFastEnumeration>

+ (instancetype)alphabetWithArray:(NSArray *) array;
+ (instancetype)alphabetWithString:(NSString *) string;
+ (instancetype)alphabetWithUnicodeRange:(NSRange) range;

- (instancetype)initAlphabetWithArray:(NSArray *) array;
- (instancetype)initAlphabetWithString:(NSString *) string;
- (instancetype)initAlphabetWithUnicodeRange:(NSRange) range;

- (NSArray *)arrayOfLetters;
- (NSString *)letterAtIndex:(NSUInteger) index;
- (NSUInteger)count;
- (NSString *)objectAtIndexedSubscript:(NSUInteger)index;

@end
