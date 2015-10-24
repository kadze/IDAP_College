//
//  SAPDynamicArray.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/24/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include "SAPDynamicArray.h"

static const uint kSAPSizeIncrement = 10;

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPDynamicArrayDeallocate(SAPDynamicArray *object) {
//    for (uint index = 0; index < kSAPArraySize; index++) {
//        object->_value[index] = NULL;
//    }
//    
//    __SAPObjectDeallocate(object);
}

SAPDynamicArray *SAPDynamicArrayCreate(void) {
    SAPDynamicArray *object = SAPObjectCreateOfType(SAPDynamicArray);
    
    return object;
}



#pragma mark -
#pragma mark Accessors

//void SAPDynamicArraySetValueAtIndex(SAPDynamicArray *object, void *value, uint index) {
//}

//void *SAPDynamicArrayValueAtIndex(SAPDynamicArray *object, size_t index) {
//    return (NULL != object && object->_allocatedElementsCount > index) ? (object->_value + index) : NULL;
//}

void SAPDynamicArrayAddElement(SAPDynamicArray *object, void *value) {
    if (NULL == object) {
        return;
        
    }
    
    if (object->_allocated == object->_elements) {
        object->_allocated = object->_allocated  + 1;
        void** dynamicArray = realloc(object->_value, sizeof(void*) * object->_allocated);
        assert(NULL != dynamicArray);
        object->_value = dynamicArray;
    }
    object->_value[object->_elements] = value;
    object->_elements++;
}

#pragma mark-
#pragma mark Public implementations
//size_t SAPDynamicArrayElementsCount(SAPDynamicArray *object) {
//}
