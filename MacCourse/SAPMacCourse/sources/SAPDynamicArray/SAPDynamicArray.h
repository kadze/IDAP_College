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
    void **_value;
    size_t _elements;
    size_t _allocated;
} SAPDynamicArray;

extern
void __SAPDynamicArrayDeallocate(SAPDynamicArray *object);

extern
SAPDynamicArray *SAPDynamicArrayCreate(void);

extern
void SAPDynamicArrayAdd(SAPDynamicArray *object, void *value);

extern
void SAPDynamicArrayRemoveValue(SAPDynamicArray *object);

extern
void SAPDynamicArraySetValueAtIndex(SAPDynamicArray *object, void *value, uint index);

extern
void *SAPArrayValueAtIndex(SAPDynamicArray *object, size_t index);

extern
size_t SAPDynamicArrayElementsCount(SAPDynamicArray *object);


#endif /* defined(__MacCourse__SAPDynamicArray__) */
