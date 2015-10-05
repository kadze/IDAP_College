//
//  SAPHumanObject.c
//  MacCourse
//
//  Created by SAP on 10/4/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//



//#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "SAPHumanObject.h"

#pragma mark --
#pragma mark Private declarations


#pragma mark --
#pragma mark Private implementations

SAPHumanObject *SAPHumanObjectCreate(void){
    SAPHumanObject *humanObject = malloc(sizeof(SAPHumanObject));
    assert(humanObject != NULL);
    return humanObject;
}

void SAPHumanObjectDeallocate(SAPHumanObject *humanObject){
    free(humanObject);
}

char *SAPHumanObjectName(SAPHumanObject *humanObject){
    return (*humanObject).name;
};

void SAPHumanObjectSetName(SAPHumanObject *humanObject, char *name){
    humanObject->name = name;
}

int SAPHumanObjectAge(SAPHumanObject *humanObject){
    return (*humanObject).age;
}

void SAPHumanObjectSetAge(SAPHumanObject *humanObject, int *age){
    humanObject->age = *age;
}

int SAPHumanObjectChildrenNumber(SAPHumanObject *humanObject){
    return (*humanObject).childrenNumber;;
}

void SAPHumanObjectSetChildrenNumber(SAPHumanObject *humanObject, int *childrenNumber){
    humanObject->childrenNumber = *childrenNumber;
}

SAPHumanObject *SAPHumanObjectPartner(SAPHumanObject *humanObject){
    return humanObject->partner;
}

void SAPHumanObjectSetPartner(SAPHumanObject *humanObject, SAPHumanObject *partner){
    humanObject->partner = partner;
}

SAPHumanObject *SAPHunmanObjectMother(SAPHumanObject *humanObject){
    return humanObject->mother;
}

void SAPHumanObjectSetMother(SAPHumanObject *humanObject, SAPHumanObject *mother){
    humanObject->mother = mother;
}

SAPHumanObject *SAPHunmanObjectFather(SAPHumanObject *humanObject){
    return humanObject->father;
}

void SAPHumanObjectSetFather(SAPHumanObject *humanObject, SAPHumanObject *father){
    humanObject->father = father;
}

//SAPHumanObject *SAPHumanObjectChildren(SAPHumanObject *humanObject){
//    static SAPHumanObject children[20];
//    children[20] = humanObject->children;
//    return children;
//}

bool SAPHumanObjectIsMarried(SAPHumanObject *humanObject){
    return humanObject->isMarried;
}

void SAPHumanObjectSetIsMarried(SAPHumanObject *humanObject, bool isMarried){
    humanObject->isMarried = isMarried;
}

void SAPHumanObjectMarry(SAPHumanObject *humanObject, SAPHumanObject *spouse){
    humanObject->isMarried = true;
    humanObject->partner = spouse;
}

void SAPHumanObjectDivorce(SAPHumanObject *humanObject){
    humanObject->isMarried = false;
    humanObject->partner = NULL;
}

//SAPHumanObject *SAPHumanObjectProcreate(SAPHumanObject *humanObject){
//    SAPHumanObject *child = SAPHumanObjectCreate();
//    children
//}
size_t size = sizeof(SAPHumanObject);