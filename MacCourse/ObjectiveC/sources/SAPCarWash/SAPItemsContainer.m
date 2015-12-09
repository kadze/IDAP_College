//
//  SAPItemsContainer.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPItemsContainer.h"

@interface SAPItemsContainer()

@property (nonatomic) NSMutableArray    *mutableItems;
//@property (nonatomic) NSUInteger        capacity;

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
    self.capacity = capacity;
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)items {
    return [[self.mutableItems copy] autorelease];
}

- (BOOL)isFull  {
    return (self.mutableItems.count == self.capacity);
}

#pragma mark-
#pragma mark Public Methods

- (BOOL)addItem:(id)item {
    BOOL result = NO;
    if (![self isFull]) {
        [self.mutableItems addObject:item];
        result = YES;
    }
    
    return result;
}

- (void)removeItem:(id)item {
    [self.mutableItems removeObject:item];
}

@end
