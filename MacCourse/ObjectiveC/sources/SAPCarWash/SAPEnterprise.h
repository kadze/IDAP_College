//
//  SAPEnterprise.h
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SAPWorker;
@class SAPItemsContainer;
@class SAPWasher;

@interface SAPEnterprise : NSObject

@property (nonatomic, retain) NSArray *staff;

- (void)hireStaff;
- (void)hireWorker:(SAPWorker *)worker;
- (void)dismissWorker:(SAPWorker *)worker;

-(NSArray *)workersOfClass:(Class)workerClass;

-(void)washCars:(NSArray *)cars;
-(SAPWasher *)freeWasher;

-(SAPWorker *)freeWorkerOfClass:(Class)class;

@end
