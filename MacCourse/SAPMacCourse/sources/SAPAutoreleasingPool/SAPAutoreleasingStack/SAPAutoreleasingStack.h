//
//  SAPAutoreleasingStack.h
//  MacCourse
//
//  Created by S A P on 11/12/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#ifndef SAPAutoreleasingStack_h
#define SAPAutoreleasingStack_h

#include <stdbool.h>
#include "SAPObject.h"

typedef struct SAPAutoreleasingStack SAPAutoreleasingStack;

struct SAPAutoreleasingStack {
    SAPObject _super;
    
    void **_data;
    void *_head;
    size_t _size;
};

typedef enum {
    kSAPAutoreleasingStackPopedNULL,
    kSAPAutoreleasingStackPopedObject
} SAPAutoreleasingStackPopType;

extern
SAPAutoreleasingStack *SAPAutoreleasingStackCreateWithSize(size_t size);

extern
bool SAPAutoreleasingStackIsEmpty(SAPAutoreleasingStack *stack);

extern
bool SAPAutoreleasingStackIsFull(SAPAutoreleasingStack *stack);

extern
void SAPAutoreleasingStackPushObject(SAPAutoreleasingStack *stack, void *object);

extern
SAPAutoreleasingStackPopType SAPAutoreleasingStackPopObject(SAPAutoreleasingStack *stack);

extern
SAPAutoreleasingStackPopType SAPAutoreleasingStackPopObjectsUntilNULL(SAPAutoreleasingStack *stack);

#endif /* SAPAutoreleasingStack_h */
