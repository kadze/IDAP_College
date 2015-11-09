//
//  SAPLinkedListEnumerator.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 11/8/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include "SAPLinkedListEnumerator.h"
#include "SAPLinkedList.h"
#include "SAPLinkedListNode.h"
#include "SAPMacro.h"
#include "SAPLinkedListPrivate.h"

#pragma mark -
#pragma mark Private Declarations

static
void SAPLinkedListEnumeratorSetList(SAPLinkedListEnumerator *enumerator, SAPLinkedList *list);

static
SAPLinkedList *SAPLinkedListEnumeratorList(SAPLinkedListEnumerator *enumerator);

static
void SAPLinkedListEnumeratorSetNode(SAPLinkedListEnumerator *enumerator, SAPLinkedListNode *node);

static
SAPLinkedListNode *SAPLinkedListEnumeratorNode(SAPLinkedListEnumerator *enumerator);

static
void SAPLinkedListEnumeratorSetMutationsCount(SAPLinkedListEnumerator *enumerator, uint64_t mutationsCount);

static
uint64_t SAPLinkedListEnumeratorMutationsCount(SAPLinkedListEnumerator *enumerator);

#pragma mark -
#pragma mark Public Implementations

void __SAPLinkedListEnumeratorDeallocate(void *object) {
    SAPLinkedListEnumeratorSetList(object, NULL);
    SAPLinkedListEnumeratorSetNode(object, NULL);
    
    __SAPObjectDeallocate(object);
}

SAPLinkedListEnumerator *APLinkedListEnumeratorCreateWithList(SAPLinkedList *list) {
    if (NULL == list) {
        return NULL;
    }
    
   	SAPLinkedListEnumerator *enumerator = SAPObjectCreateOfType(SAPLinkedListEnumerator);
    SAPLinkedListEnumeratorSetList(enumerator, list);
    SAPLinkedListEnumeratorSetMutationsCount(enumerator, SAPLinkedListMutationsCount(list));
    
    return enumerator;
}

///////!!!!!!!!!!!!!!!!!!!!
void *SAPLinkedListEnumeratorNextObject(SAPLinkedList *list) {
    return NULL;
}

bool SAPLinkedListEnumeratorIsValid(SAPLinkedListEnumerator *enumerator) {
    return SAPObjectIVarGetterSynthesize(enumerator, _isValid, false);
}

#pragma mark -
#pragma mark Private Implementations

void SAPLinkedListEnumeratorSetList(SAPLinkedListEnumerator *enumerator, SAPLinkedList *list) {
    SAPObjectRetainSetterSynthesize(enumerator, list);
}

SAPLinkedList *SAPLinkedListEnumeratorList(SAPLinkedListEnumerator *enumerator) {
    return SAPObjectIVarGetterSynthesize(enumerator, _list, NULL);
}

void SAPLinkedListEnumeratorSetNode(SAPLinkedListEnumerator *enumerator, SAPLinkedListNode *currentNode) {
    SAPObjectRetainSetterSynthesize(enumerator, currentNode);
}

SAPLinkedListNode *SAPLinkedListEnumeratorNode(SAPLinkedListEnumerator *enumerator) {
    return SAPObjectIVarGetterSynthesize(enumerator, _currentNode, NULL);
}

void SAPLinkedListEnumeratorSetMutationsCount(SAPLinkedListEnumerator *enumerator, uint64_t mutationsCount) {
    SAPObjectIVarSetterSynthesize(enumerator, mutationsCount);
}

uint64_t SAPLinkedListEnumeratorMutationsCount(SAPLinkedListEnumerator *enumerator) {
    return SAPObjectIVarGetterSynthesize(enumerator, _mutationsCount, 0);
}



