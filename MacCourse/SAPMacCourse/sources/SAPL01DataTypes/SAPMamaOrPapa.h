//
//  SAPMamaOrPapa.h
//  MacCourse
//
//  Created by Yosemite Retail on 9/17/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#ifndef __MacCourse__SAPMamaOrPapa__
#define __MacCourse__SAPMamaOrPapa__

//#include <stdio.h>


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

char* getParentName(parents);
parents SAPDefineMamaOrPapa(int param);

#endif /* defined(__MacCourse__SAPMamaOrPapa__) */
