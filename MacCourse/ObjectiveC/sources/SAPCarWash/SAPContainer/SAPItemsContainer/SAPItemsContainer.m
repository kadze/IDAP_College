//
//  SAPItemsContainer.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPItemsContainer.h"
#import "SAPContainer+Private.h"

@implementation SAPItemsContainer

#pragma mark-
#pragma mark Public Methods

- (BOOL)addItem:(id)item {
    NSMutableArray *mutableItems = self.mutableItems;
    @synchronized(mutableItems) {
        BOOL result = NO;
        [self.mutableItems addObject:item];
        result = YES;
        
        return result;
    }
}

- (void)removeItem:(id)item {
    NSMutableArray *mutableItems = self.mutableItems;
    @synchronized(mutableItems) {
        [self.mutableItems removeObject:item];
    }
}

@end
