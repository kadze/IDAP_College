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

#pragma mark-
#pragma mark Class Methods

+ (SAPArrayAlphabet *)alphabetWithArray:(NSArray *) array {
    return [[[SAPArrayAlphabet alloc] initWithArray:array] autorelease];
}

+ (SAPStringAlphabet *)alphabetWithString:(NSString *) string {
    return [[[SAPStringAlphabet alloc] initWithString:string] autorelease];
}

+ (SAPUnicodeRangeAlphabet *)alphabetWithUnicodeRange:(NSRange) range {
    return [[[SAPUnicodeRangeAlphabet alloc] initWithRange:range] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (SAPArrayAlphabet *)initAlphabetWithArray:(NSArray *) array {
    [self release];
    
    return [[SAPArrayAlphabet alloc] initWithArray:array];
}

- (SAPStringAlphabet *)initAlphabetWithString:(NSString *) string {
    [self release];
    
    return [[SAPStringAlphabet alloc] initWithString:string];
    
}

#pragma mark -
#pragma mark Public Implementations

//for overload
- (NSArray *)arrayOfLetters {
    return nil;
}

//for overload
- (id)letterAtIndex:(NSUInteger) index{
    return nil;
}

//for overload
- (NSUInteger)length {
    return 0;
}

@end
