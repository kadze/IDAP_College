//
//  SAPRunFunctionCreateMacros.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/22/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include <stdio.h>
#include "SAPRunFunctionCreateMacros.h"


//macros for creation function to print any value of any primitive type
#define SAPOutputFunction(type, specifier) \
void Output_##type(type val){\
printf("Value of type " #type " is "specifier "\n", val);\
}

//macros to invoke function from SAPOutputFunction macros
#define SAPRunFunctionFromMacros(type, value) Output_##type(value)


SAPOutputFunction(char, "%c")
//SAPOutputFunction(short int, "%i")
SAPOutputFunction(int, "%i")
//SAPOutputFunction(long int, "%f")
//SAPOutputFunction(unsigned char, "%c")
//SAPOutputFunction(unsigned short int, "%i")
//SAPOutputFunction(unsigned int, "%u")
//SAPOutputFunction(unsigned long int, "%li")
SAPOutputFunction(float, "%f")
SAPOutputFunction(double, "%f")
//SAPOutputFunction(long double, "%LF")



void SAPRunFunctionCreationMacros(){
    
    SAPRunFunctionFromMacros(char, 'A');
    SAPRunFunctionFromMacros(int, 3);
    
    SAPRunFunctionFromMacros(float, 3.5);
    SAPRunFunctionFromMacros(double, 5.5);
    
}
