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
    self = [self initWithWorkersCapacity:0];
    
    return self;
}

- (instancetype)initWithWorkers:(NSArray *)workers {
    self = [self initWithWorkers:workers workersCapacity:workers.count];
    
    return self;
}

- (instancetype)initWithWorkersCapacity:(NSUInteger)workersCapacity {
    self = [self initWithWorkers:@[] workersCapacity:workersCapacity];
    
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

- (void)setWorkersCapacity:(NSUInteger)workersCapacity {
    [self.workersContainer setCapacity:workersCapacity];
}

- (void)addWorker:(SAPWorker *)worker {
    [self.workersContainer addItem:worker];
    
}

- (void)removeWorker:(SAPWorker *)worker {
    [self.workersContainer removeItem:worker];
}

- (NSArray *)workersOfClass:(Class)workerClass {
    return [self.workersContainer itemsOfClass:workerClass];
}


@end
