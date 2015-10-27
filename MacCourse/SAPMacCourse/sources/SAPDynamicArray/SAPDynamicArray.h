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
    uint _elementsCount;
    uint _allocatedElementsCount;
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
void SAPDynamicArrayRemoveValueAtIndex(SAPDynamicArray *object, void *value, uint index);

extern
uint SAPDynamicArrayElementsCount(SAPDynamicArray *object);

extern
bool SAPDynamicArrayContain(SAPDynamicArray *boject, void *value);


#endif /* defined(__MacCourse__SAPDynamicArray__) */
