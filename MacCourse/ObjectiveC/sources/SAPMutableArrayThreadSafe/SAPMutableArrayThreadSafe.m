//
//  SAPMutableArrayThreadSafe.m
//  MacCourse
//
//  Created by S A P on 1/13/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPMutableArrayThreadSafe.h"

@interface SAPMutableArrayThreadSafe ()
@property (nonatomic, retain)   NSMutableArray      *array;

@end

@implementation SAPMutableArrayThreadSafe

@synthesize array           = _array;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.array = nil;
    
    [super dealloc];
}

- (id)init {
    return [self initWithCapacity:1];
}

- (id)initWithCapacity:(NSUInteger)numItems {
    self = [super init];
    if (self) {
        self.array = [NSMutableArray arrayWithCapacity:numItems];
    }
    
    return self;
}

#pragma mark -
#pragma mark NSArray

- (NSUInteger)count {
    return [self.array count];
}

- (id)objectAtIndex:(NSUInteger)index {
    return [self.array objectAtIndex:index];
}

#pragma mark -
#pragma mark NSMutableArray

- (void)insertObject:(id)anObject atIndex:(NSUInteger)index {
    @synchronized(self) {
        [self.array insertObject:anObject atIndex:index];
    }
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    @synchronized(self) {
        [self.array removeObjectAtIndex:index];
    }
}

- (void)addObject:(id)anObject {
    @synchronized(self) {
        [self.array addObject:anObject];
    }
}

- (void)removeLastObject {
    @synchronized(self) {
        [self.array removeLastObject];
    }
}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject {
    @synchronized(self) {
         [self.array replaceObjectAtIndex:index withObject:anObject];
    }
}

@end
