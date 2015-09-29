//
//  SAPBinaryData.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

//#include <std
#include "SAPBinaryData.h"

static const int SAPBitCount = 8;
static const int SAPLowerBitMask = 1;

#pragma mark--
#pragma mark Private declarations
void SAPOutputByte(uint8_t byte);

#pragma mark--
#pragma mark Public implementations

//create universal method to output bits of the number of any type into consol
void SAPPrintBitsOfAnyTypeNumberBigEndian(void *AnyTypeNumberPointer, size_t size){
    for(size_t index = 0; index < size; index++){
        uint8_t byte = *((uint8_t *)AnyTypeNumberPointer + index);
        SAPOutputByte(byte);
    }
    printf("\n");
}

void SAPPrintBitsOfAnyTypeNumberLittleEndian(void *AnyTypeNumberPointer, size_t size){
    for(int index = (size - 1); index >= 0; index--){
        uint8_t byte = *((uint8_t *)AnyTypeNumberPointer + index);
        SAPOutputByte(byte);
    }
    printf("\n");
}

void SAPOutputByte(uint8_t byte){
    int maxBitIndex = SAPBitCount - 1;
    for(int bitIndex = maxBitIndex; bitIndex >= 0; bitIndex--){
        printf("%c", byte >> bitIndex & 1 ? '1' : '0');
    }
    printf(" ");
}


void SAPValueBitOutput(void *data, size_t size, SAPEndian endian){
    endian == LittleEndian ? SAPPrintBitsOfAnyTypeNumberLittleEndian(data, size) : SAPPrintBitsOfAnyTypeNumberBigEndian(data, size);
}

void SAPValueBitOutputAnyEndian(void *data, size_t size){
    SAPGetEndianWithUnion() == LittleEndian ? SAPPrintBitsOfAnyTypeNumberLittleEndian(data, size) : SAPPrintBitsOfAnyTypeNumberBigEndian(data, size);
}

SAPEndian SAPGetEndianWithPointer(){
    int x = 1;
    if(*(char *)&x == 1){
        return LittleEndian;
    } else{
        return BigEndian;
    }
}

SAPEndian SAPGetEndianWithUnion(){
    union{
        int i;
        char c[sizeof(int)];
    } x;
    x.i = 1;
    if(x.c[0] == 1){
        return LittleEndian;
    }else{
        return BigEndian;
    }
}