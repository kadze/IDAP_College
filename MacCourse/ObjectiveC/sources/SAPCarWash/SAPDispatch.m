//
//  SAPDispatch.m
//  MacCourse
//
//  Created by S A P on 1/22/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPDispatch.h"

#pragma mark -
#pragma mark Public Implementations

void SAPDispatchAssyncOnMainQueue(dispatch_block_t block) {
    dispatch_async(dispatch_get_main_queue(), block);
};

void SAPDispatchSyncOnMainQueue(dispatch_block_t block) {
    dispatch_queue_t mainQueue = dispatch_get_main_queue();
    if(mainQueue == dispatch_get_current_queue()) {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
}
void SAPDispatchAssyncOnGlobalQueue(dispatch_queue_priority_t priority, dispatch_block_t block) {
    dispatch_queue_t queue = dispatch_get_global_queue(priority, 0);
    dispatch_async(queue, block);
}
void SAPDispatchSyncOnGlobalQueue(dispatch_queue_priority_t priority, dispatch_block_t block) {
    dispatch_queue_t queue = dispatch_get_global_queue(priority, 0);
    if(queue == dispatch_get_current_queue()) {
        dispatch_sync(queue, block);
    }
}
