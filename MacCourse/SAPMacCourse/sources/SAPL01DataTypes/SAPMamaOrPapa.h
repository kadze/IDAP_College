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
    kSAPOutOfCondition,
    kSAPPapa,
    kSAPMama,
    kSAPMamapapa    
} SAPParents;

extern
char* getParentName(SAPParents);

extern
SAPParents SAPDefineParent(int param);

#endif /* defined(__MacCourse__SAPMamaOrPapa__) */
