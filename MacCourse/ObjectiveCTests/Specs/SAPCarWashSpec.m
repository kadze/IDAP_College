////
////  SAPCarWash.m
////  MacCourse
////
////  Created by S A P on 12/7/15.
////  Copyright © 2015 Yosemite Retail. All rights reserved.
////
//
//#import "Kiwi.h"
//#import "SAPEnterprise.h"
//#import "SAPBuilding.h"
//#import "SAPCarWashBuilding.h"
//#import "SAPWorker.h"
//#import "SAPWasher.h"
//#import "SAPBoss.h"
//#import "SAPAccountant.h"
//
//
//
//SPEC_BEGIN(SAPCarWashSpec)
//
//describe(@"SAPCarWash", ^{
//    __block SAPEnterprise *carWashEnterprise = nil;
//    
//    context(@"when enterprise set up with +carWashEnterpriseSetup", ^{
//        beforeAll(^{
//            carWashEnterprise = [SAPEnterprise carWashEnterpriseSetup];
//        });
//        
//        it(@"should be of class SAPEnterprise", ^{
//            [[carWashEnterprise should] beMemberOfClass:[SAPEnterprise class]];
//        });
//        
//        it(@"should have 2 buildings", ^{
//            [[carWashEnterprise.realEstate should] haveCountOf:1];
//        });
//        
//        it(@"should have 1 carWash building and 1 office building", ^{
//            NSUInteger carWashCount = 0;
//            NSUInteger officeCount = 0;
//            SAPCarWashBuilding *carWash = nil;
//            SAPOfficeBuilding *office = nil;
//            for (SAPBuilding *building in carWashEnterprise.realEstate) {
//                if ([building isMemberOfClass:[SAPCarWashBuilding class]]) {
//                    carWashCount++;
//                    carWash = (SAPCarWashBuilding*)building;
//                } else if ([building isMemberOfClass:[SAPOfficeBuilding class]]) {
//                    officeCount++;
//                    office = (SAPOfficeBuilding*)building;
//                }
//            }
//            [[theValue(carWashCount) should] equal:@(1)];
//            [[theValue(officeCount) should] equal:@(1)];
//            
//            context(@"buildings composition", ^{
//                it(@"car wash building should have 1 room ", ^{
//                    [[theValue([carWash.rooms count]) should] equal:@(1)];
//                });
//                
//                SAPRoom *carWashRoom = carWash.rooms[0];
//                it(@"car wash's room should have 1 washer", ^{
//                    [[theValue([carWashRoom.people count]) should] equal:@(1)];
//                });
//                
//                it(@"car wash's room worker should be of class SAPWasher", ^{
//                    [[carWashRoom.people[0] should] beMemberOfClass:[SAPWasher class]];
//                });
//            
//            });
//        });
//    });
//});
//
//SPEC_END