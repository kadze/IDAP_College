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

@property (nonatomic, retain, readonly) NSArray *rooms;

- (instancetype)initWithRooms:(NSArray *)rooms;

- (void)addRoom:(SAPRoom *)room;
- (void)removeRoom:(SAPRoom *)room;

- (NSArray *)roomsOfClass:(Class)roomClass;

@end
