//
//  SAPCar.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPMoneyTransfer.h"

@interface SAPCar : NSObject <SAPMoneyTransfer>
@property (nonatomic, assign, getter=isClean) BOOL clean;

@end
