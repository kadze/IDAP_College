//
//  Structures.c
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#include "SAPStructures.h"
#include "SAPStructuresTest.h"

#pragma mark -
#pragma mark Private implementations

SAPStructSize(SAPBigStructure)
SAPStructSize(SAPSmallerStructure)
SAPStructSize(SAPSmallStructure)

//create test method so as to output the size of the entire structure
void SAPPerformTestPrintSizeOfStructures(){
    SAPPrintStructSize(SAPBigStructure);
    SAPPrintStructSize(SAPSmallerStructure);
    SAPPrintStructSize(SAPSmallStructure);
}
