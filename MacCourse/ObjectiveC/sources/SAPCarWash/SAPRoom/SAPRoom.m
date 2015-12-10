//
//  SAPRoom.m
//  MacCourse
//
//  Created by S A P on 12/1/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPRoom.h"
#import "SAPItemsContainer.h"
#import "SAPWorker.h"


@interface SAPRoom()

@property(nonatomic, retain) SAPItemsContainer *workersContainer;

@end

@implementation SAPRoom

@dynamic workers;

#pragma mark-
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    self.workersContainer = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [self initWithWorkers:[NSArray array] workersCapacity:0];
    
    return self;
}

- (instancetype)initWithWorkers:(NSArray*)workers workersCapacity:(NSUInteger)workersCapacity {
    if (workers.count > workersCapacity) {
        return nil;
    }
    
    self = [super init];
    self.workersContainer = [[[SAPItemsContainer alloc] initWithCapacity:workersCapacity] autorelease];
    for (SAPWorker *worker in workers) {
        [self addWorker:worker];
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *)workers {
    return self.workersContainer.items;
}

#pragma mark-
#pragma mark Public Methods

- (void)addWorker:(SAPWorker *)worker {
    if ([worker isKindOfClass:[SAPWorker class]]) {
        [self.workersContainer addItem:worker];
        [worker setCurrentWorkingPlace:self];
    }
    
}

- (void)removeWorker:(SAPWorker *)worker {
    [self.workersContainer removeItem:worker];
    [worker setCurrentWorkingPlace:nil];
}

@end
