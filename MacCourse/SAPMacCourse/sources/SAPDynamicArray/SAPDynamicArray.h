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
    void **_objects;
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
void *SAPDynamicArrayObjectAtIndex(SAPDynamicArray *object, unsigned long index);

extern
void SAPDynamicArrayInsertObjectAtIndex(SAPDynamicArray *object, void *insertion);

extern
void SAPDynamicArrayRemoveObjectAtIndex(SAPDynamicArray *object, unsigned long index);

extern
void SAPDynamicArrayRemoveAllObjects(SAPDynamicArray *object);

extern
unsigned long SAPDynamicArrayIndexOfObject(SAPDynamicArray *object, void  *value);

extern
unsigned long SAPDynamicArrayCount(SAPDynamicArray *object);

extern
unsigned long SAPDynamicArrayCapacity(SAPDynamicArray *object);

extern
bool SAPDynamicArrayContainsObject(SAPDynamicArray *object, void *value);


#endif /* defined(__MacCourse__SAPDynamicArray__) */
