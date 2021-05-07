//
//  TCLogger.h
//  TagCommander
//
//  Created by Jean-Julien ZEIL on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TCMacros.h"
#import "TCLog.h"
#import "TCEventSender.h"
#import "TCEventListener.h"

#import "TCSingleton.h"
#import "ITCDynamicStore.h"

@interface TCLogger : TCSingleton<ITCEventSenderDelegate, ITCEventListenerDelegate>

SINGLETON_CLASS_H(TCLogger)

- (id) reinit;

- (void) logMessage: (NSString *) message withLevel: (TCLogLevel) level;

- (NSString *) getPrivatePathToFile: (NSString *) fileName;
+ (NSString *) privateTCDirectory;

@property (nonatomic, retain) TCEventListener *listenerDelegate;
@property (nonatomic, retain) TCEventSender *senderDelegate;

@property (nonatomic) BOOL debugVerboseNotificationLog;

@end
