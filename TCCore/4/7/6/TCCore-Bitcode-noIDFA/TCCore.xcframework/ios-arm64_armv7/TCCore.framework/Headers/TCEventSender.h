//
//  TCEventSender.h
//  TagCommander
//
//  Created by Damien Terrier on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ITCEventSenderDelegate.h"

@interface TCEventSender : NSObject

- (BOOL) send: (NSNotification *) notification;

@property (nonatomic, assign) id<ITCEventSenderDelegate> parent;
@property (nonatomic, retain) NSNotificationCenter *notificationCenter;

@end
