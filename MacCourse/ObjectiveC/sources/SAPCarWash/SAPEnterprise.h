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

@interface SAPEnterprise : NSObject

@property (nonatomic, retain) SAPItemsContainer *staff;
@property (nonatomic, retain) SAPItemsContainer *realEstate;

+ (SAPEnterprise *)carWashEnterpriseSetup;

- (SAPWorker*)hireWorker:(Class) speciality;
- (void)dismiss:(SAPWorker*) worker;
- (SAPBuilding*)buildWithClass:(Class) buildingClass withRooms:(NSUInteger) roomsCount;

@end
