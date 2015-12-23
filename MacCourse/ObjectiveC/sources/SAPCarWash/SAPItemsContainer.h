//
//  SAPItemsContainer.h
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPItemsContainer : NSObject

@property (nonatomic, retain, readonly)         NSArray     *items;
@property (nonatomic, assign, readonly)         BOOL        isFull;

- (instancetype)initWithCapacity:(NSUInteger)capacity;

- (BOOL)addItem:(id)item;
- (void)removeItem:(id)item;
- (id)dequeue;
- (NSArray *)itemsOfClass:(Class)itemClass;



@end
