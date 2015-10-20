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
static const int kSAPMamapapaDivider   = 15;

parents SAPDefineParent(int param) {
    parents result;
    if (param % kSAPMamapapaDivider == 0) {
        result = kSAPMamapapa;
    } else if (param % kSAPPapaDivider == 0) {
        result = kSAPPapa;
    } else if (param % kSAPMamaDivider == 0) {
        result =  kSAPMama;
    } else {
        result = kSAPOutOfCondition;
    }
    
    return result;
}

char* getParentName(parents parent) {
    char* result = "";
    if (kSAPMama == parent) {
        result = "mama";
    } else if (kSAPPapa == parent) {
        result = "papa";
    }
    
    return result;
}