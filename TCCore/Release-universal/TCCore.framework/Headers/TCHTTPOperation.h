//
// Created by Damien Terrier on 11/03/14.
// Copyright (c) 2014 TagCommander. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TCHTTPOperation : NSOperation

- (id) initWithData: (NSDictionary *) userInfo;
- (NSString *) getContentOfData: (NSData *) data;

@property (nonatomic, retain) NSMutableDictionary *userInfo;
/** the corresponding userInfo in the NSNotification */
@property (nonatomic, retain) NSMutableURLRequest *request;
/** the current NSURLRequest being sent */
@property (nonatomic, retain) NSData *result; /** The data returned by the server if successful */
@property (nonatomic, assign) int timestamp; /** timestamp to keep track of request age */

@end
