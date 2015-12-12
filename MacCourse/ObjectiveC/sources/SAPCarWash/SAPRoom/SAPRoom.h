//
//  SAPRoom.h
//  MacCourse
//
//  Created by S A P on 12/1/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SAPWorker;

@interface SAPRoom : NSObject

@property (nonatomic, retain, readonly) NSArray *workers;

- (instancetype)initWithWorkers:(NSArray *)workers;
- (instancetype)initWithWorkersCapacity:(NSUInteger)workersCapacity;
- (instancetype)initWithWorkers:(NSArray*)workers workersCapacity:(NSUInteger)workersCapacity;
- (void)setWorkersCapacity:(NSUInteger)workersCapacity;

- (void)addWorker:(SAPWorker *)worker;
- (void)removeWorker:(SAPWorker *)worker;

- (NSArray *)workersOfClass:(Class)workerClass;

@end
