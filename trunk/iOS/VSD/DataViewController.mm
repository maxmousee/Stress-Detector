//
//  DataViewController.m
//  VSD
//
//  Created by Natan Facchin on 5/31/14.
//  Copyright (c) 2014 nfsindustries. All rights reserved.
//

#import "DataViewController.h"

@interface DataViewController ()

@end

@implementation DataViewController

@synthesize audioController;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [self setUpAudio];
}

- (void)viewWillDisappear:(BOOL)animated
{
    //NSLog(@"ViewWillDisappear!");
    [audioController stopAUGraph];
}

- (void)setUpAudio
{
    //if(audioController != NULL) {
        audioController = [[AudioController alloc] init];
    
    [audioController initializeAudioSession];
    [audioController createAUProcessingGraph];
	[audioController initializeAndStartProcessingGraph];
    
    /*
    
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
            
            for(;;) {
                sleep(1);
                
            }
            
            dispatch_async(dispatch_get_main_queue(), ^(void) {
                //Stop your activity indicator or anything else with the GUI
                //Code here is run on the main thread
                
            });
        });
    //}
     */
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    self.dataLabel.text = [self.dataObject description];
}

@end
