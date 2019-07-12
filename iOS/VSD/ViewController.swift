//
//  ViewController.swift
//  VSD
//
//  Created by Natan Facchin on 4/10/19.
//  Copyright © 2019 Natan Facchin. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var stressTL = CenterTextLayer()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupTextLayer()
    }
    
    func setupTextLayer() {
        stressTL.cornerRadius = 0.0
        stressTL.alignmentMode = CATextLayerAlignmentMode.center
        stressTL.contentsScale = UIScreen.main.scale
        stressTL.masksToBounds = true
        stressTL.backgroundColor = UIColor.orange.cgColor
        stressTL.frame = CGRect(x: 0, y: 0, width: UIScreen.main.bounds.width, height: UIScreen.main.bounds.height)
        stressTL.string = "processing..."
        self.view.layer.addSublayer(stressTL)
    }
    
    func updateStressView(stressCoeficient: Double) {
        let displayMessage = NSMutableString()
        displayMessage.appendFormat("%dHz", Int(stressCoeficient))
        if (stressCoeficient >= 9 && stressCoeficient <= 14) {
            displayMessage.append("\nno stress")
            stressTL.backgroundColor = UIColor.green.cgColor
            stressTL.string = displayMessage
        } else if(stressCoeficient < 9 && stressCoeficient >= 7){
            displayMessage.append("\nmarginal stress")
            stressTL.backgroundColor = UIColor.orange.cgColor
            stressTL.string = displayMessage
        } else if(stressCoeficient > 14 && stressCoeficient <= 15) {
            displayMessage.append("\nmarginal stress")
            stressTL.backgroundColor = UIColor.orange.cgColor
            stressTL.string = displayMessage
        } else if(stressCoeficient <= 3 || stressCoeficient > 50) {
            //Out of the threshold
        } else {
            displayMessage.append("\nstress")
            stressTL.backgroundColor = UIColor.red.cgColor
            stressTL.string = displayMessage
        }
    }

}

