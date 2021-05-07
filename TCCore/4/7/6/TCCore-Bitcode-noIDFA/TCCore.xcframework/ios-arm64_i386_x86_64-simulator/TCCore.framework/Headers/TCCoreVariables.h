//
// Created by JeanJulien on 03/11/2016.
// Copyright (c) 2016 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IOS
#import <WebKit/WebKit.h>
#endif

#import "ITCDynamicStore.h"
#import "TCSingleton.h"
#import "TCMacros.h"
#import "ITCEventSenderDelegate.h"
#import "TCEventSender.h"

@interface TCCoreVariables : TCSingleton <ITCDynamicStore, ITCEventSenderDelegate>

SINGLETON_CLASS_H(TCCoreVariables)

#ifdef TC_USE_IDFA
- (void) initializeAllCoreVariables;
- (void) setIDFA;
#endif

- (id) reinit;

- (void) setIDFV;
- (void) initUserAgentWithProcessPool: (WKProcessPool *) pool;

- (unsigned long long) now;
- (unsigned long long) nowMs;
- (NSString *) nowString;
- (NSString *) nowMsString;

@property (nonatomic, retain) TCDynamicStore *dynamicStore;
@property (nonatomic, assign) bool enableSDKInBG;

@property (nonatomic, retain) WKProcessPool *pool;

#if TARGET_OS_IOS
@property (nonatomic, retain) WKWebView *uaWebView;
#endif

@property (nonatomic, retain) TCEventSender *senderDelegate;

@end
