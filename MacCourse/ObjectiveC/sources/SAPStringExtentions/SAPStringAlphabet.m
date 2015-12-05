//
//  SAPAlphabetWithString.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "SAPStringAlphabet.h"
#import "SAPEnumeratedString.h"

@interface SAPStringAlphabet ()

@property (nonatomic, retain) NSString *lettersString;

@end


@implementation SAPStringAlphabet
//@dynamic letters;

#pragma mark-
#pragma mark Initializations and Deallocations

- (void) dealloc {
    self.lettersString = nil;
    [super dealloc];
}

- (instancetype) initWithString:(NSString *)string {
    self = [super init];
    if (self) {
        self.lettersString = string;
    }
    
    return self;
}

//#pragma mark-
//#pragma mark Accessors
//
//- (NSString *) letters {
//    return self.lettersString;
//}

#pragma mark-
#pragma mark Public Methods

- (NSArray *)arrayOfLetters {
    SAPEnumeratedString *enumeratedLetters = [[[SAPEnumeratedString alloc] init] autorelease] ;
    enumeratedLetters.string = self.lettersString;
    NSMutableArray *mutableResult = [[NSMutableArray new] autorelease];
    for (NSString *letter in enumeratedLetters) {
        [mutableResult addObject:letter];
    }
    
    return [mutableResult copy];
};

- (NSString *)letterAtIndex:(NSUInteger) index {
    return [[self arrayOfLetters] objectAtIndex:index];
};

- (NSUInteger)length {
    return [self lettersString].length;
}
@end
