//
//  SAPArray.h
//  MacCourse
//
//  Created by S A P on 10/22/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPArray_h
#define SAPArray_h

#include <stdlib.h>
#include "SAPObject.h"
//#include "SAPHuman.h"

static const uint kSAPArraySize = 20;

typedef struct {
    SAPObject *_super;
    void *_value[kSAPArraySize];
} SAPArray;

extern
SAPArray *SAPArrayCreate(void);

extern
void __SAPArrayDeallocate(SAPArray *object);

//extern
//void *SAPArrayValue(SAPArray *object);

//extern
//void SAPArraySetValue(SAPArray *object, void *internalArray);

extern
void SAPArraySetValueAtIndex(SAPArray *object, void *value, uint index);

extern
void *SAPArrayValueAtIndex(SAPArray *object, uint index);

#endif /* SAPArray_h */