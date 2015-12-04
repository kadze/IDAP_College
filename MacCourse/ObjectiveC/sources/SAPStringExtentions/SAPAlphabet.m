//
//  SAPAlphabet.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAlphabet.h"
#import "SAPStringAlphabet.h"
#import "SAPUnicodeRangeAlphabet.h"
#import "SAPArrayAlphabet.h"

@implementation SAPAlphabet


#pragma mark -
#pragma mark Initializations and Deallocations

- (SAPArrayAlphabet *)initAlphabetWithArray:(NSArray *) array {
    
}

- (SAPStringAlphabet *)initAlphabetWithString:(NSString *) string {
    
}

#pragma mark -
#pragma mark Public Implementations

//for overload
- (NSArray *)arrayOfLetters {
    return nil;
}

//for overload
- (id *)letterAtIndex {
    return nil;
}

//for overload
- (NSUInteger)length {
    return 0;
}

@end
