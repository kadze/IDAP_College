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

@property (nonatomic, retain, readonly) NSArray *carWashRooms;

-(instancetype)initWithRooms:(NSArray *)rooms carWashRooms:(NSArray *)carWashRooms;

-(void)addCarWashRoom:(SAPCarWashRoom *)carWashRoom;
-(void)removeCarWashRoom:(SAPCarWashRoom *)carWashRoom;

@end
