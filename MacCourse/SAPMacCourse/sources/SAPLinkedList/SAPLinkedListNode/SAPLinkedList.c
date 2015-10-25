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
SAPLinkedListNode *SAPLinkedListHead(SAPLinkedList *list);

static
void SAPLinkedListSetHead(SAPLinkedList *list, SAPLinkedListNode *head);

static
void SAPLinkedListSetCount(SAPLinkedList *list, uint64_t count);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPLinkedListDeallocate(SAPLinkedList *list) {
    SAPLinkedListSetHead(list, NULL);
    
    __SAPObjectDeallocate(list);
}

#pragma mark-
#pragma mark Public Implementations

void *SAPLinkedListFirstObject(SAPLinkedList *list){
    SAPLinkedListNode *node = SAPLinkedListHead(list);
    
    return  SAPLinkedListNodeObject(node);
}

void SAPLinkedListRemoveFirstObject(SAPLinkedList *list) {
    SAPLinkedListNode *node = SAPLinkedListHead(list);
    SAPLinkedListSetHead(list, SAPLinkedListNodeNextNode(node));
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
    return (NULL != list && 0 != SAPLinkedListCount(list));
}

void SAPLinkedListAddObject(SAPLinkedList *list, void *object) {
    if (NULL == list) {
        return;
    }
    
    SAPLinkedListNode *node = SAPLinkedListNodeCreateWithObject(object);
    SAPLinkedListNodeSetNextNode(node, SAPLinkedListHead(list));
    SAPLinkedListSetHead(list, node);
    list->_count++;
    SAPObjectRelease(node);
}

void SAPLinkedListRemoveObject(SAPLinkedList *list, void *object) {
    if (NULL == list || SAPLinkedListIsEmpty(list)) {
        return;
    }
    SAPLinkedListNode *node = SAPLinkedListHead(list);
    SAPLinkedListNode *previousNode = NULL;
    while (NULL != node) {
        void *currentObject = SAPLinkedListNodeObject(node);
        if (object == currentObject) {
            SAPLinkedListNode *nextNode = SAPLinkedListNodeNextNode(node);
            SAPLinkedListNodeSetNextNode(previousNode, nextNode);
            list->_count--;
            node = nextNode;
        }
        
        previousNode = node;
        node = SAPLinkedListNodeNextNode(node);
    }
    
}

void SAPLinkedListRemoveAllObjects(SAPLinkedList *list) {
    if (NULL == list) {
        return;
    }
    
    SAPLinkedListSetHead(list, NULL);
    list->_count = 0;
}

bool SAPLinkedListContainsObject(SAPLinkedList *list, void *object) {
    bool result = false;
    if (NULL == list) {
        return result;
    }
    
    
    SAPLinkedListNode *node = SAPLinkedListHead(list);
    while (NULL != node) {
        if (object == node) {
            result = true;
            
            break;
        }
        
        node = SAPLinkedListNodeNextNode(node);
    }
    
    return result;
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
    SAPObjectIVarSetterSynthesize(list, count);
}