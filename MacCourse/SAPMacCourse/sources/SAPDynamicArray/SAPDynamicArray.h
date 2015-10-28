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
    uint _count;
    uint _allocatedCount;
} SAPDynamicArray;

extern
void __SAPDynamicArrayDeallocate(SAPDynamicArray *object);

extern
SAPDynamicArray *SAPDynamicArrayCreate(void);

extern
void SAPDynamicArrayAdd(SAPDynamicArray *object, void *value);

extern
void SAPDynamicArrayRemove(SAPDynamicArray *object, void *value);

extern
void *SAPDynamicArrayValueAtIndex(SAPDynamicArray *object, uint index);

extern
void SAPDynamicArraySetValueAtIndex(SAPDynamicArray *object, void *value, uint index);

extern
void SAPDynamicArrayRemoveByIndex(SAPDynamicArray *object, uint index);

extern
uint SAPDynamicArrayIndexOfValue(SAPDynamicArray *object, void  *value);

extern
uint SAPDynamicArrayCount(SAPDynamicArray *object);

extern
uint SAPDynamicArrayAllocatedCount(SAPDynamicArray *object);

extern
bool SAPDynamicArrayContains(SAPDynamicArray *object, void *value);


#endif /* defined(__MacCourse__SAPDynamicArray__) */
