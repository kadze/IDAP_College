//
//  NSObject+SAPObject.m
//  MacCourse
//
//  Created by S A P on 12/15/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "NSObject+SAPObject.h"
#import "NSNumber+SAPExtentions.h"

@implementation NSObject (SAPObject)

#pragma mark-
#pragma mark Class Methods

+ (instancetype)object {
   return [[[self alloc] init] autorelease];
}

+ (NSArray *)objectsWithCount:(NSUInteger)count {
    NSMutableArray *array = [[NSMutableArray new] autorelease];
    [@(count) times:^(NSNumber *value) {[array addObject:value];}];
    
    return [[array copy] autorelease];
}
@end
