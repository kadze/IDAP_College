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

- (instancetype)initWithCars:(NSArray*)cars carsCapacity:(NSUInteger)carsCapacity;

- (void)addCar:(SAPCar *)car;
- (void)removeCar:(SAPCar *)car;

@end
