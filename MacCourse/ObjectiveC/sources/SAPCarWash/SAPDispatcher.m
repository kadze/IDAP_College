//
//  SAPDispatcher.m
//  MacCourse
//
//  Created by S A P on 1/16/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPDispatcher.h"
#import "NSObject+SAPObject.h"
#import "SAPQueue.h"

@interface SAPDispatcher ()
@property(nonatomic, retain) SAPQueue *objectsQueue;
@property (nonatomic, retain) NSMutableArray *mutableHandlers;

@end

@implementation SAPDispatcher

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.objectsQueue = nil;
    self.mutableHandlers = nil;
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.objectsQueue = [SAPQueue object];
        self.mutableHandlers = [NSMutableArray object];
    }
    
    return self;
}

#pragma mark-
#pragma mark Public Methods

-(void)addHandler:(id)handler {
    NSMutableArray *mutableHandlers = self.mutableHandlers;
    @synchronized(mutableHandlers) {
        [mutableHandlers addObject:handler];
    }
}

-(void)removeHandler:(id)handler {
    NSMutableArray *mutableHandlers = self.mutableHandlers;
    @synchronized(mutableHandlers) {
        [mutableHandlers removeObject:handler];
    }
}

-(void)performWorkWithObject:(id)object {
    
}

@end
