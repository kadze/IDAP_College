//
//  SAPDispatcher.m
//  MacCourse
//
//  Created by S A P on 1/16/16.
//  Copyright © 2016 Yosemite Retail. All rights reserved.
//

#import "SAPWorker.h"
#import "SAPDispatcher.h"
#import "SAPQueue.h"
#import "SAPThreadSafeMutableArray.h"
#import "NSObject+SAPObject.h"

@interface SAPDispatcher ()
@property (nonatomic, retain) SAPQueue                    *objectsQueue;
@property (nonatomic, retain) SAPThreadSafeMutableArray   *mutableHandlers;

- (SAPWorker *)reserveHandler;
- (void)processNextObjectWithFreeHandler;

@end

@implementation SAPDispatcher

#pragma mark -
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
        self.mutableHandlers = [SAPThreadSafeMutableArray object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)handlers {
    SAPThreadSafeMutableArray *mutableHandlers = self.mutableHandlers;
    @synchronized(mutableHandlers) {
        return [[mutableHandlers copy] autorelease];
    }
}

#pragma mark -
#pragma mark Public Methods

- (void)addHandler:(SAPObservableObject *)handler {
    @synchronized(self) {
        [self.mutableHandlers addObject:handler];
        [handler addObserver:self];
    }
}

- (void)removeHandler:(id)handler {
    @synchronized(self) {
        [self.mutableHandlers removeObject:handler];
        [handler removeObserver:self];
    }
}

- (BOOL)containsHandler:(id)handler {
    NSMutableArray *mutableHandlers = self.mutableHandlers;
    @synchronized(mutableHandlers) {
        return [self.mutableHandlers containsObject:handler];
    }
}

- (void)performWorkWithObject:(id)object {
    [self.objectsQueue enqueue:object];
    [self processNextObjectWithFreeHandler];
}

#pragma mark -
#pragma mark Private Methods

- (SAPWorker *)reserveHandler {
    for (SAPWorker *handler in self.handlers) {
        @synchronized(handler) {
            if (kSAPWorkerIsReadyToWork == handler.state) {
                handler.state = kSAPWorkerIsBusy;
                
                return handler;
            }
        }
    }
    
    return nil;
}

- (void)processNextObjectWithFreeHandler {
    SAPQueue *queue = self.objectsQueue;
    id object = [queue dequeue];
    if (object) {
        SAPWorker *handler = [self reserveHandler];
        if (handler) {
            [handler performWorkWithObject:object];
        } else {
            [queue enqueue:object];
        }
    }
}

#pragma mark -
#pragma mark SAPWorkerObservingProtocol

- (void)workerDidBecomeReadyToWork:(SAPWorker *)worker {
    [self processNextObjectWithFreeHandler];
}

@end
