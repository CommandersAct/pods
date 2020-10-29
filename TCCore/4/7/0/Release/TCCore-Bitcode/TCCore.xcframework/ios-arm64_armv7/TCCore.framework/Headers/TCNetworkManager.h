//
//  TCNetworkManager.h
//  TagCommander
//
//  Created by Jean-Julien ZEIL on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TCMacros.h"
#import "TCSingleton.h"
#import "ITCEventListenerDelegate.h"
#import "ITCEventSenderDelegate.h"
#import "ETCPrivacyState.h"

@class TCEventListener;
@class TCEventSender;
@class TCReachability;

@interface TCNetworkManager : TCSingleton <ITCEventListenerDelegate, ITCEventSenderDelegate>
{
@private
    TCReachability *reachability;
}
    + (BOOL) isValidURL: (NSString *) url;
    + (NSString *) requestTypeForNotificationName: (NSString *) notificationName;
    - (void) reachabilityChanged: (NSNotification *) note;

    - (void) enableRunningInBackground;
    - (void) waitForUserAgent;

#pragma mark OfflineHits
    - (void) restoreStockedHit;
    - (void) saveAllHits;

#pragma mark - Reachability
    - (BOOL) isInternetReachable;

    SINGLETON_CLASS_H(TCNetworkManager)

    - (id) reinit;
    - (void) postNetworkNotification: (NSString *) notificationName withUserInfo: (NSDictionary *) userInfo;

    @property (nonatomic, retain) TCEventSender *senderDelegate;
    @property (nonatomic, retain) TCEventListener *listenerDelegate;
    @property (strong) NSOperationQueue *operationQueue;
    @property (strong) NSOperationQueue *consentQueue;
    @property (nonatomic, assign) Boolean shouldWaitForUserAgent;

    @property (nonatomic, assign, readonly) unsigned int nextRequestID;
    @property (nonatomic, assign, readonly) unsigned int totalRequestSent;
    @property (nonatomic, assign, readonly) unsigned int maxRequestLifetime;
    @property (nonatomic, assign, readonly) unsigned int maxRequestsInQueue;

    @property (nonatomic, assign) ETCPrivacyState managerState;

@end
