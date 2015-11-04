//
//  SAPDynamicArray.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/24/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <limits.h>
#include <string.h>
#include "SAPDynamicArray.h"
#include "SAPMacro.h"

static const unsigned long kSAPSizeMultiplicator = 2;
static const unsigned long kSAPImpossibleValue    = ULONG_MAX;

#pragma mark -
#pragma mark Private Declarations

static
void SAPDynamicArraySetCapacity(SAPDynamicArray *object, unsigned long capacity);

static
void SAPDynamicArraySetCount(SAPDynamicArray *object, unsigned long count);

static
unsigned long SAPDynamicArrayCapacityForResize(SAPDynamicArray *object);

static
void SAPDynamicArrayResizeIfNeeded(SAPDynamicArray *object);

static
void SAPDynamicArrayShiftObjects(SAPDynamicArray *object);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPDynamicArrayDeallocate(SAPDynamicArray *object) {
    SAPDynamicArrayRemoveAll(object);
    
    __SAPObjectDeallocate(object);
}

SAPDynamicArray *SAPDynamicArrayCreate(void) {
    return SAPObjectCreateOfType(SAPDynamicArray);
}

#pragma mark -
#pragma mark Accessors

unsigned long SAPDynamicArrayCapacity(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _capacity, 0);
}

void SAPDynamicArraySetCapacity(SAPDynamicArray *object, unsigned long capacity) {
    SAPReturnIfObjectNULL;
    SAPReturnIfValuesEqual(kSAPImpossibleValue, capacity);
    unsigned long count = object->_count;
    if (count == capacity) {
        if (capacity != 1 && capacity != 2) {
            return;
        }
    }

    void **values = object->_values;
    
    if (0 == capacity) {
        free(values);
        object->_values = NULL;
    } else {
        size_t valueSize = sizeof(*values);
        size_t allocatedSize = capacity * valueSize;
        size_t size = count * valueSize;
        
        void *newValues = realloc(values, allocatedSize);
        assert(newValues);
        object->_values = newValues;
        
        if (capacity > count || (capacity == 1 && count == 1) || (capacity == 2 && count == 2)) {
            memset(object->_values + count, 0, allocatedSize - size);
        }
    }
    
    object->_capacity = capacity;
    
}

unsigned long SAPDynamicArrayCount(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _count, 0);
}
void SAPDynamicArraySetCount(SAPDynamicArray *object, unsigned long count) {
    SAPObjectIVarSetterSynthesize(object, count);
}
void SAPDynamicArraySetValueAtIndex(SAPDynamicArray *object, void *value, unsigned long index) {
    if (index < SAPDynamicArrayCapacity(object)) { //could it be differently?
        SAPObjectRelease(object->_values[index]);
        SAPObjectRetain(value);
        object->_values[index] = value;
        
        if (NULL == value) {
            SAPDynamicArrayShiftObjects(object);
            SAPDynamicArrayResizeIfNeeded(object);
            object->_count--;
        }
    }
}

void *SAPDynamicArrayValueAtIndex(SAPDynamicArray *object, unsigned long index) {
    if (NULL != object && index < SAPDynamicArrayCapacity(object)) {
        return object->_values[index];
    }
    
    return NULL;
}


#pragma mark-
#pragma mark Public Implementations

void SAPDynamicArrayAddObject(SAPDynamicArray *object, void *value) {
    SAPReturnIfObjectNULL;
    SAPReturnIfNULL(value);
    
    object->_count++;
    SAPDynamicArrayResizeIfNeeded(object);
    SAPDynamicArraySetValueAtIndex(object, value, SAPDynamicArrayCount(object)-1);
}

void SAPDynamicArrayRemoveObject(SAPDynamicArray *object, void *value) {
    SAPReturnIfObjectNULL;
    SAPDynamicArrayRemoveByIndex(object, SAPDynamicArrayIndexOfValue(object, value));
}

void SAPDynamicArrayRemoveByIndex(SAPDynamicArray *object, unsigned long index) {
    SAPDynamicArraySetValueAtIndex(object, NULL, index);
}

void SAPDynamicArrayRemoveAll(SAPDynamicArray *object) {
    SAPReturnIfObjectNULL;
    for (unsigned long index = 0; index < SAPDynamicArrayCount(object); index++) {
        SAPDynamicArraySetValueAtIndex(object, NULL, index);
    }
}

unsigned long SAPDynamicArrayIndexOfValue(SAPDynamicArray *object, void  *value) {
    unsigned long result = kSAPImpossibleValue;
    if (NULL == object || NULL == value) {
        return result;
    }
    
    for (unsigned long index = 0; index < SAPDynamicArrayCount(object); index++) {
        if (value == SAPDynamicArrayValueAtIndex(object, index)) {
            return index;
        }
    }
    
    return result;
}

bool SAPDynamicArrayContains(SAPDynamicArray *object, void *value) {
    return kSAPImpossibleValue != SAPDynamicArrayIndexOfValue(object, value);
}

#pragma mark-
#pragma mark Private Implementations

void SAPDynamicArrayShiftObjects(SAPDynamicArray *object) {
    SAPReturnIfObjectNULL;
    unsigned long shiftsCount = 0;
    for (unsigned long index = 0; index < SAPDynamicArrayCount(object); index++) {
        if (NULL == SAPDynamicArrayValueAtIndex(object, index)) {
            shiftsCount++;
        } else {
            if (0 != shiftsCount) {
                SAPDynamicArraySetValueAtIndex(object,
                                               SAPDynamicArrayValueAtIndex(object, index),
                                               index - shiftsCount);
            }
        }
    }
}

//try
void SAPDynamicArrayShiftObjects2(SAPDynamicArray *object) {
    SAPReturnIfObjectNULL;
    unsigned long index = 0;
    for (; index < SAPDynamicArrayCount(object); index++) {
        if (NULL == SAPDynamicArrayValueAtIndex(object, index)) {
            break;
        }
    }
    void **data = object->_values;
    size_t memSize = (SAPDynamicArrayCount(object) - index) + sizeof(data);
    memmove(data[index], data[index + 1], memSize);
}

void SAPDynamicArrayResizeIfNeeded(SAPDynamicArray *object) {
    SAPDynamicArraySetCapacity(object, SAPDynamicArrayCapacityForResize(object));
}

unsigned long SAPDynamicArrayCapacityForResize(SAPDynamicArray *object) {
    
    unsigned long count = SAPDynamicArrayCount(object);
    unsigned long capacity = SAPDynamicArrayCapacity(object);
    unsigned long result = kSAPImpossibleValue;
    
    if (count > capacity) {
        result = 0lu == capacity ? 1 : capacity * kSAPSizeMultiplicator;
    } else if ((count - 1) * kSAPSizeMultiplicator == capacity) {
        result = capacity / kSAPSizeMultiplicator;
    } else if (1 == capacity && 1 == count) {
        result = 0;
    }

    return result;
}
