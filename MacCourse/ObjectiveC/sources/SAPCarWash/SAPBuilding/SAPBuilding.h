//
//  SAPBuilding.h
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPRoom.h"

@interface SAPBuilding : NSObject

@property (nonatomic, retain, readonly) NSArray *rooms;

+ (BOOL)canContainItemsOfClass:(Class)itemClass;

@end
