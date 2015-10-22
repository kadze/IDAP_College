//
//  SAPString.c
//  MacCourse
//
//  Created by S A P on 10/21/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "SAPString.h"

#pragma mark -
#pragma mark Initializations & Deallocation

SAPString *SAPStringCreate(char *value) {
    SAPString *object = SAPObjectCreateOfType(SAPString);
    SAPStringSetValue(object, value);
    
    return object;
}

void __SAPStringDeallocate(SAPString *object) {
    SAPStringSetValue(object, NULL);
    __SAPObjectDeallocate(object);
}

#pragma mark -
#pragma mark Accessors

char *SAPStringValue(SAPString *object){
    return object->_value;
}

void SAPStringSetValue(SAPString *object, const char *value) {
    if (NULL == object || value == object->_value) {
        
        return;
    }
    
    if (NULL != object->_value) {
        free(object->_value);
        object->_value = NULL;
    }
    
    if (value) {
        object->_value = strdup(value);
    }
}

#pragma mark -
#pragma mark Public implementations

void SAPStringPrint(SAPString *object) {
    printf("%s", SAPStringValue(object));
}


size_t SAPStringLength(SAPString *object) {
    return strlen(SAPStringValue(object));
}
