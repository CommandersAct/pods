//
//  ITCEventListenerDelegate.h
//  TagCommander
//
//  Created by Damien Terrier on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
* @protocol ITCEventListenerDelegate
*
* The ITCEventListenerDelegate is a protocol to make sure the implementing class
* can actually listened to internal notifications.
*
* The single most important method is onNotificationReceived: where all the notifications are dispatched.
* It's up to the implementing class to act upon the received notification.
*
*/
@protocol ITCEventListenerDelegate <NSObject>

/**
* Change the notification center to a custom one.
*
* It's mainly for testing purpose when we want to make sure the notification
* center is really the one set from the unit tests.
*
* @param notificationCenter The new notification center
*/
- (void) changeNotificationCenter: (NSNotificationCenter *) notificationCenter;

/**
* The entry point for all the notifications received.
*
* The class must know what's inside the notification and especially in the userInfo property.
*
* @see TCDispatcher
* @see TCVendor
*/
- (void) onNotificationReceived: (NSNotification *) incomingNotification;

@end
