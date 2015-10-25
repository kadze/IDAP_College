//
//  SAPLinkedListNode.c
//  MacCourse
//
//  Created by S A P on 11/6/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPLinkedListNode.h"
#include "SAPMacro.h"

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPLinkedListNodeDeallocate(SAPLinkedListNode *object) {
    SAPLinkedListNodeSetObject(object, NULL);
    SAPLinkedListNodeSetNextNode(object, NULL);
    
    __SAPObjectDeallocate(object);
}

SAPLinkedListNode *SAPLinkedListNodeCreateWithObject(void *contentObject) {
    SAPLinkedListNode *result =  SAPObjectCreateOfType(SAPLinkedListNode);
    SAPLinkedListNodeSetObject(result, contentObject);
    
    return result;
}

#pragma mark -
#pragma mark Accessors

SAPLinkedListNode *SAPLinkedListNodeNextNode(SAPLinkedListNode *object) {
    return SAPObjectIVarGetterSynthesize(object, _nextNode, NULL);
}

void SAPLinkedListNodeSetNextNode(SAPLinkedListNode *object, SAPLinkedListNode *nextNode) {
    SAPObjectRetainSetterSynthesize(object, nextNode);
}

void *SAPLinkedListNodeObject(SAPLinkedListNode *object) {
    return SAPObjectIVarGetterSynthesize(object, _object, NULL);
}

void SAPLinkedListNodeSetObject(SAPLinkedListNode *object, void *contentObject) {
    if (object == contentObject) {
        return;
    }
    
    SAPObjectRetainSetterSynthesize(object, contentObject);
}