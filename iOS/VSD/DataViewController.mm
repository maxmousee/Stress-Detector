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
    
    stressTL = [[CATextLayer alloc] init];
    
    stressTL.backgroundColor = [UIColor orangeColor].CGColor;
    if ( UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad )
    {
        /* Device is iPad */
        stressTL.fontSize = 2*stressTL.fontSize;
    }
    stressTL.cornerRadius = 0.0;
    stressTL.alignmentMode = kCAAlignmentCenter;
    stressTL.contentsScale = [[UIScreen mainScreen] scale];
    stressTL.frame = CGRectMake(00.0f, ((self.view.bounds.size.height)/4), self.view.bounds.size.width,
                                self.view.bounds.size.height/2);
    
    [stressTL setString:@"\n\n\nprocessing..."];
    [self.view.layer addSublayer:stressTL];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(updateStressView:)
                                                 name:kStressProcessedNotification
                                               object:nil];
    [self setUpAudio];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [audioController stopIOUnit];
}

- (void)setUpAudio
{
    
    [[AVAudioSession sharedInstance] requestRecordPermission:^(BOOL granted) {
        if (granted)
        {
            
            dispatch_queue_t vsdQueue = dispatch_queue_create("VSD_Queue",NULL);
            dispatch_async(vsdQueue, ^{
                audioController = [[AudioController alloc] init];
                [audioController startIOUnit];
            });
        }
        else
        {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Microphone Access Denied"
                                                            message:@"You must allow microphone access in Settings > Privacy > Microphone"
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
            [alert show];
        }
    }];
}

- (void)updateStressView:(NSNotification *)theNotification
{
    try {
        NSNumber *stressCoefNSNumber = [theNotification.userInfo objectForKey:kStressCoefVarName];
        float stressCoef = [stressCoefNSNumber floatValue];
        NSMutableString *stressMessage = [[NSMutableString alloc]init];
        if (stressCoef >= 9 && stressCoef <= 14) {
            [stressMessage appendString:@"\n\nno stress"];
            stressTL.backgroundColor = [UIColor greenColor].CGColor;
            [stressMessage appendFormat:@"\n\n%.2fHz", stressCoef];
            [stressTL setString:stressMessage];
        } else if(stressCoef < 9 && stressCoef >= 7){
            [stressMessage appendString:@"\n\nmarginal stress"];
            [stressMessage appendFormat:@"\n\n%.2fHz", stressCoef];
            [stressTL setString:stressMessage];
            stressTL.backgroundColor = [UIColor orangeColor].CGColor;
        } else if(stressCoef > 14 && stressCoef <= 15) {
            [stressMessage appendString:@"\n\nmarginal stress"];
            stressTL.backgroundColor = [UIColor orangeColor].CGColor;
            [stressMessage appendFormat:@"\n\n%.2fHz", stressCoef];
            [stressTL setString:stressMessage];
        } else if(stressCoef <= 3 || stressCoef > 42) {
            //[stressMessage appendString:@"can't process"];
            //stressTL.backgroundColor = [UIColor blackColor].CGColor;
        } else {
            [stressMessage appendString:@"\n\nstress"];
            stressTL.backgroundColor = [UIColor redColor].CGColor;
            [stressMessage appendFormat:@"\n\n%.2fHz", stressCoef];
            [stressTL setString:stressMessage];
        }
        [stressTL performSelectorOnMainThread:@selector(setNeedsDisplay) withObject:0 waitUntilDone:NO];
    } catch (...) {
        NSLog(@"Could not read stress value from NSNotification");
    }
    
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
