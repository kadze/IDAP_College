//
//  main.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/15/15
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#include <stdio.h>
#include "SAPLesson1Tests.h"
#include "SAPRunFunctionCreateMacros.h"
#include "SAPStructuresTest.h"
#include "SAPBinaryTest.h"
#include "SAPHumanTests.h"

int main(int argc, const char * argv[]) {

//    //testing
//    
//    //lesson 1
//    SAPPerformTestPrintTypeSize();
//    SAPPerformTestDefineParent();
//    SAPPeformTestDefineParentInLoop();
//    
//    //leson 2
//    
//    //function creation and performing with macros
//    SAPRunFunctionCreationMacros();
//    
//    //lesson 3
//    //structures
//    SAPPerformTestPrintSizeOfStructures();
//    SAPPerformTestPrintStructMemberPositions();
//    
//    
//    //binary data
//    SAPPerformTestPrintBitsOfAnyTypeNumber();
//    
//    SAPPerformTestGetEndian();
    
    //Human
    SAPPerformAllHumanTests();
    
    return 0;
}


