//
//  SAPAlphabetWithString.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import "NSObject+SAPObject.h"
#import "SAPStringAlphabet.h"
#import "SAPEnumeratedString.h"

@interface SAPStringAlphabet ()
@property (nonatomic, retain) NSString *lettersString;

@end

@implementation SAPStringAlphabet

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.lettersString = nil;
    [super dealloc];
}

- (instancetype)initWithString:(NSString *)string {
    //self = [super init];
    if (self) {
        self.lettersString = string;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (NSArray *)letters {
    SAPEnumeratedString *enumeratedLetters = [SAPEnumeratedString object];
    enumeratedLetters.string = self.lettersString;
    NSMutableArray *mutableResult = [NSMutableArray arrayWithCapacity:self.lettersString.length];
    for (NSString *letter in enumeratedLetters) {
        [mutableResult addObject:letter];
    }
    
    return [[mutableResult copy] autorelease];
}

- (NSString *)letterAtIndex:(NSUInteger)index {
    return [[self letters] objectAtIndex:index];
}

- (NSUInteger)count {
    return [self lettersString].length;
}

@end
