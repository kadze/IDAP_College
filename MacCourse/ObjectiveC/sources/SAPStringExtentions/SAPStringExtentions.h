//
//  SAPStringAdditions.h
//  MacCourse
//
//  Created by S A P on 11/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (SAPStringExtentions)

+ (NSString *)sap_generateRandomStringWithAlphabet:(NSString *)alphabet size:(NSUInteger) size;

- (NSString *)sap_separateWithSpaces;

- (NSString *)sap_generateRandomStringOfSize:(NSUInteger) size;

@end
