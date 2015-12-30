//
//  SAPCarsGenerator.h
//  MacCourse
//
//  Created by S A P on 12/25/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SAPEnterprise;

@interface SAPCarsGenerator : NSObject

- (void)sendCarsToCarWash:(SAPEnterprise *)enterprise;
- (void)sendCarsAndWashByCarWash:(SAPEnterprise *)enterprise;

@end
