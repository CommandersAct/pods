//
//  TCPrivacyConstants.h
//  TCPrivacy
//
//  Created by JeanJulien on 28/12/2017.
//  Copyright © 2017 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef TagCommander_TCPrivacyConstants_h
#define TagCommander_TCPrivacyConstants_h

@interface TCPrivacyConstants : NSObject

extern NSString *const kTCConsentTime;
extern NSString *const kTCPrivacyConsent;

extern NSString *const kTCCategoryPrefix;
extern NSString *const kTCVendorPrefix;
extern NSString *const kTCFeaturePrefix;

extern NSString *const kTCSavedCategories;
extern NSString *const kTCSavedVendors;
extern NSString *const kTCSavedFeatures;

extern unsigned long long const kTCConsentExpirationDuration;
extern unsigned long long const kTCConsentOneMonthDuration;


// Privacy Configuration
extern NSString *const kTCConfigurationCDNURLStringFormat;

extern NSString *const kTCVendorListOfflineKey;
extern NSString *const kTCVendorListURL;

// Privacy configuration constants
extern NSString *const kTCConfKey_Information;
extern NSString *const kTCConfKey_Components;
extern NSString *const kTCConfKey_Texts;
extern NSString *const kTCConfKey_Categories;
extern NSString *const kTCConfKey_Vendors;
extern NSString *const kTCConfKey_Customisation;
extern NSString *const kTCConfKey_Order;
extern NSString *const kTCConfKey_OrderCustom;
extern NSString *const kTCConfKey_OrderIAB;

// type_actions
extern NSString *const kTCTypeActionViewPrivacyCenter;
extern NSString *const kTCTypeActionSavePrivacyCenter;

// file names
extern NSString *const kTCPublisherRestrictionConfiguration;
extern NSString *const kTCVendorListConfiguration;

// Notifications keys
extern NSString *const kTCUserInfo_ResetSave;
extern NSString *const kTCShouldDisplayPrivacyCenter;
extern NSString *const kTCUserInfo_SignificantChanges;

extern int const kTCVendorOffset;
extern int const kTCPurposeOffset;
extern int const kTCSpePurposeOffset;
extern int const kTCFeatureOffset;
extern int const kTCSpeFeatureOffset;

// UI ids keys
extern NSString *const kTCDropDownCell;
extern NSString *const kTCLabelCell;
extern NSString *const kTCVendorCell;
extern NSString *const kTCCustomCell;
@end

#endif
