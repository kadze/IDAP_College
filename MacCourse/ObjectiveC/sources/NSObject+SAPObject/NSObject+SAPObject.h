//
//  NSObject+SAPObject.h
//  MacCourse
//
//  Created by S A P on 12/15/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (SAPObject)

+ (instancetype)object;
+ (NSArray *)objectsWithCount:(NSUInteger)count;

@end
