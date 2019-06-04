//
// Created by JeanJulien on 03/11/2016.
// Copyright (c) 2016 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ITCDynamicStore.h"
#import "TCSingleton.h"
#import "TCMacros.h"

@interface TCCoreVariables : TCSingleton <ITCDynamicStore>

SINGLETON_CLASS_H(TCCoreVariables)

#ifdef TC_USE_IDFA
- (void) initializeAllCoreVariables;
#endif
- (id) reinit;

- (void) setIDFV;
- (void) setIDFA;

@property (nonatomic, retain) TCDynamicStore *dynamicStore;
@property (nonatomic, assign) bool enableSDKInBG;

@end
