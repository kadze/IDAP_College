//
//  SAPStringAdditions.m
//  MacCourse
//
//  Created by S A P on 11/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPStringAdditions.h"

@implementation NSString (SAPStringAdditions)

- (NSMutableString *)sap_separateWithSpaces {
    NSUInteger initialLength = [self length];
    NSMutableString *result = [[NSMutableString stringWithCapacity:(initialLength) * 2 - 1 ] autorelease];
    NSString *formatSpecifier;
//    [formatSpecifier autorelease];
    for (NSUInteger index = 0; index < initialLength; index++) {

        if ( 0 == index) {
            formatSpecifier = @"%c";
        } else {
            formatSpecifier = @" %c";
        }
        NSString *tempString = [NSString stringWithFormat:formatSpecifier, [self characterAtIndex:index]];
        [tempString autorelease];
        [result appendString:tempString];
    }
    
    return result;
}

@end
