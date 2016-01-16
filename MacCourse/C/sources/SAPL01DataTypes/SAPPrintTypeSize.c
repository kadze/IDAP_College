//
//  SAPPrintTypesSize.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//
#include <stdio.h>
#include "SAPPrintTypeSize.h"

#pragma mark -
#pragma mark Private implementations

void SAPPrintTypeSize(void) {
    
    SAPSizeofOutput(char);
    SAPSizeofOutput(short int);
    SAPSizeofOutput(int);
    SAPSizeofOutput(long int);
    SAPSizeofOutput(unsigned char);
    SAPSizeofOutput(unsigned short int);
    SAPSizeofOutput(unsigned int);
    SAPSizeofOutput(unsigned long int);
    SAPSizeofOutput(float);
    SAPSizeofOutput(double);
    SAPSizeofOutput(long double);
}