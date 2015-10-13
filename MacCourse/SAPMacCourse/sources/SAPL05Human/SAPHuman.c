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
#include <string.h>
#include "SAPHuman.h"

#define ObjectGetterBody(fieldName) \
return NULL != object ? object->fieldName : NULL

#pragma mark --
#pragma mark Private declarations

static void _SAPHumanSetPartner(SAPHuman *object, SAPHuman *partner);
static void _SAPHumanSetGender(SAPHuman *object, SAPGender gender);
static void _SAPHumanSetMother(SAPHuman *object, SAPHuman *mother);
static void _SAPHumanSetFather(SAPHuman *object, SAPHuman *father);

#pragma mark --
#pragma mark Private implementations

static void _SAPHumanSetPartner(SAPHuman *object, SAPHuman *partner){
    if(NULL != object && object->_partner != partner){
        SAPHumanRetain(partner);
        SAPHumanRelease(object->_partner);
        object->_partner = partner;
    }
}

static void _SAPHumanSetGender(SAPHuman *object, SAPGender gender){
    if(NULL != object){
        object->_gender = gender;
    }
}

static void _SAPHumanSetMother(SAPHuman *object, SAPHuman *mother){
    if(NULL != object && object->_mother != mother){
        SAPHumanRetain(mother);
        SAPHumanRelease(object->_mother);
        object->_mother = mother;
    }
}

static void _SAPHumanSetFather(SAPHuman *object, SAPHuman *father){
    if(NULL != object && object->_father != father){
        SAPHumanRetain(father);
        SAPHumanRelease(object->_father);
        object->_father = father;
    }
}

#pragma mark --
#pragma mark Public implementations

SAPHuman *SAPHumanCreate(void){
    SAPHuman *object = calloc(1, sizeof(SAPHuman));
    assert(NULL != object);
    
    return object;
}

SAPHuman *SAPHumanCreateWithParameters(SAPHuman *mother, SAPHuman *father, SAPGender gender){
    SAPHuman *object = SAPHumanCreate();
    _SAPHumanSetMother(object, mother);
    _SAPHumanSetFather(object, father);
    _SAPHumanSetGender(object, gender);
    
    return object;
}

//memory management functions

void _SAPHumanDeallocate(SAPHuman *object){
    SAPHumanSetName(object, NULL);
    _SAPHumanSetGender(object, 0);
    _SAPHumanSetPartner(object, NULL);
    _SAPHumanSetMother(object, NULL);
    _SAPHumanSetFather(object, NULL);
    for (int childrenCounter = 0; childrenCounter < kSAPChildrenLimit; childrenCounter++) {
        object->_children[childrenCounter] = NULL;
    }
    free(object);
}

void SAPHumanRelease(SAPHuman *object){
    if(NULL != object){
        if(0 != --(object->_referenceCount)){
            _SAPHumanDeallocate(object);
        }
    }
}

void SAPHumanRetain(SAPHuman *object){
    if(object){
        object->_referenceCount++;
    }
}

//accessors

char *SAPHumanName(SAPHuman *object){
    ObjectGetterBody(_name);
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
    return NULL != object ? object->_gender : SAPHumanGenderMale; /////????????? by default??????????
}


uint8_t SAPHumanAge(SAPHuman *object){
    return NULL != object ? object->_age : 0;
}

void SAPHumanSetAge(SAPHuman *object, uint8_t *age){
    if (NULL != object){
        object->_age = *age;
    }
}

int SAPHumanChildrenCount(SAPHuman *object){
    int childrenCounter = 0;
    if(NULL != object){
        for (int index = 0; index < kSAPChildrenLimit; index++) {
            if(NULL != object->_children[index]){
                childrenCounter++;
            }
        }
    }
    
    return childrenCounter; //!!!
}

SAPHuman *SAPHumanPartner(SAPHuman *object){
    ObjectGetterBody(_partner);
}

SAPHuman *SAPHumanMother(SAPHuman *object){
    ObjectGetterBody(_mother);
}

SAPHuman *SAPHumanFather(SAPHuman *object){
    ObjectGetterBody(_father);
}

bool SAPHumanIsMarried(SAPHuman *object){
    return (NULL != object) && (NULL != SAPHumanPartner(object)) ? true : false;
}

//behavior umplementing functions

SAPHuman *SAPHumanBornChild(SAPHuman *object){
    if(NULL != object
       && NULL != SAPHumanPartner(object)
       && SAPHumanGender(object) != SAPHumanGender(SAPHumanPartner(object))){
        for (int childIndex = 0; childIndex < kSAPChildrenLimit; childIndex++) {
            if(NULL == object->_children[childIndex]){
                SAPHuman *bornChild = SAPHumanCreate();
                object->_children[childIndex] = bornChild;
                if(SAPHumanGender(object) == SAPHumanGenderMale){
                    _SAPHumanSetFather(bornChild, object);
                    _SAPHumanSetMother(bornChild, SAPHumanPartner(object));
                } else{
                    _SAPHumanSetMother(bornChild, object);
                    _SAPHumanSetFather(bornChild, SAPHumanPartner(object));
                }
                
                return bornChild;
            }
        }
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
    SAPHumanDivorce(object);
    if(SAPHumanGenderMale == SAPHumanGender(object)){
        _SAPHumanSetPartner(object, spouse);
        spouse->_partner = object;
    } else{
        _SAPHumanSetPartner(spouse, object);
        object->_partner = spouse;
    }
    married = true;
    
    return married;
}

void SAPHumanDivorce(SAPHuman *object){
    if(NULL == object){
        return;
    }
    if(SAPHumanGenderMale == object){
        object->_partner->_partner = NULL;
        _SAPHumanSetPartner(object, NULL);
    } else{
        object->_partner = NULL;
        _SAPHumanSetPartner(SAPHumanPartner(object), NULL);
    }
}

