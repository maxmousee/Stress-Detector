//
//  VSDUITests.swift
//  VSDUITests
//
//  Created by Natan Facchin on 4/10/19.
//  Copyright © 2019 Natan Facchin. All rights reserved.
//

import XCTest
@testable import VSD

class VSDUITests: XCTestCase {

    override func setUp() {
        // In UI tests it is usually best to stop immediately when a failure occurs.
        continueAfterFailure = false
    }

    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
    }

    func testApplicationStarts() {
        XCUIApplication().launch()
        XCTAssertEqual(.runningForeground, XCUIApplication().state)
        // Use recording to get started writing UI tests.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
    }
    
    func testStartupPerformance() {
        self.measure {
            XCUIApplication().launch()
        }
    }

}
