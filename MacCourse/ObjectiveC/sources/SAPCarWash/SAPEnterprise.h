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

@interface SAPEnterprise : NSObject

@property (nonatomic, retain) NSSet *staff;
@property (nonatomic, retain) NSSet *realEstate;

+ (SAPEnterprise *)carWashEnterpriseSetup;

- (SAPWorker*)hireWorker:(Class) speciality;
- (void)dismiss:(SAPWorker*) worker;
- (SAPBuilding*)buildWithClass:(Class) buildingClass withRooms:(NSUInteger) roomsCount;

@end
