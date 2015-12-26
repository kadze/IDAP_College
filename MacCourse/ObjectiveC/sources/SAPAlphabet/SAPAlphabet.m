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

NSRange SAPMakeAlphabetRange(unichar sign1, unichar sign2) {
    unichar maxSign = MAX(sign1, sign2);
    unichar minSign = MIN(sign1, sign2);
    
    return NSMakeRange(minSign, maxSign - minSign + 1);
}

@implementation SAPAlphabet

#pragma mark -
#pragma mark Class Methods

+ (instancetype)alphabetWithArray:(NSArray *)array {
    return [[[SAPArrayAlphabet alloc] initWithArray:array] autorelease];
}

+ (instancetype)alphabetWithString:(NSString *)string {
    return [[[SAPStringAlphabet alloc] initWithString:string] autorelease];
}

+ (instancetype)alphabetWithUnicodeRange:(NSRange)range {
    return [[[SAPUnicodeRangeAlphabet alloc] initWithRange:range] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (instancetype)init {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

- (instancetype)initAlphabetWithArray:(NSArray *)array {
    [self release];
    
    return [[SAPArrayAlphabet alloc] initWithArray:array];
}

- (instancetype)initAlphabetWithString:(NSString *)string {
    [self release];
    
    return [[SAPStringAlphabet alloc] initWithString:string];
}

- (instancetype)initAlphabetWithUnicodeRange:(NSRange)range {
    [self release];
    
    return [[SAPUnicodeRangeAlphabet alloc] initWithRange:range];
}

#pragma mark -
#pragma mark Public Implementations

- (NSString *)string {
    NSMutableString *mutableResult = [NSMutableString stringWithCapacity:[self count]];
    for (NSString *letter in self) {
        [mutableResult appendString:letter];
    }
    
    return [[mutableResult copy] autorelease];
}

- (NSArray *)letters {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

- (NSString *)letterAtIndex:(NSUInteger)index{
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

- (NSUInteger)count {
    [self doesNotRecognizeSelector:_cmd];
    
    return 0;
}

- (NSString *)objectAtIndexedSubscript:(NSUInteger)index{
    return [self letterAtIndex:index];
}

#pragma mark -
#pragma mark NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                objects:(id [])buffer
                                    count:(NSUInteger)len {
    state->mutationsPtr = (unsigned long *)self;
    NSUInteger length = MIN(state->state + len, [self count]);
    len = length - state->state;
    
    if (0 != len) {
        for (NSUInteger index = 0; index < len; index++) {
            buffer[index] = self[index + state->state];
        }
    }
    
    state->itemsPtr = buffer;
    state->state += len;
    
    return len;
}

@end
