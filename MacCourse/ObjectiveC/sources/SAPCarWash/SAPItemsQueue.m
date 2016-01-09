//
//  SAPItemsQueue.m
//  MacCourse
//
//  Created by S A P on 1/9/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPItemsQueue.h"

@interface SAPItemsQueue ()
@property (nonatomic, retain) NSMutableArray    *mutableItems;

@end

@implementation SAPItemsQueue

- (void)enqueue:(id)item {
    NSMutableArray *mutableItems = self.mutableItems;
    @synchronized(mutableItems) {
        [self.mutableItems addObject:item];
    }
}

- (id)dequeue {
    NSMutableArray *items = self.mutableItems;
    @synchronized(items) {
        if (items != self.mutableItems) {
            items = self.mutableItems;
        }
        
        id result = nil;
        if (0 != items.count) {
            result = [[items[0] retain] autorelease];
            [items removeObjectAtIndex:0];
        }
        
        return result;
    }
}

@end
