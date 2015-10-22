//
//  SAPPrintTypesSize.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPPrintTypesSize__
#define __MacCourse__SAPPrintTypesSize__

#define SAPSizeofOutput(type) \
    printf("Size of type " #type " = %lu\n", sizeof(type))

extern
void SAPPrintTypeSize();

#endif /* defined(__MacCourse__SAPPrintTypesSize__) */
