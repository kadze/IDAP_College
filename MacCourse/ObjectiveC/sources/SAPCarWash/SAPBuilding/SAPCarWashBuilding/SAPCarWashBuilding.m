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

@interface SAPCarWashBuilding()

@end

@implementation SAPCarWashBuilding

@dynamic carWashRooms;

#pragma mark-
#pragma mark Accessors

- (NSArray *)carWashRooms {
    return [self roomsOfClass:[SAPCarWashRoom class]];
}

@end
