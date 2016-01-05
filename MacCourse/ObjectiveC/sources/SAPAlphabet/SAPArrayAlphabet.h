//
//  SAPAlphabetWithArray.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAlphabet.h"

@interface SAPArrayAlphabet : SAPAlphabet

@property (nonatomic, retain, readonly) NSArray*  letters;

- (instancetype) initWithArray:(NSArray *)  lettersArray;

@end
