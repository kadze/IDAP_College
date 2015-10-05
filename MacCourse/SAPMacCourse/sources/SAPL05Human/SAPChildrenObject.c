//
//  SAPChildren.c
//  MacCourse
//
//  Created by SAP on 10/5/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

//#include "SAPChildren.h"
#include <stdlib.h>
#include "SAPHumanObject.h"
#include "SAPChildrenObject.h"

struct SAPChildrenObject{
    SAPHumanObject *children[20];
};

SAPChildrenObject *SAPChildrenObjectCreate(){
    SAPChildrenObject *childrenObjectPointer = malloc(sizeof(SAPChildrenObject));
    SAPChildrenObject childrenObject = *childrenObjectPointer;
    memset(childrenObject.children, NULL, sizeof(childrenObject.children));
    
    return childrenObjectPointer;
}

//SAPHumanObject *SAPChildrenObjectChild(){
//    SAPHumanObject allchildren[20];
//    SAPHumanObject *children[20] = malloc(sizeof(allchildren));
//}
//
//int SAPHumanObjectChildrenNumber(SAPChildrenObject *childrenObject){
//   static SAPHumanObject children[20] = *(childrenObject->children);
//    return;
//}

SAPHumanObject *SAPChildrenObjectChildren(SAPChildrenObject *childrenObject){
    SAPHumanObject *children = (SAPHumanObject *)malloc(sizeof(SAPHumanObject) * 20);
    
    return children;
}
