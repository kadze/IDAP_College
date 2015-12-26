//
//  SAPBinaryTest.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/27/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//
#include <stdio.h>
#include "SAPBinaryData.h"

#pragma mark --
#pragma mark Public implementations

void SAPPerformTestPrintBitsOfAnyTypeNumber(void) {
    printf("====================BINARY==============\n");
    int value = 5;
    void* valuePointer = &value;
    printf("Printing bits of 5 int\n");
    printf("as if byte order is big-endian\n");
    SAPValueBitOutput(valuePointer, sizeof(value), kSAPBigEndian);
    printf("as if byte order is little-endian\n");
    SAPValueBitOutput(valuePointer, sizeof(value), kSAPLittleEndian);
    printf("determine byte order automatically\n");
    SAPValueBitOutputAnyEndian(valuePointer, sizeof(value));
}

void SAPPerformTestGetEndian(void) {
    printf("===Test determining endian with pointer===\n");
    if (kSAPLittleEndian == SAPGetEndianWithPointer()) {
        printf("Little-endian\n");
    } else {
        printf("Big-endian\n");
    }
    
    printf("===Test determining endian with union===\n");
    if (kSAPLittleEndian == SAPGetEndianWithUnion()) {
        printf("Little-endian\n");
    } else {
        printf("Big-endian\n");
    }
}