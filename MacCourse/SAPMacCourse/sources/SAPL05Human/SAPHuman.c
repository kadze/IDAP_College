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

#define SAPObjectIVarGetterSynthesize(objectVariableName,ivar) \
return NULL != objectVariableName ? objectVariableName->ivar : NULL

#define SAPObjectIVarSetterSynthesize(objectVariableName, ivar) \
    if (NULL != objectVariableName) { \
        objectVariableName->_##ivar = ivar; \
    }

#pragma mark -
#pragma mark Private declarations

static
void SAPHumanSetGender(SAPHuman *object, SAPGender gender);

static
void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother);

static
void SAPHumanSetFather(SAPHuman *object, SAPHuman *father);

static
void SAPHumanRemoveChild(SAPHuman *parent, SAPHuman *child);

static
void SAPHumanRemoveChildAtIndex(SAPHuman *parent, uint8_t childIndex);

static
void SAPHumanRemoveAllChildren(SAPHuman *object);

static
void SAPHumanSetChildAtIndex(SAPHuman *object, SAPHuman *child, uint8_t childIndex);

static
SAPHuman *SAPHumanChildAtIndex(SAPHuman *object, uint8_t childIndex);

static
void SAPHumanAddChild(SAPHuman *object, SAPHuman *child);

#pragma mark -
#pragma mark Initializations & Deallocation

SAPHuman *SAPHumanCreate(void) {
    SAPHuman *object = SAPObjectCreateOfType(SAPHuman);
    
    return object;
}

SAPHuman *SAPHumanCreateWithParameters(SAPHuman *mother, SAPHuman *father, SAPGender gender) {
    SAPHuman *object = SAPHumanCreate();
    SAPHumanSetMother(object, mother);
    SAPHumanAddChild(mother, object);
    SAPHumanSetFather(object, father);
    SAPHumanAddChild(father, object);
    SAPHumanSetGender(object, gender);
    
    return object;
}

void __SAPHumanDeallocate(SAPHuman *object) {
    SAPHumanSetName(object, NULL);
    SAPHumanDivorce(object);
    SAPHumanRemoveAllChildren(object);
    __SAPObjectDeallocate(object);
}

#pragma mark -
#pragma mark Accessors

char *SAPHumanName(SAPHuman *object) {
    SAPObjectIVarGetterSynthesize(object, _name);
};

void SAPHumanSetName(SAPHuman *object, char *name) {
    if (NULL == object || name == object->_name) {
        return;
    }
    
    if (NULL != object->_name) {
        free(object->_name);
        object->_name = NULL;
    }
    
    if (name) {
        object->_name = strdup(name);
    }
    
}

SAPGender SAPHumanGender(SAPHuman *object) {
    return NULL != object ? object->_gender : 0;
}


uint8_t SAPHumanAge(SAPHuman *object) {
    return NULL != object ? object->_age : 0;
}

void SAPHumanSetAge(SAPHuman *object, uint8_t age) {
    SAPObjectIVarSetterSynthesize(object, age);
}

SAPHuman *SAPHumanPartner(SAPHuman *object) {
    SAPObjectIVarGetterSynthesize(object, _partner);
}

SAPHuman *SAPHumanMother(SAPHuman *object) {
    SAPObjectIVarGetterSynthesize(object, _mother);
}

SAPHuman *SAPHumanFather(SAPHuman *object) {
    SAPObjectIVarGetterSynthesize(object, _father);
}

#pragma mark -
#pragma mark Private implementations

void SAPHumanSetGender(SAPHuman *object, SAPGender gender) {
    SAPObjectIVarSetterSynthesize(object, gender);
}

void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother) {
    SAPObjectIVarSetterSynthesize(object, mother);
}

void SAPHumanSetFather(SAPHuman *object, SAPHuman *father) {
    SAPObjectIVarSetterSynthesize(object, father);
}

void SAPHumanRemoveChild(SAPHuman *parent, SAPHuman *child) {
    if (NULL == parent || NULL == child) {
        return;
    }
    
    SAPHumanGender(parent) == kSAPHumanGenderMale ? SAPHumanSetFather(child, NULL) : SAPHumanSetMother(child, NULL);
    SAPObjectRelease(child);
    
    for (uint8_t childIndex = 0; childIndex < kSAPChildrenLimit; childIndex ++) {
        if (child == SAPHumanChildAtIndex(parent, childIndex)) {
            SAPHumanSetChildAtIndex(parent, NULL, childIndex);
        }
    }
}

void SAPHumanRemoveChildAtIndex(SAPHuman *parent, uint8_t childIndex) {
    if (NULL == parent) {
        
        return;
    }
    
    SAPHuman *child = SAPHumanChildAtIndex(parent, childIndex);
    if (NULL == child) {
        
        return;
    }
    
    SAPHumanGender(parent) == kSAPHumanGenderMale ? SAPHumanSetFather(child, NULL) : SAPHumanSetMother(child, NULL);
    SAPObjectRelease(child);
    SAPHumanSetChildAtIndex(parent, NULL, childIndex);
}

void SAPHumanRemoveAllChildren(SAPHuman *parent) {
    if (NULL == parent) {
        
        return;
    }
    
    for (uint8_t childIndex = 0; childIndex < kSAPChildrenLimit; childIndex++) {
        SAPHumanRemoveChildAtIndex(parent, childIndex);
    }
}

void SAPHumanSetChildAtIndex(SAPHuman *object, SAPHuman *child, uint8_t childIndex) {
    if (NULL != object) {
        object->_children[childIndex] = child;
    }
    
    return;
}

SAPHuman *SAPHumanChildAtIndex(SAPHuman *object, uint8_t childIndex) {
    return NULL != object ? object->_children[childIndex] : NULL;
}

void SAPHumanAddChild(SAPHuman *object, SAPHuman *child) {
    if (NULL == object || NULL == child) {
        return;
    }
    
    for (int childIndex = 0; childIndex < kSAPChildrenLimit; childIndex++) {
        if (NULL == SAPHumanChildAtIndex(object, childIndex)) {
            SAPHumanSetChildAtIndex(object, child, childIndex);
            SAPObjectRetain(child);
            
            return;
        }
    }
}

#pragma mark -
#pragma mark Public implementations

uint8_t SAPHumanChildrenCount(SAPHuman *object) {
    uint8_t childrenCounter = 0;
    if (NULL != object) {
        for (int index = 0; index < kSAPChildrenLimit; index++) {
            if (NULL != SAPHumanChildAtIndex(object, index)) {
                childrenCounter++;
            }
        }
    }
    
    return childrenCounter; //!!!
}

bool SAPHumanIsMarried(SAPHuman *object) {
    return (NULL != object) && (NULL != SAPHumanPartner(object));
}

//////BEHAVIOR IMPLEMENTING FUNCTIONS

SAPHuman *SAPHumanBornChild(SAPHuman *object, SAPGender gender) {
    if (NULL != object && NULL != SAPHumanPartner(object)) {
        SAPHuman *partner = SAPHumanPartner(object);
        SAPHuman *father = (SAPHumanGender(object) == kSAPHumanGenderMale) ? object : partner;
        SAPHuman *mother = (father == object) ? partner : object;
        
        SAPHuman *bornChild = SAPHumanCreateWithParameters(mother, father, gender);
        
        return bornChild;
    }
    
    return NULL;
}


//weak member of connection is female. male-female - retain setter. female-male - assign setter.
bool SAPHumanMarry(SAPHuman *object, SAPHuman *spouse) {
    bool married = false;
    if (NULL == object
       || NULL == spouse
       || SAPHumanGender(object) == SAPHumanGender(spouse)
       || object == spouse) {
        
        return married;
    }
    
    SAPHuman *strong = (SAPHumanGender(object) == kSAPHumanGenderMale) ? object : spouse;
    SAPHuman *weak   = (strong == object) ? spouse : object;
    
    SAPHumanDivorce(strong);
    SAPHumanDivorce(weak);

    strong->_partner = weak;
    SAPObjectRetain(weak);
    weak->_partner = strong;

    married = true;
    
    return married;
}

bool SAPHumanDivorce(SAPHuman *object) {
    bool divorceComplete = false;
    if (NULL == object
       || NULL == SAPHumanPartner(object)) {
        
        return divorceComplete;
    }
    
    SAPHuman *strong = (SAPHumanGender(object) == kSAPHumanGenderMale) ? object : SAPHumanPartner(object);
    SAPHuman *weak   = (strong == object) ? SAPHumanPartner(object) : object;
    
    weak->_partner = NULL;
    strong->_partner = NULL;
    SAPObjectRelease(weak);
   
    divorceComplete = true;
    
    return divorceComplete;
}
