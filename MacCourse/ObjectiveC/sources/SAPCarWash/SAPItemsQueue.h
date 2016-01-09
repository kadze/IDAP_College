//
//  SAPItemsQueue.h
//  MacCourse
//
//  Created by S A P on 1/9/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPContainer.h"

@interface SAPItemsQueue : SAPContainer

- (void)enqueue:(id)item;
- (id)dequeue;

@end
