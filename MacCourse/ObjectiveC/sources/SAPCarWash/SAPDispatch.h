//
//  SAPDispatch.h
//  MacCourse
//
//  Created by S A P on 1/22/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//
#import <dispatch/dispatch.h>

void SAPDispatchAsyncOnMainQueue(dispatch_block_t block);
void SAPDispatchSyncOnMainQueue(dispatch_block_t block);
void SAPDispatchAsyncOnGlobalQueue(dispatch_queue_priority_t priority, dispatch_block_t block);
void SAPDispatchSyncOnGlobalQueue(dispatch_queue_priority_t priority, dispatch_block_t block);
void SAPDispatchAsyncOnQueue(dispatch_queue_t queue, dispatch_block_t block);
void SAPDispatchSyncOnQueue(dispatch_queue_t queue, dispatch_block_t block);