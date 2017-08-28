//
//  TCEventListener.h
//  TagCommander
//
//  Created by Damien Terrier on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ITCEventListenerDelegate.h"

@interface TCEventListener : NSObject

- (void) listen: (NSString *) listenedNotificationName;
- (void) onNotification: (NSNotification *) incomingNotification;

@property (nonatomic, assign) id<ITCEventListenerDelegate> parent;
@property (nonatomic, retain) NSNotificationCenter *notificationCenter;

@end
