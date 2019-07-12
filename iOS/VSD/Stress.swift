//
//  StressLevel.swift
//  VSD
//
//  Created by Natan Facchin on 12/07/2019.
//  Copyright © 2019 Natan Facchin. All rights reserved.
//

import Foundation
import UIKit

enum StressLevel {
    case stress
    case nostress
    case marginalstress
}

class Stress {
    var stressLvl = StressLevel.nostress
    var displayMessage = String()
    var color = UIColor.green.cgColor
    init(stressCoeficient: Double) {
        stressLvl = self.getStressLevel(stressCoeficient: stressCoeficient)
        displayMessage = self.getDisplayMessage(stressCoeficient: stressCoeficient)
        color = self.getColor()
    }
    
    func getStressLevel(stressCoeficient: Double) -> StressLevel {
        if (stressCoeficient >= 9 && stressCoeficient <= 14) {
            return StressLevel.nostress
        } else if(stressCoeficient < 9 && stressCoeficient >= 7){
            return StressLevel.marginalstress
        } else if(stressCoeficient > 14 && stressCoeficient <= 15) {
            return StressLevel.marginalstress
        } else {
            return StressLevel.stress
        }
    }
    
    func getDisplayMessage(stressCoeficient: Double) -> String {
        let displayMessage = NSMutableString()
        displayMessage.appendFormat("%dHz", Int(stressCoeficient))
        switch stressLvl {
        case .nostress:
            displayMessage.append("\nno stress")
        case .marginalstress:
            displayMessage.append("\nmarginal stress")
        case .stress:
            displayMessage.append("\nstress")
        }
        return String(displayMessage)
    }
    
    func getColor() -> CGColor {
        switch stressLvl {
        case .nostress:
            return UIColor.green.cgColor
        case .marginalstress:
            return UIColor.orange.cgColor
        case .stress:
            return UIColor.red.cgColor
        }
    }
}
