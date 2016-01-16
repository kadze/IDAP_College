//
//  SAPWeakReference.m
//  MacCourse
//
//  Created by S A P on 12/11/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//
#import "SAPAssignReference.h"

@interface SAPWeakReference()

@property (nonatomic, assign) id target;

@end

@implementation SAPWeakReference

@synthesize target = _target;

@end
