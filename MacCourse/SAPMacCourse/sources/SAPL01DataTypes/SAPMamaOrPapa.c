//
//  SAPMamaOrPapa.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include "SAPMamaOrPapa.h"

#pragma mark -
#pragma mark Private implementations

static const int kMamaDivider = 3;
static const int kPapaDivider = 5;
static const int kMamapapaDivider = 15;

parents SAPDefineParent(int param){
    parents result;
    if (param % kMamapapaDivider == 0) {
        result = kSAPMamapapa;
    } else if (param % kPapaDivider == 0){
        result =  kSAPPapa;
    } else if (param % kMamaDivider == 0){
        result =  kSAPMama;
    } else
        result = kSAPOutOfCondition;
    
    return result;
}

char* getParentName(parents parent){
    char* result = "";
    if(kSAPMama == parent)
        result = "mama";
    else if(kSAPPapa == parent)
        result = "papa";
    else
        result = "";
    
    return result;
}