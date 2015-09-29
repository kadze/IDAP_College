//
//  SAPBinaryData.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/24/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPBinaryData_h
#define SAPBinaryData_h

#include <stdlib.h>

#pragma mark--
#pragma mark Public declarations
typedef enum{
    BigEndian,
    LittleEndian
} SAPEndian;
extern
void SAPPrintBitsOfAnyTypeNumberBigEndian(void *value, size_t size);
extern
void SAPPrintBitsOfAnyTypeNumberLittleEndian(void *value, size_t size);
extern
void SAPValueBitOutput(void *data, size_t size, SAPEndian endian);
extern
void SAPValueBitOutputAnyEndian(void *data, size_t size);
extern
SAPEndian SAPGetEndianWithPointer();
extern
SAPEndian SAPGetEndianWithUnion();

#endif /* SAPBinaryData_h */
