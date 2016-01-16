//
//  SAPCreature.h
//  MacCourse
//
//  Created by S A P on 11/18/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, SAPGender) {
    kSAPGenderMale,
    kSAPGenderFemale,
    kSAPGenderHermaphrodite
};

@interface SAPCreature : NSObject
@property (nonatomic, copy)             NSString       *name;
@property (nonatomic, readonly)         NSSet          *children;
@property (nonatomic, assign)           NSUInteger     *mass;
@property (nonatomic, assign)           NSUInteger     *age;

+ (instancetype)creatureWithGender:(SAPGender)gender;
+ (Class)classForGender:(SAPGender)gender;

- (instancetype)initWithGender:(SAPGender)gender;

- (id)performGengerSpecificOperation;
- (void)addChild:(SAPCreature *)child;
- (void)removeChild:(SAPCreature *)child;
- (void)sayHello;

@end

