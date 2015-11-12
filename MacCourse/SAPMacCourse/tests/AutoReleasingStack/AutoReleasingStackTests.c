//
//  AutoReleasingStackTests.c
//  MacCourse
//
//  Created by S A P on 11/12/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include "AutoReleasingStackTests.h"

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
    printf("===Perform SAPLinkedList tests ===\n");
    SAPAutoreleasingStackOneObjectPushTest();
    SAPAutoreleasingStackOneNullTest();
    SAPAutoreleasingStackIsFullTest();
    printf("OK\n");
}

#pragma mark -
#pragma mark Private Implementations

void SAPAutoreleasingStackOneObjectPushTest(void) {
    //after stack was created with size for 64 pointers
    //  stack must be empty
    //  stack must not be full
    //after object was created
    //
    //after object was pushed into the stack
    //  objects retain count must not be changed
    //  stack must not be empty
    //  stack must not be full
    //after object was popped
    //  pop type must be "PoppedObject"
    //  object reference count must be decremented
    //  stack must be empty
    //  stack must not be full
}

void SAPAutoreleasingStackOneNullTest(void) {
    //after stack was created with size for 64 pointers
    //  stack must be empty
    //  stack must not be full
    //after NULL was pushed into the stack
    //  stack must not be empty
    //  stack must not be full
    //after object was popped
    //  pop type must be "PoppedObject"
    //  object reference count must be decremented
    //  stack must be empty
    //  stack must not be full
}

static
void SAPAutoreleasingStackIsFullTest(void) {
    //after stack was created with size for 64 pointers
    //  stack must be empty
    //  stack must not be full
    //after object was created
    //
    //after object was pushed into the stack 64 times
    //  objects retain count must not be changed
    //  stack must not be empty
    //  stack must be full
    //after object was popped
    //  pop type must be "PoppedObject"
    //  object reference count must be decremented
    //  stack must not be empty
    //  stack must not be full
    //after 63 objects were popped
    //  pop type must be "PoppedObject"
    //  object reference count must be decremented 63 times
    //  stack must be empty
    //  stack must not be full
}
