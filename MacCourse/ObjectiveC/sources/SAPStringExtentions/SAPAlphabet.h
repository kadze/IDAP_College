//
//  SAPAlphabet.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPAlphabet : NSObject

- (NSArray *)arrayOfLetters;
- (id)letterAtIndex:(NSUInteger) index;
- (NSUInteger)length;

@end
