//
//  SAPEnterprise.h
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPWorkerObservingProtocol.h"

@class SAPWorker;
@class SAPItemsContainer;
@class SAPWasher;

@interface SAPEnterprise : NSObject <SAPWorkerObservingProtocol>

@property (nonatomic, retain, readonly) NSArray *staff;

- (void)hireStaff;
- (void)hireWorker:(SAPWorker *)worker;
- (void)dismissWorker:(SAPWorker *)worker;

-(NSArray *)workersOfClass:(Class)workerClass;

-(void)washCars:(NSArray *)cars;
-(void)washNextCarWithWasher:(SAPWasher *)washer;
-(SAPWasher *)freeWasher;
-(SAPWorker *)freeWorkerOfClass:(Class)class;

@end
