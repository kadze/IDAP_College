//
//  SAPEnterprise.h
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SAPWorker;
@class SAPBuilding;
@class SAPItemsContainer;
@class SAPWasher;
@class SAPRoom;

@interface SAPEnterprise : NSObject

@property (nonatomic, retain) NSArray *staff;
@property (nonatomic, retain) NSArray *buildings;

- (void)initialSetup;
- (void)hireWorker:(SAPWorker *)worker;
- (void)dismissWorker:(SAPWorker *)worker;

- (void)addBuilding:(SAPBuilding *)building;
- (void)removeBuilding:(SAPBuilding *)building;

-(NSArray *)buildingsOfClass:(Class)buildingClass;
-(NSArray *)workersOfClass:(Class)workerClass;

-(void)washCars:(NSArray *)cars;
-(SAPRoom *)findFreeRoomOfClass:(Class)roomClass;
-(SAPWasher *)findFreeWasher;

@end
