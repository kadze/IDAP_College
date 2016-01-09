//
//  SAPContainer.h
//  MacCourse
//
//  Created by S A P on 1/9/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPContainer : NSObject
@property (nonatomic, readonly) NSArray     *items;

- (NSArray *)itemsOfClass:(Class)itemClass;
- (void)removeAllItems;

@end
