//
//  SAPCreature.m
//  MacCourse
//
//  Created by S A P on 11/18/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCreature.h"

@implementation SAPCreature

#pragma mark-
#pragma mark Class Methods

+(SAPCreature *)creature {
    SAPCreature *object = [self new];
    
    return object;
}

+(SAPCreature *)creatureWithGender:(SAPGender)gender {
    SAPCreature *object = [self creature];
    [object setGender:gender];

    return object;
}

#pragma mark-
#pragma mark Public Methods

-(void)fight {
    NSLog(@"Must die!!!!!");
}

-(SAPCreature *)bornChildWithGender:(SAPGender)gender {
    SAPCreature *child = [SAPCreature creatureWithGender:gender];
    
    return child;
}

-(void)sayHello {
    [self sayHello:self];
}

-(void)sayHello:(SAPCreature *)creature {
    NSLog(@"Hello, I'm %@", [creature name]);
    for (SAPCreature *child in [creature children]) {
        [child sayHello];
    }
}

-(void)addChild:(SAPCreature *)child {
    NSSet *chidren = [self children];
    NSMutableSet *childrenSet = [NSMutableSet setWithSet:chidren];
    [childrenSet addObject:child];
    chidren = [NSSet setWithSet:childrenSet];
    [self setChildren:chidren];
    
    [childrenSet release];
}
#pragma mark-
#pragma mark Private Methods


@end
