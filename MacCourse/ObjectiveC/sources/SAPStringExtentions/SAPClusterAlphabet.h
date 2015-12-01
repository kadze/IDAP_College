//
//  SAPClusterAlphabet.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPAlphabetWithArray.h"
#import "SAPAlphabetWithString.m"

@interface SAPClusterAlphabet : NSObject

+ (SAPAlphabetWithArray *) initAlphabetWithArray:(NSArray *) array;

+ (SAPAlphabetWithString *) initAlphabetWithString:(NSString *) string;

@end
