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
#include "SAPObject.h"
#include "SAPString.h"
#include "SAPArray.h"

static char *testMothersNameString = "Mommy";
static char *testFathersNameString = "Daddy";
#pragma mark -
#pragma mark Private declarations

SAPHuman *SAPCreateSpecialTestHumanWithParameters(SAPGender gender);
void SAPReleaseSpecialTestHumanWithParameters(SAPHuman *testHuman);

#pragma mark -
#pragma mark Private implementations

//auto create human with some parameters
SAPHuman *SAPCreateSpecialTestHumanWithParameters(SAPGender gender) {
    SAPString *testMothersName = SAPStringCreate(testMothersNameString);
    SAPString *testFathersName = SAPStringCreate(testFathersNameString);
    SAPHuman *testMother = SAPHumanCreate(kSAPHumanGenderFemale);
    SAPHumanSetName(testMother, testMothersName);
    SAPHuman *testFather = SAPHumanCreate(kSAPHumanGenderMale);
    SAPHumanSetName(testFather, testFathersName);
    SAPHumanMarry(testFather, testMother);
    SAPHuman *testHuman = SAPHumanCreateWithParameters(testFather, gender);
    
    return testHuman;
}

void SAPReleaseSpecialTestHumanWithParameters(SAPHuman *testHuman) {
    SAPObjectRelease(SAPHumanMother(testHuman));
    SAPObjectRelease(SAPHumanFather(testHuman));
    SAPObjectRelease(testHuman);
}

//ensure that object created and initialized with null or zero values
void SAPPerformHumanCreateTest(void) {
    printf("===Perform SAPHumanCreate() test ===\n");
    SAPHuman *testHuman = SAPHumanCreate(kSAPHumanGenderMale);
    assert(NULL != testHuman);
    //initial retaincount must be 1
    assert(1 == SAPObjectRetainCount(testHuman));
    //All fields have to be empty
    assert(0 == SAPHumanAge(testHuman));
    assert(NULL == SAPHumanName(testHuman));
    assert(kSAPHumanGenderMale == SAPHumanGender(testHuman));
    assert(NULL == SAPHumanMother(testHuman));
    assert(NULL == SAPHumanFather(testHuman));
    for (int childIndex = 0; childIndex < kSAPChildrenLimit; childIndex ++) {
        assert(NULL == SAPDynamicArrayObjectAtIndex(testHuman->_children, childIndex));
    }
    
    SAPObjectRelease(testHuman);
    //after release test Human doesn't exist, and at this case release() method must return 0.
    assert(0 == SAPObjectRetainCount(testHuman));
    SAPObjectRetainCount(testHuman);
    printf("OK\n");
}

void SAPPerformTestHumanCreateWithParameters(void) {
    printf("===Perform SAPHumanCreateWithParameters() test ===\n");
    SAPHuman *testHuman = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderMale);
    //human object must be created
    assert(NULL != testHuman);
    //special testHuman must be male
    assert(kSAPHumanGenderMale == SAPHumanGender(testHuman));
    //initial retainCount must be 1 + mother and father retained it. Hence retain count = 3.
    assert(3 == SAPObjectRetainCount(testHuman));
    //fields Mother, Father and Gender must be set.
    assert(0 == strcmp(testMothersNameString,SAPStringValue(SAPHumanName(SAPHumanMother(testHuman)))));
    assert(kSAPHumanGenderFemale == SAPHumanGender(SAPHumanMother(testHuman)));
    assert(0 == strcmp(testFathersNameString, SAPStringValue(SAPHumanName(SAPHumanFather(testHuman)))));
    assert(kSAPHumanGenderMale == SAPHumanGender(SAPHumanFather(testHuman)));
    SAPReleaseSpecialTestHumanWithParameters(testHuman);
    //this special function must release human and his parents
    assert(0 == SAPObjectRetainCount(testHuman));
    printf("OK\n");
}

void SAPPerformTestSAPHumanSetName(void) {
    printf("===Perform SAPHumanSetName() test===\n");
    SAPHuman *testHuman = SAPHumanCreate(kSAPHumanGenderMale);
    char *name = "Petya";
    SAPHumanSetName(testHuman, SAPStringCreate(name));
    //object must have the right name after setting
    assert(0 == strcmp(name, SAPStringValue(SAPHumanName(testHuman))));
    //the property must not be string constant
    assert("Petya" != SAPStringValue(SAPHumanName(testHuman)));
    SAPObjectRelease(testHuman);
    assert(0 == SAPObjectRetainCount(testHuman));
    printf("OK\n");
}

void SAPPerformTestSAPHumanSetAge(void) {
    printf("===Perform SAPHumanSetAge() test===\n");
    SAPHuman *testHuman = SAPHumanCreate(kSAPHumanGenderMale);
    assert(0 == SAPHumanAge(testHuman));
    SAPHumanSetAge(testHuman, 22);
    assert(22 == SAPHumanAge(testHuman));
    // printf("Human's age after setting age is %d\n", SAPHumanAge(testHuman));
    SAPObjectRelease(testHuman);
    printf("OK\n");
}

void SAPPerformTestSAPHumanChildrenCount(void) {
    printf("===Perform SAPHumanChildrenCount() test===\n");
    SAPHuman *testHuman = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderMale);
    SAPHuman *testHumanFemale = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderFemale);
    SAPHumanMarry(testHuman, testHumanFemale);
    SAPHuman *child1 = SAPHumanCreateChild(testHuman, kSAPHumanGenderMale);
    SAPHuman *child2 =SAPHumanCreateChild(testHuman, kSAPHumanGenderFemale);
    SAPHuman *child3 =SAPHumanCreateChild(testHuman, kSAPHumanGenderFemale);
    assert(3 == SAPHumanChildrenCount(testHuman));
    SAPReleaseSpecialTestHumanWithParameters(testHuman);
    SAPReleaseSpecialTestHumanWithParameters(child1);
    SAPReleaseSpecialTestHumanWithParameters(child2);
    SAPReleaseSpecialTestHumanWithParameters(child3);
    printf("OK\n");
}

void SAPPerformBehaviorTest(void) {
    printf("===Perform behavior test===\n");
    SAPHuman *testMan = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderMale);
    SAPHumanSetName(testMan, SAPStringCreate("TestMan"));
    SAPHuman *testWoman = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderFemale);
    SAPHumanSetName(testWoman, SAPStringCreate("TestWoman"));
    //assert(true ==
    SAPHumanMarry(testMan, testWoman);
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
    
   // assert(true ==
    SAPHumanDivorce(testMan);
    //after divorce each former spouse must have not partner
    assert(NULL == SAPHumanPartner(testMan));
    assert(NULL == SAPHumanPartner(testWoman));
    //after divorce each former spouse must not be married
    assert(false == SAPHumanIsMarried(testMan));
    assert(false == SAPHumanIsMarried(testWoman));
    
    //marry again for another test
   // assert(true ==
    SAPHumanMarry(testMan, testWoman);
    SAPHuman *testMan2 = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderMale);
    SAPHumanSetName(testMan2, SAPStringCreate("TestMan2"));
    //marry again for further test
    //assert(true ==
    SAPHumanMarry(testMan2, testWoman);
    //after marriage former spouses must firstly divorce
    assert(testMan != SAPHumanPartner(testWoman));
    assert(testWoman != SAPHumanPartner(testMan));
    assert(NULL == SAPHumanPartner(testMan));
    //and new pair must get merried
    assert(testMan2 == SAPHumanPartner(testWoman));
    assert(testWoman == SAPHumanPartner(testMan2));
    
    //in this test the initial amount of children of each partner is 0
    assert(0 == SAPHumanChildrenCount(testWoman));
    assert(0 == SAPHumanChildrenCount(SAPHumanPartner(testWoman)));
    SAPHuman *child = SAPHumanCreateChild(testWoman, kSAPHumanGenderMale);
    assert(NULL != child);
    //woman born boy
    assert(kSAPHumanGenderMale == SAPHumanGender(child));
    SAPHumanSetName(child, SAPStringCreate("Baby1"));
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
    SAPReleaseSpecialTestHumanWithParameters(testWoman);
    SAPObjectRelease(child);
    printf("OK\n");
}

void SAPPerformMemoryManagementTest(void) {
    printf("===Perform memory management test===\n");
    SAPHuman *testMan = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderMale);
    SAPHumanSetName(testMan, SAPStringCreate("TestMan"));
    assert(3 == SAPObjectRetainCount(testMan));
    SAPHuman *testWoman = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderFemale);
    SAPHumanSetName(testWoman, SAPStringCreate("TestWoman"));
    assert(3 == SAPObjectRetainCount(testWoman));
    SAPHumanMarry(testMan, testWoman);
    //Man retains Woman hence womans retainCount must be incremented (from 3 to 4)
    assert(4 == SAPObjectRetainCount(testWoman));
    //man's retainCount must not be incremented (remain 3)
    assert(3 == SAPObjectRetainCount(testMan));
    SAPHumanDivorce(testMan);
    //after divorce man's retainCount must decrement
    assert(3 == SAPObjectRetainCount(testMan));
    //woman's retain count must remain
    assert(3 == SAPObjectRetainCount(testWoman));
    SAPHumanMarry(testMan, testWoman);
    //here testWoman's retainCount again 4, testMan's 3
    SAPHuman *testMan2 = SAPCreateSpecialTestHumanWithParameters(kSAPHumanGenderMale);
    //testMan2's initial retain count is 3
    assert(3 == SAPObjectRetainCount(testMan2));
    SAPHumanSetName(testMan2, SAPStringCreate("TestMan2"));
    SAPHumanMarry(testMan2, testWoman);
    //testWoman's retainCount must increment (from 3 to 4) while testMan's and testMan2's retainCount must remain
    assert(3 == SAPObjectRetainCount(testMan));
    assert(3 == SAPObjectRetainCount(testMan2));
    assert(4 == SAPObjectRetainCount(testWoman));
    SAPHuman *child = SAPHumanCreateChild(testWoman, kSAPHumanGenderMale);
    //child's retain count must be 3 (initial 1 + mother's retain + father's retain)
    assert(3 == SAPObjectRetainCount(child));
    SAPReleaseSpecialTestHumanWithParameters(testMan);
    assert(0 == SAPObjectRetainCount(testMan));
    SAPReleaseSpecialTestHumanWithParameters(testMan2);
    assert(0 == SAPObjectRetainCount(testMan2));
    SAPReleaseSpecialTestHumanWithParameters(testWoman);
    assert(0 == SAPObjectRetainCount(testWoman));
    SAPObjectRelease(child);
    assert(0 == SAPObjectRetainCount(child));
    printf("OK\n");
}

#pragma mark -
#pragma mark Public implementations

void SAPPerformAllHumanTests(void) {
    printf("=====================H U M A N ======================\n");
    SAPPerformHumanCreateTest();
    SAPPerformTestSAPHumanSetName();
    SAPPerformTestHumanCreateWithParameters();
    SAPPerformTestSAPHumanChildrenCount();
    SAPPerformBehaviorTest();
    SAPPerformMemoryManagementTest();
}
