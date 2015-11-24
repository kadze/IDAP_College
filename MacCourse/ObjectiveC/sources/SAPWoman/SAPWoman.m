//
//  SAPWoman.m
//  MacCourse
//
//  Created by S A P on 11/19/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPWoman.h"

@implementation SAPWoman

- (void)performGengerSpecificOperation {
    SAPGender genderForChild = ([self.children count] % 2 == 0) ? kSAPGenderMale : kSAPGenderFemale;
    SAPCreature *child = [[SAPCreature creatureWithGender:genderForChild] autorelease];
    [self addChild:child];
}

@end
