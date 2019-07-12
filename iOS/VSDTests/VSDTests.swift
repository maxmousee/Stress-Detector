//
//  VSDTests.swift
//  VSDTests
//
//  Created by Natan Facchin on 4/10/19.
//  Copyright © 2019 Natan Facchin. All rights reserved.
//

import XCTest
@testable import VSD

class VSDTests: XCTestCase {

    func testWithZeros() {
        let sampleRate = 8000
        var inputAudioBuffer: Array<Double> = Array(repeating: 0, count: sampleRate)
        let inputAudioUMP = UnsafeMutablePointer<Double>.allocate(capacity: sampleRate)
        inputAudioUMP.initialize(from: &inputAudioBuffer, count: Int(sampleRate))
        let stressFreq = vsd(inputAudioUMP, Int32(sampleRate))
        XCTAssertEqual(0, stressFreq)
    }
    
    func testWithOnes() {
        let sampleRate = 8000
        var inputAudioBuffer: Array<Double> = Array(repeating: 1, count: sampleRate)
        let inputAudioUMP = UnsafeMutablePointer<Double>.allocate(capacity: sampleRate)
        inputAudioUMP.initialize(from: &inputAudioBuffer, count: Int(sampleRate))
        let stressFreq = vsd(inputAudioUMP, Int32(sampleRate))
        XCTAssertEqual(0, stressFreq)
    }
    
    func testWithNegativeOnes() {
        let sampleRate = 8000
        var inputAudioBuffer: Array<Double> = Array(repeating: -1, count: sampleRate)
        let inputAudioUMP = UnsafeMutablePointer<Double>.allocate(capacity: sampleRate)
        inputAudioUMP.initialize(from: &inputAudioBuffer, count: Int(sampleRate))
        let stressFreq = vsd(inputAudioUMP, Int32(sampleRate))
        XCTAssertEqual(0, stressFreq)
    }

    func testPerformanceWithZeros() {
        let sampleRate = 8000
        var inputAudioBuffer: Array<Double> = Array(repeating: 0, count: sampleRate)
        let inputAudioUMP = UnsafeMutablePointer<Double>.allocate(capacity: sampleRate)
        inputAudioUMP.initialize(from: &inputAudioBuffer, count: Int(sampleRate))
        self.measure {
            _ = vsd(inputAudioUMP, Int32(sampleRate))
        }
    }
}
