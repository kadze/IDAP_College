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

static const unsigned long kSAPFirstCapacity     = 1;
static const unsigned long kSAPCapacityMultiplicator = 2;
static const unsigned long kSAPUndefinedObject   = ULONG_MAX;

#pragma mark -
#pragma mark Private Declarations
static
void **SAPDynamicArrayObjects(SAPDynamicArray *object);

static
void SAPDynamicArraySetCapacity(SAPDynamicArray *object, unsigned long capacity);

static
void SAPDynamicArraySetCount(SAPDynamicArray *object, unsigned long count);

static
unsigned long SAPDynamicArrayCapacityForResize(SAPDynamicArray *object, unsigned long newCount);

static
bool SAPDynamicArrayShouldResize(SAPDynamicArray *object, unsigned long newCount);

static
void SAPDynamicArrayResizeIfNeeded(SAPDynamicArray *object, unsigned long count);

static
void SAPDynamicArrayShiftObjects(SAPDynamicArray *object, unsigned long index);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPDynamicArrayDeallocate(SAPDynamicArray *object) {
    SAPDynamicArrayRemoveAllObjects(object);
    
    __SAPObjectDeallocate(object);
}

SAPDynamicArray *SAPDynamicArrayCreate(void) {
    return SAPObjectCreateOfType(SAPDynamicArray);
}

#pragma mark -
#pragma mark Accessors

void **SAPDynamicArrayObjects(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _objects, NULL);
}

unsigned long SAPDynamicArrayCapacity(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _capacity, 0);
}

void SAPDynamicArraySetCapacity(SAPDynamicArray *object, unsigned long capacity) {
    if (NULL == object || capacity == object->_capacity) {
        return;
    }
    unsigned long count = SAPDynamicArrayCount(object);
    
    void **objects = SAPDynamicArrayObjects(object);
    
    if (0 == capacity && NULL != objects) {
        free(objects);
        object->_objects = NULL;
    } else {
        size_t valueSize = sizeof(*objects);
        size_t allocatedSize = capacity * valueSize;
        size_t size = count * valueSize;
        
        void *newValues = realloc(objects, allocatedSize);
        assert(newValues);
        object->_objects = newValues;
        
        if (capacity > count) {
            memset(object->_objects + count, 0, allocatedSize - size);
        }
    }
    
    object->_capacity = capacity;
    
}

unsigned long SAPDynamicArrayCount(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _count, 0);
}

void SAPDynamicArraySetCount(SAPDynamicArray *object, unsigned long count) {
    SAPDynamicArrayResizeIfNeeded(object, count);
    SAPObjectIVarSetterSynthesize(object, count);
}

void SAPDynamicArraySetObjectAtIndex(SAPDynamicArray *object, void *value, unsigned long index) {
    if (NULL == object) {
        return;
    }
    assert(index < SAPDynamicArrayCapacity(object));
//    if (index < SAPDynamicArrayCapacity(object)) { //could it be differently?
        SAPObjectRelease(object->_objects[index]);
        SAPObjectRetain(value);
        SAPDynamicArrayObjects(object)[index] = value;
//    }
}

void *SAPDynamicArrayObjectAtIndex(SAPDynamicArray *object, unsigned long index) {
    if (NULL != object) {
        assert(index < SAPDynamicArrayCount(object));
        
        return SAPDynamicArrayObjects(object)[index];
    }
    
    return NULL;
}

#pragma mark-
#pragma mark Public Implementations

void SAPDynamicArrayAddObject(SAPDynamicArray *object, void *value) {
    if (NULL == object || NULL == value) {
        return;
    }
    
    unsigned long countBeforeAdd = SAPDynamicArrayCount(object);
    SAPDynamicArraySetCount(object, countBeforeAdd + 1);
    SAPDynamicArraySetObjectAtIndex(object, value, countBeforeAdd);
}

void SAPDynamicArrayRemoveObject(SAPDynamicArray *object, void *value) {
    if (NULL == object) {
        return;
    }
    
    SAPDynamicArrayRemoveObjectAtIndex(object, SAPDynamicArrayIndexOfObject(object, value));
}

void SAPDynamicArrayRemoveObjectAtIndex(SAPDynamicArray *object, unsigned long index) {
    SAPDynamicArraySetObjectAtIndex(object, NULL, index);
    SAPDynamicArrayShiftObjects(object, index);
    SAPDynamicArraySetCount(object, SAPDynamicArrayCount(object) - 1);
}

void SAPDynamicArrayRemoveAllObjects(SAPDynamicArray *object) {
    if (NULL == object) {
        return;
    }
    
    for (unsigned long index = 0; index < SAPDynamicArrayCount(object); index++) {
        SAPDynamicArrayRemoveObjectAtIndex(object, index);
    }
}

unsigned long SAPDynamicArrayIndexOfObject(SAPDynamicArray *object, void  *value) {
    if (NULL == object || NULL == value) {
        return 0;
    }
    
    for (unsigned long index = 0; index < SAPDynamicArrayCount(object); index++) {
        if (value == SAPDynamicArrayObjectAtIndex(object, index)) {
            return index;
        }
    }
    
    return kSAPUndefinedObject;
}

bool SAPDynamicArrayContainsObject(SAPDynamicArray *object, void *value) {
    if (NULL != object && kSAPUndefinedObject != SAPDynamicArrayIndexOfObject(object, value)) {
        return true;
    }
    
    return false;
}

#pragma mark-
#pragma mark Private Implementations

void SAPDynamicArrayShiftObjects(SAPDynamicArray *object, unsigned long index) {
    if (NULL == object
        || 0 == index) //in this case array allocated memory was freed)
    {
        return;
    }
    
    void **data = object->_objects;
    unsigned long count = SAPDynamicArrayCount(object);
    size_t bytesForShift = (count - index) * sizeof(&data);
    memmove(&data[index], &data[index + 1], bytesForShift);
    SAPDynamicArraySetObjectAtIndex(object, NULL, count - 1);
}

bool SAPDynamicArrayShouldResize(SAPDynamicArray *object, unsigned long newCount) {
    unsigned long capacity = SAPDynamicArrayCapacity(object);
    bool result = false;
    if (newCount > capacity) {
        result = true;
    } else if (newCount * kSAPCapacityMultiplicator == capacity) {
        result = true;
    } else if (kSAPFirstCapacity == capacity && 0 == result) {
        result = true;
    }
    
    return result;
}

void SAPDynamicArrayResizeIfNeeded(SAPDynamicArray *object, unsigned long newCount) {
    if (SAPDynamicArrayShouldResize(object, newCount)) {
        SAPDynamicArraySetCapacity(object, SAPDynamicArrayCapacityForResize(object, newCount));
    }
}

unsigned long SAPDynamicArrayCapacityForResize(SAPDynamicArray *object, unsigned long newCount) {
    unsigned long capacity = SAPDynamicArrayCapacity(object);
    unsigned long result = capacity;
    
    if (newCount > capacity) {
        //in the case of growth
        if (0 == capacity) {
            result = kSAPFirstCapacity;
        } else {
            result = capacity * kSAPCapacityMultiplicator;
        }
    } else if (0 == newCount) {
        result = 0;
    } else if (capacity == newCount * kSAPCapacityMultiplicator) {
        result = capacity/kSAPCapacityMultiplicator;
    }
    
    return result;
}
