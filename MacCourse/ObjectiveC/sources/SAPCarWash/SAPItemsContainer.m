//
//  SAPItemsContainer.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPItemsContainer.h"

@interface SAPItemsContainer()

@property (nonatomic, retain) NSMutableArray    *mutableItems;

@end

@implementation SAPItemsContainer

@dynamic items;
@dynamic isFull;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.mutableItems = nil;
    
    [super dealloc];
}

- (instancetype)init {
    [self initWithCapacity:0];
    
    return self;
}

- (instancetype)initWithCapacity:(NSUInteger)capacity {
    self = [super init];
    self.mutableItems = [[[NSMutableArray alloc] initWithCapacity:capacity] autorelease];
//    self.capacity = capacity;
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)items {
    return [[self.mutableItems copy] autorelease];
}

- (NSArray *)itemsOfClass:(Class)itemClass {
    NSMutableArray *mutableResult = [NSMutableArray array];
    for (id item in self.mutableItems) {
        if ([item isMemberOfClass:itemClass]) {
            [mutableResult addObject:item];
        }
    }
    
    return [[mutableResult copy] autorelease];
}

//- (BOOL)isFull  {
//    return (self.mutableItems.count == self.capacity);
//}

#pragma mark-
#pragma mark Public Methods

- (BOOL)addItem:(id)item {
    BOOL result = NO;
//    if (!self.isFull) {
        [self.mutableItems addObject:item];
        result = YES;
//    }
    
    return result;
}

//- (void)extendWithItem:(id)item {
//    if (!self.isFull) {
//        self.capacity++;
//    }
//    
//    [self.mutableItems addObject:item];
//}

- (void)removeItem:(id)item {
    [self.mutableItems removeObject:item];
}

- (id)dequeue {
    id result = nil;
    NSMutableArray *items = [self mutableItems];
    if (0 != items.count) {
        result = items[0];
        [items removeObjectAtIndex:0];
    }
    
    return result;
}

//- (void)removeItemShrinkCapacity:(id)item {
//    [self removeItem:item];
//    self.capacity = self.mutableItems.count;
//}


@end
