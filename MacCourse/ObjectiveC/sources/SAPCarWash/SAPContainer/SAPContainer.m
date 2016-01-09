//
//  SAPContainer.m
//  MacCourse
//
//  Created by S A P on 1/9/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPContainer.h"

@interface SAPContainer ()
@property (nonatomic, retain) NSMutableArray    *mutableItems;

@end

@implementation SAPContainer

@dynamic items;

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
    NSMutableArray *mutableItems = self.mutableItems;
    @synchronized(mutableItems) {
        return [[self.mutableItems copy] autorelease];
    }
    
}

#pragma mark-
#pragma mark Public Methods

- (NSArray *)itemsOfClass:(Class)itemClass {
    @synchronized(self) {
        NSMutableArray *mutableResult = [NSMutableArray array];
        for (id item in self.items) {
            if ([item isMemberOfClass:itemClass]) {
                [mutableResult addObject:item];
            }
        }
        
        return [[mutableResult copy] autorelease];
    }
}

- (void)removeAllItems {
    NSMutableArray *mutableItems = self.mutableItems;
    @synchronized(mutableItems) {
        [self.mutableItems removeAllObjects];
    }
}

@end
