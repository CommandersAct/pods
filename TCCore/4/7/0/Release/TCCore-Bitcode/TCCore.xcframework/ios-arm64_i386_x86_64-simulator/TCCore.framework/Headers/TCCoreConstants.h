//
//  TCConstants.h
//  TagCommander
//
//  Created by Jean-Julien ZEIL on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#ifndef TagCommander_TCCoreConstants_h
#define TagCommander_TCCoreConstants_h

#import <Foundation/Foundation.h>
#import "CoreGenerated.h"

#define TC_UNIT_TESTS
#define TC_FUNCTIONAL_TESTS


#pragma mark - misc
extern NSString *const kTCFileOfflineHits;
extern NSTimeInterval const kTCNetworkDefaultTimeout;
extern NSURLRequestCachePolicy kTCNetworkDefaultRequestCachePolicy;
extern unsigned long long const kTCVisitDurationDefaultValue;
extern NSString *const kTCFilePrivateDocuments;
extern NSString *const kTCConfigurationFilesPrefix;

#pragma mark HTTP Hit Notifications
extern NSString *const kTCNotification_HitSent;

#pragma mark - Message
extern NSString *const kTCErrorMessageInvalidURL;

#pragma mark HTTP Request Notifications
extern NSString *const kTCNotification_HTTPRequest;
extern NSString *const kTCNotification_HTTPRequestSent;
extern NSString *const kTCNotification_HTTPRequestError;
extern NSString *const kTCNotification_HTTPResponse;
extern NSString *const kTCNotification_HTTPPartnerRequest;
extern NSString *const kTCNotification_HTTPPartnerResponse;
extern NSString *const kTCNotification_SegmentRequest;
extern NSString *const kTCNotification_SegmentResponse;
extern NSString *const kTCNotification_ConfigurationRequest;
extern NSString *const kTCNotification_ConfigurationResponse;
extern NSString *const kTCNotification_VendorListRequest;
extern NSString *const kTCNotification_VendorListResponse;

#pragma mark Internet Notifications
extern NSString *const kTCNotification_InternetUp;
extern NSString *const kTCNotification_InternetDown;
extern NSString *const kTCNotification_InternetChanged;

#pragma mark User Agent Notifications
extern NSString *const kTCNotification_UserAgentAvailable;

#pragma mark Background / Foreground notifications
extern NSString *const kTCNotification_OnBackground;
extern NSString *const kTCNotification_OnForeground;

#pragma mark Misc Notifications
extern NSString *const kTCNotification_Unknown;
extern NSString *const kTCNotification_StoppingTheSDK;
extern NSString *const kTCNotification_StartingTheSDK;
extern NSString *const kTCNotification_ConfigurationChanged;

#pragma mark - notification userInfo
extern NSString *const kTCUserInfo_DataKey;
extern NSString *const kTCUserInfo_URLKey;
extern NSString *const kTCUserInfo_POSTData;
extern NSString *const kTCUserInfo_ResponseKey;
extern NSString *const kTCUserInfo_ErrorKey;
extern NSString *const kTCUserInfo_RequestType;
extern NSString *const kTCUserInfo_ContentKey;
extern NSString *const kTCUserInfo_RequestID;

#pragma mark - predefined dynamic variables
extern NSString *const kTCPredefinedVariable_UniqueID;

extern NSString *const kTCPredefinedVariable_IDFA;
extern NSString *const kTCPredefinedVariable_IDFV;
extern NSString *const kTCPredefinedVariable_isTrackingEnabled;
extern NSString *const kTCPredefinedVariable_LimitUserTrackingEnabled;

extern NSString *const kTCPredefinedVariable_SDKID;
extern NSString *const kTCPredefinedVariable_NormalizedID;
extern NSString *const kTCPredefinedVariable_UserAgent;

extern NSString *const kTCPredefinedVariable_Connexion;

#pragma mark - Regexps
extern NSString *const kTCRegexpDynamicVariable;

extern NSString *const kTCRegexpIP;
extern NSString *const kTCRegexpAppleLocale;
extern NSString *const kTCRegexpScreenResolution;
extern NSString *const kTCRegexpSoftwareVersion;
extern NSString *const kTCRegexpUUID;

#endif // !#ifndef TagCommander_TCCoreConstants_h
