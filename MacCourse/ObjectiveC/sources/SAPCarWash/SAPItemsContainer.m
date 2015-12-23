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

#pragma mark-
#pragma mark Public Methods

- (BOOL)addItem:(id)item {
    BOOL result = NO;
    [self.mutableItems addObject:item];
    result = YES;
    
    return result;
}

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

@end
