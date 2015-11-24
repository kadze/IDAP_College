//
//  SAPCreatureTests.m
//  MacCourse
//
//  Created by S A P on 11/19/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCreatureTests.h"
#import "SAPCreature.h"
#import "SAPMan.h"
#import "SAPWoman.h"
#import "SAPStringAdditions.h"

@implementation SAPCreatureTests

+(void)performSAPCreatureTests {
    [SAPCreatureTests performSAPCreatureHalloTest];
    [SAPCreatureTests performSAPAddChildTest];
    [SAPCreatureTests performTestByTechAssignment];
}

+(void)performSAPCreatureHalloTest {
    NSLog(@"Performing %@ test", NSStringFromSelector(_cmd));
    
    SAPCreature *creature = [SAPCreature creatureWithGender:kSAPGenderMale];
    [creature setName:@"Bob"];
    SAPCreature *child1 = [SAPCreature creatureWithGender:kSAPGenderMale];
    SAPCreature *child2 = [SAPCreature creatureWithGender:kSAPGenderMale];
    SAPCreature *grandchild1 = [SAPCreature creatureWithGender:kSAPGenderMale];
    SAPCreature *grandchild2 = [SAPCreature creatureWithGender:kSAPGenderMale];
    [child1 setName:@"Child1"];
    [child2 setName:@"Child2"];
    [grandchild1 setName:@"Grandchild1"];
    [grandchild2 setName:@"Grandchild2"];
    [creature addChild:child1];
    [creature addChild:child2];
    [child1 addChild:grandchild1];
    [child1 addChild:grandchild2];
    [creature sayHello];
    
    NSLog(@"OK");
}

+(void)performSAPAddChildTest {
    NSLog(@"Performing %@ test\n", NSStringFromSelector(_cmd));
    
    SAPCreature *creature = [SAPCreature creatureWithGender:kSAPGenderMale];
    [creature setName:@"Bob"];
    SAPCreature *child1 = [SAPCreature creatureWithGender:kSAPGenderFemale];
    SAPCreature *child2 = [SAPCreature creatureWithGender:kSAPGenderFemale];
    [creature addChild:child1];
    [creature addChild:child2];
    assert(2 ==[[creature children] count]);
    
    NSLog(@"OK\n");
}

+(void)performTestByTechAssignment {
    NSLog(@"Performing %@ test\n", NSStringFromSelector(_cmd));
    
    SAPCreature *creature1 = [SAPCreature creatureWithGender:kSAPGenderMale];
    [creature1 setName:@"Bob"];

    SAPCreature *creature2 = [SAPCreature creatureWithGender:kSAPGenderMale];
    [creature2 setName:@"Frank"];
    
    SAPCreature *creature3 = [SAPCreature creatureWithGender:kSAPGenderFemale];
    [creature3 setName:@"Lucy"];
    
    NSArray *creatures = @[creature1, creature2, creature3];
    for (SAPCreature *creature in creatures) {
        NSUInteger initialChildrenCount = [[creature children] count];
        [creature performGengerSpecificOperation];
        if ([creature isMemberOfClass:[SAPWoman class]]) {
            assert((initialChildrenCount + 1) ==[[creature children] count]);
        }
    }
    
    NSLog(@"OK\n");
    
    NSString *start = @"lalalalalala";
    NSMutableString *finish = [start sap_separateWithSpaces];
    NSLog(@"%@",finish);
}
@end
