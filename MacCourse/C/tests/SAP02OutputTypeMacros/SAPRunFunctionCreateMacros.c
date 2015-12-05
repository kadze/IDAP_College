//
//  SAPRunFunctionCreateMacros.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/22/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <stdio.h>
#include "SAPRunFunctionCreateMacros.h"
#include "SAPFunctionCreationMacros.h"


SAPOutputFunction(char, "%c")
SAPOutputFunction(short, "%i")
SAPOutputFunction(int, "%i")
SAPOutputFunction(long, "%li")
SAPOutputFunction(float, "%f")
SAPOutputFunction(double, "%f")

void SAPRunFunctionCreationMacros(void) {
    
    printf("================================\n");
    printf("Macros for creation and applying function testing:\n");
    SAPOutputValueOfType(char, 'A');
    SAPOutputValueOfType(int, 3);
    SAPOutputValueOfType(long, 2000000000l);
    SAPOutputValueOfType(float, 3.5f);
    SAPOutputValueOfType(double, 5.5);
    
}
