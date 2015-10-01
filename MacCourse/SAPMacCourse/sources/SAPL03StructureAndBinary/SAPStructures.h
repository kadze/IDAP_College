//
//  Structures.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef Structures_h
#define Structures_h

#include <stdbool.h>
#include <stdlib.h>

#define SAPStructSize(Struct) \
    size_t SAPSizeof##Struct(){\
        return sizeof(Struct);\
    }
#define SAPPrintStructSize(Struct) printf("The size of " #Struct " is %lu\n", SAPSizeof##Struct())

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

//create data structure which stores randomly settled
//6 bool, 1 float, 1 int, 1 long long, 3 short, 1 double, 1 string pointer
typedef struct{
    short myShort1;
    short myShort2;         //2
    int myInt1;             //4
    bool myBool1;           //1
    float myFloat1;         //4
    double myDouble1;       //8
    long long myLongLong1;  //8
    bool myBool2;
    bool myBool3;
    short myShort3;
    bool myBool4;
    char *myStringPointer;  //1
    bool myBool5;
    bool myBool6;
} SAPBigStructure;

//extra task: second variant of the original structure with rearranged for tructure to have minimal size
typedef struct{
    double myDouble1;
    long long myLongLong1;
    float myFloat1;
    int myInt1;
    short myShort1;
    short myShort2;
    short myShort3;
    bool myBool1;
    bool myBool2;
    bool myBool3;
    bool myBool4;
    bool myBool5;
    bool myBool6;
    char *myStringPointer;
} SAPSmallerStructure;

//int this variant place boolean variables into bit field and create union
typedef struct{
    double myDouble1;
    long long myLongLong1;
    float myFloat1;
    int myInt1;
    short myShort1;
    short myShort2;
    short myShort3;
    union {
        struct{
            bool myBool1 :1;
            bool myBool2 :1;
            bool myBool3 :1;
            bool myBool4 :1;
            bool myBool5 :1;
            bool myBool6 :1;
        };
        char boolFlags;
    };
    char *myStringPointer;
} SAPSmallStructure;

#endif /* Structures_h */
