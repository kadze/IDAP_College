//
//  SAPDispatcher.h
//  MacCourse
//
//  Created by S A P on 1/16/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SAPQueue;

@interface SAPDispatcher : NSObject
@property(nonatomic, readonly) NSArray *handlers;

- (void)addHandler:(id)handler;
- (void)removeHandler:(id)handler;
- (void)performWorkWithObject:(id)object;

@end
