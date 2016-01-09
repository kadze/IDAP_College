//
//  SAPStringAdditions.h
//  MacCourse
//
//  Created by S A P on 11/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPAlphabet.h"

@interface NSString (SAPStringExtentions)

+ (NSString *)alphanumericAlphabet;
+ (NSString *)numericAlphabet;
+ (NSString *)letterAlphabet;
+ (NSString *)lowerCaseLetterAlphabet;
+ (NSString *)capitalizedCaseLetterAlphabet;
+ (NSString *)alphabetWithUnicodeRange:(NSRange)range;

+ (NSString *)generateRandomStringWithAlphabetString:(NSString *)alphabet ofSize:(NSUInteger)size;
+ (NSString *)generateRandomStringWithAlphabet:(SAPAlphabet *)alphabet ofSize:(NSUInteger)size;

- (NSString *)generateRandomStringFromSelfOfSize:(NSUInteger)size;

- (instancetype)separateWithSpaces;
- (NSArray *)symbols;

@end
