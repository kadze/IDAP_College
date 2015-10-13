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
uint8_t SAPHumanAge(SAPHuman *object);
extern
void SAPHumanSetAge(SAPHuman *object, uint8_t *age);

extern
SAPHuman *SAPHumanBornChild(SAPHuman *object, SAPGender gender);

extern
int SAPHumanChildrenCount(SAPHuman *object);

extern
SAPHuman *SAPHumanPartner(SAPHuman *object);

extern
SAPHuman *SAPHumanMother(SAPHuman *object);

extern
SAPHuman *SAPHumanFather(SAPHuman *object);

extern
bool SAPHumanIsMarried(SAPHuman *object);

extern
bool SAPHumanMarry(SAPHuman *object, SAPHuman *spouse);
extern
bool SAPHumanDivorce(SAPHuman *object);

#endif /* defined(__MacCourse__SAPHuman__) */
