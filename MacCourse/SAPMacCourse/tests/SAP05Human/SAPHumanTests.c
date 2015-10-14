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
    for (int childIndex = 0; childIndex < kSAPChildrenLimit; childIndex ++) {
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
    SAPHumanSetAge(testHuman, 22);
    assert(22 == SAPHumanAge(testHuman));
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

void SAPPerformBehaviorTest(void){
    printf("===Perform behavior test===\n");
    SAPHuman *testMan = SAPCreateSpecialTestHumanWithParameters();
    SAPHumanSetName(testMan, "TestMan");
    SAPHuman *testWoman = SAPHumanCreateWithParameters(NULL, NULL, SAPHumanGenderFemale);
    SAPHumanSetName(testWoman, "TestWoman");
    
    assert(true == SAPHumanMarry(testMan, testWoman));
    //only human of different gender can marry
    assert(SAPHumanGender(testMan) != SAPHumanGender(testWoman));
    //human can't marry with null
    assert(NULL != testWoman && NULL != testMan);
    //human can't marry with himself
    assert(testMan != testWoman);
    //after marriage each spouse must have the property Partner filled with his (or her) spouse
    assert(testMan == SAPHumanPartner(testWoman));
    assert(testWoman == SAPHumanPartner(testMan));
    //after marriage each spouse must be married
    assert(true == SAPHumanIsMarried(testMan));
    assert(true == SAPHumanIsMarried(testWoman));
    
    assert(true == SAPHumanDivorce(testMan));
    //after divorce each former spouse must have not partner
    assert(NULL == SAPHumanPartner(testMan));
    assert(NULL == SAPHumanPartner(testWoman));
    //after divorce each former spouse must not be married
    assert(false == SAPHumanIsMarried(testMan));
    assert(false == SAPHumanIsMarried(testWoman));
    
    //marry again for another test
    assert(true == SAPHumanMarry(testMan, testWoman));
    SAPHuman *testMan2 = SAPCreateSpecialTestHumanWithParameters();
    SAPHumanSetName(testMan2, "TestMan2");
    //marry again for further test
    assert(true == SAPHumanMarry(testMan2, testWoman));
    //after marriage former spouses must firstly divorce
    assert(testMan != SAPHumanPartner(testWoman));
    assert(testWoman != SAPHumanPartner(testMan));
    assert(NULL == SAPHumanPartner(testMan));
    //and new pair must get merried
    assert(testMan2 == SAPHumanPartner(testWoman));
    assert(testWoman == SAPHumanPartner(testMan2));
    
    //in this test the initial amount of children of each partner is 0
    int amountOfChildrenPartner1Before = SAPHumanChildrenCount(testWoman);
    int amountOfChildrenPartner2Before = SAPHumanChildrenCount(SAPHumanPartner(testWoman));
    assert(0 == amountOfChildrenPartner1Before);
    assert(0 == amountOfChildrenPartner2Before);
    SAPHuman *child = SAPHumanBornChild(testWoman, SAPHumanGenderMale);
    assert(NULL != child);
    //woman born boy
    assert(SAPHumanGenderMale == SAPHumanGender(child));
    SAPHumanSetName(child, "Baby1");
    //human can't born child without a partner
    assert(NULL != SAPHumanPartner(testWoman));
    //child must have parents
    assert(testWoman == SAPHumanMother(child));
    assert(testMan2 == SAPHumanFather(child));
    //after the birth of the child each partner must have 1 child
    assert(1 == SAPHumanChildrenCount(testWoman));
    assert(1 == SAPHumanChildrenCount(SAPHumanPartner(testWoman)));
    
    SAPReleaseSpecialTestHumanWithParameters(testMan);
    SAPReleaseSpecialTestHumanWithParameters(testMan2);
    SAPHumanRelease(testWoman);
    SAPHumanRelease(child);
    
}

#pragma mark --
#pragma mark Public implementations

void SAPPerformAllHumanTests(void){
    printf("=====================H U M A N======================\n");
    SAPPerformHumanCreateTest();
    SAPPerformTestSAPHumanSetName();
    SAPPerformTestHumanCreateWithParameters();
    SAPPerformTestSAPHumanChildrenCount();
    SAPPerformBehaviorTest();
    
}
