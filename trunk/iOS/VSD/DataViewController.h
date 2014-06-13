//
//  DataViewController.h
//  VSD
//
//  Created by Natan Facchin on 5/31/14.
//  Copyright (c) 2014 nfsindustries. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

// Local includes
#import "AudioController.h"
#import "BufferManager.h"

@interface DataViewController : UIViewController {
    CATextLayer *stressTL;
}

@property (strong, nonatomic) IBOutlet AudioController *audioController;
@property (strong, nonatomic) IBOutlet UILabel *dataLabel;
@property (strong, nonatomic) id dataObject;

@end
