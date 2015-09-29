//
//  SAPBinaryTest.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/27/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPBinaryData.h"

#pragma mark--
#pragma mark Public implementations

void SAPPerformTestPrintBitsOfAnyTypeNumber(){
    printf("====================BINARY==============\n");
    int value = 5;
    void* valuePointer = &value;
    printf("Printing bits of 5 int\n");
    printf("as if byte order is big-endian\n");
    SAPValueBitOutput(valuePointer, sizeof(value), BigEndian);
    printf("as if byte order is little-endian\n");
    SAPValueBitOutput(valuePointer, sizeof(value), LittleEndian);
    printf("determine byte order automatically\n");
    SAPValueBitOutputAnyEndian(valuePointer, sizeof(value));
}

void SAPPerformTestGetEndian(){
    printf("==Test determining endian with pointer==\n");
    if (SAPGetEndianWithPointer() == LittleEndian){
        printf("Little-endian\n");
    } else{
        printf("Big-endian\n");
    }
    printf("==Test determining endian with union==\n");
    if (SAPGetEndianWithUnion() == LittleEndian){
        printf("Little-endian\n");
    } else{
        printf("Big-endian\n");
    }
}