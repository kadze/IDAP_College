//
//  Controller.h
//  MacCourse
//
//  Created by S A P on 1/16/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPController : NSObject
@property (nonatomic, readonly, getter=isWorking) BOOL working;

- (void)startWork;
- (void)stopWork;

@end
