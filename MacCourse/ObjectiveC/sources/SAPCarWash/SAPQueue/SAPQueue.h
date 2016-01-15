//
//  SAPContainer.h
//  MacCourse
//
//  Created by S A P on 1/9/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPQueue : NSObject
@property (nonatomic, readonly) NSArray     *items;
@property (nonatomic, readonly) NSUInteger  count;

- (void)enqueue:(id)item;
- (id)dequeue;

@end
