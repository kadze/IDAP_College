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

- (void)addWorker:(SAPWorker *)worker;
- (void)removeWorkers:(SAPWorker *)worker;

@end
