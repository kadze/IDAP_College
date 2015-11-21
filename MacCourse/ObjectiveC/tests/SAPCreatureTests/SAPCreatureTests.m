//
//  SAPCreatureTests.m
//  MacCourse
//
//  Created by S A P on 11/19/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCreatureTests.h"
#import "SAPCreature.h"

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
    SAPCreature *child1 = [creature bornChildWithGender:kSAPGenderFemale];
    SAPCreature *child2 = [creature bornChildWithGender:kSAPGenderFemale];
    [creature addChild:child1];
    [creature addChild:child2];
    assert(2 ==[[creature children] count]);
    
    NSLog(@"OK\n");
}

+(void)performTestByTechAssignment {
    NSLog(@"Performing %@ test\n", NSStringFromSelector(_cmd));
    
    SAPCreature *creature1 = [SAPCreature creatureWithGender:kSAPGenderMale];
    [creature1 setName:@"Bob"];
    SAPCreature *child1 = [creature1 bornChildWithGender:kSAPGenderFemale];
    SAPCreature *child2 = [creature1 bornChildWithGender:kSAPGenderFemale];
    [creature1 addChild:child1];
    [creature1 addChild:child2];

    SAPCreature *creature2 = [SAPCreature creatureWithGender:kSAPGenderMale];
    [creature2 setName:@"Frank"];
    SAPCreature *child3 = [creature2 bornChildWithGender:kSAPGenderFemale];
    SAPCreature *child4 = [creature2 bornChildWithGender:kSAPGenderFemale];
    [creature2 addChild:child3];
    [creature2 addChild:child4];

    SAPCreature *creature3 = [SAPCreature creatureWithGender:kSAPGenderFemale];
    [creature3 setName:@"Lucy"];
    SAPCreature *child5 = [creature3 bornChildWithGender:kSAPGenderFemale];
    SAPCreature *child6 = [creature3 bornChildWithGender:kSAPGenderFemale];
    [creature3 addChild:child5];
    [creature3 addChild:child6];
    
    NSArray *creatures = @[creature1, creature2, creature3];
    for (SAPCreature *creature in creatures) {
        if (kSAPGenderMale == [creature gender]) {
            [creature fight];
        } else if (kSAPGenderFemale == [creature gender]) {
            SAPCreature *boy = [creature bornChildWithGender:kSAPGenderMale];
            assert(NULL != boy);
        }
    }
    
    NSLog(@"OK\n");
}
@end
