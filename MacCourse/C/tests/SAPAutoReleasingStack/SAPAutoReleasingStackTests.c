//
//  AutoReleasingStackTests.c
//  MacCourse
//
//  Created by S A P on 11/12/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include "SAPAutoReleasingStackTests.h"
#include "SAPAutoreleasingStack.h"

#pragma mark -
#pragma mark Private Declarations

static
void SAPAutoreleasingStackOneObjectPushTest(void);

static
void SAPAutoreleasingStackOneNullTest(void);

static
void SAPAutoreleasingStackIsFullTest(void);

#pragma mark -
#pragma mark Public Implementations

void SAPPerformAllAutoreleasingStackTests(void) {
    printf("===Perform SAPAutoreleasingStack tests ===\n");
    SAPAutoreleasingStackOneObjectPushTest();
    SAPAutoreleasingStackOneNullTest();
    SAPAutoreleasingStackIsFullTest();
    printf("OK\n");
}

#pragma mark -
#pragma mark Private Implementations

void SAPAutoreleasingStackOneObjectPushTest(void) {
    //after stack was created with size for 64 pointers
    SAPAutoreleasingStack *stack = SAPAutoreleasingStackCreateWithSize(64 * sizeof(SAPObject*));
    //  stack must be empty
    assert(true == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(true != SAPAutoreleasingStackIsFull(stack));
    //after object was created
    SAPObject *object = SAPObjectRetain(SAPObjectCreateOfType(SAPObject));
    //after object was pushed into the stack
    SAPAutoreleasingStackPushObject(stack, object);
    //  objects retain count must not be changed
    assert(2 == SAPObjectRetainCount(object));
    //  stack must not be empty
    assert(false == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(false == SAPAutoreleasingStackIsFull(stack));
    //after object was popped
    SAPAutoreleasingStackPopType type = SAPAutoreleasingStackPopObject(stack);
    //  pop type must be "PoppedObject"
    assert(kSAPAutoreleasingStackPopedObject == type);
    //  object retain count must be decremented
    assert(1 == SAPObjectRetainCount(object));
    //  stack must be empty
    assert(true == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(true != SAPAutoreleasingStackIsFull(stack));
    
    SAPObjectRelease(stack);
}

void SAPAutoreleasingStackOneNullTest(void) {
    //after stack was created with size for 64 pointers
    SAPAutoreleasingStack *stack = SAPAutoreleasingStackCreateWithSize(64 * sizeof(SAPObject*));
    //  stack must be empty
    assert(true == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(true != SAPAutoreleasingStackIsFull(stack));
    //after NULL was pushed into the stack
    SAPAutoreleasingStackPushObject(stack, NULL);
    //  stack must not be empty
    assert(false == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(false == SAPAutoreleasingStackIsFull(stack));
    //after object was popped
    SAPAutoreleasingStackPopType type = SAPAutoreleasingStackPopObject(stack);
    //  pop type must be "PoppedNull"
    assert(kSAPAutoreleasingStackPopedNULL == type);
    //  object reference count must be decremented
    //  stack must be empty
    assert(true == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(true != SAPAutoreleasingStackIsFull(stack));
    
    SAPObjectRelease(stack);
}

static
void SAPAutoreleasingStackIsFullTest(void) {
    //after stack was created with size for 64 pointers
    SAPAutoreleasingStack *stack = SAPAutoreleasingStackCreateWithSize(64 * sizeof(SAPObject*));
    //  stack must be empty
    assert(true == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(true != SAPAutoreleasingStackIsFull(stack));
    //after object was created
    SAPObject *object = SAPObjectRetain(SAPObjectCreateOfType(SAPObject));
    //
    //after object was pushed into the stack 64 times
    for (uint64_t counter = 0; counter < 64 ; counter++) {
        SAPAutoreleasingStackPushObject(stack, object);
    }
    //  stack must not be empty
    assert(false == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must be full
    assert(true == SAPAutoreleasingStackIsFull(stack));
    //after object was popped
    SAPAutoreleasingStackPopType type = SAPAutoreleasingStackPopObject(stack);
    //  pop type must be "PoppedObject"
    assert(kSAPAutoreleasingStackPopedObject == type);
    //  object retain count must be decremented
    assert(64 == SAPObjectRetainCount(object));
    //  stack must not be empty
    assert(false == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(false == SAPAutoreleasingStackIsFull(stack));
    //after 63 objects were popped
    for (uint64_t counter = 0; counter < 63; counter++) {
        SAPAutoreleasingStackPopType type = SAPAutoreleasingStackPopObject(stack);
        assert(kSAPAutoreleasingStackPopedObject == type);
    }
    //  pop type must be "PoppedObject"
    //  object reference count must be decremented 63 times
    assert(64 == SAPObjectRetainCount(object));
    //  stack must be empty
    assert(true == SAPAutoreleasingStackIsEmpty(stack));
    //  stack must not be full
    assert(true != SAPAutoreleasingStackIsFull(stack));
    
    SAPObjectRelease(stack);
}
