//
//  SAPDynamicArray.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/24/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include "SAPDynamicArray.h"
#include "SAPMacro.h"

static const uint kSAPSizeMultiplicator = 2;
static const uint kSAPSizeIncrement = 100000;
static const uint kSAPSizeMultiplyUntil = 200000;

#pragma mark -
#pragma mark Private Declarations

static
void SAPDynamicArraySetAllocatedElementsCount(SAPDynamicArray *object, uint allocatedElementsCount);

static
uint SAPDynamicArrayAllocatedElementsCount(SAPDynamicArray *object);

static
void SAPDynamicArraySetElementsCount(SAPDynamicArray *object, uint elementsCount);

static
void SAPDynamicArrayExtend(SAPDynamicArray *object);

static
bool SAPDynamicArrayShouldExtend(SAPDynamicArray *object);

static
void SAPDynamicArrayShiftElements(SAPDynamicArray *object);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPDynamicArrayDeallocate(SAPDynamicArray *object) {
    for (uint index = 0; index < SAPDynamicArrayElementsCount(object); index++) {
        SAPDynamicArraySetValueAtIndex(object, NULL, index);
    }
    __SAPObjectDeallocate(object);
}

SAPDynamicArray *SAPDynamicArrayCreate(void) {
    SAPDynamicArray *object = SAPObjectCreateOfType(SAPDynamicArray);
    
    return object;
}

#pragma mark -
#pragma mark Accessors

uint SAPDynamicArrayAllocatedElementsCount(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _allocatedElementsCount, 0);
}

void SAPDynamicArraySetAllocatedElementsCount(SAPDynamicArray *object, uint allocatedElementsCount) {
    SAPObjectIVarSetterSynthesize(object, allocatedElementsCount);
}

uint SAPDynamicArrayElementsCount(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _elementsCount, 0);
}
void SAPDynamicArraySetElementsCount(SAPDynamicArray *object, uint elementsCount) {
    SAPObjectIVarSetterSynthesize(object, elementsCount);
}
void SAPDynamicArraySetValueAtIndex(SAPDynamicArray *object, void *value, uint index) {
    if (index < SAPDynamicArrayAllocatedElementsCount(object)) {
        if (NULL == value) {
            object->_elementsCount--;
            SAPDynamicArrayShiftElements(object);
        }
        SAPObjectRelease(object->_values[index]);
        SAPObjectRetain(value);
        object->_values[index] = value;
    }
}

void *SAPDynamicArrayValueAtIndex(SAPDynamicArray *object, uint index) {
    if (NULL != object && index < SAPDynamicArrayAllocatedElementsCount(object)) {
        return object->_values[index];
    }
    
    return NULL;
}

void SAPDynamicArrayAdd(SAPDynamicArray *object, void *value) {
    if (NULL == object) {
        return;
    }
    
    if (SAPDynamicArrayShouldExtend(object)) {
        SAPDynamicArrayExtend(object);
    }
    SAPDynamicArraySetValueAtIndex(object, value, SAPDynamicArrayElementsCount(object));
    object->_elementsCount++;
}




#pragma mark-
#pragma mark Public Implementations



#pragma mark-
#pragma mark Private Implementations

bool SAPDynamicArrayShouldExtend(SAPDynamicArray *object) {
    return (SAPDynamicArrayAllocatedElementsCount(object) == SAPDynamicArrayElementsCount(object));
}

void SAPDynamicArrayExtend(SAPDynamicArray *object) {
    uint allocatedElementsCount = SAPDynamicArrayAllocatedElementsCount(object);
    if (kSAPSizeMultiplyUntil < allocatedElementsCount) {
        allocatedElementsCount *= kSAPSizeMultiplicator;
    } else {
        allocatedElementsCount += kSAPSizeIncrement;
    }
    void** dynamicArray = realloc(object->_values, sizeof(object ->_values) * object->_allocatedElementsCount);
    assert(NULL != dynamicArray);
    object->_values = dynamicArray;
    SAPDynamicArraySetAllocatedElementsCount(object, allocatedElementsCount);
}

void SAPDynamicArrayShiftElements(SAPDynamicArray *object) {
    uint shiftsCount = 0;
    for (uint index = 0; SAPDynamicArrayElementsCount(object); index++) {
        if (NULL == SAPDynamicArrayValueAtIndex(object, index)) {
            shiftsCount++;
        } else {
            SAPDynamicArraySetValueAtIndex(object,
                                           SAPDynamicArrayValueAtIndex(object, index),
                                           index - shiftsCount);
            shiftsCount = 0;
        }
    }
}