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
NULL != object ? object->fieldName : NULL

#pragma mark --
#pragma mark Private declarations


#pragma mark --
#pragma mark Private implementations


SAPHuman *SAPHumanCreate(void){
    SAPHuman *object = calloc(1, sizeof(SAPHuman));
    assert(NULL != object);
    
    return object;
}

SAPHuman *SAPHumanCreateWithParameters(SAPHuman *mother, SAPHuman *father, SAPGender gender){
    SAPHuman *object = calloc(1, sizeof(SAPHuman));
    assert(NULL != object);
    SAPHumanSetMother(object, mother);
    SAPHumanSetFather(object, father);
    SAPHumanSetGender(object, gender);
    return object;
}

void _SAPHumanDeallocate(SAPHuman *object){
    SAPHumanSetName(object, NULL);
    SAPHumanSetGender(object, 0);
    SAPHumanSetPartner(object, NULL);
    SAPHumanSetMother(object, NULL);
    SAPHumanSetFather(object, NULL);
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

char *SAPHumanName(SAPHuman *object){
    return ObjectGetterBody(_name);
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

void SAPHumanSetGender(SAPHuman *object, SAPGender gender){
    if(NULL != object){
        object->_gender = gender;
    }
}

uint8_t SAPHumanAge(SAPHuman *object){
    return NULL != object ? object->_age : 0;
}

void SAPHumanSetAge(SAPHuman *object, uint8_t *age){
    if (NULL != object){
        object->_age = *age;
    }
}

void SAPHumanBornChild(SAPHuman *object){
    if(NULL != object &&
      NULL != SAPHumanPartner(object) &&
      SAPHumanGender(object) != SAPHumanGender(SAPHumanPartner(object))){
        for (int childIndex = 0; childIndex < kSAPChildrenLimit; childIndex++) {
            if(NULL == object->_children[childIndex]){
                SAPHuman *bornChild = SAPHumanCreate();
                object->_children[childIndex] = bornChild;
                if(SAPHumanGender(object) == SAPHumanGenderMale){
                    SAPHumanSetFather(bornChild, object);
                    SAPHumanSetMother(bornChild, SAPHumanPartner(object));
                } else{
                    SAPHumanSetMother(bornChild, object);
                    SAPHumanSetFather(bornChild, SAPHumanPartner(object));
                }
                return;
            }
        }
    }
    
    return;
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
    return ObjectGetterBody(_partner);
}

void SAPHumanSetPartner(SAPHuman *object, SAPHuman *partner){
    if(NULL != object && object->_partner != partner){
        SAPHumanRetain(partner);
        SAPHumanRelease(object->_partner);
        object->_partner = partner;
    }
}

SAPHuman *SAPHumanMother(SAPHuman *object){
    return ObjectGetterBody(_mother);
}

void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother){
    if(NULL != object && object->_mother != mother){
        SAPHumanRetain(mother);
        SAPHumanRelease(object->_mother);
        object->_mother = mother;
    }
}

SAPHuman *SAPHumanFather(SAPHuman *object){
    return ObjectGetterBody(_father);
}

void SAPHumanSetFather(SAPHuman *object, SAPHuman *father){
    if(NULL != object && object->_father != father){
        SAPHumanRetain(father);
        SAPHumanRelease(object->_father);
        object->_father = father;
    }
}

bool SAPHumanIsMarried(SAPHuman *object){
    return (NULL != object) && (SAPHumanPartner(object) != NULL) ? SAPHumanPartner(object) : false;
}

//weak member of connection is female. male-female - retain setter. female-male - assign setter.
void SAPHumanMarry(SAPHuman *object, SAPHuman *spouse){
    if(NULL == object ||
       NULL == spouse ||
       SAPHumanGender(object) == SAPHumanGender(spouse) ||
       object == spouse){
        return;
    }
    SAPHumanDivorce(object);
    if(SAPHumanGenderMale == SAPHumanGender(object)){
        SAPHumanSetPartner(object, spouse);
        spouse->_partner = object;
    } else{
        SAPHumanSetPartner(spouse, object);
        object->_partner = spouse;
    }
}

void SAPHumanDivorce(SAPHuman *object){
    if(NULL == object){
        return;
    }
    if(SAPHumanGenderMale == object){
        object->_partner->_partner = NULL;
        SAPHumanSetPartner(object, NULL);
    } else{
        object->_partner = NULL;
        SAPHumanSetPartner(SAPHumanPartner(object), NULL);
    }
}

