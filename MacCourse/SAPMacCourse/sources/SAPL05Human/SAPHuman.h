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

typedef enum{
    SAPHumanGenderMale,
    SAPHumanGenderFemale
} SAPHumanGender;

typedef struct SAPHuman SAPHuman;
struct SAPHuman{
    char *_name;
    int _age;
    SAPHumanGender _gender;
    SAPHuman *_partner;
    SAPHuman *_mother;
    SAPHuman *_father;
    SAPHuman *_children[20];
    bool _isMarried;
};

extern
SAPHuman *SAPHumanCreate(void);
extern
void SAPHumanDeallocate(SAPHuman *object);

extern
char *SAPHumanName(SAPHuman *object);
extern
void SAPHumanSetName(SAPHuman *object, char *name);

extern
int SAPHumanAge(SAPHuman *object);
extern
void SAPHumanSetAge(SAPHuman *object, int *age);

extern
int SAPHumanChildrenCount(SAPHuman *object);

extern
SAPHuman *SAPHumanPartner(SAPHuman *object);
extern
void SAPHumanSetPartner(SAPHuman *object, SAPHuman *partner);

extern
SAPHuman *SAPHunmanObjectMother(SAPHuman *object);
extern
void SAPHumanSetMother(SAPHuman *object, SAPHuman *mother);

extern
SAPHuman *SAPHunmanObjectFather(SAPHuman *object);
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
