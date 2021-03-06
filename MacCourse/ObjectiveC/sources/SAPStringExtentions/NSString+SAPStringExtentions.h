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

+ (NSString *)sap_generateRandomStringWithString:(NSString *)alphabet ofSize:(NSUInteger) size;
+ (NSString *)sap_generateRandomStringWithAlphabet:(SAPAlphabet *)alphabet ofSize:(NSUInteger) size;

- (NSString *)sap_generateRandomStringFromSelfOfSize:(NSUInteger) size;

- (instancetype)sap_separateWithSpaces;
- (NSArray *)symbols;

@end
