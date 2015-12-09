//
//  SAPCarWashRoom.h
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPRoom.h"

@class SAPCar;

@interface SAPCarWashRoom : SAPRoom

@property (nonatomic, retain, readonly) NSArray *cars;

- (void)addCar:(SAPWorker *)car;
- (void)removeCar:(SAPWorker *)car;

@end
