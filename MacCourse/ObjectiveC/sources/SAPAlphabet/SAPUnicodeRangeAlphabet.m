//
//  SAPAlphabetWithRange.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPUnicodeRangeAlphabet.h"

@interface SAPUnicodeRangeAlphabet ()

@property (nonatomic, assign) NSRange range;

@end

@implementation SAPUnicodeRangeAlphabet

#pragma mark-
#pragma mark Initializations and Deallocations

- (instancetype) initWithRange:(NSRange) range {
//    self = [super init];
    if (self) {
        self.range = range;
    }
    
    return self;

}

#pragma mark-
#pragma mark Public Methods

- (NSArray *)arrayOfLetters {
    NSMutableArray *result = [NSMutableArray array];
    NSRange range = self.range;
    for (unichar symbol = range.location; symbol < NSMaxRange(range); symbol++) {
        [result addObject:[NSString stringWithFormat:@"%C", symbol]];
    }
    
    return [[result copy] autorelease];
}

- (NSString *)letterAtIndex:(NSUInteger) index {
    NSRange range = self.range;
    NSAssert(index < range.length, NSRangeException);
    return [NSString stringWithFormat:@"%C", (unichar)(range.location + index)];
}

- (NSUInteger)count {
    return self.range.length;
}

@end
