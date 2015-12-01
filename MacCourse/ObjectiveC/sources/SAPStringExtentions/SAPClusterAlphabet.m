//
//  SAPClusterAlphabet.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPClusterAlphabet.h"

@implementation SAPClusterAlphabet

#pragma mark-
#pragma mark Class Methods

+ (SAPAlphabetWithArray *) initAlphabetWithArray:(NSArray *) array {
    return [[SAPAlphabetWithArray alloc] initWithArray:array];
}

+ (SAPAlphabetWithString *) initAlphabetWithString:(NSString *) string {
    return [[SAPAlphabetWithString alloc] initWithString:string];
}

@end
