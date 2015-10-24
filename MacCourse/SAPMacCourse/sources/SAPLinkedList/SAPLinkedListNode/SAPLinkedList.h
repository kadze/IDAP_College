//
//  SAPLinkedList.h
//  MacCourse
//
//  Created by S A P on 11/6/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPLinkedList_h
#define SAPLinkedList_h

#include <stdbool.h>
#include "SAPObject.h"
#include "SAPLinkedListNode.h"

typedef struct SAPLinkedList SAPLinkedList;

struct SAPLinkedList{
    SAPObject _super;
    SAPLinkedListNode *_head;
    uint64_t _count;
};

extern
void __SAPLinkedListDeallocate(SAPLinkedList *object);

extern
void *SAPLinkedListFirstContentObject(SAPLinkedList *object);

extern
void SAPLinkedListRemoveFirstContentObject(SAPLinkedList *object);

extern
bool SAPLinkedListIsEmpty(SAPLinkedList *object);

extern
void SAPLinkedListAddContentObject(SAPLinkedList *object, void *contentObject);

extern
void SAPLinkedListRemoveContentObject(SAPLinkedList *object, void *contentObject);

extern
void SAPLinkedListRemoveAllContentObjects(SAPLinkedList *object);

extern
bool SAPLinkedListContainsObject(SAPLinkedList *object, void *contentObject);

extern
uint64_t SAPLinkedListCount(SAPLinkedList *object);

#endif /* SAPLinkedList_h */
