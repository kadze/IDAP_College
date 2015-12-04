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

@interface SAPAlphabet : NSObject

+ (SAPArrayAlphabet *)alphabetWithArray:(NSArray *) array;

+ (SAPStringAlphabet *)alphabetWithString:(NSString *) string;

+ (SAPUnicodeRangeAlphabet *)alphabetWithUnicodeRange:(NSRange) range;

- (SAPArrayAlphabet *)initAlphabetWithArray:(NSArray *) array;

- (SAPStringAlphabet *)initAlphabetWithString:(NSString *) string;


- (NSArray *)arrayOfLetters;
- (id)letterAtIndex:(NSUInteger) index;
- (NSUInteger)length;

@end
