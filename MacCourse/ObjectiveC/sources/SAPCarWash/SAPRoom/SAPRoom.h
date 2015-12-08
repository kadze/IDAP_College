//
//  SAPRoom.h
//  MacCourse
//
//  Created by S A P on 12/1/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPRoom : NSObject

@property (nonatomic, assign, readonly) NSUInteger maxSeatingCapacity;
@property (nonatomic, retain, readonly) NSArray *people;

@end
