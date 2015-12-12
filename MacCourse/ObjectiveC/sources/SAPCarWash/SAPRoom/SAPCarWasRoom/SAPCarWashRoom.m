//
//  SAPCarWashRoom.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCarWashRoom.h"
#import "SAPItemsContainer.h"
#import "SAPCar.h"

@interface SAPCarWashRoom()

@property(nonatomic, retain) SAPItemsContainer *carsContainer;

@end

@implementation SAPCarWashRoom

@dynamic cars;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.carsContainer = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [self initWithCars:[NSArray array] carsCapacity:0];
    
    return self;
}

- (instancetype)initWithCars:(NSArray*)cars carsCapacity:(NSUInteger)carsCapacity {
    if (cars.count > carsCapacity) {
        return nil;
    }
    
    self = [super init];
    self.carsContainer = [[[SAPItemsContainer alloc] initWithCapacity:carsCapacity] autorelease];
    for (SAPCar *car in cars) {
        [self addCar:car];
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)cars {
    return self.carsContainer.items;
}

#pragma mark-
#pragma mark Public Methods

- (void)addCar:(SAPCar *)car {
    if ([car isKindOfClass:[SAPCar class]]) {
        [self.carsContainer addItem:car];
    }
    
}

- (void)removeCar:(SAPCar *)car {
    [self.carsContainer removeItem:car];
}



@end
