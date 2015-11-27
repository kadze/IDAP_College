//
//  SAPStringAdditions.m
//  MacCourse
//
//  Created by S A P on 11/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPStringExtentions.h"

@implementation NSString (SAPStringExtentions)

- (NSString *)sap_separateWithSpaces {
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
    
    NSString *result = [mutableResult copy];
    
    return result;
}

@end
