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
void *SAPLinkedListHead(SAPLinkedList *object);

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
    return SAPLinkedListHead(object); //shirt either in the name or in this body or in SAPLinkedListHead!!!!!!!!!!!!!!!!
}

void SAPLinkedListRemoveFirstContentObject(SAPLinkedList *object);

bool SAPLinkedListIsEmpty(SAPLinkedList *object);

void SAPLinkedListAddContentObject(SAPLinkedList *object, void *contentObject);

void SAPLinkedListRemoveContentObject(SAPLinkedList *object, void *contentObject);

void SAPLinkedListRemoveAllObjects(SAPLinkedList *object);

bool SAPLinkedListContainsObject(SAPLinkedList *object, void *contentObject);

uint64_t SAPLinkedListCount(SAPLinkedList *object);

#pragma mark-
#pragma mark Private Implementations

void *SAPLinkedListHead(SAPLinkedList *object){
    return SAPObjectIVarGetterSynthesize(object, _head, NULL);
}

void SAPLinkedListSetHead(SAPLinkedList *object, SAPLinkedListNode *head){
    
}