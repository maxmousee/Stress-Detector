//
//  ViewController.swift
//  VSD
//
//  Created by Natan Facchin on 4/10/19.
//  Copyright © 2019 Natan Facchin. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var stressTL = CATextLayer()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupTextLayer()
    }
    
    func setupTextLayer() {
        stressTL.cornerRadius = 0.0
        stressTL.alignmentMode = CATextLayerAlignmentMode.center
        stressTL.contentsScale = UIScreen.main.scale
        stressTL.backgroundColor = UIColor.orange.cgColor
        stressTL.frame = CGRect(x: 0, y: ((self.view.bounds.size.height)/4), width: self.view.bounds.size.width, height: self.view.bounds.size.height/2)
        stressTL.string = "\n\n\nprocessing..."
        self.view.layer.addSublayer(stressTL)
    }

}

