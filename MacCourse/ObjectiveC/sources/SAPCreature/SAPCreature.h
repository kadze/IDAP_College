//
//  SAPCreature.h
//  MacCourse
//
//  Created by S A P on 11/18/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum SAPGender : NSUInteger{
    kSAPGenderMale,
    kSAPGenderFemale,
    kSAPGenderHermaphrodite
}SAPGender;

@interface SAPCreature : NSObject

@property SAPGender gender;

@property NSString *name;

@property NSNumber *mass;

@property NSNumber *age;

@property NSSet *children;


+(SAPCreature *)creature;

+(SAPCreature *)creatureWithGender:(SAPGender)gender;


-(void)fight;

-(SAPCreature *)bornChildWithGender:(SAPGender)gender;

-(void)addChild:(SAPCreature *)child;

-(void)removeChild:(SAPCreature *)child;

-(void)sayHello;

-(void)sayHello:(SAPCreature *)creature;

@end

