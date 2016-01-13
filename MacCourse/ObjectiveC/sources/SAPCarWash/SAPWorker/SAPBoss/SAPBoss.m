//
//  SAPBoss.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPBoss.h"
#import "SAPWorker_Private.h"
#import "SAPQueue.h"

@implementation SAPBoss
@synthesize objectsQueue = _objectsQueue;

#pragma mark-
#pragma mark Private Methods

-(void)processObject:(SAPWorker *)worker {
    //profit
    SAPQueue *objectsQueue = self.objectsQueue;
    while (worker) {
        [self takeAllMoneyFromSender:worker];
        worker = [objectsQueue dequeue];
    }
    NSLog(@"now boss has %lu", self.money);
}

@end
