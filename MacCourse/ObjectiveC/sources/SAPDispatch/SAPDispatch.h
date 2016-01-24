//
//  SAPDispatch.h
//  MacCourse
//
//  Created by S A P on 1/22/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//
#import <dispatch/dispatch.h>

extern
void SAPDispatchAsyncOnMainQueue(dispatch_block_t block);

extern
void SAPDispatchSyncOnMainQueue(dispatch_block_t block);

extern
void SAPDispatchAsyncOnGlobalQueue(dispatch_queue_priority_t priority, dispatch_block_t block);

extern
void SAPDispatchSyncOnGlobalQueue(dispatch_queue_priority_t priority, dispatch_block_t block);

extern
void SAPDispatchAsyncOnQueue(dispatch_queue_t queue, dispatch_block_t block);

extern
void SAPDispatchSyncOnQueue(dispatch_queue_t queue, dispatch_block_t block);