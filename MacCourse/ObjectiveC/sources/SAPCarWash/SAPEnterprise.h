//
//  SAPEnterprise.h
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPWorkerObservingProtocol.h"

@class SAPCar;

@interface SAPEnterprise : NSObject <SAPWorkerObservingProtocol>

@property (nonatomic, retain, readonly) NSArray *staff;

- (void)washCar:(SAPCar *)car;

@end
