//
//  SAPMamaOrPapa.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include "SAPMamaOrPapa.h"

int SAPDefineMamaOrPapa(int param){
    
    int mamapapaDivider = 15;
    int papaDivider = 5;
    int mamaDivider = 3;
    int nonConditional = 0;
    if (param % mamapapaDivider ==0) {
        printf("mamapapa\n");
        return mamapapaDivider;
    } else if (param % papaDivider == 0){
        printf("papa\n");
        return papaDivider;
    } else if (param % 3 == 0){
        printf("mama\n");
        return mamaDivider;
    } else
        return nonConditional;
}