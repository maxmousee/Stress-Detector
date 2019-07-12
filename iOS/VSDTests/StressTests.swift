//
//  StressTest.swift
//  VSDTests
//
//  Created by Natan Facchin on 12/07/2019.
//  Copyright © 2019 Natan Facchin. All rights reserved.
//

import XCTest
@testable import VSD

class StressTests: XCTestCase {

    func testStressLowFreq() {
        let stress = Stress(stressCoeficient: 4)
        XCTAssertEqual(UIColor.red.cgColor, stress.color)
        XCTAssertEqual(StressLevel.stress, stress.stressLvl)
        XCTAssertEqual("4.00Hz\nstress", stress.displayMessage)
    }
    
    func testStressHighFreq() {
        let stress = Stress(stressCoeficient: 15.01)
        XCTAssertEqual(UIColor.red.cgColor, stress.color)
        XCTAssertEqual(StressLevel.stress, stress.stressLvl)
        XCTAssertEqual("15.01Hz\nstress", stress.displayMessage)
    }
    
    func testNoStressLowFreq() {
        let stress = Stress(stressCoeficient: 8)
        XCTAssertEqual(UIColor.green.cgColor, stress.color)
        XCTAssertEqual(StressLevel.nostress, stress.stressLvl)
        XCTAssertEqual("8.00Hz\nno stress", stress.displayMessage)
    }
    
    func testNoStressHighFreq() {
        let stress = Stress(stressCoeficient: 14)
        XCTAssertEqual(UIColor.green.cgColor, stress.color)
        XCTAssertEqual(StressLevel.nostress, stress.stressLvl)
        XCTAssertEqual("14.00Hz\nno stress", stress.displayMessage)
    }
    
    func testMarginalStressLowFreq() {
        let stress = Stress(stressCoeficient: 7.99)
        XCTAssertEqual(UIColor.orange.cgColor, stress.color)
        XCTAssertEqual(StressLevel.marginalstress, stress.stressLvl)
        XCTAssertEqual("7.99Hz\nmarginal stress", stress.displayMessage)
    }
    
    func testMarginalStressHighFreq() {
        let stress = Stress(stressCoeficient: 14.99)
        XCTAssertEqual(UIColor.orange.cgColor, stress.color)
        XCTAssertEqual(StressLevel.marginalstress, stress.stressLvl)
        XCTAssertEqual("14.99Hz\nmarginal stress", stress.displayMessage)
    }

}
