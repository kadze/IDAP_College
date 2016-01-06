//
//  SAPAlphabetWithRange.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAlphabet.h"

@interface SAPUnicodeRangeAlphabet : SAPAlphabet

@property (nonatomic, readonly)     NSRange range;

- (instancetype)initWithRange:(NSRange)range;

@end
