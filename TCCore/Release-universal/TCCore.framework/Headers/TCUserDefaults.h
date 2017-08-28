//
// Created by Jean-Julien ZEIL on 06/03/14.
// Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCUserDefaults : NSObject

+ (void) saveInfoToUserDefaults: (NSString *)info forLabel: (NSString *) label;
+ (NSString *) retrieveInfoFromUserDefaults: (NSString *) label;

@end
