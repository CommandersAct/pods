//
//  TCPrivacyCenterViewController.h
//  TCPrivacy
//
//  Created by JeanJulien on 26/10/2018.
//  Copyright © 2018 TagCommander. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TCPrivacyCenterViewController : UIViewController<UIScrollViewDelegate>

- (NSString *) getSaveButtonText;

- (void) parseCustomisation: (NSDictionary *) custo;
- (NSDictionary *) retrieveSavedConsent;

@property (nonatomic, retain) NSDictionary *JSONDictionary;

@property (nonatomic, retain) UIScrollView *scrollView;
@property (nonatomic, retain) UIView *contentView;
@property (nonatomic, retain) UISwitch *globalConsent;
@property (nonatomic, retain) NSMutableDictionary *viewsDictionary;
@property (nonatomic, retain) NSMutableArray *categoryUIObjects;
@property (nonatomic, retain) NSMutableDictionary *categoryLinks;
@property (nonatomic, retain) NSDictionary *savedConsent;

@property (nonatomic, retain) NSMutableArray *privacyButtons;
@property (nonatomic, retain) NSMutableArray *privacyUrls;

@property (nonatomic, retain) NSMutableDictionary *customisation;
@property (nonatomic, retain) NSMutableDictionary *metrics;

@property (nonatomic, assign) int numberOfViews;

@end
