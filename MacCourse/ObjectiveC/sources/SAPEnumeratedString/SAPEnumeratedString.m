//
//  SAPEnumeratedString.m
//  MacCourse
//
//  Created by S A P on 11/27/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPEnumeratedString.h"

@implementation SAPEnumeratedString

#pragma mark-
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.string = nil;
    
    [super dealloc];
}

#pragma mark-
#pragma mark NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                        objects:(id [])buffer
                        count:(NSUInteger)len
{
    NSString *string = self.string;
    
    state->mutationsPtr = (unsigned long *)string;
    
    NSUInteger currentOffset = state->state;
    
    NSUInteger result = MIN(currentOffset + len, string.length);
    result -= currentOffset;
    
    for (NSUInteger index = 0; index < result; index++) {
        unichar symbol = [string characterAtIndex:(currentOffset + index)];
        NSString *symbolString = [NSString stringWithFormat:@"%C", symbol];
        buffer[index] = symbolString;
    }
    
    state->itemsPtr = buffer;
    state->state += result;
    
    return result;
}


@end
