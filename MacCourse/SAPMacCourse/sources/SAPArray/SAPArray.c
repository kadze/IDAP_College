//
//  SAPArray.c
//  MacCourse
//
//  Created by S A P on 10/22/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPObject.h"
#include "SAPArray.h"

#pragma mark -
#pragma mark Initializations & Deallocation

SAPArray *SAPArrayCreate(void) {
    SAPArray *object = SAPObjectCreateOfType(SAPArray);
    
    return object;
}

void __SAPArrayDeallocate(SAPArray *object) {
    void *arrayElementPointer = object->_value;
    for (int counter = 0; counter < kSAPArraySize; counter++) {
        void *a = (arrayElementPointer +counter);
        
        SAPHuman *hum = (SAPHuman *)arrayElementPointer + counter;
        hum = NULL;
    }
    __SAPObjectDeallocate(object);
    
}

#pragma mark -
#pragma mark Accessors

void *SAPArrayValue(SAPArray *object);

void SAPArraySetValue(void *value);

#pragma mark -
#pragma mark Public implementations

