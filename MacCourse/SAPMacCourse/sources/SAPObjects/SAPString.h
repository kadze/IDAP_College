//
//  SAPString.h
//  MacCourse
//
//  Created by S A P on 10/21/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPString_h
#define SAPString_h

#include "SAPObject.h"
#include <stdlib.h>

typedef struct {
    SAPObject _super;
    char *_value;
} SAPString;

extern
SAPString *SAPStringCreate(char *value);

extern
void __SAPStringDeallocate(SAPString *object);

extern
char *SAPStringValue(SAPString *object);

extern
void SAPStringSetValue(SAPString *object, const char *value);

extern
void SAPStringPrint(SAPString *object);

extern
size_t SAPStringLength(SAPString *object);

#endif /* SAPString_h */
