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
    var stress = Stress(stressCoeficient: 0)
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setupTextLayer()
        NotificationCenter.default.addObserver(self, selector: #selector(updateStressView(notification:)), name: NSNotification.Name(rawValue: STRESS_NOTIFICATION_NAME), object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(askForMicrophonePermission(notification:)), name: NSNotification.Name(rawValue: NO_MIC_PERMISSION_NOTIFICATION_NAME), object: nil)
    }
    
    func setupTextLayer() {
        stressTL.cornerRadius = 0.0
        stressTL.alignmentMode = CATextLayerAlignmentMode.center
        stressTL.contentsScale = UIScreen.main.scale
        stressTL.masksToBounds = true
        stressTL.backgroundColor = UIColor.gray.cgColor
        stressTL.frame = CGRect(x: 0, y: 0, width: UIScreen.main.bounds.width, height: UIScreen.main.bounds.height)
        stressTL.string = "processing..."
        self.view.layer.addSublayer(stressTL)
    }
    
    @objc func updateStressView(notification: NSNotification) {
        stress = notification.object as! Stress
        DispatchQueue.main.async {
            self.stressTL.backgroundColor = self.stress.color
            self.stressTL.string = self.stress.displayMessage
        }
    }
    
    @objc func askForMicrophonePermission(notification: NSNotification) {
        DispatchQueue.main.async {
            let errorMessage = "Please enable microphone access to monitor your stress level"
            let alert = UIAlertController(title: "Error", message: errorMessage, preferredStyle: UIAlertController.Style.alert)
            alert.addAction(UIAlertAction(title: "Open Settings", style: UIAlertAction.Style.default, handler: self.openSettings))
            self.present(alert, animated: true, completion: nil)
        }
    }
    
    func openSettings(alert: UIAlertAction!) {
        if let url = URL.init(string: UIApplication.openSettingsURLString) {
            UIApplication.shared.open(url, options: [:], completionHandler: nil)
        }
    }
}
