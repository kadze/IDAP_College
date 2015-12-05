//
//  SAPEnumeratedStringTests.m
//  MacCourse
//
//  Created by S A P on 11/30/15.
//  Copyright © 2015 Yosemite Retail. All rights reserved.
//

#import <Kiwi/Kiwi.h>
#import "SAPEnumeratedString.h"

SPEC_BEGIN(EnumeratedStringSpec)

describe(@"SAPEnumeratedString", ^{
    context(@"NSFastEnumeration", ^{
        __block SAPEnumeratedString *string = [SAPEnumeratedString new];
        string.string = @"3212asdfdasf";
        
        it(@"shouldn't raise while enumerated", ^{
            for (NSString *object in string) {
                NSLog(@"%@", object);
            }
        });
    });
    
    context(@"inheritance", ^{
        __block SAPEnumeratedString *string = nil;
        beforeAll(^{
            string = [SAPEnumeratedString new];
            string.string = @"asdfadsfadsf";
        });
        
        it(@"should be subclass of NSString", ^{
            [[string shouldNot] beKindOfClass:[NSString class]];
        });
    });
    
});

SPEC_END
