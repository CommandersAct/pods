//
// Created by JeanJulien on 03/11/2016.
// Copyright (c) 2016 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCLog.h"

@interface TCDebug : NSObject

extern TCLogLevel logLevel;
extern BOOL blockHits;

+ (void) setDebugLevel: (TCLogLevel) level;
+ (TCLogLevel) getLogLevel;

+ (void) setNotificationLog: (BOOL) logNotification;

+ (void) blockHits: (BOOL) blockHits;
+ (BOOL) areHitBlocked;

@end
