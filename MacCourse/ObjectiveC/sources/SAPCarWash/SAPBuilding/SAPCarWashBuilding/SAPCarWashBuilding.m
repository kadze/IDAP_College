//
//  SAPCarWashBuilding.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCarWashBuilding.h"
#import "SAPItemsContainer.h"
#import "SAPCarWashRoom.h"

static NSUInteger const kDefaultInitialCarWashRoomsCount = 1;
static NSUInteger const kDefaultInitialRoomsCount = 1;

@interface SAPCarWashBuilding()

@property (nonatomic, retain) SAPItemsContainer *carWashRoomsContainer;

@end

@implementation SAPCarWashBuilding

@dynamic carWashRooms;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.carWashRoomsContainer = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [self initWithRoomsCount:(NSUInteger)kDefaultInitialRoomsCount carWashRoomsCount:(NSUInteger)kDefaultInitialCarWashRoomsCount];
    
    return self;
}

-(instancetype)initWithRoomsCount:(NSUInteger)roomsCount carWashRoomsCount:(NSUInteger)carWashRoomsCount {
    self = [super initWithRoomsCount:roomsCount];
    self.carWashRoomsContainer = [[[SAPItemsContainer alloc] initWithCapacity:carWashRoomsCount] autorelease];
    for (NSUInteger counter = 0; counter < carWashRoomsCount; counter++) {
        SAPCarWashRoom *newCarWashRoom = [[[SAPCarWashRoom alloc] init] autorelease];
        [self addRoom:newCarWashRoom];
    }
    
    return self;
}



#pragma mark-
#pragma mark Accessors

- (NSArray *)carWashRooms {
    return self.carWashRoomsContainer.items;
}

#pragma mark-
#pragma mark Public Methods

- (void)addCarWashRoom:(SAPRoom *)room {
    if([room isMemberOfClass:[SAPCarWashRoom class]]) {
        [self.carWashRoomsContainer setCapacity:(self.carWashRoomsContainer.items.count + 1)]; //unlimited carWashRooms capacity
        [self.carWashRoomsContainer addItem:room];
    }
}

- (void)removeRoom:(SAPRoom *)room {
    [self.carWashRoomsContainer removeItem:room];
    [self.carWashRoomsContainer setCapacity: self.carWashRoomsContainer.items.count];
}


@end
