//
//  TCConfigurationFile.h
//  TCCore
//
//  Created by JeanJulien on 30/08/2019.
//  Copyright © 2019 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <TCCore/TCEventListener.h>
#import <TCCore/TCEventSender.h>

@interface TCConfigurationFile : NSObject <ITCEventListenerDelegate, ITCEventSenderDelegate>

- (void) setSiteID: (int) siteID fileID: (int) fileID fileName: (NSString *) fileName versionPath: (NSString *) versionPath andURL: (NSString *) url;
- (void) setSiteID: (int) siteID fileID: (int) fileID fileName: (NSString *) fileName andVersionPath: (NSString *) versionPath;
- (void) setSiteID: (int) siteID fileID: (int) fileID andFileName: (NSString *) fileName;
- (void) setFilename: (NSString *) filename versionPath: (NSString *) versionPath andURL: (NSString *) url;

- (NSString *) getFullJSON;
- (NSDictionary *) getJSONDictionary;
- (NSDictionary *) getJSONDictionaryFromString: (NSString *) json;
- (int) getVersionFromJSONObject: (NSDictionary *) conf;
- (void) preSaveOfflineJSON;
- (void) downloadConfigurationUpdate;
- (NSString *) getJsonLeafFromPath: (NSString *) branchPath;
- (NSString *) getJsonLeaf: (NSDictionary *) conf fromPath: (NSString *) branchPath;

@property (nonatomic, assign) int siteID;
@property (nonatomic, assign) int fileID;
@property (nonatomic, retain) NSString *offlineName;
@property (nonatomic, retain) NSString *sharedName;
@property (nonatomic, retain) NSString *baseURL;
@property (nonatomic, assign) int version;
@property (nonatomic, retain) NSString *versionPath;
@property (nonatomic, retain) NSBundle *bundle;

@property (nonatomic, retain) TCEventSender *senderDelegate;
@property (nonatomic, retain) TCEventListener *listenerDelegate;

@end
