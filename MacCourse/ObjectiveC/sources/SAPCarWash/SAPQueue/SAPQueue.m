//
//  SAPContainer.m
//  MacCourse
//
//  Created by S A P on 1/9/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPQueue.h"
#import "NSObject+SAPObject.h"

@interface SAPQueue ()
@property (nonatomic, retain) NSMutableArray    *mutableItems;

@end

@implementation SAPQueue

@dynamic count;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.mutableItems = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    self.mutableItems = [NSMutableArray object];
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSUInteger)count {
    @synchronized(self) {
        return [self.mutableItems count];
    }
}

#pragma mark-
#pragma mark Public Methods

- (void)enqueue:(id)item {
    NSMutableArray *mutableItems = self.mutableItems;
    @synchronized(mutableItems) {
        [self.mutableItems addObject:item];
    }
}

- (id)dequeue {
    NSMutableArray *items = self.mutableItems;
    @synchronized(items) {
        id result = nil;
        if (0 != items.count) {
            result = [[items[0] retain] autorelease];
            [items removeObjectAtIndex:0];
        }
        
        return result;
    }
}

@end
