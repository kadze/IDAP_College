//
//  NSArray+SAPExtentions.m
//  MacCourse
//
//  Created by S A P on 1/13/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "NSArray+SAPExtentions.h"

@implementation NSArray (SAPExtentions)

#pragma mark-
#pragma mark Public Methods

- (NSArray *)objectsOfClass:(Class)class {
    NSMutableArray *mutableResult = [NSMutableArray array];
    for (id object in self) {
        if ([object isMemberOfClass:class]) {
            [mutableResult addObject:object];
        }
    }
    
    return [[mutableResult copy] autorelease];
}

@end
