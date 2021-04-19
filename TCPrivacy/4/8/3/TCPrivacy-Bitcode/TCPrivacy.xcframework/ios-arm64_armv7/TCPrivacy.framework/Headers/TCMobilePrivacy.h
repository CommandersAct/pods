//
//  TCMobilePrivacy.h
//  TCPrivacy
//
//  Created by JeanJulien on 28/12/2017.
//  Copyright © 2017 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TCCore/ETCPrivacyState.h>
#import <TCCore/TCSingleton.h>
#import <TCCore/TCMacros.h>
#import <TCCore/TCEventSender.h>
#import <TCCore/TCEventListener.h>
#import "TCPrivacyCallbacks.h"

@class TagCommander;

@interface TCMobilePrivacy : TCSingleton <ITCEventSenderDelegate, ITCEventListenerDelegate>

SINGLETON_CLASS_H(TCMobilePrivacy)

- (void) customPCMSetSiteID: (int) siteID privacyID: (int) privacyID containerID: (int) containerID andTCInstance: (TagCommander *) tc;
- (void) customPCMSetSiteID: (int) siteID privacyID: (int) privacyID;

- (void) setSiteID: (int) siteID containerID: (int) containerID privacyID: (int) privacyID andTCInstance: (TagCommander *) tc;
- (void) setSiteID: (int) siteID privacyID: (int) privacyID andTCInstance: (TagCommander *) tc;
- (void) setSiteID: (int) siteID andPrivacyID: (int) privacyID;
- (void) setSiteID: (int) siteID containerID: (int) containerID privacyID: (int) privacyID;

- (void) setLanguage: (NSString *) languageCode;
- (NSString *) getConsentAsJson;

- (void) acceptAllConsent;
- (void) refuseAllConsent;

- (void) saveConsent: (NSDictionary *) consent;
- (void) resetSavedConsent;
- (void) setConsentUser: (NSString *) userID;
- (NSString *) resolveUserID;
- (void) viewConsent;
- (void) enableSDK;
- (void) disableSDK;
- (void) registerCallback: (id<TCPrivacyCallbacks>) listener;
+ (NSArray *) getSavedCategoriesAndVendors;
- (void) useCustomPublisherRestrictions;

- (void) saveCustomCategoriesInSharedPreferences: (NSDictionary *) consent;

@property (nonatomic, assign) Boolean enableIAB;
@property (nonatomic, assign) ETCPrivacyState privacyState;
@property (nonatomic, assign) int clientSiteID;
@property (nonatomic, assign) int privacyID;
@property (nonatomic, assign) float consentDuration;
@property (nonatomic, assign) Boolean consentExpired;
@property (nonatomic, assign) Boolean generatePublisherTC;
@property (nonatomic, retain) TagCommander *tcInstance;
@property (nonatomic, retain) NSString *userID;
@property (nonatomic, retain) id<TCPrivacyCallbacks> callback;
@property (nonatomic, assign) int vendorListVersion;
@property (nonatomic, assign) Boolean switchDefaultState;
@property (nonatomic, retain) NSString *consentVersion;

@property (nonatomic, assign) int maxVendorID;
@property (nonatomic, assign) NSString *languageCode;

@property (nonatomic, retain) TCEventSender *senderDelegate;
@property (nonatomic, retain) TCEventListener *listenerDelegate;

@end
