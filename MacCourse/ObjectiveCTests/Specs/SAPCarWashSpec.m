//
//  SAPCarWash.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "Kiwi.h"
#import "SAPEnterprise.h"
#import "SAPBuilding.h"
#import "SAPCarWashBuilding.h"
#import "SAPWorker.h"
#import "SAPWasher.h"
#import "SAPBoss.h"
#import "SAPAccountant.h"
#import "SAPRoom.h"
#import "SAPCarWashRoom.h"



SPEC_BEGIN(SAPCarWashSpec)

describe(@"SAPCarWash", ^{
    __block SAPEnterprise *carWashEnterprise = nil;
    
    context(@"when enterprise set up ", ^{
        __block NSArray *carWashBuildings;
        __block NSArray *officeBuildings;
        
        beforeAll(^{
            carWashEnterprise = [[SAPEnterprise alloc] init];
            [carWashEnterprise initialSetup];
        });
        
        it(@"should be of class SAPEnterprise", ^{
            [[carWashEnterprise should] beMemberOfClass:[SAPEnterprise class]];
        });
        
        it(@"should have 2 buildings", ^{
            [[carWashEnterprise.buildings should] haveCountOf:2];
        });
        
        it(@"should have 1 carWash building and 1 office building", ^{
            carWashBuildings = [carWashEnterprise buildingsOfClass:[SAPCarWashBuilding class]];
            [[carWashBuildings should] haveCountOf:1];
            officeBuildings = [carWashEnterprise buildingsOfClass:[SAPBuilding class]];
            [[officeBuildings should] haveCountOf:1];
        });
        
        it(@"car wash building should have 1 car wash room ", ^{
            SAPCarWashBuilding *carWash = carWashBuildings[0];
            [[carWash.carWashRooms should] haveCountOf:1];
            [[carWash.carWashRooms[0] should] beMemberOfClass:[SAPCarWashRoom class]];
        });
        
        it(@"car wash's room should have 1 washer", ^{
            SAPCarWashBuilding *carWash = carWashBuildings[0];
            SAPCarWashRoom *carWashRoom = carWash.carWashRooms[0];
            [[carWashRoom.workers should] haveCountOf:1];
            [[carWashRoom.workers[0] should] beKindOfClass:[SAPWasher class]];
        });
        
        it(@"office building should have 1 office room", ^{
            SAPBuilding *officeBuilding = officeBuildings[0];
            [[officeBuilding.rooms should] haveCountOf:1];
            [[officeBuilding.rooms[0] should] beMemberOfClass:[SAPRoom class]];
        });
        
        it(@"office room should have 2 workers: accountant and boss", ^{
            SAPBuilding *officeBuilding = officeBuildings[0];
            SAPRoom *officeRoom = officeBuilding.rooms[0];
            [[officeRoom.workers should] haveCountOf:2];
            [[[officeRoom workersOfClass:[SAPAccountant class]] should] haveCountOf:1];
            [[[officeRoom workersOfClass:[SAPBoss class]] should] haveCountOf:1];
        });
    });
});

SPEC_END