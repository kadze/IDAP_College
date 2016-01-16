//
//  SAPObservableObjectSpec.m
//  MacCourse
//
//  Created by S A P on 12/11/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "Kiwi.h"
#import "SAPObservableObject.h"
#import "SAPWeakReference.h"

SPEC_BEGIN(SAPObservableObjectSpec)

describe(@"SAPObservableObject", ^{
    
    context(@"after object created", ^{
        __block SAPObservableObject *object = nil;
        beforeAll(^{
            object = [[SAPObservableObject alloc]init];
        });

        it(@"observers count must be 0", ^{
            [[theValue(object.observers.count) should] equal:theValue(0)];
        });
        
        it(@"object must not be nil", ^{
            [[object should] beNonNil];
        });
        
        context(@"after observer added", ^{
            __block id observer = [NSObject new];
            
            beforeAll(^{
                [object addObserver:observer];
            });
            
            it(@"contains 1 observer", ^{
                [[theValue(object.observers.count) should] equal:theValue(1)];
            });
            
            it(@"observer must be equal to object", ^{
                SAPWeakReference *reference = [object.observers firstObject];
                [[reference.target should] beIdenticalTo:observer];
            });
            
            afterAll(^{
                [object removeObserver:observer];
            });
        });
        
        context(@"after observer added twice", ^{
            id observer2 = [NSObject new];
            
            beforeAll(^{
                [object addObserver:observer2];
                [object addObserver:observer2];
            });
            
            it(@"contains 1 observer", ^{
                [[theValue(object.observers.count) should] equal:theValue(1)];
            });
            
            it(@"observer must be equal to object", ^{
                SAPWeakReference *reference = [object.observers firstObject];
                [[reference.target should] beIdenticalTo:observer2];
            });
        });
    });
});

SPEC_END