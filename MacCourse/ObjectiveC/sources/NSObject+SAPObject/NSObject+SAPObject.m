//
//  NSObject+SAPObject.m
//  MacCourse
//
//  Created by S A P on 12/15/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "NSObject+SAPObject.h"

@implementation NSObject (SAPObject)

+ (instancetype)object {
   return [[[self alloc] init] autorelease];
}

@end
