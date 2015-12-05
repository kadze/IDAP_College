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

+ (instancetype)alphabetWithArray:(NSArray *) array {
    return [[[SAPArrayAlphabet alloc] initWithArray:array] autorelease];
}

+ (instancetype)alphabetWithString:(NSString *) string {
    return [[[SAPStringAlphabet alloc] initWithString:string] autorelease];
}

+ (instancetype)alphabetWithUnicodeRange:(NSRange) range {
    return [[[SAPUnicodeRangeAlphabet alloc] initWithRange:range] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

- (instancetype)initAlphabetWithArray:(NSArray *) array {
    [self release];
    
    return [[SAPArrayAlphabet alloc] initWithArray:array];
}

- (instancetype)initAlphabetWithString:(NSString *) string {
    [self release];
    
    return [[SAPStringAlphabet alloc] initWithString:string];
}

- (instancetype)initAlphabetWithUnicodeRange:(NSRange) range {
    [self release];
    
    return [[SAPUnicodeRangeAlphabet alloc] initWithRange:range];
}

#pragma mark -
#pragma mark Public Implementations

//for overload
- (NSArray *)arrayOfLetters {
    return nil;
}

//for overload
- (NSString *)letterAtIndex:(NSUInteger) index{
    return nil;
}

//for overload
- (NSUInteger)count {
    return 0;
}

- (NSString *)objectAtIndexSubscript:(NSUInteger) index{
    return [self letterAtIndex:index];
}

#pragma mark-
#pragma mark NSFastEnumeration

//- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
//                                objects:(id [])buffer
//                                    count:(NSUInteger)len {
//    
//}


@end
