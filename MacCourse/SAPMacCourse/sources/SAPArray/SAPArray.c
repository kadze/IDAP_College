//
//  SAPArray.c
//  MacCourse
//
//  Created by S A P on 10/22/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPObject.h"
#include "SAPA"

#pragma mark -
#pragma mark Initializations & Deallocation

SAPArray *SAPArrayCreate(void) {
    SAPArray *object = SAPObjectCreateOfType(SAPArray);
    
    return object;
}

void __SAPArrayDeallocate(SAPArray *object) {
    for (int index = 0; index < kSAPArraySize; index++) {
        object->_value[index] = NULL;
    }
    
    __SAPObjectDeallocate(object);
}

#pragma mark -
#pragma mark Accessors

//void SAPArraySetValue(SAPArray *object, void *internalArray);

void SAPArraySetValueAtIndex(SAPArray *object, void *value, uint index) {
    if (object != NULL) {
        object->_value[index] = value;
    }
}

void *SAPArrayValueAtIndex(SAPArray *object, uint index) {
    if (NULL != object) {
        return = object->_value[index];
    }
}

#pragma mark -
#pragma mark Public implementations

