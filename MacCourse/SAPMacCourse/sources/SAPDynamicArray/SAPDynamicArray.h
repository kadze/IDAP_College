//
//  SAPDynamicArray.h
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/24/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPDynamicArray__
#define __MacCourse__SAPDynamicArray__

#include <stdlib.h>
#include <stdbool.h>
#include "SAPObject.h"

typedef struct {
    SAPObject _super;
    void **_values;
    unsigned long _count;
    unsigned long _capacity;
} SAPDynamicArray;

extern
void __SAPDynamicArrayDeallocate(SAPDynamicArray *object);

extern
SAPDynamicArray *SAPDynamicArrayCreate(void);

extern
void SAPDynamicArrayAddObject(SAPDynamicArray *object, void *value);

extern
void SAPDynamicArrayRemoveObject(SAPDynamicArray *object, void *value);

extern
void *SAPDynamicArrayValueAtIndex(SAPDynamicArray *object, unsigned long index);

extern
void SAPDynamicArraySetValueAtIndex(SAPDynamicArray *object, void *value, unsigned long index);

extern
void SAPDynamicArrayRemoveByIndex(SAPDynamicArray *object, unsigned long index);

extern
void SAPDynamicArrayRemoveAll(SAPDynamicArray *object);

extern
unsigned long SAPDynamicArrayIndexOfValue(SAPDynamicArray *object, void  *value);

extern
unsigned long SAPDynamicArrayCount(SAPDynamicArray *object);

extern
unsigned long SAPDynamicArrayCapacity(SAPDynamicArray *object);

extern
bool SAPDynamicArrayContains(SAPDynamicArray *object, void *value);


#endif /* defined(__MacCourse__SAPDynamicArray__) */
