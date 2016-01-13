//
//  SAPAccountant.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPAccountant.h"
#import "SAPQueue.h"


@implementation SAPAccountant

#pragma mark-
#pragma mark Private Methods

- (void)processObject:(SAPWorker *)washer {
    [self takeAllMoneyFromSender:washer];
}
@end
