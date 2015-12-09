//
//  SAPBuilding.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SAPRoom;

@interface SAPBuilding : NSObject

@property (nonatomic, readonly) NSArray *rooms;

//+ (BOOL)canContainItemsOfClass:(Class)itemClass;

- (instancetype)initWithRoomsCount:(NSUInteger)roomsCount;

- (void)addRoom:(SAPRoom *)room;
- (void)removeRoom:(SAPRoom *)room;

@end
