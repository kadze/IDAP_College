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

static const int kSAPMamaDivider       = 3;
static const int kSAPPapaDivider       = 5;
//static const int kSAPMamapapaDivider   = 15;

SAPParents SAPDefineParent(int param) {
    SAPParents result = kSAPOutOfCondition;
    if (0 == param){
        return result;
    }
    
    if (param % kSAPMamaDivider == 0) {
        result = kSAPMama;
    }
    
    if (param % kSAPPapaDivider == 0) {
        result = (kSAPMama == result) ? kSAPMamapapa : kSAPPapa;
    }
    
    return result;
}

char* getParentName(SAPParents parent) {
    char* result = "";
    if (kSAPMama == parent) {
        result = "mama";
    } else if (kSAPPapa == parent) {
        result = "papa";
    } else if (kSAPMamapapa == parent) {
        result = "mamapapa";
    }
    
    return result;
}