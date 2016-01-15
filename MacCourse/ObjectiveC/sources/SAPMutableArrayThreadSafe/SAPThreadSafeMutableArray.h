//
//  SAPThreadSafeMutableArray.h
//  MacCourse
//
//  Created by S A P on 1/13/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPThreadSafeMutableArray : NSMutableArray

- (NSUInteger)count;
- (id)objectAtIndex:(NSUInteger)index;
- (void)insertObject:(id)anObject atIndex:(NSUInteger)index;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)addObject:(id)anObject;
- (void)removeLastObject;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;

@end
