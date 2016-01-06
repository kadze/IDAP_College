//
//  SAPWorkerObservingProtocol.h
//  MacCourse
//
//  Created by S A P on 12/25/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SAPWorker;

@protocol SAPWorkerObservingProtocol <NSObject>

@optional

- (void)workerDidFinishWork:(SAPWorker *)worker;
- (void)workerDidBecomeReadyToWork:(SAPWorker *)worker;

//- (void)start;
//- (void)finish;
//- (void)becomeFree;

@end
