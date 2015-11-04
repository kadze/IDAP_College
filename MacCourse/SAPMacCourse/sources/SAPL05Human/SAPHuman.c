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

#pragma mark -
#pragma mark Private declarations

static
void SAPHumanSetGender(SAPHuman *object, SAPGender gender);

static
void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother);

static
void SAPHumanSetFather(SAPHuman *object, SAPHuman *father);

static
void SAPHumanSetChildren(SAPHuman *object, SAPDynamicArray *children);

static
void SAPHumanRemoveChild(SAPHuman *parent, SAPHuman *child);

static
void SAPHumanRemoveAllChildren(SAPHuman *object);

static
SAPHuman *SAPHumanChildAtIndex(SAPHuman *object, uint8_t childIndex);

static
void SAPHumanAddChild(SAPHuman *object, SAPHuman *child);

static
SAPHuman *SAPHumanWhoIsStronger(SAPHuman *human1, SAPHuman *human2);

#pragma mark -
#pragma mark Initializations & Deallocation

void __SAPHumanDeallocate(SAPHuman *object) {
    SAPHumanSetName(object, NULL);
    SAPHumanDivorce(object);
    SAPHumanRemoveAllChildren(object);
    SAPHumanSetChildren(object, NULL);
    __SAPObjectDeallocate(object);
}

SAPHuman *SAPHumanCreate(SAPGender gender) {
    SAPHuman *result = SAPObjectCreateOfType(SAPHuman);
    SAPHumanSetGender(result, gender);
    SAPDynamicArray *array = SAPDynamicArrayCreate();
    SAPHumanSetChildren(result, array);
    SAPObjectRelease(array);
    
    return result;
}

SAPHuman *SAPHumanCreateWithParameters(SAPHuman *parent, SAPGender gender) {
    if (NULL == parent
        || SAPHumanGender(parent) == SAPHumanGender(SAPHumanPartner(parent)))
    {
        return NULL;
    }
    
    SAPHuman *object = SAPHumanCreate(gender);
    SAPHuman *father = kSAPHumanGenderMale == SAPHumanGender(parent) ? parent : SAPHumanPartner(parent);
    SAPHuman *mother = parent == father ? SAPHumanPartner(parent) : parent;
    SAPHumanSetMother(object, mother);
    SAPHumanSetFather(object, father);
    
    return object;
}

#pragma mark -
#pragma mark Accessors

SAPString *SAPHumanName(SAPHuman *object) {
    return SAPObjectIVarGetterSynthesize(object, _name, NULL);
}

void SAPHumanSetName(SAPHuman *object, SAPString *name) {
    SAPObjectRetainSetterSynthesize(object, name);
}

SAPDynamicArray *SAPHumanChildren(SAPHuman *object) {
    return SAPObjectIVarGetterSynthesize(object, _children, NULL);
}

void SAPHumanSetChildren(SAPHuman *object, SAPDynamicArray *children) {
    SAPObjectRetainSetterSynthesize(object, children);
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
    return SAPObjectIVarGetterSynthesize(object, _partner, NULL);
}

SAPHuman *SAPHumanMother(SAPHuman *object) {
    return SAPObjectIVarGetterSynthesize(object, _mother, NULL);
}

SAPHuman *SAPHumanFather(SAPHuman *object) {
    return SAPObjectIVarGetterSynthesize(object, _father, NULL);
}

void SAPHumanSetGender(SAPHuman *object, SAPGender gender) {
    SAPObjectIVarSetterSynthesize(object, gender);
}

void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother) {
    if (NULL == object
        || SAPHumanMother(object) == mother
        || kSAPHumanGenderFemale != SAPHumanGender(mother))
    {
        return;
    }
    
    SAPHuman *currentMother = SAPHumanMother(object);
    if (currentMother) {
        SAPHumanRemoveChild(currentMother, object);
    }
    
    SAPObjectIVarSetterSynthesize(object, mother);
    SAPHumanAddChild(mother, object);
}

void SAPHumanSetFather(SAPHuman *object, SAPHuman *father) {
    if (NULL == object
        || SAPHumanFather(object) == father
        || kSAPHumanGenderMale != SAPHumanGender(father))
    {
        return;
    }
    
    SAPHuman *currentMother = SAPHumanMother(object);
    if (currentMother) {
        SAPHumanRemoveChild(currentMother, object);
    }
    
    SAPObjectIVarSetterSynthesize(object, father);
    SAPHumanAddChild(father, object);
}

#pragma mark -
#pragma mark Private implementations

void SAPHumanRemoveChild(SAPHuman *parent, SAPHuman *child) {
    if (NULL == parent || NULL == child || false == SAPHumanHasChild(parent, child)) {
        return;
    }
    
    if (SAPHumanGender(parent) == kSAPHumanGenderMale) {
        SAPHumanSetFather(child, NULL);
    } else {
        SAPHumanSetMother(child, NULL);
    }
    
    SAPDynamicArrayRemoveObject(SAPHumanChildren(parent), child);
}

void SAPHumanRemoveAllChildren(SAPHuman *parent) {
    if (parent) {
        SAPDynamicArrayRemoveAll(SAPHumanChildren(parent));
    }
}

SAPHuman *SAPHumanChildAtIndex(SAPHuman *object, uint8_t childIndex) {
    return (NULL != object && kSAPChildrenLimit > childIndex)
            ? SAPDynamicArrayValueAtIndex(SAPHumanChildren(object), childIndex)
            : NULL;
}

void SAPHumanAddChild(SAPHuman *object, SAPHuman *child) {
    if (false == SAPHumanHasChild(object, child)) {
        SAPDynamicArrayAddObject(SAPHumanChildren(object), child);
    }
}

SAPHuman *SAPHumanWhoIsStronger(SAPHuman *human1, SAPHuman *human2) {
    if (human1 && human2 && human1 != human2 && SAPHumanGender(human1) != SAPHumanGender(human2)) {
        return (SAPHumanGender(human1) == kSAPHumanGenderMale) ? human1 : human2;
    }
    
    return NULL;
}

#pragma mark -
#pragma mark Public implementations

uint SAPHumanChildrenCount(SAPHuman *object) {
    return SAPDynamicArrayCount(SAPHumanChildren(object));
}

bool SAPHumanIsMarried(SAPHuman *object) {
    return (NULL != SAPHumanPartner(object));
}

bool SAPHumanHasChild(SAPHuman *object, SAPHuman *child) {
    SAPReturnValueIfObjectNULL(false);
    
    return SAPDynamicArrayContains(SAPHumanChildren(object), child);
}

//////BEHAVIOR IMPLEMENTING FUNCTIONS

SAPHuman *SAPHumanCreateChild(SAPHuman *object, SAPGender gender) {
    if (NULL != object && NULL != SAPHumanPartner(object)) {
        
        SAPHuman *bornChild = SAPHumanCreateWithParameters(object, gender);
        
        return bornChild;
    }
    
    return NULL;
}


//weak member of connection is female. male-female - retain setter. female-male - assign setter.
void SAPHumanMarry(SAPHuman *object, SAPHuman *partner) {
    if (NULL == object
       || NULL == partner
       || SAPHumanGender(object) == SAPHumanGender(partner)
       || object == partner
       || SAPHumanPartner(object) == partner)
    {
        return;
    }
    
    SAPHumanDivorce(object);
    
    SAPHuman *strong = SAPHumanWhoIsStronger(object, partner);
    SAPHuman *weak = object == strong ? partner : object;
    
    strong->_partner = weak;
    SAPObjectRetain(weak);
    weak->_partner = strong;
}

void SAPHumanDivorce(SAPHuman *object) {
    SAPHuman *partner = SAPHumanPartner(object);
    if (NULL == object || NULL == partner) {
        return;
    }
    
    SAPHuman *strong = SAPHumanWhoIsStronger(object, partner);
    SAPHuman *weak = object == strong ? partner : object;
    
    weak->_partner = NULL;
    strong->_partner = NULL;
    SAPObjectRelease(weak);
    
}

