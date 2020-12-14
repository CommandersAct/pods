//
//  TCPrivacyConfiguration.h
//  TCPrivacy
//
//  Created by JeanJulien on 13/11/2018.
//  Copyright © 2018 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TCCore/TCConfigurationFile.h>

@interface TCPrivacyConfiguration : TCConfigurationFile

- (id) initPrivacyWithSiteID: (int) siteID privacyID: (int) privacyID fileName: (NSString *) fileName versionPath: (NSString *) versionPath andURL: (NSString *) url;
- (id) initPrivacyWithSiteID: (int) siteID privacyID: (int) privacyID andFileName: (NSString *) fileName;

- (id) initFromConfiguration: (TCConfigurationFile *) file;

- (BOOL) compareCategories: (NSString *) savedConf with: (NSString *) newConf;

- (NSString *) getTextForKey: (NSString *) key withSuffix: (NSString *) suffix;
- (NSString *) getTextForKey: (NSString *) key;

// For testing purposes
- (NSArray *) categoryList: (NSDictionary *) obj;

@property (nonatomic, retain) NSMutableDictionary *customisation;
@property (nonatomic, retain) NSMutableDictionary *components;

@end
