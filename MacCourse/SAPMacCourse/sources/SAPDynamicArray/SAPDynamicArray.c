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

#pragma mark -
#pragma mark Private Declarations

static
void SAPDynamicArraySetAllocatedCount(SAPDynamicArray *object, unsigned long allocatedCount);

static
void SAPDynamicArraySetCount(SAPDynamicArray *object, unsigned long count);

static
unsigned long SAPDynamicArrayAllocatedCountForResize(SAPDynamicArray *object);

static
void SAPDynamicArrayResize(SAPDynamicArray *object);

static
void SAPDynamicArrayShiftElements(SAPDynamicArray *object);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPDynamicArrayDeallocate(SAPDynamicArray *object) {
    for (unsigned long index = 0; index < SAPDynamicArrayCount(object); index++) {
        SAPDynamicArraySetValueAtIndex(object, NULL, index);
    }
    
    __SAPObjectDeallocate(object);
}

SAPDynamicArray *SAPDynamicArrayCreate(void) {
    return SAPObjectCreateOfType(SAPDynamicArray);
}

#pragma mark -
#pragma mark Accessors

unsigned long SAPDynamicArrayAllocatedCount(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _allocatedCount, 0);
}

void SAPDynamicArraySetAllocatedCount(SAPDynamicArray *object, unsigned long allocatedCount) {
    SAPReturnIfObjectNULL;
    SAPReturnIfValuesEqual(ULLONG_MAX, allocatedCount);
    unsigned long count = object->_count;
    if (count == allocatedCount) {
        if (allocatedCount != 1 && allocatedCount != 2) {
            return;
        }
    }

    void **values = object->_values;
    
    if (0 == allocatedCount) {
        free(values);
        object->_values = NULL;
    } else {
        size_t valueSize = sizeof(*values);
        size_t allocatedSize = allocatedCount * valueSize;
        size_t size = count * valueSize;
        
        void *newValues = realloc(values, allocatedSize);
        assert(newValues);
        object->_values = newValues;
        
        if (allocatedCount > count || (allocatedCount == 1 && count == 1) || (allocatedCount == 2 && count == 2)) {
            memset(object->_values + count, 0, allocatedSize - size);
        }
    }
    
    object->_allocatedCount = allocatedCount;
    
}

unsigned long SAPDynamicArrayCount(SAPDynamicArray *object) {
    return SAPObjectIVarGetterSynthesize(object, _count, 0);
}
void SAPDynamicArraySetCount(SAPDynamicArray *object, unsigned long count) {
    SAPObjectIVarSetterSynthesize(object, count);
}
void SAPDynamicArraySetValueAtIndex(SAPDynamicArray *object, void *value, unsigned long index) {
    if (index < SAPDynamicArrayAllocatedCount(object)) { //could it be differently?
        SAPObjectRelease(object->_values[index]);
        SAPObjectRetain(value);
        object->_values[index] = value;
        
        if (NULL == value) {
            SAPDynamicArrayShiftElements(object);
            SAPDynamicArrayResize(object);
            object->_count--;
        }
    }
}

void *SAPDynamicArrayValueAtIndex(SAPDynamicArray *object, unsigned long index) {
    if (NULL != object && index < SAPDynamicArrayAllocatedCount(object)) {
        return object->_values[index];
    }
    
    return NULL;
}


#pragma mark-
#pragma mark Public Implementations

void SAPDynamicArrayAddElement(SAPDynamicArray *object, void *value) {
    SAPReturnIfObjectNULL;
    SAPReturnIfNULL(value);
    
    object->_count++;
    SAPDynamicArrayResize(object);
    SAPDynamicArraySetValueAtIndex(object, value, SAPDynamicArrayCount(object)-1);
}

void SAPDynamicArrayRemoveElement(SAPDynamicArray *object, void *value) {
    SAPReturnIfObjectNULL;
    SAPDynamicArrayRemoveByIndex(object, SAPDynamicArrayIndexOfValue(object, value));
}

void SAPDynamicArrayRemoveByIndex(SAPDynamicArray *object, unsigned long index) {
    SAPDynamicArraySetValueAtIndex(object, NULL, index);
}

unsigned long SAPDynamicArrayIndexOfValue(SAPDynamicArray *object, void  *value) {
    unsigned long result = ULONG_MAX;
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
    return ULONG_MAX != SAPDynamicArrayIndexOfValue(object, value);
}

#pragma mark-
#pragma mark Private Implementations

void SAPDynamicArrayShiftElements(SAPDynamicArray *object) {
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

void SAPDynamicArrayResize(SAPDynamicArray *object) {
    SAPDynamicArraySetAllocatedCount(object, SAPDynamicArrayAllocatedCountForResize(object));
}

unsigned long SAPDynamicArrayAllocatedCountForResize(SAPDynamicArray *object) {
    
    unsigned long count = SAPDynamicArrayCount(object);
    unsigned long allocatedCount = SAPDynamicArrayAllocatedCount(object);
    unsigned long result = ULLONG_MAX;
    
    if (count > allocatedCount) {
        result = 0lu == allocatedCount ? 1 : allocatedCount * kSAPSizeMultiplicator;
    } else if ((count - 1) * kSAPSizeMultiplicator == allocatedCount) {
        result = allocatedCount / kSAPSizeMultiplicator;
    } else if (1 == allocatedCount && 1 == count) {
        result = 0;
    }

    return result;
}
