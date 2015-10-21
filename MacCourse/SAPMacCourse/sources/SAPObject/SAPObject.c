//
//  SAPObject.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/16/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include "SAPObject.h"

#pragma mark -
#pragma mark Public Implementations

void *__SAPObjectCreate(size_t size, SAPObjectDeallocator deallocator) {
    assert(0 != size);
    assert(NULL != deallocator);
    
    SAPObject *object = calloc(1, size);
    
    assert(NULL != object);
    
    object->_retainCount = 1;
    object->_deallocatorFunctionPointer = deallocator;
    
    return object;
}

void __SAPObjectDeallocate(void *object) {
    if (NULL != object) {
        free(object);
    }
}

uint64_t SAPObjectRetainCount(void *object) {
    return object ? ((SAPObject *)object)->_retainCount : 0;
}

void SAPObjectRelease(void *object) {
    if (NULL != object) {
        SAPObject *releasedObject = (SAPObject *)object;
        if (0 == --(releasedObject->_retainCount)) {
            SAPObjectDeallocator deallocator = releasedObject->_deallocatorFunctionPointer;
            deallocator(object);
        }
    }
    
}

void *SAPObjectRetain(void *object) {
    if (NULL != object) {
        ((SAPObject*)object)->_retainCount++;
    }
    
    return object;
}
