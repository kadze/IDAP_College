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

+ (NSString *)sap_generateRandomStringWithString:(NSString *)alphabet ofSize:(NSUInteger) size;

+ (NSString *)sap_generateRandomStringWithAlphabet:(SAPAlphabet *)alphabet ofSize:(NSUInteger) size;

- (NSString *)sap_separateWithSpaces;

- (NSString *)sap_generateRandomStringOfSize:(NSUInteger) size;

@end
