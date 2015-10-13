//
//  SAPHumanTests.c
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/7/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "SAPHuman.h"

#pragma mark --
#pragma mark Private implementations

//auto create human with some parameters
SAPHuman *SAPCreateSpecialTestHumanWithParameters(void){
    SAPHuman *testMother = SAPHumanCreate();
    SAPHumanSetName(testMother, "Mommy");
    SAPHuman *testFather = SAPHumanCreate();
    SAPHumanSetName(testFather, "Daddy");
    SAPHuman *testHuman = SAPHumanCreateWithParameters(testMother, testFather, SAPHumanGenderMale);
    
    return testHuman;
}

void SAPReleaseSpecialTestHumanWithParameters(SAPHuman *testHuman){
    SAPHumanRelease(SAPHumanMother(testHuman));
    SAPHumanRelease(SAPHumanFather(testHuman));
    SAPHumanRelease(testHuman);
}

//ensure that object created and initialized with null or zero values
void SAPPerformHumanCreateTest(void){
    printf("===Perform SAPHumanCreate() test ===\n");
    SAPHuman *testHuman = SAPHumanCreate();
    assert(NULL != testHuman);
    //All fields have to be empty
    assert(0 == SAPHumanAge(testHuman));
    assert(NULL == SAPHumanName(testHuman));
    assert(SAPHumanGenderMale == SAPHumanGender(testHuman));
    assert(NULL == SAPHumanMother(testHuman));
    assert(NULL == SAPHumanFather(testHuman));
    //SAPPrintChildrenArray(testHuman->_children);
    for (int childIndex = 0; childIndex < 20; childIndex ++) {
        assert(NULL == testHuman->_children[childIndex]);
    }
    SAPHumanRelease(testHuman);
}

void SAPPerformTestHumanCreateWithParameters(void){
    printf("===Perform SAPHumanCreateWithParameters() test ===\n");
    SAPHuman *testHuman = SAPCreateSpecialTestHumanWithParameters();
    //human object must be created
    assert(NULL != testHuman);
    //fields Mother, Fatrer and Gender must be set.
    assert(0 == strcmp("Mommy",SAPHumanName(SAPHumanMother(testHuman))));
    assert(0 == strcmp("Daddy", SAPHumanName(SAPHumanFather(testHuman))));
    assert(SAPHumanGenderMale == SAPHumanGender(testHuman));
    SAPReleaseSpecialTestHumanWithParameters(testHuman);
}

void SAPPerformTestSAPHumanSetName(void){
    printf("===Perform SAPHumanSetName() test===\n");
    SAPHuman *testHuman = SAPHumanCreate();
    char *name = "Petya";
    SAPHumanSetName(testHuman, name);
    //object must have the right name after setting
    assert(0 == strcmp(name, SAPHumanName(testHuman)));
    //the property must not be string constant
    assert("Petya" != SAPHumanName(testHuman));
    //the property must be the copy of the string
    assert(name != SAPHumanName(testHuman));
    SAPHumanRelease(testHuman);
}

void SAPPerformTestSAPHumanSetAge(void){
    printf("===Perform SAPHumanSetAge() test===\n");
    SAPHuman *testHuman = SAPHumanCreate();
    //printf("Human's age before setting age is %d\n", SAPHumanAge(testHuman));
    SAPHumanSetAge(testHuman, 20);
    assert(20 == SAPHumanAge(testHuman));
   // printf("Human's age after setting age is %d\n", SAPHumanAge(testHuman));
    SAPHumanRelease(testHuman);
}

void SAPPerformTestSAPHumanChildrenCount(void){
    printf("===Perform SAPHumanChildrenCount() test===\n");
    SAPHuman *testHuman = SAPCreateSpecialTestHumanWithParameters();
    SAPHuman *child1 = SAPCreateSpecialTestHumanWithParameters();
    SAPHuman *child2 = SAPCreateSpecialTestHumanWithParameters();
    SAPHuman *child3 = SAPCreateSpecialTestHumanWithParameters();
    testHuman->_children[0] = child1;
    testHuman->_children[1] = child2;
    testHuman->_children[2] = child3;
    assert(3 == SAPHumanChildrenCount(testHuman));
    SAPReleaseSpecialTestHumanWithParameters(testHuman);
    SAPReleaseSpecialTestHumanWithParameters(child1);
    SAPReleaseSpecialTestHumanWithParameters(child2);
    SAPReleaseSpecialTestHumanWithParameters(child3);
}

#pragma mark --
#pragma mark Public implementations

void SAPPerformAllHumanTests(void){
    printf("=====================H U M A N======================\n");
    SAPPerformHumanCreateTest();
    SAPPerformTestSAPHumanSetName();
    SAPPerformTestHumanCreateWithParameters();
    SAPPerformTestSAPHumanChildrenCount();
    
}
