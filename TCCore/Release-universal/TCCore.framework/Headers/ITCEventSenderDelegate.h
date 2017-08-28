//
//  ITCEventSenderDelegate.h
//  TagCommander
//
//  Created by Damien Terrier on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
* @protocol ITCEventSenderDelegate
*
* The ITCEventSenderDelegate is a protocol to make sure the implementing class can actually send notifications.
*
* The only method is changeNotificationCenter: which make unit testing easier by instrumenting the sending NSNotificationCenter
*
*/
@protocol ITCEventSenderDelegate <NSObject>


/**
* Update the notification center.
*
* This method is mainly used to instrument the unit tests.
*
* @param notificationCenter The new notification center for the implementing class.
*/
- (void) changeNotificationCenter: (NSNotificationCenter *) notificationCenter;

@end
