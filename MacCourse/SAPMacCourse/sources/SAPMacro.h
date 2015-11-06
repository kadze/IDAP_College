//
//  macro.h
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/22/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef MacCourse_macro_h
#define MacCourse_macro_h

#define SAPObjectIVarGetterSynthesize(objectVariableName, ivar, defaultValue) \
    NULL != objectVariableName ? objectVariableName->ivar : defaultValue

#define SAPObjectIVarSetterSynthesize(objectVariableName, ivar) \
    if (NULL != objectVariableName) { \
        objectVariableName->_##ivar = ivar; \
    }

#define SAPObjectRetainSetterSynthesize(objectVariableName, ivar) \
    if (NULL == objectVariableName || ivar == objectVariableName->_##ivar) { \
        return; \
    } \
    SAPObjectRetain(ivar); \
    SAPObjectRelease(objectVariableName->_##ivar); \
    objectVariableName->_##ivar = ivar \

#define SAPReturnIfObjectNULL \
    if (NULL == object) {\
        return;\
    }

#define SAPReturnValueIfObjectNULL(value) \
    if (NULL == object) {\
        return value;\
    }
#define SAPReturnIfNULL(var)\
    if (NULL == var) {\
        return;\
    }

#define SAPReturnIfValuesEqual(value1, value2) \
    if(value1 == value2) {\
        return;\
    }

#endif
