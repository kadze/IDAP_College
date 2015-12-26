//
//  SAPEnterprise.m
//  MacCourse
//
//  Created by S A P on 12/7/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//



#import "SAPWorker.h"
#import "SAPWasher.h"
#import "SAPAccountant.h"
#import "SAPBoss.h"
#import "SAPCar.h"

#import "SAPDispatcher.h"
#import "SAPEnterprise.h"

#import "SAPQueue.h"

#import "NSArray+SAPExtentions.h"
#import "NSObject+SAPObject.h"

static NSUInteger const kSAPWashersCount = 5;
static NSUInteger const kSAPAccountantsCount = 3;
static NSUInteger const kSAPBossCount = 1;

@interface SAPEnterprise ()
@property (nonatomic, retain) SAPDispatcher *washersDispatcher;
@property (nonatomic, retain) SAPDispatcher *accountantsDispatcher;
@property (nonatomic, retain) SAPDispatcher *bossDispatcher;
@property (nonatomic, retain) NSMutableArray *mutableStaff;
@property (nonatomic, retain) SAPQueue      *carsQueue;

- (void)hireStaff;
- (void)hireWorkers:(NSArray *)workers withDispatcher:(SAPDispatcher *)dispatcher;
- (void)dismissStaff;
- (SAPDispatcher *)dispatcherHandlerForWorker:(SAPWorker *)worker;

@end

@implementation SAPEnterprise

@dynamic staff;

#pragma mark -
#pragma mark Initializatinos and Deallocations

- (void)dealloc {
    [self dismissStaff];
    self.mutableStaff = nil;
    self.carsQueue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    
    if (self) {
        self.washersDispatcher = [SAPDispatcher object];
        self.accountantsDispatcher = [SAPDispatcher object];
        self.bossDispatcher = [SAPDispatcher object];
        self.mutableStaff = [NSMutableArray object];
        self.carsQueue = [SAPQueue object];
        [self hireStaff];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (NSArray *)staff {
    return [[self.mutableStaff copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)washCar:(SAPCar *)car {
    [self.washersDispatcher performWorkWithObject:car];
}

#pragma mark -
#pragma mark Private Methods

- (void)hireStaff {
    
    //carWash has 1 accountant and 1 boss
    NSArray *washers = [SAPWasher objectsWithCount:kSAPWashersCount];
    NSArray *accountants = [SAPAccountant objectsWithCount:kSAPAccountantsCount];
    NSArray *bosses = [SAPBoss objectsWithCount:kSAPBossCount];
    
    [self hireWorkers:washers withDispatcher:self.washersDispatcher];
    [self hireWorkers:accountants withDispatcher:self.accountantsDispatcher];
    [self hireWorkers:bosses withDispatcher:self.bossDispatcher];
}

- (void)hireWorkers:(NSArray *)workers withDispatcher:(SAPDispatcher *)dispatcher {
    for (SAPWorker *worker in workers) {
        [dispatcher addHandler:worker];
        [worker addObserver:dispatcher];
        [worker addObserver:self];
        [self.mutableStaff addObject:worker];
    }
}

- (void)dismissStaff {
    NSMutableArray *staff = self.mutableStaff;
    for (SAPWorker *worker in staff) {
        [worker removeObserver:self];
        [worker removeObserversFromArray:staff];
    }
    
    [staff removeAllObjects];
}

- (SAPDispatcher *)dispatcherHandlerForWorker:(SAPWorker *)worker {
    if ([self.accountantsDispatcher containsHandler:worker]) {
        return self.bossDispatcher;
    } else if ([self.washersDispatcher containsHandler:worker]) {
        return self.accountantsDispatcher;
    } else {
        return nil;
    }
}

#pragma mark -
#pragma mark SAPWorkerObservingProtocol

- (void)workerDidFinishWork:(SAPWorker *)worker {
    [[self dispatcherHandlerForWorker:worker] performWorkWithObject:worker];
}

@end
