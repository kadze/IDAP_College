//
//  SAPHuman.h
//  MacCourse
//
//  Created by SAP on 10/4/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPHuman__
#define __MacCourse__SAPHuman__

# include <stdbool.h>

static const int kSAPChildrenLimit = 20;

typedef enum{
    SAPHumanGenderMale,
    SAPHumanGenderFemale
} SAPGender;

typedef struct SAPHuman SAPHuman;
struct SAPHuman{
    uint64_t _referenceCount;
    char *_name;
    SAPGender _gender;
    SAPHuman *_partner;
    SAPHuman *_mother;
    SAPHuman *_father;
    SAPHuman *_children[20];
    uint8_t _age;
};

extern
SAPHuman *SAPHumanCreate(void);
extern
SAPHuman *SAPHumanCreateWithParameters(SAPHuman *mother, SAPHuman *Father, SAPGender gender);

extern
void SAPHumanRelease(SAPHuman *object);
extern
void SAPHumanRetain(SAPHuman *object);

extern
char *SAPHumanName(SAPHuman *object);
extern
void SAPHumanSetName(SAPHuman *object, char *name);

extern
SAPGender SAPHumanGender(SAPHuman *object);
extern
void SAPHumanSetGender(SAPHuman *object, SAPGender gender);

extern
uint8_t SAPHumanAge(SAPHuman *object);
extern
void SAPHumanSetAge(SAPHuman *object, uint8_t *age);

extern
void SAPHumanBornChild(SAPHuman *object);

extern
int SAPHumanChildrenCount(SAPHuman *object);

extern
SAPHuman *SAPHumanPartner(SAPHuman *object);
extern
void SAPHumanSetPartner(SAPHuman *object, SAPHuman *partner);

extern
SAPHuman *SAPHumanMother(SAPHuman *object);
extern
void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother);

extern
SAPHuman *SAPHumanFather(SAPHuman *object);
extern
void SAPHumanSetFather(SAPHuman *object, SAPHuman *father);

//SAPHuman *SAPHumanChildren(SAPHuman *object){
//    static SAPHuman children[20];
//    children[20] = object->children;
//    return children;
//}
extern
bool SAPHumanIsMarried(SAPHuman *object);

extern
void SAPHumanMarry(SAPHuman *object, SAPHuman *spouse);
extern
void SAPHumanDivorce(SAPHuman *object);

//SAPHuman *SAPHumanProcreate(SAPHuman *object){
//    SAPHuman *child = SAPHumanCreate();
//    children
//}

#endif /* defined(__MacCourse__SAPHuman__) */
