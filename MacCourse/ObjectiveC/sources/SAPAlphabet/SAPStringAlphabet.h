//
//  SAPAlphabetWithString.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAlphabet.h"

@interface SAPStringAlphabet : SAPAlphabet

//@property (nonatomic, retain, readonly)     NSString*  letters;

- (instancetype)initWithString:(NSString *)string;

@end
