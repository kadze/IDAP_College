//
//  SAPLinkedList.c
//  MacCourse
//
//  Created by S A P on 11/6/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <string.h>
#include "SAPLinkedListNode.h"
#include "SAPMacro.h"
#include "SAPLinkedListPrivate.h"
#include "SAPLinkedListEnumeratorPrivate.h"

#pragma mark -
#pragma mark Private Declarations

static
void SAPLinkedListSetCount(SAPLinkedList *list, uint64_t count);

static
void SAPLinkedListMutate(SAPLinkedList *list);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPLinkedListDeallocate(SAPLinkedList *list) {
    SAPLinkedListSetHead(list, NULL);
    
    __SAPObjectDeallocate(list);
}

#pragma mark-
#pragma mark Public Implementations

SAPLinkedListEnumerator *SAPLinkedListEnumeratorFromList(SAPLinkedList *list) {
    return SAPLinkedListEnumeratorCreateWithList(list);
}

void *SAPLinkedListFirstObject(SAPLinkedList *list){
    SAPLinkedListNode *node = SAPLinkedListHead(list);
    
    return  SAPLinkedListNodeObject(node);
}

void SAPLinkedListRemoveFirstObject(SAPLinkedList *list) {
    uint64_t count = SAPLinkedListCount(list);
    if (0 != count) {
        SAPLinkedListNode *node = SAPLinkedListHead(list);
        SAPLinkedListSetHead(list, SAPLinkedListNodeNextNode(node));
        SAPLinkedListSetCount(list, count - 1);
    }
}

void *SAPLinkedListObjectBeforeObject(SAPLinkedList *list, void *object) {
    if (NULL == list || SAPLinkedListIsEmpty(list)) {
        return NULL;
    }
    
    SAPLinkedListNode *currentNode = SAPLinkedListHead(list);
    void *previousObject = NULL;
    do {
        void *currentObject = SAPLinkedListNodeObject(currentNode);
        if (object == currentObject) {
            return previousObject;
        }
        
        previousObject = currentObject;
    } while (NULL != (currentNode = SAPLinkedListNodeNextNode(currentNode)));
    
    return NULL;
}

bool SAPLinkedListIsEmpty(SAPLinkedList *list) {
    return (NULL != list && 0 == SAPLinkedListCount(list));
}

void SAPLinkedListAddObject(SAPLinkedList *list, void *object) {
    if (NULL == list) {
        return;
    }
    
    SAPLinkedListNode *node = SAPLinkedListNodeCreateWithObject(object);
    SAPLinkedListNodeSetNextNode(node, SAPLinkedListHead(list));
    SAPLinkedListSetHead(list, node);
    SAPLinkedListSetCount(list, SAPLinkedListCount(list) + 1);
    SAPObjectRelease(node);
}

void SAPLinkedListRemoveObject(SAPLinkedList *list, void *object) {
    SAPLinkedListContext context;
    memset(&context, 0, sizeof(context));
    context.object = object;
    SAPLinkedListNode *node = NULL;
    while (NULL != (node = SAPLinkedListFindNodeWithContext(list, SAPLinkedListNodeContainsObject, &context))) {
        SAPLinkedListNodeSetNextNode(context.previousNode, SAPLinkedListNodeNextNode(node));
        SAPLinkedListSetCount(list, SAPLinkedListCount(list) - 1);
    }
}

void SAPLinkedListRemoveAllObjects(SAPLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    SAPLinkedListSetCount(list, 0);
}

bool SAPLinkedListContainsObject(SAPLinkedList *list, void *object) {
    if (NULL == list) {
        return false;
    }
    SAPLinkedListContext context;
    memset(&context, 0, sizeof(context));
    context.object = object;
    SAPLinkedListNode *node = SAPLinkedListFindNodeWithContext(list, SAPLinkedListNodeContainsObject, &context);
    
    return NULL != node;
}

uint64_t SAPLinkedListCount(SAPLinkedList *list) {
    return SAPObjectIVarGetterSynthesize(list, _count, 0);
}

#pragma mark-
#pragma mark Private Implementations

SAPLinkedListNode *SAPLinkedListHead(SAPLinkedList *object){
    return SAPObjectIVarGetterSynthesize(object, _head, NULL);
}

void SAPLinkedListSetHead(SAPLinkedList *object, SAPLinkedListNode *head){
    SAPObjectRetainSetterSynthesize(object, head);
}

void SAPLinkedListSetCount(SAPLinkedList *list, uint64_t count) {
    if (NULL != list) {
        if (0 == count) {
            SAPLinkedListSetHead(list, NULL);
        }
        list->_count = count;
        SAPLinkedListMutate(list);
    }
}

void SAPLinkedListMutate(SAPLinkedList *list) {
    SAPLinkedListSetMutationsCount(list, SAPLinkedListMutationsCount(list) + 1);
}

#pragma mark -
#pragma mark SAPLinkedListPrivate

void SAPLinkedListSetMutationsCount(SAPLinkedList *list, uint64_t mutationsCount) {
    SAPObjectIVarSetterSynthesize(list, mutationsCount);
}

uint64_t SAPLinkedListMutationsCount(SAPLinkedList *list) {
    return SAPObjectIVarGetterSynthesize(list, _mutationsCount, 0);
}

SAPLinkedListNode *SAPLinkedListFindNodeWithContext(SAPLinkedList *list,
                                                   SAPLinkedListComparisonFunction comparator,
                                                   SAPLinkedListContext *context) {
    SAPLinkedListNode *result = NULL;
    if (NULL == list) {
        return result;
    }
    
    SAPLinkedListEnumerator *enumerator = SAPLinkedListEnumeratorCreateWithList(list);
    while (SAPLinkedListEnumeratorIsValid(enumerator)
           && NULL != SAPLinkedListEnumeratorNextObject(enumerator)) {
        SAPLinkedListNode *node = SAPLinkedListEnumeratorCurrentNode(enumerator);
        context->node = node;
        if (SAPLinkedListNodeContainsObject(node, *context)) {
            result = node;
            
            break;
        }
        
        context->previousNode = node;
    }
    
    return result;
}

bool SAPLinkedListNodeContainsObject(SAPLinkedListNode *node, SAPLinkedListContext context) {
    return (NULL != node) && context.object == SAPLinkedListNodeObject(node);;
}