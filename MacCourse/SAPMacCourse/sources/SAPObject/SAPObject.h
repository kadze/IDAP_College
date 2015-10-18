//
//  SAPObject.h
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/16/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPObject__
#define __MacCourse__SAPObject__

#include <stdlib.h>

typedef void(*SAPObjectDeallocator)(void *object);

typedef struct{
    uint64_t _retainCount;
    SAPObjectDeallocator _deallocatorFunctionPointer;
} SAPObject;

#define SAPObjectCreateOfType(type) __SAPObjectCreate(sizeof(type), __ ##type ##Deallocate)

extern
void *__SAPObjectCreate(size_t size, SAPObjectDeallocator);

extern
void __SAPObjectDeallocate(void *object);

extern
uint64_t SAPObjectRetainCount(void *object);

extern
void SAPObjectRelease(void *object);

extern
void *SAPObjectRetain(void *object);

#endif /* defined(__MacCourse__SAPObject__) */
