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
    SAPLinkedListNodeSetContentObject(object, NULL);
    SAPLinkedListNodeSetNextNode(object, NULL);
    
    __SAPObjectDeallocate(object);
}

SAPLinkedListNode *SAPDynamicArrayCreateWithContentObject(SAPObject *contentObject) {
    SAPLinkedListNode *result =  SAPObjectCreateOfType(SAPLinkedListNode);
    SAPLinkedListNodeSetContentObject(result, contentObject);
    
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

void *SAPLinkedListNodeContentObject(SAPLinkedListNode *object) {
    return SAPObjectIVarGetterSynthesize(object, _contentObject, NULL);
}

void SAPLinkedListNodeSetContentObject(SAPLinkedListNode *object, void *contentObject) {
    if (object == contentObject) {
        return;
    }
    
    SAPObjectRetainSetterSynthesize(object, contentObject);
}