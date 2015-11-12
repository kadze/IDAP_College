//
//  SAPAutoreleasingStack.c
//  MacCourse
//
//  Created by S A P on 11/12/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include "SAPAutoreleasingStack.h"
#include "SAPMacro.h"

#pragma mark -
#pragma mark Private Declarations

static
void **SAPAutoreleasingStackData(SAPAutoreleasingStack *stack);

static
void *SAPAutoreleasingStackHead(SAPAutoreleasingStack *stack);

static
void SAPAutoreleasingStackSetHead(SAPAutoreleasingStack *stack, void  *head);

static
size_t SAPAutoreleasingStackSize(SAPAutoreleasingStack *stack);

static
void SAPAutoreleasingStackSetSize(SAPAutoreleasingStack *stack, size_t size);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPAutoreleasingStackDeallocate(void *object) {
    SAPAutoreleasingStackSetSize(object, 0);
    __SAPObjectDeallocate(object);
}

SAPAutoreleasingStack *SAPAutoreleasingStackCreateWithSize(size_t size) {
    assert(0 != size);
    SAPAutoreleasingStack *stack = SAPObjectCreateOfType(SAPAutoreleasingStack);
    SAPAutoreleasingStackSetSize(stack, size);
    SAPAutoreleasingStackSetHead(stack, SAPAutoreleasingStackData(stack));
    
    return stack;
}

#pragma mark -
#pragma mark Public Implementations

bool SAPAutoreleasingStackIsEmpty(SAPAutoreleasingStack *stack) {
    return NULL != stack && SAPAutoreleasingStackHead(stack) == SAPAutoreleasingStackData(stack);
}

bool SAPAutoreleasingStackIsFull(SAPAutoreleasingStack *stack) {
    if (NULL == stack) {
        return false;
    }
    
    void **data = SAPAutoreleasingStackData(stack);
    uint64_t count = SAPAutoreleasingStackSize(stack) / sizeof(*data);
    void *head = SAPAutoreleasingStackHead(stack);
    
    return (void*)(&(data[count - 1])) <= head;
//    return (data - (void **)head) >= count;
}

void SAPAutoreleasingStackPushObject(SAPAutoreleasingStack *stack, void *object) {
    if (NULL == stack) {
        return;
    }
    
    assert(false == SAPAutoreleasingStackIsFull(stack));
    void **head = SAPAutoreleasingStackHead(stack);
    head++;
    *head = object;
    SAPAutoreleasingStackSetHead(stack, head);
}

SAPAutoreleasingStackPopType SAPAutoreleasingStackPopObject(SAPAutoreleasingStack *stack) {
    if (NULL == stack) {
        return 0;
    }
    
    assert(false == SAPAutoreleasingStackIsEmpty(stack));
    void **head = SAPAutoreleasingStackHead(stack);
    SAPObject *object = *head;
    head --;
    SAPAutoreleasingStackSetHead(stack, head);
    
    SAPAutoreleasingStackPopType type = NULL != object ? kSAPAutoreleasingStackPopedObject : kSAPAutoreleasingStackPopedNULL;
    SAPObjectRelease(object);
    return type;
}

SAPAutoreleasingStackPopType SAPAutoreleasingStackPopObjectsUntilNULL(SAPAutoreleasingStack *stack) {
    if (NULL == stack) {
        return 0;
    }
    
    SAPAutoreleasingStackPopType type;
    do {
        type = SAPAutoreleasingStackPopObject(stack);
    } while (kSAPAutoreleasingStackPopedNULL != type && false == SAPAutoreleasingStackIsEmpty(stack));

    return type;
}

#pragma mark -
#pragma mark Private Implementations

void **SAPAutoreleasingStackData(SAPAutoreleasingStack *stack) {
    return SAPObjectIVarGetterSynthesize(stack, _data, NULL);
}

void *SAPAutoreleasingStackHead(SAPAutoreleasingStack *stack) {
    return SAPObjectIVarGetterSynthesize(stack, _head, NULL);
}

void SAPAutoreleasingStackSetHead(SAPAutoreleasingStack *stack, void  *head) {
    SAPObjectIVarSetterSynthesize(stack, head);
}

size_t SAPAutoreleasingStackSize(SAPAutoreleasingStack *stack) {
    return SAPObjectIVarGetterSynthesize(stack, _size, 0);
}

void SAPAutoreleasingStackSetSize(SAPAutoreleasingStack *stack, size_t size) {
    if (NULL == stack) {
        return;
    }
    
    size_t previousSize = stack->_size;
    if (previousSize == size) {
        return;
    }
    
    if (0 != previousSize) {
        free(stack->_data);
        stack->_data = NULL;
    }
    
    if (0 != size) {
        stack->_data = calloc(size, sizeof(*stack->_data));
        assert(NULL != stack->_data);
    }
    
    SAPObjectIVarSetterSynthesize(stack, size);
}