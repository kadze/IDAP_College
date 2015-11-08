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
#include "SAPLinkedListEnumerator.h"

typedef struct SAPLinkedList SAPLinkedList;

struct SAPLinkedList{
    SAPObject _super;
    SAPLinkedListNode *_head;
    uint64_t _count;
    uint64_t _mutationsCount;
};

extern
SAPLinkedListEnumerator *SAPLinkedListEnumeratorFromList(SAPLinkedList *list);

extern
void __SAPLinkedListDeallocate(SAPLinkedList *list);

extern
void *SAPLinkedListFirstObject(SAPLinkedList *list);

extern
void SAPLinkedListRemoveFirstObject(SAPLinkedList *list);

extern
void *SAPLinkedListObjectBeforeObject(SAPLinkedList *list, void *object);

extern
bool SAPLinkedListIsEmpty(SAPLinkedList *list);

extern
void SAPLinkedListAddObject(SAPLinkedList *list, void *object);

extern
void SAPLinkedListRemoveObject(SAPLinkedList *list, void *object);

extern
void SAPLinkedListRemoveAllObjects(SAPLinkedList *list);

extern
bool SAPLinkedListContainsObject(SAPLinkedList *list, void *object);

extern
uint64_t SAPLinkedListCount(SAPLinkedList *list);

#endif /* SAPLinkedList_h */
