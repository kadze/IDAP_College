//
//  SAPBinaryData.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <stdio.h>
#include "SAPBinaryData.h"

static const int kSAPBitCount = 8;
static const int kSAPLowerBitMask = 1;

#pragma mark-
#pragma mark Private declarations
void SAPOutputByte(uint8_t byte);

#pragma mark -
#pragma mark Private implementations

void SAPOutputByte(uint8_t byte) {
    int maxBitIndex = kSAPBitCount - 1;
    for (int bitIndex = maxBitIndex; bitIndex >= 0; bitIndex--) {
        printf("%c", byte >> bitIndex & kSAPLowerBitMask ? '1' : '0');
    }
    
    printf(" ");
}

#pragma mark-
#pragma mark Public implementations

//create universal method to output bits of the number of any type into consol

void SAPPrintBitsOfAnyTypeNumberBigEndian(void *AnyTypeNumberPointer, size_t size) {
    for (size_t index = 0; index < size; index++) {
        uint8_t byte = *((uint8_t *)AnyTypeNumberPointer + index);
        SAPOutputByte(byte);
    }
    
    printf("\n");
}

void SAPPrintBitsOfAnyTypeNumberLittleEndian(void *AnyTypeNumberPointer, size_t size) {
    for (int index = (size - 1); index >= 0; index--) {
        uint8_t byte = *((uint8_t *)AnyTypeNumberPointer + index);
        SAPOutputByte(byte);
    }
    
    printf("\n");
}

//create method to output bytes in direct or reverse order according to the flag
void SAPValueBitOutput(void *data, size_t size, SAPEndian endian) {
    kSAPLittleEndian == endian ? SAPPrintBitsOfAnyTypeNumberLittleEndian(data, size) : SAPPrintBitsOfAnyTypeNumberBigEndian(data, size);
}

//revise byte output so that it works on the machines with direct and indirect byte order
void SAPValueBitOutputAnyEndian(void *data, size_t size) {
    kSAPLittleEndian == SAPGetEndianWithUnion() ? SAPPrintBitsOfAnyTypeNumberLittleEndian(data, size) : SAPPrintBitsOfAnyTypeNumberBigEndian(data, size);
}

SAPEndian SAPGetEndianWithPointer(void) {
    int one = 1;
    if (*(char *)&one == 1) {
        
        return kSAPLittleEndian;
    } else {
        
        return kSAPBigEndian;
    }
}

SAPEndian SAPGetEndianWithUnion(void) {
    union {
        int intOne;
        char charArray[sizeof(int)];
    } definingUnion;
    definingUnion.intOne = 1;
    if (definingUnion.charArray[0] == 1) {
        
        return kSAPLittleEndian;
    } else {
        
        return kSAPBigEndian;
    }
}