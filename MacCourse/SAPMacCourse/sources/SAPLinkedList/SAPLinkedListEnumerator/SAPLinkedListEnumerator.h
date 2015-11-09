//
//  SAPLinkedListEnumerator.h
//  MacCourse
//
//  Created by Andrey Shevtsov on 11/8/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPLinkedListEnumerator__
#define __MacCourse__SAPLinkedListEnumerator__

#include <stdbool.h>
#include "SAPObject.h"

typedef struct SAPLinkedList SAPLinkedList;

typedef struct SAPLinkedListNode SAPLinkedListNode;

typedef struct {
    SAPObject           _super;
    SAPLinkedList       *_list;
    SAPLinkedListNode   *_currentNode;
    uint64_t _mutationsCount;
    bool _isValid;
} SAPLinkedListEnumerator;

extern
SAPLinkedListEnumerator *SAPLinkedListEnumeratorCreateWithList(SAPLinkedList *list);

extern
void __SAPLinkedListEnumeratorDeallocate(void *object);

extern
void *SAPLinkedListEnumeratorNextObject(SAPLinkedList *list);

extern
bool SAPLinkedListEnumeratorIsValid(SAPLinkedListEnumerator *enumerator);

#endif /* defined(__MacCourse__SAPLinkedListEnumerator__) */
