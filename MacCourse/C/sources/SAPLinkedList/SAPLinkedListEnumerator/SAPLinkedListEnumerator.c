//
//  SAPLinkedListEnumerator.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 11/8/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include "SAPLinkedListEnumerator.h"
#include "SAPLinkedListNode.h"
#include "SAPMacro.h"
#include "SAPLinkedListPrivate.h"
#include "SAPLinkedListEnumeratorPrivate.h"

#pragma mark -
#pragma mark Private Declarations

static
void SAPLinkedListEnumeratorSetList(SAPLinkedListEnumerator *enumerator, SAPLinkedList *list);

static
SAPLinkedList *SAPLinkedListEnumeratorList(SAPLinkedListEnumerator *enumerator);

static
void SAPLinkedListEnumeratorSetCurrentNode(SAPLinkedListEnumerator *enumerator, SAPLinkedListNode *node);

static
void SAPLinkedListEnumeratorSetMutationsCount(SAPLinkedListEnumerator *enumerator, uint64_t mutationsCount);

static
uint64_t SAPLinkedListEnumeratorMutationsCount(SAPLinkedListEnumerator *enumerator);

static
void SAPLinkedListEnumeratorSetValid(SAPLinkedListEnumerator * enumerator, bool isValid);

static
bool SAPLinkedListEnumeratorMutationsCountValidate(SAPLinkedListEnumerator * enumerator);

#pragma mark -
#pragma mark Public Implementations

void __SAPLinkedListEnumeratorDeallocate(void *object) {
    SAPLinkedListEnumeratorSetList(object, NULL);
    SAPLinkedListEnumeratorSetCurrentNode(object, NULL);
    
    __SAPObjectDeallocate(object);
}

SAPLinkedListEnumerator *SAPLinkedListEnumeratorCreateWithList(SAPLinkedList *list) {
    if (NULL == list || NULL == SAPLinkedListHead(list)) {
        return NULL;
    }
    
   	SAPLinkedListEnumerator *enumerator = SAPObjectCreateOfType(SAPLinkedListEnumerator);
    SAPLinkedListEnumeratorSetList(enumerator, list);
    SAPLinkedListEnumeratorSetMutationsCount(enumerator, SAPLinkedListMutationsCount(list));
    SAPLinkedListEnumeratorSetValid(enumerator, true);
    
    return enumerator;
}

void *SAPLinkedListEnumeratorNextObject(SAPLinkedListEnumerator *enumerator) {
    if (NULL == enumerator) {
        return NULL;
    }
    
    if (SAPLinkedListEnumeratorMutationsCountValidate(enumerator)) {
        SAPLinkedListNode *currentNode = SAPLinkedListEnumeratorCurrentNode(enumerator);
        SAPLinkedList *list = SAPLinkedListEnumeratorList(enumerator);
        if (NULL == currentNode) {
            currentNode = SAPLinkedListHead(list);
        } else {
            currentNode = SAPLinkedListNodeNextNode(currentNode);
        }
        
        //reached the end of list
        if (NULL == currentNode) {
            SAPLinkedListEnumeratorSetValid(enumerator, false);
        }
        
        SAPLinkedListEnumeratorSetCurrentNode(enumerator, currentNode);
        
        return SAPLinkedListNodeObject(currentNode);
    }
    
    return NULL;
    
}

bool SAPLinkedListEnumeratorIsValid(SAPLinkedListEnumerator *enumerator) {
    return SAPObjectIVarGetterSynthesize(enumerator, _isValid, false);
}

void SAPLinkedListEnumeratorSetValid(SAPLinkedListEnumerator * enumerator, bool isValid) {
    SAPObjectIVarSetterSynthesize(enumerator, isValid);
}

#pragma mark -
#pragma mark Private Implementations

void SAPLinkedListEnumeratorSetList(SAPLinkedListEnumerator *enumerator, SAPLinkedList *list) {
    SAPObjectRetainSetterSynthesize(enumerator, list);
}

SAPLinkedList *SAPLinkedListEnumeratorList(SAPLinkedListEnumerator *enumerator) {
    return SAPObjectIVarGetterSynthesize(enumerator, _list, NULL);
}

void SAPLinkedListEnumeratorSetCurrentNode(SAPLinkedListEnumerator *enumerator, SAPLinkedListNode *currentNode) {
    SAPObjectIVarSetterSynthesize(enumerator, currentNode);
}

SAPLinkedListNode *SAPLinkedListEnumeratorCurrentNode(SAPLinkedListEnumerator *enumerator) {
    return SAPObjectIVarGetterSynthesize(enumerator, _currentNode, NULL);
}

void SAPLinkedListEnumeratorSetMutationsCount(SAPLinkedListEnumerator *enumerator, uint64_t mutationsCount) {
    SAPObjectIVarSetterSynthesize(enumerator, mutationsCount);
}

uint64_t SAPLinkedListEnumeratorMutationsCount(SAPLinkedListEnumerator *enumerator) {
    return SAPObjectIVarGetterSynthesize(enumerator, _mutationsCount, 0);
}

bool SAPLinkedListEnumeratorMutationsCountValidate(SAPLinkedListEnumerator * enumerator) {
    if (SAPLinkedListEnumeratorIsValid(enumerator)) {
        SAPLinkedList *list = SAPLinkedListEnumeratorList(enumerator);
        assert(SAPLinkedListEnumeratorMutationsCount(enumerator) == SAPLinkedListMutationsCount(list));
    
        return true;
    }
    
    return false;
}

