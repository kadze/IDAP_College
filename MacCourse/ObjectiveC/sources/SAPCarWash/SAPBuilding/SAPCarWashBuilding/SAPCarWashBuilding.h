//
//  SAPCarWashBuilding.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPBuilding.h"

@interface SAPCarWashBuilding : SAPBuilding

@property (nonatomic, assign, readonly) NSUInteger  maxCarsCapacity;
@property (nonatomic, retain)           NSSet       *cars;

@end
