//
//  TCDynamicStore.h
//  TagCommander
//
//  Created by Jean-Julien ZEIL on 10/02/14.
//  Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ITCDynamicStore.h"

@interface TCDynamicStore : NSObject<ITCDynamicStore, NSCoding>

@property (nonatomic, retain) NSMutableDictionary *dynamicStore;
@property (nonatomic, retain) NSMutableArray *orderedKeys;

@end
