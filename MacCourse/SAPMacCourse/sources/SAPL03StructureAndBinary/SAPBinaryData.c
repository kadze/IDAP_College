//
//  SAPBinaryData.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPBinaryData.h"

void SAPPrintIntNumberBits(int intNumber){
    short intSize = sizeof(int);
    short arraySize = intSize * 8;
    short position = arraySize - 1;
    short bit = 0;
    short resultArray[arraySize];
    //initialize array with values
    for (short i = 0; i < arraySize; i++){
        resultArray[i] = 0;
    }
    int tempResult = intNumber;
    short rest = 0;
    while (tempResult > 0){
        rest = tempResult % 2;
        tempResult = tempResult / 2;
        resultArray[position] = rest;
        position = position - 1;
    };
    
    for (short i = 0; i < arraySize; i++) {
        printf("%d",resultArray[i]);
    }
    printf("\n");
}
void SAPPrintAnyTypeNumberBits(*NumberPointer){
    
}