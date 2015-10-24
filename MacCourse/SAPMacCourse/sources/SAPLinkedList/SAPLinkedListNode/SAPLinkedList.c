//
//  SAPLinkedList.c
//  MacCourse
//
//  Created by S A P on 11/6/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPLinkedList.h"
#include "SAPLinkedListNode.h"
#include "SAPMacro.h"

#pragma mark -
#pragma mark Private Declarations

static
SAPLinkedListNode *SAPLinkedListHead(SAPLinkedList *object);

static
void SAPLinkedListSetHead(SAPLinkedList *object, SAPLinkedListNode *head);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPLinkedListDeallocate(SAPLinkedList *object) {
    SAPLinkedListSetHead(object, NULL);
    
    __SAPObjectDeallocate(object);
}

#pragma mark-
#pragma mark Public Implementations

void *SAPLinkedListFirstContentObject(SAPLinkedList *object){
    SAPLinkedListNode *node = SAPLinkedListHead(object);
    
    return  SAPLinkedListNodeContentObject(node);
}

void SAPLinkedListRemoveFirstContentObject(SAPLinkedList *object) {
    SAPLinkedListNode *node = SAPLinkedListHead(object);
    SAPLinkedListSetHead(object, SAPLinkedListNodeNextNode(node));
}

bool SAPLinkedListIsEmpty(SAPLinkedList *object) {
    return (NULL != object && 0 != SAPLinkedListCount(object));
}

void SAPLinkedListAddContentObject(SAPLinkedList *object, void *contentObject) {
    if (NULL == object) {
        return;
    }
    
    SAPLinkedListNode *node = SAPLinkedListNodeCreateWithContentObject(contentObject);
    SAPLinkedListNodeSetNextNode(node, SAPLinkedListHead(object));
    SAPLinkedListSetHead(object, node);
    object->_count++;
    SAPObjectRelease(node);
}

void SAPLinkedListRemoveContentObject(SAPLinkedList *object, void *contentObject);

void SAPLinkedListRemoveAllContentObjects(SAPLinkedList *object) {
    if (NULL == object) {
        return;
    }
    
    SAPLinkedListSetHead(object, NULL);
    object->_count = 0;
}

bool SAPLinkedListContainsObject(SAPLinkedList *object, void *contentObject);

uint64_t SAPLinkedListCount(SAPLinkedList *object) {
    return SAPObjectIVarGetterSynthesize(object, _count, 0);
}

#pragma mark-
#pragma mark Private Implementations

SAPLinkedListNode *SAPLinkedListHead(SAPLinkedList *object){
    return SAPObjectIVarGetterSynthesize(object, _head, NULL);
}

void SAPLinkedListSetHead(SAPLinkedList *object, SAPLinkedListNode *head){
    SAPObjectRetainSetterSynthesize(object, head);
}