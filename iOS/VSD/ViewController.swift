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
        let stress = Stress(stressCoeficient: stressCoeficient)
        stressTL.backgroundColor = stress.color
        stressTL.string = stress.displayMessage
    }
}
