//
//  SAPHuman.c
//  MacCourse
//
//  Created by SAP on 10/4/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//


#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "SAPHuman.h"
#include "SAPObject.h"

#define SAPObjectIVarGetterSynthesize(ivar) \
return NULL != object ? object->ivar : NULL

#pragma mark --
#pragma mark Private declarations

static
void SAPHumanSetGender(SAPHuman *object, SAPGender gender);
static
void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother);
static
void SAPHumanSetFather(SAPHuman *object, SAPHuman *father);
static
void SAPHumanRemoveAllChildren(SAPHuman *object);
static
void SAPSetChildAtIndex(SAPHuman *object, SAPHuman *child, int childIndex);
static
SAPHuman *SAPChildAtIndex(SAPHuman *object, int childIndex);

#pragma mark --
#pragma mark Private implementations

static
void SAPHumanSetGender(SAPHuman *object, SAPGender gender){
    if(NULL != object){
        object->_gender = gender;
    }
}

static
void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother){
    if(NULL != object){
        object->_mother = mother;
    }
}

static
void SAPHumanSetFather(SAPHuman *object, SAPHuman *father){
    if(NULL != object){
        object->_father = father;
    }
}

static
void SAPHumanRemoveAllChildren(SAPHuman *parent){
    for (int childIndex = 0; childIndex < kSAPChildrenLimit; childIndex++) {
        SAPHuman *child = SAPChildAtIndex(parent, childIndex);
        if(NULL == child){
            continue;
        }
        SAPHumanGender(parent) == SAPHumanGenderMale ? SAPHumanSetFather(child, NULL)
                                                     : SAPHumanSetMother(child, NULL);
        SAPObjectRelease(child);
        SAPSetChildAtIndex(parent, NULL, childIndex);
        
    }
}

static
void SAPSetChildAtIndex(SAPHuman *object, SAPHuman *child, int childIndex){
    if(NULL != object){
        object->_children[childIndex] = child;
    }
    
    return;
}

static
SAPHuman *SAPChildAtIndex(SAPHuman *object, int childIndex){
    return NULL != object ? object->_children[childIndex] : NULL;
}

static
void SAPHumanAddChild(SAPHuman *object, SAPHuman *child){
    if(NULL == object || NULL == child){
        return;
    }
    for (int childIndex = 0; childIndex < kSAPChildrenLimit; childIndex++) {
        if(NULL == SAPChildAtIndex(object, childIndex)){
            SAPSetChildAtIndex(object, child, childIndex);
            SAPObjectRetain(child);
            return;
        }
    }
}


#pragma mark --
#pragma mark Public implementations

SAPHuman *SAPHumanCreate(void){
    SAPHuman *object = SAPObjectCreateOfType(SAPHuman);
    //SAPHuman *object = __SAPObjectCreate(sizeof(SAPHuman), __SAPHumanDeallocate);
    
    return object;
}

SAPHuman *SAPHumanCreateWithParameters(SAPHuman *mother, SAPHuman *father, SAPGender gender){
    SAPHuman *object = SAPHumanCreate();
    SAPHumanSetMother(object, mother);
    SAPHumanAddChild(mother, object);
    SAPHumanSetFather(object, father);
    SAPHumanAddChild(father, object);
    SAPHumanSetGender(object, gender);
    
    return object;
}

void __SAPHumanDeallocate(SAPHuman *object){
    SAPHumanSetName(object, NULL);
    SAPHumanDivorce(object);
    SAPHumanRemoveAllChildren(object);
    __SAPObjectDeallocate(object);
}

//memory management functions



//void SAPHumanRelease(SAPHuman *object){
//    if(NULL != object){
//        if(0 == --(object->_referenceCount)){
//            __SAPHumanDeallocate(object);
//        }
//    }
//}
//
//void SAPHumanRetain(SAPHuman *object){
//    if(object){
//        object->_referenceCount++;
//    }
//}

#pragma mark -
#pragma mark Accessors

char *SAPHumanName(SAPHuman *object){
    SAPObjectIVarGetterSynthesize(_name);
};

void SAPHumanSetName(SAPHuman *object, char *name){
    if(NULL != object){
        if(NULL !=object->_name){
            free(object->_name);
            object->_name = NULL;
        }
        if(name){
            object->_name = strdup(name);
        }
    }
}

SAPGender SAPHumanGender(SAPHuman *object){
    return NULL != object ? object->_gender : 0;
}


uint8_t SAPHumanAge(SAPHuman *object){
    return NULL != object ? object->_age : 0;
}

void SAPHumanSetAge(SAPHuman *object, uint8_t age){
    if (NULL != object){
        object->_age = age;
    }
}

int SAPHumanChildrenCount(SAPHuman *object){
    int childrenCounter = 0;
    if(NULL != object){
        for (int index = 0; index < kSAPChildrenLimit; index++) {
            if(NULL != SAPChildAtIndex(object, index)){
                childrenCounter++;
            }
        }
    }
    
    return childrenCounter; //!!!
}

SAPHuman *SAPHumanPartner(SAPHuman *object){
    SAPObjectIVarGetterSynthesize(_partner);
}

SAPHuman *SAPHumanMother(SAPHuman *object){
    SAPObjectIVarGetterSynthesize(_mother);
}

SAPHuman *SAPHumanFather(SAPHuman *object){
    SAPObjectIVarGetterSynthesize(_father);
}

bool SAPHumanIsMarried(SAPHuman *object){
    return (NULL != object) && (NULL != SAPHumanPartner(object));
}

//behavior umplementing functions

SAPHuman *SAPHumanBornChild(SAPHuman *object, SAPGender gender){
    if(NULL != object && NULL != SAPHumanPartner(object)){
        SAPHuman *father = (SAPHumanGender(object) == SAPHumanGenderMale) ? object : SAPHumanPartner(object);
        SAPHuman *mother = (father == object) ? SAPHumanPartner(object) : object;
        
        SAPHuman *bornChild = SAPHumanCreateWithParameters(mother, father, gender);
        
        return bornChild;
    }
    
    return NULL;
}


//weak member of connection is female. male-female - retain setter. female-male - assign setter.
bool SAPHumanMarry(SAPHuman *object, SAPHuman *spouse){
    bool married = false;
    if(NULL == object
       || NULL == spouse
       || SAPHumanGender(object) == SAPHumanGender(spouse)
       || object == spouse){
        
        return married;
    }
    
    SAPHuman *strong = (SAPHumanGender(object) == SAPHumanGenderMale) ? object : spouse;
    SAPHuman *weak   = (strong == object) ? spouse : object;
    
    SAPHumanDivorce(strong);
    SAPHumanDivorce(weak);

    strong->_partner = weak;
    SAPObjectRetain(weak);
    weak->_partner = strong;

    married = true;
    
    return married;
}

bool SAPHumanDivorce(SAPHuman *object){
    bool divorceComplete = false;
    if(NULL == object
       || NULL == SAPHumanPartner(object)){
        return divorceComplete;
    }
    
    SAPHuman *strong = (SAPHumanGender(object) == SAPHumanGenderMale) ? object : SAPHumanPartner(object);
    SAPHuman *weak   = (strong == object) ? SAPHumanPartner(object) : object;
    
    weak->_partner = NULL;
    strong->_partner = NULL;
    SAPObjectRelease(weak);
   
    divorceComplete = true;
    
    return divorceComplete;
}

