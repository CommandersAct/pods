//
// Created by Damien TERRIER on 24/06/14.
// Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum TCSingletonInitState
{
    TCSingletonInitState_NotInitialised,
    TCSingletonInitState_Initialising,
    TCSingletonInitState_Initialised,
    TCSingletonInitState_Reinitialisation
} TCSingletonInitState;

@interface TCSingleton : NSObject

@end
