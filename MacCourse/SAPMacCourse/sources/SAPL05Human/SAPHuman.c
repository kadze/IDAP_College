//
//  SAPHuman.c
//  MacCourse
//
//  Created by SAP on 10/4/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//



//#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "SAPHuman.h"

#pragma mark --
#pragma mark Private declarations


#pragma mark --
#pragma mark Private implementations

SAPHuman *SAPHumanCreate(void){
    SAPHuman *object = malloc(sizeof(SAPHuman));
    assert(object != NULL);
    return object;
}

void SAPHumanDeallocate(SAPHuman *object){
    free(object);
}

char *SAPHumanName(SAPHuman *object){
    return (*object)._name;
};

void SAPHumanSetName(SAPHuman *object, char *name){
    object->_name = name;
}

int SAPHumanAge(SAPHuman *object){
    return (*object)._age;
}

void SAPHumanSetAge(SAPHuman *object, int *age){
    object->_age = *age;
}

int SAPHumanChildrenCount(SAPHuman *object){
    return 0; //!!!
}

SAPHuman *SAPHumanPartner(SAPHuman *object){
    return object->_partner;
}

void SAPHumanSetPartner(SAPHuman *object, SAPHuman *partner){
    object->_partner = partner;
}

SAPHuman *SAPHunmanObjectMother(SAPHuman *object){
    return object->_mother;
}

void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother){
    object->_mother = mother;
}

SAPHuman *SAPHunmanObjectFather(SAPHuman *object){
    return object->_father;
}

void SAPHumanSetFather(SAPHuman *object, SAPHuman *father){
    object->_father = father;
}

//SAPHuman *SAPHumanChildren(SAPHuman *object){
//    static SAPHuman children[20];
//    children[20] = object->children;
//    return children;
//}

bool SAPHumanIsMarried(SAPHuman *object){
    return false; //!!!
}

void SAPHumanMarry(SAPHuman *object, SAPHuman *spouse){
    object->_isMarried = true;
    object->_partner = spouse;
}

void SAPHumanDivorce(SAPHuman *object){
    object->_isMarried = false;
    object->_partner = NULL;
}

//SAPHuman *SAPHumanProcreate(SAPHuman *object){
//    SAPHuman *child = SAPHumanCreate();
//    children
//}