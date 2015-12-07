//
//  SAPAlphabetWithArray.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPArrayAlphabet.h"

@interface SAPArrayAlphabet ()

@property (nonatomic, retain) NSArray *lettersArray;

@end



@implementation SAPArrayAlphabet
//@dynamic letters;

#pragma mark-
#pragma mark Initializations and Deallocations

- (void) dealloc {
    self.lettersArray = nil;
    [super dealloc];
}

- (instancetype) initWithArray:(NSArray *) array {
//    self = [super init];
    if (self) {
        self.lettersArray = array;
    }
    
    return self;
}

//#pragma mark-
//#pragma mark Accessors
//
//- (NSArray *) letters {
//    return self.lettersArray;
//}

#pragma mark-
#pragma mark Public Methods

- (NSArray *)arrayOfLetters {
    return self.lettersArray;
}

- (NSString *)letterAtIndex:(NSUInteger) index {
    return [self.lettersArray objectAtIndex:index];
}

- (NSUInteger)count {
    return [self lettersArray].count;
}

#pragma mark-
#pragma mark NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id  _Nonnull *)buffer
                                    count:(NSUInteger)len {
    return [[self lettersArray ]countByEnumeratingWithState:state objects:buffer count:len];
}

@end
