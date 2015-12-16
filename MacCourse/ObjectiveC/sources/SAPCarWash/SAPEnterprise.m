//
//  SAPEnterprise.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "NSObject+SAPObject.h"
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
    self.staffContainter = [SAPItemsContainer object];
    self.buildingsContainter = [SAPItemsContainer object];
    
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
    [self.staffContainter extendWithItem:worker];
}

- (void)dismissWorker:(SAPWorker *)worker {
    [self.staffContainter removeItemShrinkCapacity:worker];
}

- (void)addBuilding:(SAPBuilding *)building {
    [self.buildingsContainter extendWithItem:building];
}

- (void)removeBuilding:(SAPBuilding *)building {
    [self.buildingsContainter removeItemShrinkCapacity:building];
}

-(NSArray *)buildingsOfClass:(Class)buildingClass {
    return [self.buildingsContainter itemsOfClass:buildingClass];
}

-(NSArray *)workersOfClass:(Class)workerClass {
    return [self.staffContainter itemsOfClass:workerClass];
}

- (void)initialSetup {
    // 1 room for car wash building wich can contain 1 washer and 1 car
    SAPCarWashRoom *carWashRoom = [SAPCarWashRoom object];
    [carWashRoom setWorkersCapacity:1];
    [carWashRoom setCarsCapacity:1];
    
    
    //1 car wash building
    SAPCarWashBuilding *carWashBuilding = [[SAPCarWashBuilding alloc] initWithRooms:@[carWashRoom]];
    
    //1 room for office building which can contain 2 workers
    SAPRoom *officeRoom = [[[SAPRoom alloc] initWithWorkersCapacity:2] autorelease];
    
    //1 office building
    SAPBuilding *officeBuilding =[[SAPBuilding alloc] initWithRooms:@[officeRoom]];
    
    //add buildings to enterprise
    [self addBuilding:officeBuilding];
    [self addBuilding:carWashBuilding];
    
    //hire workers
    SAPWasher *washer =[SAPWasher object];
    SAPAccountant *accountant = [SAPAccountant object];
    SAPBoss *boss = [SAPBoss object];
    
    NSArray *workers = @[washer, accountant, boss];
    for (SAPWorker* worker in workers) {
        [self hireWorker:worker];
    }
    
    //accomodate workers on working places
    [carWashRoom addWorker:washer];
    [officeRoom addWorker:accountant];
    [officeRoom addWorker:boss];
    
    //accountant observes for washer
    [washer addObserver:accountant];
    //boss is a moneyRecipient of the accountant
    [accountant addObserver:boss];
    
}

-(void)washCars:(NSArray *)cars {
//    SAPCarWashBuilding *carWashBuilding = [self buildingsOfClass:[SAPCarWashBuilding class]].firstObject;
//    SAPCarWashRoom *carWashRoom = carWashBuilding.carWashRooms.firstObject;
//    SAPWasher *washer = carWashRoom.workers.firstObject;
    while (true) {
        for (SAPCar *car in cars) {
            SAPCarWashRoom *carWashRoom = (SAPCarWashRoom *)[self findFreeRoomOfClass:[SAPCarWashRoom class]];
            if (carWashRoom) {
                [carWashRoom addCar:car];
            } else {
                break;
            }
            SAPWasher *washer = [self findFreeWasher];
            if (washer) {
                [washer makeJobWithObject:car];
                [carWashRoom removeCar:car];
            }
        }
    }
}

-(SAPRoom *)findFreeRoomOfClass:(Class)roomClass {
    SAPRoom *result = nil;
    for (SAPBuilding *building in self.buildingsContainter.items) {
        for (SAPCarWashRoom *room in [building roomsOfClass:roomClass]) {
            if (0 == [room cars].count) {
                result = room;
                
                break;
            }
        }
        
        if (result) {
            break;
        }
    }
    
    return result;
}

-(SAPWasher *)findFreeWasher {
    SAPWasher *washer= nil;
    for (washer in [self workersOfClass:[SAPWasher class]]) {
        if (kSAPIsReadyToWork == washer.state) {
            break;
        }
    }
    
    return washer;
}


@end
