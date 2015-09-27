//
//  SAPBinaryData.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

//#include <stdlib.h>
#include "SAPBinaryData.h"

//create universal method to output bits of the number of any type into consol
void SAPPrintBitsOfAnyTypeNumber(void *AnyTypeNumberPointer, size_t size){
        
    size = 1;
    char num = 255;
    typeof(num);
    
    //нипоняв как из входного параметра функции сделать переменную конкретного типа с конкретным значением
    for(int i = size << 3; i != 0; i--){
        if(((num >> (i - 1)) & 1) != 0)
            printf ("1");
        else
            printf ("0");
    }
    printf("\n");
    
}