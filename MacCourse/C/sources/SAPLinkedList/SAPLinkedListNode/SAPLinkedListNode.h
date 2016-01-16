//
//  SAPLinkedListNode.h
//  MacCourse
//
//  Created by S A P on 11/6/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPLinkedListNode_h
#define SAPLinkedListNode_h

#include "SAPObject.h"

typedef struct SAPLinkedListNode SAPLinkedListNode;

struct SAPLinkedListNode{
    SAPObject _super;
    void *_object;
    SAPLinkedListNode *_nextNode;
};

extern
void __SAPLinkedListNodeDeallocate(SAPLinkedListNode *object);

extern
SAPLinkedListNode *SAPLinkedListNodeCreateWithObject(void *contentObject);

extern
SAPLinkedListNode *SAPLinkedListNodeNextNode(SAPLinkedListNode *object);

extern
void SAPLinkedListNodeSetNextNode(SAPLinkedListNode *object, SAPLinkedListNode *nextNode);

extern
void *SAPLinkedListNodeObject(SAPLinkedListNode *object);

extern
void SAPLinkedListNodeSetObject(SAPLinkedListNode *object, void *contentObject);

#endif /* SAPLinkedListNode_h */
