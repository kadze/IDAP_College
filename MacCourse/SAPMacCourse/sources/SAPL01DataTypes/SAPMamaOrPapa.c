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
        result = mamapapa;
    } else if (param % kPapaDivider == 0){
        result =  papa;
    } else if (param % kMamaDivider == 0){
        result =  mama;
    } else
        result = outOfCondition;
    
    return result;
}

char* getParentName(parents parent){
    char* result = "";
    if(parent == mama)
        result = "mama";
    else if(parent == papa)
        result = "papa";
    else
        result = "";
    
    return result;
}