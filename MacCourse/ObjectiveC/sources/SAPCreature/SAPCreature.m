//
//  SAPCreature.m
//  MacCourse
//
//  Created by S A P on 11/18/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPCreature.h"

@interface SAPCreature ()

@property (nonatomic, retain) NSMutableSet *mutableChildren;

@end

@implementation SAPCreature

@dynamic children;

#pragma mark-
#pragma mark Class Methods

+ (SAPCreature *)creature {
    return [[[self alloc] init] autorelease] ;
}

+ (SAPCreature *)creatureWithGender:(SAPGender)gender {
    return [[[self alloc] initWithGender:gender] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableChildren = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableChildren = [NSMutableSet set];
    }
    
    return self;
}

- (instancetype)initWithGender:(SAPGender)gender {
    self = [self init];
    if (self) {
        self.gender = gender;
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSSet *) children {
    return [[self.mutableChildren copy] autorelease];
}

#pragma mark-
#pragma mark Public Methods

- (void)fight {
    NSLog(@"Must die!!!!!");
}

- (SAPCreature *)bornChildWithGender:(SAPGender)gender {
    return [SAPCreature creatureWithGender:gender];
}

- (void)sayHello {
    NSLog(@"Hello, I'm %@", self.name);
    for (SAPCreature *child in self.mutableChildren) {
        [child sayHello];
    }
}

- (void)addChild:(SAPCreature *)child {
    if ([child isKindOfClass:[SAPCreature class]]) {
        [self.mutableChildren addObject:child];
    }
}
         
- (void)removeChild:(SAPCreature *)child {
    [self.mutableChildren removeObject:child];
}
         
#pragma mark-
#pragma mark Private Methods


@end
