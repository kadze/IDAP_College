//
//  Structures.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPStructures_h
#define SAPStructures_h

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

#endif /* SAPStructures_h */
