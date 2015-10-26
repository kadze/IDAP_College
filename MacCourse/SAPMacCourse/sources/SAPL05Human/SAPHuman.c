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
#include "SAPMacro.h"

#define DetermineRolesOfPartners(strongPartnerName, weakPartnerName) \
    SAPHuman *strongPartnerName = (SAPHumanGender(object) == kSAPHumanGenderMale) ? object : partner;\
    SAPHuman *weakPartnerName   = (strongPartnerName == object) ? partner : object;

#pragma mark -
#pragma mark Private declarations

static
void SAPHumanSetGender(SAPHuman *object, SAPGender gender);

static
void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother);

static
void SAPHumanSetFather(SAPHuman *object, SAPHuman *father);

static
void SAPHumanSetChildren(SAPHuman *object, SAPArray *children);

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

void __SAPHumanDeallocate(SAPHuman *object) {
    SAPHumanSetName(object, NULL);
    SAPHumanDivorce(object);
    SAPHumanRemoveAllChildren(object);
    SAPHumanSetChildren(object, NULL);
    __SAPObjectDeallocate(object);
}

SAPHuman *SAPHumanCreate(void) {
    SAPHuman *result = SAPObjectCreateOfType(SAPHuman);
    SAPHumanSetChildren(result, SAPArrayCreate());
    
    return result;
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

#pragma mark -
#pragma mark Accessors

SAPString *SAPHumanName(SAPHuman *object) {
    SAPObjectIVarGetterSynthesize(object, _name, NULL);
}

void SAPHumanSetName(SAPHuman *object, SAPString *name) {
    SAPObjectRetainingSetterSynthesize(object, name)
}

void SAPHumanSetChildren(SAPHuman *object, SAPArray *children) {
    SAPObjectRetainingSetterSynthesize(object, children)
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
    SAPObjectIVarGetterSynthesize(object, _partner, NULL);
}

SAPHuman *SAPHumanMother(SAPHuman *object) {
    SAPObjectIVarGetterSynthesize(object, _mother, NULL);
}

SAPHuman *SAPHumanFather(SAPHuman *object) {
    SAPObjectIVarGetterSynthesize(object, _father, NULL);
}

void SAPHumanSetGender(SAPHuman *object, SAPGender gender) {
    SAPObjectIVarSetterSynthesize(object, gender);
}

void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother) {
    SAPObjectIVarSetterSynthesize(object, mother);
}

void SAPHumanSetFather(SAPHuman *object, SAPHuman *father) {
    SAPObjectIVarSetterSynthesize(object, father);
}

#pragma mark -
#pragma mark Private implementations

void SAPHumanRemoveChild(SAPHuman *parent, SAPHuman *child) {
    if (NULL == parent || NULL == child) {
        return;
    }
    //WHAT IF HASN'T CHILD?????????????????
    SAPHumanGender(parent) == kSAPHumanGenderMale ? SAPHumanSetFather(child, NULL) : SAPHumanSetMother(child, NULL);
    SAPObjectRelease(child);
    
    for (uint8_t childIndex = 0; childIndex < kSAPChildrenLimit; childIndex ++) {
        if (child == SAPHumanChildAtIndex(parent, childIndex)) {
            SAPHumanSetChildAtIndex(parent, NULL, childIndex);
        }
    }
}

void SAPHumanRemoveChildAtIndex(SAPHuman *parent, uint8_t childIndex) {
    if (NULL == parent || kSAPChildrenLimit <= childIndex) {
        return;
    }
    
    SAPHuman *child = SAPHumanChildAtIndex(parent, childIndex);
    if (NULL != child) {
        SAPHumanGender(parent) == kSAPHumanGenderMale ? SAPHumanSetFather(child, NULL) : SAPHumanSetMother(child, NULL);
        SAPObjectRelease(child);
        SAPHumanSetChildAtIndex(parent, NULL, childIndex);
    }
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
    if (NULL != object
        && kSAPChildrenLimit > childIndex
        && child != SAPHumanChildAtIndex(object, childIndex)
        && NULL == SAPHumanChildAtIndex(object, childIndex))
    {
        SAPArraySetValueAtIndex(object->_children, child, childIndex);
    }
    
    return;
}

SAPHuman *SAPHumanChildAtIndex(SAPHuman *object, uint8_t childIndex) {
    return (NULL != object && kSAPChildrenLimit > childIndex)
            ? SAPArrayValueAtIndex(object->_children, childIndex)
            : NULL;
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
    childrenCounter = SAPArrayNotNullElementsCount(object->_children);
    
    return childrenCounter;
}

bool SAPHumanIsMarried(SAPHuman *object) {
    return (NULL != object) && (NULL != SAPHumanPartner(object));
}

//////BEHAVIOR IMPLEMENTING FUNCTIONS

SAPHuman *SAPHumanBornChild(SAPHuman *object, SAPGender gender) {
    if (NULL != object && NULL != SAPHumanPartner(object)) {
        SAPHuman *partner = SAPHumanPartner(object);
        DetermineRolesOfPartners(father, mother)
        
        SAPHuman *bornChild = SAPHumanCreateWithParameters(mother, father, gender);
        
        return bornChild;
    }
    
    return NULL;
}


//weak member of connection is female. male-female - retain setter. female-male - assign setter.
bool SAPHumanMarry(SAPHuman *object, SAPHuman *partner) {
    bool married = false;
    if (NULL == object
       || NULL == partner
       || SAPHumanGender(object) == SAPHumanGender(partner)
       || object == partner)
    {
        return married;
    }
    
    DetermineRolesOfPartners(strong, weak)
    
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
    SAPHuman *partner = SAPHumanPartner(object);
    if (NULL == object
        || NULL == partner)
    {
        return divorceComplete;
    }
    
    DetermineRolesOfPartners(strong, weak)
    
    weak->_partner = NULL;
    strong->_partner = NULL;
    SAPObjectRelease(weak);
   
    divorceComplete = true;
    
    return divorceComplete;
}

