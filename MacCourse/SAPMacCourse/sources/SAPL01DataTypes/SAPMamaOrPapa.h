//
//  SAPMamaOrPapa.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPMamaOrPapa__
#define __MacCourse__SAPMamaOrPapa__

//enum dividers;
typedef enum {
    kSAPPapa,
    kSAPMama,
    kSAPMamapapa,
    kSAPOutOfCondition
} parents;

extern
char* getParentName(parents);

extern
parents SAPDefineParent(int param);

#endif /* defined(__MacCourse__SAPMamaOrPapa__) */
