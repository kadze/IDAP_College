//
//  Structures.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPStructuresTest_h
#define SAPStructuresTest_h

#include <stdbool.h>
#include <stdlib.h>

#define SAPPrintOffsetof(Struct, variable)\
    printf("Position of " #variable " is %lu\n",__builtin_offsetof(Struct, variable));

#define SAPPrintSmallStructMemberPositions(Struct)\
    printf("======Positions of structure " #Struct " =======\n");\
    SAPPrintOffsetof(Struct, myShort1)\
    SAPPrintOffsetof(Struct, myShort2)\
    SAPPrintOffsetof(Struct, myShort3)\
    SAPPrintOffsetof(Struct, myInt1)\
    SAPPrintOffsetof(Struct, myFloat1)\
    SAPPrintOffsetof(Struct, myDouble1)\
    SAPPrintOffsetof(Struct, myLongLong1)\
    SAPPrintOffsetof(Struct, myStringPointer)\
    SAPPrintOffsetof(Struct, boolFlags)

#define SAPPrintStructMemberPositions(Struct) \
    printf("======Positions of structure " #Struct " =======\n");\
    SAPPrintOffsetof(Struct, myShort1)\
    SAPPrintOffsetof(Struct, myShort2)\
    SAPPrintOffsetof(Struct, myShort3)\
    SAPPrintOffsetof(Struct, myBool1)\
    SAPPrintOffsetof(Struct, myBool2)\
    SAPPrintOffsetof(Struct, myBool3)\
    SAPPrintOffsetof(Struct, myBool4)\
    SAPPrintOffsetof(Struct, myBool5)\
    SAPPrintOffsetof(Struct, myBool6)\
    SAPPrintOffsetof(Struct, myInt1)\
    SAPPrintOffsetof(Struct, myDouble1)\
    SAPPrintOffsetof(Struct, myLongLong1)\
    SAPPrintOffsetof(Struct, myStringPointer)

#define SAPPrintBoolFlagsPosition(Struct)\
    printf("Position of boolFlags is %lu\n",__builtin_offsetof(Struct, boolFlags));

#define SAPStructSize(Struct) \
    size_t SAPSizeof##Struct(){\
        return sizeof(Struct);\
}

#define SAPPrintStructSize(Struct) printf("The size of " #Struct " is %lu\n", SAPSizeof##Struct())

extern
void SAPPerformTestPrintSizeOfStructures(void);

extern
void SAPPerformTestPrintStructMemberPositions(void);
#endif /* Structures_h */
