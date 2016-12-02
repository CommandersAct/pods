![alt tag](../res/logo.png)


Segment's Implementation Guide
==============================
**iOS**

Last update : *02/12/2016*<br />
Release version : *4.0.0*


<p><div id="end_first_page" /></p>

[TOC]

Introduction
============

By using TagCommander's Engage product you will be able to store a lot of data and create segments of users. With those segments you can target precisely your offers to your customers or server personalized content in your application.

TCSegment is a small module especially made to get the segment of your user from within your application.

Creating Segments
=================

For the creation of segments, please check the documentation of the Engage product.


Getting Segments
================

The module needs some information to be able to fetch segments. It will need your siteID and also your security token. Your siteID and token are provided by TagCommander.

For debugging purpose, we recommand the use of TCDebug which will help you seeing what's happening inside the modules.

	:::objectivec
	[TCDebug setDebugLevel: TCLogLevel_Verbose];
    [TCDebug setNotificationLog: YES];
	[[TCSegmentation sharedInstance] setSiteID: 3311
								      andToken: @"e2032376eca5533858b7d6616d40802be54d221db1b75e1b"];


Since fetching segments needs internet and is not instantaneous, getting the segments require two steps. First you will ask the module to fetch the segmentation, then you will be able to get the list of segment once the first operation ended by either registering to a notification or by asking directly the segment list.

Fetching
--------

To ask the module to fetch the segments, simply call the following line. Call it back each time you want to refresh the value.

	:::objectivec
	[[TCSegmentation sharedInstance] fetchSegment];


Getting the notification
------------------------

The simplest way to have the segment list as soon as possible is by listening to the notification sent by the module.
First you need to listen to the kTCNotification_SegmentAvailable notification like this:

	:::objectivec
    NSNotificationCenter *notificationCenter = [NSNotificationCenter defaultCenter];
    [notificationCenter addObserver: self
                           selector: (@selector(onNotification:))
                               name: kTCNotification_SegmentAvailable
                             object: nil];

Then declare the function that will treat the notification:

    :::objectivec
    - (void) onNotification: (NSNotification *) incomingNotification
	{
	    NSString *name = incomingNotification.name;
	    if ([name isEqualToString: kTCNotification_SegmentAvailable])
	    {
	        // Do anything you want here
	    }
	}

Asking for the List
-------------------

If you don't want to or can't register to the notification, you can also simply call a method from the module that will give you the current list. Be carefull as it not synchroneous, the list may get updated after you asked for it.

	:::objectivec
	NSArray *segments = [[TCSegmentation sharedInstance] getSegments];

If no segment are found or they were never fetched, the list will be empty and not null.

Support and contacts
====================
![alt tag](../res/logo.png)

***
**Support**
*support@tagcommander.com*

http://www.tagcommander.com

TagCommander | 3/5 rue Saint Georges - 75009 PARIS - France
***

This documentation was generated on 02/12/2016 11:23:19
