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
    if (NULL == parent) {
        return NULL;
    }
    
    SAPHuman *partner = SAPHumanPartner(parent);
    if ( NULL == partner || SAPHumanGender(parent) == SAPHumanGender(partner)) {
        return NULL;
    }
    
    SAPHuman *child = SAPHumanCreate(gender);
    SAPHumanAddChild(parent, child);
    SAPHumanAddChild(partner, child);
    
    return child;
}

SAPHuman *SAPHumanCreateChild(SAPHuman *object, SAPGender gender) {
    if (NULL != object && NULL != SAPHumanPartner(object)) {
        return SAPHumanCreateWithParameters(object, gender);;
    }
    
    return NULL;
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
//    if (NULL == object
//        || SAPHumanMother(object) == mother
//        || kSAPHumanGenderFemale != SAPHumanGender(mother))
//    {
//        return;
//    }
    
//    SAPHuman *currentMother = SAPHumanMother(object);
//    if (currentMother) {
//        SAPHumanRemoveChild(currentMother, object);
//    }
    
    SAPObjectIVarSetterSynthesize(object, mother);
}

void SAPHumanSetFather(SAPHuman *object, SAPHuman *father) {
//    if (NULL == object
//        || SAPHumanFather(object) == father
//        || kSAPHumanGenderMale != SAPHumanGender(father))
//    {
//        return;
//    }
//    
//    SAPHuman *currentFather = SAPHumanFather(object);
//    if (currentFather) {
//        SAPHumanRemoveChild(currentFather, object);
//    }
    
    SAPObjectIVarSetterSynthesize(object, father);
//    SAPHumanAddChild(father, object);
}

#pragma mark -
#pragma mark Private implementations

void SAPHumanAddChild(SAPHuman *object, SAPHuman *child) {
    if (NULL == object || NULL == child) {
        return;
    }
    
    if (false == SAPHumanHasChild(object, child)) {
        SAPHuman *currentFather = SAPHumanFather(object);
        SAPHuman *currentMother = SAPHumanMother(object);
        if (currentFather) {
            SAPHumanRemoveChild(currentFather, child);
        }
        
        if (currentMother) {
            SAPHumanRemoveChild(currentMother, child);
        }
        
        SAPDynamicArrayAddObject(SAPHumanChildren(object), child);
        if (kSAPHumanGenderFemale == SAPHumanGender(object)) {
            SAPHumanSetMother(child, object);
        } else {
            SAPHumanSetFather(child, object);
        }
    }
}

void SAPHumanRemoveChild(SAPHuman *parent, SAPHuman *child) {
    if (NULL == parent || NULL == child || false == SAPHumanHasChild(parent, child)) {
        return;
    }
    
    SAPDynamicArrayRemoveObject(SAPHumanChildren(parent), child);
    if (SAPHumanGender(parent) == kSAPHumanGenderMale) {
        SAPHumanSetFather(child, NULL);
    } else {
        SAPHumanSetMother(child, NULL);
    }
}

void SAPHumanRemoveAllChildren(SAPHuman *parent) {
    if (parent) {
        SAPDynamicArrayRemoveAllObjects(SAPHumanChildren(parent));
    }
}

SAPHuman *SAPHumanChildAtIndex(SAPHuman *object, uint8_t childIndex) {
    return (NULL != object && kSAPChildrenLimit > childIndex)
            ? SAPDynamicArrayObjectAtIndex(SAPHumanChildren(object), childIndex)
            : NULL;
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
    return SAPDynamicArrayContainsObject(SAPHumanChildren(object), child);
}

//////BEHAVIOR IMPLEMENTING FUNCTIONS

//weak member of connection is female. male-female - retain setter. female-male - assign setter.
void SAPHumanMarry(SAPHuman *object, SAPHuman *newPartner) {
    if (NULL == object
       || NULL == newPartner
       || SAPHumanGender(object) == SAPHumanGender(newPartner)
       || object == newPartner
       || SAPHumanPartner(object) == newPartner)
    {
        return;
    }
    
    SAPHumanDivorce(object);
    SAPHumanDivorce(newPartner);
    
    SAPHuman *strong = SAPHumanWhoIsStronger(object, newPartner);
    SAPHuman *weak = object == strong ? newPartner : object;
    
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

