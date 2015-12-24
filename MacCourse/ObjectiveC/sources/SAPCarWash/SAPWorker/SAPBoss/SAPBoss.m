//
//  SAPBoss.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPBoss.h"

@implementation SAPBoss

-(void)makeJobWithObject:(id)accountant {
    [self takeAllMoneyFromSender:accountant];
    
    NSLog(@"%@ got all money from %@", self, accountant);
    NSLog(@"now boss has %lu", self.money);
}


@end
