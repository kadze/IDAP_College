//
//  SAPBoss.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPBoss.h"

@implementation SAPBoss

#pragma mark-
#pragma mark Public Methods

-(void)makeJobWithObject:(id)accountant {
    @synchronized(self) {
        self.state = kSAPIsBusy;
        [self takeAllMoneyFromSender:accountant];
        [accountant setState:kSAPIsReadyToWork];
        self.state = kSAPIsReadyToWork;
        
        NSLog(@"now boss has %lu", self.money);
    }
}

@end
