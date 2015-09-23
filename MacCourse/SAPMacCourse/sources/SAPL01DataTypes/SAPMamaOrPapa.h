//
//  SAPMamaOrPapa.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPMamaOrPapa__
#define __MacCourse__SAPMamaOrPapa__


#pragma mark -
#pragma mark Public implementations

//enum dividers;
typedef enum {
    papa,
    mama,
    mamapapa,
    outOfCondition
} parents;

#pragma mark -
#pragma mark Public declarations

extern
char* getParentName(parents);

extern
parents SAPDefineParent(int param);

#endif /* defined(__MacCourse__SAPMamaOrPapa__) */
