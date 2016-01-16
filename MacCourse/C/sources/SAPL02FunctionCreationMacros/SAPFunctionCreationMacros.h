//
//  SAPFunctionCreationMacros.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/22/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPFunctionCreationMacros_h
#define SAPFunctionCreationMacros_h

//macros for creation function to print any value of any primitive type
#define SAPOutputFunction(type, specifier) \
    void SAPOutput_##type(type val) {\
        printf("Value of type " #type " is "specifier "\n", val);\
    }

//macros to invoke function from SAPOutputFunction macros
#define SAPOutputValueOfType(type, value) SAPOutput_##type(value)

#endif /* SAPFunctionCreationMacros_h */
