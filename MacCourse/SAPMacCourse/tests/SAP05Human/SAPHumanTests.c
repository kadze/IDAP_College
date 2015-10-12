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

//#include "SAPHumanTests.h"


void SAPPrintChildrenArray(SAPHuman *children){
    for (int counter = 0; counter < kSAPChildrenLimit; counter ++) {
        printf("child[%d] %s\n", counter, SAPHumanName(children));
        children++;
    }
}

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
    printf("All fields have to be nulled\n");
    printf("age = %d\n", SAPHumanAge(testHuman));
    printf("name = %s\n", SAPHumanName(testHuman));
    printf("gender = %s\n", SAPHumanGenderMale == SAPHumanGender(testHuman) ? "Male(0)" : "Female(1)");
    printf("mother = %s\n", SAPHumanMother(testHuman));
    printf("father = %s\n", SAPHumanFather(testHuman));
    SAPPrintChildrenArray(testHuman->_children);
    SAPHumanRelease(testHuman);
}

//
//void SAPPerformTestSAPHumanDeallocate(void){
//    printf("===Perform SAPHumanDeallocate() test ===\n");
//    SAPHuman *testHuman = SAPCreateSpecialTestHumanWithParameters();
//    SAPHuman *testGirfriend = SAPHumanCreate();
//    SAPHumanSetName(testGirfriend, "Juddy");
//    SAPHumanSetGender(testGirfriend, SAPHumanGenderFemale);
//    SAPHumanSetPartner(testHuman, testGirfriend);
//    SAPHumanSetAge(testHuman, 20); //20 - let's set age of human
//    SAPHumanBornChild(testHuman);
//    
//    SAPHumanDeallocate(testHuman);
//    
//    
//}


void SAPPerformTestHumanCreateWithParameters(void){
    printf("===Perform SAPHumanCreateWithParameters() test ===\n");
    SAPHuman *testHuman = SAPCreateSpecialTestHumanWithParameters();
    printf("Created human with parameters. Human's initial properties are: \
           Mother %s\nFather %s\nGender %s\n",
           SAPHumanName(SAPHumanMother(testHuman)),
           SAPHumanName(SAPHumanFather(testHuman)),
           SAPHumanGenderMale == SAPHumanGender(testHuman) ? "Male(0)" : "Female(1)");
    
    SAPReleaseSpecialTestHumanWithParameters(testHuman);
}

void SAPPerformTestSAPHumanSetName(void){
    printf("===Perform SAPHumanSetName() test===\n");
    SAPHuman *testHuman = SAPHumanCreate();
    printf("Human's name before setting name is %s\n", SAPHumanName(testHuman));
    char *name = "Petya";
    SAPHumanSetName(testHuman, name);
    assert(0 == strcmp(name, SAPHumanName(testHuman)));
    printf("Human's name after setting name is %s\n", SAPHumanName(testHuman));
    SAPHumanRelease(testHuman);
}

void SAPPerformTestSAPHumanSetGender(){
    printf("===Perform SAPHumanSetGender() test===\n");
    SAPHuman *testHuman = SAPHumanCreate();
    printf("Human's gender before setting name is %s\n",
           SAPHumanGenderMale == SAPHumanGender(testHuman) ? "Male(0)" : "Female(1)");
    SAPHumanSetGender(testHuman, SAPHumanGenderFemale);
    assert(SAPHumanGenderFemale == SAPHumanGender(testHuman));
    printf("Human's gender after setting is %s\n",
           SAPHumanGenderMale == SAPHumanGender(testHuman) ? "Male(0)" : "Female(1)");
    SAPHumanRelease(testHuman);
}

void SAPPerformTestSAPHumanSetAge(void){
    printf("===Perform SAPHumanSetAge() test===\n");
    SAPHuman *testHuman = SAPHumanCreate();
    printf("Human's age before setting age is %d\n", SAPHumanAge(testHuman));
    SAPHumanSetAge(testHuman, 20);
    assert(20 == SAPHumanAge(testHuman));
    printf("Human's age after setting age is %d\n", SAPHumanAge(testHuman));
    SAPHumanRelease(testHuman);
}

void SAPPerformTestSAPHumanSetPartner(void){
    printf("===Perform SAPHumanSetPartner() test===\n");
    SAPHuman *testHuman = SAPHumanCreate();
    printf("Human's Partner before setting is %s\n", SAPHumanName(SAPHumanPartner(testHuman)));
    SAPHuman *testPartner = SAPHumanCreate();
    SAPHumanSetName(testPartner, "Josefina");
    SAPHumanSetPartner(testHuman, testPartner);
    assert(testPartner == SAPHumanPartner(testHuman));
    printf("Human's name after setting name is %s\n", SAPHumanName(SAPHumanPartner(testHuman)));
    SAPHumanRelease(testPartner);
    SAPHumanRelease(testHuman);
}

//void SAPPerformTestSAPHumanSetMother(void){
//    printf("===Perform SAPHumanSetMother() test===\n");
//    SAPHuman *testHuman = SAPHumanCreate();
//    printf("Human's name before setting name is %s\n", testHuman->_name);
//    SAPHumanSetName(testHuman, "Petya");
//    printf("Human's name after setting name is %s\n", testHuman->_name);
//    SAPHumanRelease(testHuman);
//}
//
//void SAPPerformTestSAPHumanSetFather(void){
//    printf("===Perform SAPHumanSetFather() test===\n");
//    SAPHuman *testHuman = SAPHumanCreate();
//    printf("Human's name before setting name is %s\n", testHuman->_name);
//    SAPHumanSetName(testHuman, "Petya");
//    printf("Human's name after setting name is %s\n", testHuman->_name);
//    SAPHumanRelease(testHuman);
//}

void SAPPerformTestSAPHumanChildrenCount(void){
    printf("===Perform SAPHumanChildrenCount() test===\n");
    printf("expecting 3 children as a result\n");
    SAPHuman *testHuman = SAPCreateSpecialTestHumanWithParameters();
    SAPHuman *child1 = SAPCreateSpecialTestHumanWithParameters();
    SAPHuman *child2 = SAPCreateSpecialTestHumanWithParameters();
    SAPHuman *child3 = SAPCreateSpecialTestHumanWithParameters();
    testHuman->_children[0] = child1;
    testHuman->_children[1] = child2;
    testHuman->_children[2] = child3;
    printf("The result is %d children", SAPHumanChildrenCount(testHuman));
    SAPReleaseSpecialTestHumanWithParameters(testHuman);
    SAPReleaseSpecialTestHumanWithParameters(child1);
    SAPReleaseSpecialTestHumanWithParameters(child2);
    SAPReleaseSpecialTestHumanWithParameters(child3);
}

void SAPPerformAllHumanTests(void){
    printf("=====================H U M A N======================\n");
    SAPPerformHumanCreateTest();
    SAPPerformTestSAPHumanSetName();
    SAPPerformTestSAPHumanSetGender();
    SAPPerformTestHumanCreateWithParameters();
    SAPPerformTestSAPHumanChildrenCount();
    
//    SAPHuman *children[kSAPChildrenLimit];
//    SAPHuman *child = SAPHumanCreate();
//    SAPHumanSetName(child, "Petya");
//    children[0] = child;
//    SAPPrintChildrenArray(*children);
}
