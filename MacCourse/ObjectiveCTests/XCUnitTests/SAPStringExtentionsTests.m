//
//  SAPStringExtentionsTests.m
//  MacCourse
//
//  Created by Andrey Shevtsov on 11/29/15.
//  Copyright (c) 2015 Yosemite Retail. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "NSString+SAPStringExtentions.h"

@interface SAPStringExtentionsTests : XCTestCase

@end

@implementation SAPStringExtentionsTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testSap_separateWithSpacesTest {
    NSString *start = @"lalalalalala";
    NSString *finish = [start sap_separateWithSpaces];
    XCTAssert([finish isEqualToString:@"l a l a l a l a l a l a"], @"result of separation with spaces isn't right");
    
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
