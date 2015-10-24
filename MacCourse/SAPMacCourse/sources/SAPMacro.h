//
//  macro.h
//  MacCourse
//
//  Created by Andrey Shevtsov on 10/22/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef MacCourse_macro_h
#define MacCourse_macro_h

#define SAPObjectIVarGetterSynthesize(objectVariableName,ivar) \
    return NULL != objectVariableName ? objectVariableName->ivar : NULL

#define SAPObjectIVarSetterSynthesize(objectVariableName, ivar) \
    if (NULL != objectVariableName) { \
        objectVariableName->_##ivar = ivar; \
    }

#define SAPObjectRetainingSetterSynthesize(objectVariableName, ivar) \
    if (NULL == objectVariableName || ivar == objectVariableName->_##ivar) { \
        return; \
    } \
    SAPObjectRetain(ivar); \
    SAPObjectRelease(objectVariableName->_##ivar); \
    objectVariableName->_##ivar = ivar; \

#endif
