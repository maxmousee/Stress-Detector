//
//  VSDTests.m
//  VSDTests
//
//  Created by Natan Facchin on 5/31/14.
//  Copyright (c) 2014 nfsindustries. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <KIF/KIF.h>


@interface VSDTests : XCTestCase

@end

@implementation VSDTests

- (void)setUp
{
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown
{
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testStartUpPerformance
{
    CFTimeInterval startTime = CACurrentMediaTime();
    //Test the performance of this function.
    [tester waitForAnimationsToFinish];
    CFTimeInterval elapsedTime = CACurrentMediaTime() - startTime;
    NSLog(@"startUp Time %f", elapsedTime);
    if (elapsedTime > 10.0) {
        XCTFail(@"VSD is taking too long to start");
    }
}


@end
