//
//  SAPCarWashBuilding.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPBuilding.h"

@class SAPCarWashRoom;

@interface SAPCarWashBuilding : SAPBuilding

@property (nonatomic, readonly) NSArray *carWashRooms;

-(instancetype)initWithRoomsCount:(NSUInteger)roomsCount carWashRoomsCount:(NSUInteger)carWashRoomsCount;

-(void)addCarWashRoom:(SAPCarWashRoom *)carWashRoom;
-(void)removeCarWashRoom:(SAPCarWashRoom *)carWashRoom;

@end
