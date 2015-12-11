//
//  SAPObservableObject.m
//  MacCourse
//
//  Created by S A P on 12/10/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPObservableObject.h"
#import "SAPWeakReference.h"

@interface SAPObservableObject()

@property(nonatomic, retain) NSMutableSet *mutableObservers;

@end

@implementation SAPObservableObject

@dynamic observers;

#pragma mark-
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableObservers = nil;
    
    [super dealloc];
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.mutableObservers = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *) observers {
    return [self.mutableObservers allObjects];
}

#pragma mark-
#pragma mark Public Methods

- (void)addObserver:(id)observer {
    [self.mutableObservers addObject:[[[SAPWeakReference alloc] initWithTarget:observer] autorelease]];
}

- (void)removeObserver:(id)observer {
    for (SAPWeakReference *reference in self.observers) {
        if (reference.target == observer) {
            [self.mutableObservers removeObject:reference];
            
            break;
        }
    }
    
    
}

- (void)notifyObserversWithSelector:(SEL)selector {
    [self notifyObserversWithSelector:(SEL)selector withObject:(id)nil];
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object {
    [self notifyObserversWithSelector:(SEL)selector withObject:(id)object withObject:(id)nil];
}

- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object withObject:(id)object2 {
    for (id observer in self.observers) {
        [observer performSelector:selector withObject:object withObject:object2];
    }
}

@end
