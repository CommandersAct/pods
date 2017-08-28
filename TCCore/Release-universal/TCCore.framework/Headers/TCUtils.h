//
// Created by Damien TERRIER on 05/06/14.
// Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCUtils : NSObject
+ (BOOL) matchDynamicVariableRegexp: (NSString *) dynamicVariable;
+ (BOOL) matchAppleLocaleRegexp: (NSString *) appleLocale;
+ (BOOL) matchIPRegexp: (NSString *) ip;
+ (BOOL) matchSoftwareVersionRegexp: (NSString *) versionString;
+ (BOOL) matchScreenResolutionRegexp: (NSString *) screenResolution;
+ (BOOL) matchUUIDRegexp: (NSString *) UUIDString;
+ (BOOL) isNumeric: (NSString *) numericalString;
+ (BOOL) doesString: (NSString *) string matchRegexp: (NSString *) expr;
+ (int) numberFromNSString: (NSString *) number;
@end

@interface NSString (TagCommander)

- (NSString *) TCURLEncodedString;

@end
