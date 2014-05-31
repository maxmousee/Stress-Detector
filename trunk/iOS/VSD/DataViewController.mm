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

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [self setUpAudio];
}

- (void)viewWillDisappear:(BOOL)animated
{
    //NSLog(@"ViewWillDisappear!");
    //[audioController stopIOUnit];
}

- (void)setUpAudio
{
    audioController = [[AudioController alloc] init];
    l_fftData = (Float32*) calloc([audioController getBufferManagerInstance]->GetFFTOutputBufferLength(), sizeof(Float32));
    [audioController startIOUnit];

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
