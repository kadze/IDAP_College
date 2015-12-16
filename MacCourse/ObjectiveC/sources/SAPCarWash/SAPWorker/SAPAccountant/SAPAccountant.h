//
//  SAPAccountant.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWorker.h"

@class SAPWasher;
@interface SAPAccountant : SAPWorker

- (void)didFinishWork:(SAPWasher *)washer;

@end
