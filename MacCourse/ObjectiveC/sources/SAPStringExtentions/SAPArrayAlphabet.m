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
@dynamic letters;

#pragma mark-
#pragma mark Initializations and Deallocations

- (void) dealloc {
    self.lettersArray = nil;
    [super dealloc];
}

- (instancetype) initWithArray:(NSArray *) array {
    self = [super init];
    if (self) {
        self.lettersArray = array;
    }
    
    return self;
}

#pragma mark-
#pragma mark Accessors

- (NSArray *) letters {
    return self.lettersArray;
}

#pragma mark-
#pragma mark Public Methods

- (NSArray *)arrayOfLetters {
    return self.letters;
}

- (id)letterAtIndex:(NSUInteger) index {
    return [self.letters objectAtIndex:index];
}

- (NSUInteger)length {
    return [self letters].count;
}
@end
