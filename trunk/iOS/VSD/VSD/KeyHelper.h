//
//  KeyHelper.h
//  Created by Natan Facchin on 01/07/2012.
//  Copyright 2012 Pandorga Tecnologia. All rights reserved.
//
//

/*
 *	This class is a singleton providing globally accessible methods 
 *	and properties that may be needed by multiple classes wanting to map frequency
 *	values to pitches (e.g. A, Bb, C, F#, etc).
 */


#import <Foundation/Foundation.h>

@interface KeyHelper : NSObject {
	NSMutableDictionary *keyMapping;
	NSMutableDictionary *frequencyMapping;
}

@property(nonatomic, retain) NSMutableDictionary *keyMapping;
@property(nonatomic, retain) NSMutableDictionary *frequencyMapping;

#pragma mark Key Generation
- (void)buildKeyMapping;
- (NSString *)closestCharForFrequency:(float)frequency;

#pragma mark Singleton Methods
+ (KeyHelper *)sharedInstance;


@end