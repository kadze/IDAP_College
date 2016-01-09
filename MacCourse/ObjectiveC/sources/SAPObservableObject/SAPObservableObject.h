//
//  SAPObservableObject.h
//  MacCourse
//
//  Created by S A P on 12/10/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPObservableObject : NSObject
@property (nonatomic, assign)   NSUInteger      state;
@property (nonatomic, retain, readonly) NSArray *observers;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)removeAllObservers;

- (void)notifyObserversWithSelector:(SEL)selector;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object;
- (void)notifyObserversWithSelector:(SEL)selector withObject:(id)object withObject:(id)object2;
@end
