//
//  SAPLinkedListTest.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/24/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include "SAPLinkedListTest.h"
#include "SAPLinkedList.h"
#include "SAPObject.h"

#pragma mark -
#pragma mark Private Declarations

static
void SAPLinkedListOneObjectTest(void);

static
void SAPLinkedListEnumeratorTest(void);

#pragma mark -
#pragma mark Public Implementations

void SAPPerformAllLinkedListBehaviorTests(void) {
    printf("===Perform SAPLinkedList tests ===\n");
    SAPLinkedListOneObjectTest();
    SAPLinkedListEnumeratorTest();
    printf("OK\n");
}

#pragma mark -
#pragma mark Private Implementations

void SAPLinkedListOneObjectTest(void) {
    //after list was creted
    SAPLinkedList *list = SAPObjectCreateOfType(SAPLinkedList);
    //list should be empty
    assert(true == SAPLinkedListIsEmpty(list));
    
    //after object was created
    void *object = SAPObjectCreateOfType(SAPObject);
    //list must not contain object
    assert(false == SAPLinkedListContainsObject(list, object));
    //arter object was added to list
    SAPLinkedListAddObject(list, object);
    //object reference count must be 2
    assert(2 == SAPObjectRetainCount(object));
    //list must not be empty
    assert(false == SAPLinkedListIsEmpty(list));
    //list must contain object
    assert(true == SAPLinkedListContainsObject(list, object));
    
    //after object was removed from list
    SAPLinkedListRemoveObject(list, object);
    //list must be empty
    assert(true == SAPLinkedListIsEmpty(list));
    //list must not contain object
    assert(false == SAPLinkedListContainsObject(list, object));
    //retain count must be one
    assert(1 == SAPObjectRetainCount(object));
    
    //after object was added 1000 times
    for (uint64_t counter = 0; counter < 1000 ; counter++) {
        SAPLinkedListAddObject(list, object);
    }
    //object reference count must be 1001
    assert(1001 == SAPObjectRetainCount(object));
    //list must not be empty
    assert(false == SAPLinkedListIsEmpty(list));
    //list must contain object
    assert(true == SAPLinkedListContainsObject(list, object));
    
    //after first object was removed from list
    SAPLinkedListRemoveFirstObject(list);
    //retain count must be 1000
    assert(1000 == SAPObjectRetainCount(object));
    
    //after object was removed from the list (all nodes with this object of object)
    SAPLinkedListRemoveObject(list, object);
    //retain count must be 1
    assert(1 == SAPObjectRetainCount(object));
    //list must be empty
    assert(true == SAPLinkedListIsEmpty(list));
    //list must not contain object
    assert(false == SAPLinkedListContainsObject(list, object));
    
    SAPObjectRelease(object);
    SAPObjectRelease(list);
}

void SAPLinkedListEnumeratorTest(void) {
    SAPObject *sampleObjects[5];
    //after list was creted
    SAPLinkedList *list = SAPObjectCreateOfType(SAPLinkedList);
    //list retain count must be 1
    assert(1 == SAPObjectRetainCount(list));
    //after 5 objects were added to list
    for (uint64_t counter = 0; counter < 5 ; counter++) {
        SAPObject *object = SAPObjectCreateOfType(SAPObject);
        SAPLinkedListAddObject(list, object);
        sampleObjects[4 - counter] = object;
        SAPObjectRelease(object);
    }
    //after enumerator was created
    SAPLinkedListEnumerator *enumerator = SAPLinkedListEnumeratorFromList(list);
    //list retain count should be 2
    assert(2 == SAPObjectRetainCount(list));
    //enumerators retain count should be 1
    assert(1 == SAPObjectRetainCount(enumerator));
    //iterations count should be 5
    void *object = SAPLinkedListEnumeratorNextObject(enumerator);
    uint64_t iterationsCount = 0;
    while (SAPLinkedListEnumeratorIsValid(enumerator)) {
        assert(sampleObjects[iterationsCount] == object);
       // SAPLinkedListAddObject(list, object); //if add object - assert in validate()
        iterationsCount++;
        object = SAPLinkedListEnumeratorNextObject(enumerator);
    }
    assert(5 == iterationsCount);
    SAPObjectRelease(enumerator);
    SAPObjectRelease(list);
}