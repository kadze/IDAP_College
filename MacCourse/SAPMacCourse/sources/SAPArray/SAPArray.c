//
//  SAPArray.c
//  MacCourse
//
//  Created by S A P on 10/22/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPArray.h"

#pragma mark -
#pragma mark Initializations & Deallocation

SAPArray *SAPArrayCreate(void) {
    SAPArray *object = SAPObjectCreateOfType(SAPArray);
    
    return object;
}

void __SAPArrayDeallocate(SAPArray *object) {
    for (uint index = 0; index < kSAPArraySize; index++) {
        object->_value[index] = NULL;
    }
    
    __SAPObjectDeallocate(object);
}

#pragma mark -
#pragma mark Accessors

void SAPArraySetValueAtIndex(SAPArray *object, void *value, uint index) {
    if (object != NULL) {
        object->_value[index] = value;
    }
}

void *SAPArrayValueAtIndex(SAPArray *object, uint index) {
    return (NULL != object) ? object->_value[index] : NULL;
}

#pragma mark -
#pragma mark Public implementations

