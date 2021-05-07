//
//  TCLog.h
//  TagCommander
//
//  Created by Jean-Julien ZEIL on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#ifndef TagCommander_TCLog_h
#define TagCommander_TCLog_h

typedef enum TCLogLevel
{
    TCLogLevel_Verbose,
    TCLogLevel_Debug,
    TCLogLevel_Info,
    TCLogLevel_Warn,
    TCLogLevel_Error,
    TCLogLevel_Assert,
    TCLogLevel_None,
} TCLogLevel;

#endif
