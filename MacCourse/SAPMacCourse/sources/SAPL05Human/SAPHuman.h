//
//  SAPHuman.h
//  MacCourse
//
//  Created by SAP on 10/4/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPHuman__
#define __MacCourse__SAPHuman__

#include <stdbool.h>
#include "SAPObject.h"
#include "SAPString.h"
#include "SAPDynamicArray.h"

static const int kSAPChildrenLimit = 20;

typedef enum {
    kSAPHumanGenderMale,
    kSAPHumanGenderFemale
} SAPGender;

typedef struct SAPHuman SAPHuman;

struct SAPHuman {
    SAPObject _super;
    SAPString *_name;
    SAPHuman *_partner;
    SAPHuman *_mother;
    SAPHuman *_father;
    SAPDynamicArray *_children;
    SAPGender _gender;
    uint8_t _age;
};

extern
SAPHuman *SAPHumanCreate(SAPGender gender);

extern
SAPHuman *SAPHumanCreateWithParameters(SAPHuman *parent, SAPGender gender);

extern
void __SAPHumanDeallocate(SAPHuman *object);

extern
SAPString *SAPHumanName(SAPHuman *object);

extern
void SAPHumanSetName(SAPHuman *object, SAPString *name);

extern
SAPGender SAPHumanGender(SAPHuman *object);

extern
uint8_t SAPHumanAge(SAPHuman *object);

extern
void SAPHumanSetAge(SAPHuman *object, uint8_t age);

extern
SAPHuman *SAPHumanCreateChild(SAPHuman *object, SAPGender gender);

extern
SAPDynamicArray *SAPHumanChildren(SAPHuman * object);

extern
uint SAPHumanChildrenCount(SAPHuman *object);

extern
SAPHuman *SAPHumanPartner(SAPHuman *object);

extern
SAPHuman *SAPHumanMother(SAPHuman *object);

extern
SAPHuman *SAPHumanFather(SAPHuman *object);

extern
bool SAPHumanHasChild(SAPHuman *object, SAPHuman *child);

extern
bool SAPHumanIsMarried(SAPHuman *object);

extern
void SAPHumanMarry(SAPHuman *object, SAPHuman *spouse);

extern
void SAPHumanDivorce(SAPHuman *object);

#endif /* defined(__MacCourse__SAPHuman__) */
