//
//  SAPHumanObject.h
//  MacCourse
//
//  Created by SAP on 10/4/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPHumanObject__
#define __MacCourse__SAPHumanObject__

# include <stdbool.h>
# include "SAPChildrenObject.h"

typedef struct SAPHumanObject SAPHumanObject;
struct SAPHumanObject{
    char *name;
    int age;
    int childrenNumber;
    SAPHumanObject *partner;
    SAPHumanObject *mother;
    SAPHumanObject *father;
    SAPChildrenObject children;
    bool isMarried;
};

SAPHumanObject *SAPHumanObjectCreate(void);
void SAPHumanObjectDeallocate(SAPHumanObject *humanObject);

char *SAPHumanObjectName(SAPHumanObject *humanObject);
void SAPHumanObjectSetName(SAPHumanObject *humanObject, char *name);

int SAPHumanObjectAge(SAPHumanObject *humanObject);
void SAPHumanObjectSetAge(SAPHumanObject *humanObject, int *age);

int SAPHumanObjectChildrenNumber(SAPHumanObject *humanObject);
void SAPHumanObjectSetChildrenNumber(SAPHumanObject *humanObject, int *childrenNumber);

SAPHumanObject *SAPHumanObjectPartner(SAPHumanObject *humanObject);
void SAPHumanObjectSetPartner(SAPHumanObject *humanObject, SAPHumanObject *partner);

SAPHumanObject *SAPHunmanObjectMother(SAPHumanObject *humanObject);
void SAPHumanObjectSetMother(SAPHumanObject *humanObject, SAPHumanObject *mother);

SAPHumanObject *SAPHunmanObjectFather(SAPHumanObject *humanObject);
void SAPHumanObjectSetFather(SAPHumanObject *humanObject, SAPHumanObject *father);

//SAPHumanObject *SAPHumanObjectChildren(SAPHumanObject *humanObject){
//    static SAPHumanObject children[20];
//    children[20] = humanObject->children;
//    return children;
//}

bool SAPHumanObjectIsMarried(SAPHumanObject *humanObject);
void SAPHumanObjectSetIsMarried(SAPHumanObject *humanObject, bool isMarried);

void SAPHumanObjectMarry(SAPHumanObject *humanObject, SAPHumanObject *spouse);
void SAPHumanObjectDivorce(SAPHumanObject *humanObject);

//SAPHumanObject *SAPHumanObjectProcreate(SAPHumanObject *humanObject){
//    SAPHumanObject *child = SAPHumanObjectCreate();
//    children
//}

#endif /* defined(__MacCourse__SAPHumanObject__) */
