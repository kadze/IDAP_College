//
//  SAPLinkedListPrivate.h
//  MacCourse
//
//  Created by S A P on 11/6/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPLinkedListPrivate_h
#define SAPLinkedListPrivate_h

#include "SAPLinkedList.h"

typedef struct SAPLinkedList SAPLinkedList;

extern
uint64_t SAPLinkedListMutationsCount(SAPLinkedList *list);

extern
void SAPLinkedListSetMutationsCount(SAPLinkedList *list, uint64_t count);

extern
SAPLinkedListNode *SAPLinkedListHead(SAPLinkedList *list);

extern
void SAPLinkedListSetHead(SAPLinkedList *list, SAPLinkedListNode *head);


#endif /* SAPLinkedListPrivate_h */
