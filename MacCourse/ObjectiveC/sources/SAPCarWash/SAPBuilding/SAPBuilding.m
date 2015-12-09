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

static NSUInteger const kDefaultInitialRoomsCount = 1;

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
    self = [self initWithRoomsCount:kDefaultInitialRoomsCount];
    
    return self;
}

- (instancetype)initWithRoomsCount:(NSUInteger)roomsCount {
    self = [super init];
    self.roomsContainer = [[[SAPItemsContainer alloc] initWithCapacity:roomsCount] autorelease];
    for (NSUInteger counter = 0; counter < roomsCount; counter++) {
        SAPRoom *newRoom = [[[SAPRoom alloc] init] autorelease];
        [self addRoom:newRoom];
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
    [self.roomsContainer setCapacity:(self.roomsContainer.items.count + 1)]; //unlimited rooms capacity
    [self.roomsContainer addItem:room];
}

- (void)removeRoom:(SAPRoom *)room {
    [self.roomsContainer removeItem:room];
    [self.roomsContainer setCapacity:self.roomsContainer.items.count];
}

@end
