//
//  SAPAccountant.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAccountant.h"
#import "SAPWorker_Private.h"
#import "SAPItemsQueue.h"


@implementation SAPAccountant
@synthesize objectsQueue = _objectsQueue;

#pragma mark-
#pragma mark Private Methods

- (void)processObject:(SAPWorker *)washer {
    SAPItemsQueue *objectsQueue = self.objectsQueue;
    while (washer) {
        [self takeAllMoneyFromSender:washer];
        washer = [objectsQueue dequeue];
    }
}
@end
