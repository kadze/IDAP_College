//
//  Structures.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//
#include <stdio.h>
#include "SAPStructuresTest.h"
#include "SAPStructures.h"


SAPStructSize(SAPBigStructure)
SAPStructSize(SAPSmallerStructure)
SAPStructSize(SAPSmallStructure)

//create test method so as to output the size of the entire structure
void SAPPerformTestPrintSizeOfStructures(void) {
    SAPPrintStructSize(SAPBigStructure);
    SAPPrintStructSize(SAPSmallerStructure);
    SAPPrintStructSize(SAPSmallStructure);
}

//create test method to output the possition of the each member of structure with the help of "offsetof"
void SAPPerformTestPrintStructMemberPositions(void) {
    SAPPrintStructMemberPositions(SAPBigStructure)
    SAPPrintStructMemberPositions(SAPSmallerStructure)
    SAPPrintSmallStructMemberPositions(SAPSmallStructure)
}