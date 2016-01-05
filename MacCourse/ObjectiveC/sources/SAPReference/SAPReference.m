//
//  SAPReference.m
//  MacCourse
//
//  Created by S A P on 12/11/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPReference.h"

@implementation SAPReference

@dynamic target;

#pragma mark-
#pragma mark Initializations & Deallications

- (void)dealloc {
    self.target = nil;
    
    [super dealloc];
}

- (instancetype)initWithTarget:(id)object {
    if (nil == object) {
        [self release];
        return nil;
    }
    
    self = [super init];
    if (self) {
        self.target = object;
    }
    
    return self;
}

#pragma mark-
#pragma mark NSCopying

- (id)copyWithZone:(NSZone *)zone {
    return [[[self class] alloc] initWithTarget:self.target];
}

#pragma mark-
#pragma mark NSObject equality

- (NSUInteger)hash {
    return [self.target hash];
}

- (BOOL)isEqual:(SAPReference *)object {
    return [object isMemberOfClass:[self class]] && object.target == self.target;
}

@end
