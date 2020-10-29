//
//  TCConfigurationFileFactory.h
//  TCCore
//
//  Created by JeanJulien on 30/08/2019.
//  Copyright © 2019 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TCSingleton.h"
#import "TCConfigurationFile.h"
#import "TCMacros.h"

@interface TCConfigurationFileFactory : TCSingleton<NSObject>

SINGLETON_CLASS_H(TCConfigurationFileFactory)

- (void) initWithSiteID: (int) siteID andContainerID: (int) containerID;

- (void) addConfigurationFile: (NSString *) filename;
- (void) addConfigurationFile: (NSString *) filename withVersionPath: (NSString *) versionPath;
- (void) addConfigurationFile: (NSString *) filename withVersionPath: (NSString *) versionPath forURL: (NSString *) url;

- (void) setBundle: (NSBundle *) bundle forConfiguration: (NSString *) name;

- (void) addConfigurationFile: (NSString *) filename forListener: (id) instance;
- (void) addConfigurationFile: (NSString *) filename fromFile: (TCConfigurationFile *) file forListener: (id) instance;

- (TCConfigurationFile *) getConfigurationFile: (NSString *) filename;

@property (nonatomic, assign) int siteID;
@property (nonatomic, assign) int containerID;
@property (nonatomic, retain) NSMutableDictionary *configurations;
@property (nonatomic, retain) NSMutableDictionary *bundles;

@end
