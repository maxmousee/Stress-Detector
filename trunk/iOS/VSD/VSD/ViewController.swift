//
//  ViewController.swift
//  VSD-swift
//
//  Created by Natan Facchin on 09/12/16.
//  Copyright © 2016 Natan Facchin. All rights reserved.
//

import UIKit
import QuartzCore
import AVFoundation

class ViewController: UIViewController {
    var stressTL: CATextLayer!;
    var vsdGCDQueue = "com.nfsindustries.VSD";
    var loadingString = "\nloading...";
    var stressedString = "\nstressed";
    var notStressedString = "\nnot stressed";
    var tooNoisyString = "\ntoo noisy, can't process";
    
    override func viewDidLoad() {
        super.viewDidLoad();
        stressTL = CATextLayer();
        
        stressTL.backgroundColor = (UIColor .orange).cgColor;
        let isiPad: Bool = (UIDevice.current.userInterfaceIdiom == .pad);
        if (isiPad){
            /* Device is iPad */
            stressTL.fontSize = 2*stressTL.fontSize;
        }
        stressTL.cornerRadius = 0.0;
        stressTL.alignmentMode = kCAAlignmentCenter;
        stressTL.contentsScale = UIScreen.main.scale;
        stressTL.frame = CGRect(x: 0, y: ((3 * self.view.bounds.size.height)/8),
                                width: self.view.bounds.size.width,
                                height: self.view.bounds.size.height/4);
        
        stressTL.string = loadingString;
        self.view.layer.addSublayer(stressTL);
        setUpAudio();
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning();
        // Dispose of any resources that can be recreated.
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        //[audioController stopIOUnit];
    }
    
    func setUpAudio() {
        AVAudioSession.sharedInstance().requestRecordPermission({(granted: Bool)-> Void in
            if (granted) {
                let vsdQueue = DispatchQueue(label: self.vsdGCDQueue);
                vsdQueue.async {
                    // Detect Voice Stress in the background
                    //self.stressTL.string = "\nAsync";
                }
                vsdQueue.sync {
                    //self.stressTL.string = "\nDone";
                }
                
                /* debugPrint("granted");
                 session.setCategory(AVAudioSessionCategoryPlayAndRecord, error: nil)
                 session.setActive(true, error: nil)
                 self.recorder ()
                 
                 dispatch_queue_t myQueue = dispatch_queue_create("My Queue",NULL);
                 dispatch_async(myQueue, ^{
                 audioController = [[AudioController alloc] init];
                 [audioController startIOUnit];
                 });
                 */
            } else{
                let alertController: UIAlertController = (UIAlertController.init(title: "Microphone Access Denied",
                                                                                 message: "You must allow microphone access in Settings > Privacy > Microphone",
                                                                                 preferredStyle: .alert));
                
                let defaultAction = UIAlertAction(title: "OK", style: .default, handler: nil);
                alertController.addAction(defaultAction);
                self.present(alertController, animated: true, completion: nil);
                
            }
        })
        
    }
}

