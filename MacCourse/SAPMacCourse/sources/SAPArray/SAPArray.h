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

static const uint kSAPArraySize = 20;

typedef struct {
    SAPObject _super;
    void *_values[kSAPArraySize];
} SAPArray;

extern
SAPArray *SAPArrayCreate(void);

extern
void __SAPArrayDeallocate(SAPArray *object);

extern
void SAPArraySetValueAtIndex(SAPArray *object, void *value, uint index);

extern
void *SAPArrayValueAtIndex(SAPArray *object, uint index);

extern
uint SAPArrayNotNullElementsCount(SAPArray *object);

#endif /* SAPArray_h */