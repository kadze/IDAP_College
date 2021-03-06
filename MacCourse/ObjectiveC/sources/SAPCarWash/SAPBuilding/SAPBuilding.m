//
//  SAPBuilding.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPBuilding.h"
#import "SAPItemsContainer.h"
#import "SAPRoom.h"

@interface SAPBuilding()

@property (nonatomic, retain) SAPItemsContainer *roomsContainer;

@end

@implementation SAPBuilding

@dynamic rooms;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.roomsContainer = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [self initWithRooms:nil];
    
    return self;
}

- (instancetype)initWithRooms:(NSArray *)rooms {
    self = [super init];
    self.roomsContainer = [[[SAPItemsContainer alloc] initWithCapacity:rooms.count] autorelease];
    for (SAPRoom *room in rooms) {
        [self addRoom:room];
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)rooms {
    return self.roomsContainer.items;
}

#pragma mark-
#pragma mark Public Methods

- (void)addRoom:(SAPRoom *)room {
    [self.roomsContainer extendWithItem:room]; //unlimited rooms capacity
}

- (void)removeRoom:(SAPRoom *)room {
    [self.roomsContainer removeItemShrinkCapacity:room];
}

- (NSArray *)roomsOfClass:(Class)roomClass {
    return [self.roomsContainer itemsOfClass:roomClass];
}

@end
