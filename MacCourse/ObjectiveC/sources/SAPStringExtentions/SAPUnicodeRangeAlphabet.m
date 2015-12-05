//
//  SAPAlphabetWithRange.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPUnicodeRangeAlphabet.h"

@interface SAPUnicodeRangeAlphabet ()

@property (nonatomic, assign) NSRange unicodeRange;

@end

@implementation SAPUnicodeRangeAlphabet

#pragma mark-
#pragma mark Initializations and Deallocations

- (instancetype) initWithRange:(NSRange) range {
    self = [super init];
    if (self) {
        self.unicodeRange = range;
    }
    
    return self;

}

#pragma mark-
#pragma mark Public Methods

- (NSArray *)arrayOfLetters {
    NSMutableArray *result = [NSMutableArray array];
    for (unichar symbol = self.unicodeRange.location; symbol < self.unicodeRange.length; symbol++) {
        [result addObject:[NSString stringWithFormat:@"%C", symbol]];
    }
    
    return [result copy];
}

- (id)letterAtIndex:(NSUInteger) index {
    unichar unicharIndex = (unichar)index;
    unichar letterLocation = self.unicodeRange.location + unicharIndex;
    
    return [NSString stringWithFormat:@"%C", letterLocation];
}

- (NSUInteger)length {
    return self.unicodeRange.length;
}

@end
