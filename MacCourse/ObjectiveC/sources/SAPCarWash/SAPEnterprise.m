//
//  SAPEnterprise.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPEnterprise.h"
#import "SAPItemsContainer.h"
#import "SAPBuilding.h"
#import "SAPCarWashBuilding.h"
#import "SAPWorker.h"
#import "SAPWasher.h"
#import "SAPAccountant.h"
#import "SAPBoss.h"
#import "SAPCarWashRoom.h"
#import "SAPRoom.h"



@interface SAPEnterprise()

@property (nonatomic, retain) SAPItemsContainer *staffContainter;
@property (nonatomic, retain) SAPItemsContainer *buildingsContainter;

@end


@implementation SAPEnterprise

@dynamic buildings;
@dynamic staff;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.staffContainter = nil;
    self.buildingsContainter = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    self.staffContainter = [[[SAPItemsContainer alloc] init] autorelease];
    self.buildingsContainter = [[[SAPItemsContainer alloc] init] autorelease];
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)staff {
    return self.staffContainter.items;
}

- (NSArray *)buildings {
    return self.buildingsContainter.items;
}

#pragma mark Public Methods

- (void)hireWorker:(SAPWorker *)worker {
    self.staffContainter.capacity = self.staffContainter.items.count + 1;
    [self.staffContainter addItem:worker];
}

- (void)dismissWorker:(SAPWorker *)worker {
    [self.staffContainter removeItem:worker];
    self.staffContainter.capacity = self.staffContainter.items.count - 1;
}

- (void)addBuilding:(SAPBuilding *)building {
    self.buildingsContainter.capacity = self.buildingsContainter.items.count + 1;
    [self.buildingsContainter addItem:building];
}

- (void)removeBuilding:(SAPBuilding *)building {
    [self.buildingsContainter removeItem:building];
    self.buildingsContainter.capacity = self.buildingsContainter.items.count - 1;
}

-(NSArray *)buildingsOfClass:(Class)buildingClass {
    return [self.buildingsContainter itemsOfClass:buildingClass];
}

-(NSArray *)workersOfClass:(Class)workerClass {
    return [self.staffContainter itemsOfClass:workerClass];
}

- (void)initialSetup {
    // 1 room for car wash building wich can contain 1 washer and 1 car
    SAPCarWashRoom *carWashRoom = [[[SAPCarWashRoom alloc] init] autorelease];
    [carWashRoom setWorkersCapacity:1];
    [carWashRoom setCarsCapacity:1];
    
    
    //1 car wash building
    SAPCarWashBuilding *carWashBuilding = [[SAPCarWashBuilding alloc] initWithRooms:[NSArray array] carWashRooms:@[carWashRoom]];
    
    //1 room for office building which can contain 2 workers
    SAPRoom *officeRoom = [[[SAPRoom alloc] initWithWorkersCapacity:2] autorelease];
    
    //1 office building
    SAPBuilding *officeBuilding =[[SAPBuilding alloc] initWithRooms:@[officeRoom]];
    
    //add buildings to enterprise
    [self addBuilding:officeBuilding];
    [self addBuilding:carWashBuilding];
    
    //hire workers
    SAPWasher *washer =[[[SAPWasher alloc] init] autorelease];
    SAPAccountant *accountant = [[[SAPAccountant alloc] init] autorelease];
    SAPBoss *boss = [[[SAPBoss alloc] init] autorelease];
    
    [self hireWorker:washer];
    [self hireWorker:accountant];
    [self hireWorker:boss];
    
    //accomodate workers on workerking places
    [carWashRoom addWorker:washer];
    [officeRoom addWorker:accountant];
    [officeRoom addWorker:boss];
    
    //accountant observes for washer
    [washer addObserver:accountant];
    //boss is a moneyRecipient of the accountant
    accountant.moneyRecipient = boss;
    
}

-(void)washCars:(NSArray *)cars {
    SAPCarWashBuilding *carWashBuilding = [self buildingsOfClass:[SAPCarWashBuilding class]].firstObject;
    SAPCarWashRoom *carWashRoom = carWashBuilding.carWashRooms.firstObject;
    SAPWasher *washer = carWashRoom.workers.firstObject;
    for (SAPCar *car in cars) {
        [carWashRoom addCar:car];
        [washer makeJob];
        [carWashRoom removeCar:car];
    }
}

@end
