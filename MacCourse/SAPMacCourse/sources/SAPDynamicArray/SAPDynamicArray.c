//
//  SAPDynamicArray.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/24/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <limits.h>
#include "SAPDynamicArray.h"
#include "SAPMacro.h"

#define SAPDynamicArrayReallocate \
    SAPDynamicArraySetAllocatedCount(object, allocatedCount);\
    uint count = SAPDynamicArrayCount(object);\
    void** dynamicArray = realloc(object->_values, sizeof(object ->_values) * object->_allocatedCount);\
    assert(NULL != dynamicArray);\
    for (uint index = count; index < allocatedCount; index++) {\
        dynamicArray[index] = NULL;\
    }\
    object->_values = dynamicArray

static const uint kSAPSizeMultiplicator = 2;
static const uint kSAPSizeIncrement     = 100000;
static const uint kSAPSizeMultiplyUntil = 200000;
static const uint kSAPResizeThreshold   = 3;

#pragma mark -
#pragma mark Private Declarations

static
void SAPDynamicArraySetAllocatedCount(SAPDynamicArray *object, uint allocatedCount);

static
void SAPDynamicArraySetCount(SAPDynamicArray *object, uint count);

static
uint SAPDynamicArrayAllocatedCountForExtend(SAPDynamicArray *object);

static
uint SAPDynamicArrayAllocatedCountForShrink(SAPDynamicArray *bject);

static
bool SAPDynamicArrayShouldExtend(SAPDynamicArray *object);

static
void SAPDynamicArrayExtend(SAPDynamicArray *object);

static
bool SAPDynamicArrayShouldShrink(SAPDynamicArray *object);

static
void SAPDynamicArrayShrink(SAPDynamicArray *object);

static
void SAPDynamicArrayShiftElements(SAPDynamicArray *object);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPDynamicArrayDeallocate(SAPDynamicArray *object) {
    for (uint index = 0; index < SAPDynamicArrayCount(object); index++) {
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

uint SAPDynamicArrayAllocatedCount(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _allocatedCount, 0);
}

void SAPDynamicArraySetAllocatedCount(SAPDynamicArray *object, uint allocatedCount) {
    SAPObjectIVarSetterSynthesize(object, allocatedCount);
}

uint SAPDynamicArrayCount(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _count, 0);
}
void SAPDynamicArraySetCount(SAPDynamicArray *object, uint count) {
    SAPObjectIVarSetterSynthesize(object, count);
}
void SAPDynamicArraySetValueAtIndex(SAPDynamicArray *object, void *value, uint index) {
    if (index < SAPDynamicArrayAllocatedCount(object)) {
        if (NULL == value) {
            object->_count--;
            SAPDynamicArrayShiftElements(object);
            SAPDynamicArrayShrink(object);
        }
        
        SAPObjectRelease(object->_values[index]);
        SAPObjectRetain(value);
        object->_values[index] = value;
    }
}

void *SAPDynamicArrayValueAtIndex(SAPDynamicArray *object, uint index) {
    if (NULL != object && index < SAPDynamicArrayAllocatedCount(object)) {
        return object->_values[index];
    }
    
    return NULL;
}


#pragma mark-
#pragma mark Public Implementations

void SAPDynamicArrayAdd(SAPDynamicArray *object, void *value) {
    SAPReturnIfObjectNULL;
    if (NULL == value) {
        return;
    }
    
    SAPDynamicArrayExtend(object);
    
    SAPDynamicArraySetValueAtIndex(object, value, SAPDynamicArrayCount(object));
    object->_count++;
}

void SAPDynamicArrayRemove(SAPDynamicArray *object, void *value) {
    SAPReturnIfObjectNULL;
    SAPDynamicArrayRemoveByIndex(object, SAPDynamicArrayIndexOfValue(object, value));
}

void SAPDynamicArrayRemoveByIndex(SAPDynamicArray *object, uint index) {
    SAPDynamicArraySetValueAtIndex(object, NULL, index);
}

uint SAPDynamicArrayIndexOfValue(SAPDynamicArray *object, void  *value) {
    uint result = UINT_MAX;
    if (NULL == object || NULL == value) {
        return result;
    }
    
    for (uint index = 0; index < SAPDynamicArrayCount(object); index++) {
        if (value == SAPDynamicArrayValueAtIndex(object, index)) {
            return index;
        }
    }
    
    return result;
}

bool SAPDynamicArrayContains(SAPDynamicArray *object, void *value) {
    return UINT_MAX != SAPDynamicArrayIndexOfValue(object, value);
}


#pragma mark-
#pragma mark Private Implementations

void SAPDynamicArrayShiftElements(SAPDynamicArray *object) {
    SAPReturnIfObjectNULL;
    uint shiftsCount = 0;
    for (uint index = 0; SAPDynamicArrayCount(object); index++) {
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

bool SAPDynamicArrayShouldExtend(SAPDynamicArray *object) {
    SAPReturnValueIfObjectNULL(false);
    
    return (SAPDynamicArrayAllocatedCount(object) == SAPDynamicArrayCount(object));
}

bool SAPDynamicArrayShouldShrink(SAPDynamicArray *object) {
    bool result = false;
    SAPReturnValueIfObjectNULL(result);
    uint allocatedCount = SAPDynamicArrayAllocatedCount(object);
    uint count = SAPDynamicArrayCount(object);
    if (0 == allocatedCount) {
        return result;
    }
    
    if ((kSAPSizeMultiplicator == (allocatedCount + kSAPResizeThreshold) / count)
        || (kSAPSizeIncrement + kSAPResizeThreshold == allocatedCount - count))
    {
        result = true;
    }
    
    return result;
}

uint SAPDynamicArrayAllocatedCountForExtend(SAPDynamicArray *object) {
    uint allocatedCount = SAPDynamicArrayAllocatedCount(object);
    if (0 == allocatedCount) {
        allocatedCount = 1;
    } else if (kSAPSizeMultiplyUntil > allocatedCount) {
        allocatedCount *= kSAPSizeMultiplicator;
    } else {
        allocatedCount += kSAPSizeIncrement;
    }
    return allocatedCount;
}

uint SAPDynamicArrayAllocatedCountForShrink(SAPDynamicArray *object) {
    uint allocatedCount = SAPDynamicArrayAllocatedCount(object);
    uint count = SAPDynamicArrayCount(object);
    if ((kSAPSizeIncrement + kSAPResizeThreshold == allocatedCount - count)
        && (allocatedCount + kSAPResizeThreshold) > kSAPSizeMultiplyUntil) {
        allocatedCount = allocatedCount - kSAPSizeIncrement;
    } else {
        allocatedCount = (allocatedCount + kSAPResizeThreshold) / kSAPSizeMultiplicator - kSAPResizeThreshold;
    }
    return allocatedCount;
}

void SAPDynamicArrayExtend(SAPDynamicArray *object) {
    if (SAPDynamicArrayShouldExtend(object)) {
        uint allocatedCount = SAPDynamicArrayAllocatedCountForExtend(object);
        SAPDynamicArrayReallocate;
    }
}

void SAPDynamicArrayShrink(SAPDynamicArray *object) {
    if (SAPDynamicArrayShouldShrink(object)) {
        uint allocatedCount = SAPDynamicArrayAllocatedCountForShrink(object);
        SAPDynamicArrayReallocate;
    }
}