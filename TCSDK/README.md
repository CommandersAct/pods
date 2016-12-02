![alt tag](../res/logo.png)


SDK's Implementation Guide
==========================
**iOS**

Last update : *02/12/2016*<br />
Release version : *4.0.0*


<p><div id="end_first_page" /></p>

[TOC]

Introduction
============

TagCommander enables marketers to easily add, edit, update, and deactivate tags on web pages, videos and mobile applications with little-to-no support from IT departments.

Instead of implementing several SDK's in the application, TagCommander for mobile provides clients with a single SDK which sends data to our server which then create and send hits to your partners.

Owing to remote configuration tools, it is also possible to modify the configuration without having to resubmit your application.

The purpose of this document is to explain how to add TagCommander into your application.


Main Technical Specifications
-----------------------------

- Weight from 110 ko to 120 ko in your application depending on the iPhone model.
- Fully threaded and asynchronous.
- Automatic enabling / disabling depending on the Internet reachability or battery level.
- Offline mode (the hits are stored in the phone to be replayed at the next launch.)
- Very low CPU and memory usage.
- Dynamic variable storage. If a value never changes, it's possible to set it only once.
- The state of the phone is easily accessed through TagCommander (network connection type, name of the phone, geographical location.)


Dynamic Variables
-----------------

A dynamic variable is a combination of a name and a value. It is used to give the TagCommander SDK data such as the name of the current screen or the product ID in a cart.

Dynamic Variables are implemented inside the application. They are replaced on the server at the time of the execution by the value transmitted.

A dynamic variable is formatted like this: `#SCREEN#`.

<div class="warning"></div>
> The dynamic variables are case sensitive. They should always be in
> upper case. The dynamic variable both begins and ends with a `#`. Don't
> forget them when setting your dynamic variables.

Dynamic Variables has two purposes:

 1. Define information for analytics purposes. For instance, you would put `restaurants_list` in the `#SCREEN#` dynamic variable.
 2. Test if conditions are met to fire a tag. For instance, if you set the `#EVENT#` to `click`, the tag with the condition `#EVENT# EQUAL 'click'` will be executed.

Execution
---------

When you call the sendData method, a hit will be packaged and sent to TagCommander's server.

![alt tag](../res/sdk_scheme.png)


SDK integration
===============

Steps
-----

You can divide the integration of TagCommander's SDK into four steps:

1.  Add the required frameworks
2.  Add the TagCommander framework
3.  Implement TagCommander in your application according to the tagging plan.
4.  Verify that all tags are being sent

Integration of the SDK Module
-----------------------------

Please check the Developers Implementation Guide to chose the best way to implement this module in your project.

Dependencies
------------
TagCommander requires the following frameworks:

- CoreLocation.framework
- SystemConfiguration.framework
- libz.dylib


Compiler Flags
-------------
Please add the following option to your projects setting or xcconfig file

OTHER_LDFLAGS = $(inherited) -ObjC


Compatibility
-------------

- Architecture: armv7, arm64, i386 and x86_64, bitcode sections
- iOS version: 7.0 minimum
- Compiled with the ENABLE_BITCODE = YES option
- Compiled with ARC enabled


Using the SDK
=============

Initialisation
--------------

It is recommended to initialise TagCommander in your `AppDelegate's applicationdidFinishLaunchingWithOptions`
 so it will be operational as soon as possible.

A single line of code is required to properly initialize an instance of TagCommander:

	:::objectivec
	TagCommander *TagCommanderInstance = [[TagCommander alloc] initWithSiteID: siteID
															   andContainerID: containerID];

<div class="warning"></div>
> This class is not a Singleton. If you have the need for only one pair
> of siteID's and containerID's, you might want to use it as a Singleton
> anyway for reasons of simplication.

If you want to use localisation, you will need to instanciation TCLocation after TagCommander.

	:::objectivec
	[TCLocation sharedInstance];

We have set the default setInterval to 30 minutes to save battery. If you need another time precision, you can set TCLocation.GPSInterval to any value and it will be used instead of the default value.

Executing tags
--------------

For every element that needs tagging in your application, you need to call addData on your TagCommander instance and when you want to send all those information to the server, you will simply need to call sendData.

	:::objectivec
	[TCInstance addData: @"#EVENT#" withValue: @"click"];
	[TCInstance addData: @"#PAGE#" withValue: @"order"];
	[TCInstance addData: @"#AMOUNT#" withValue: @"584.46"];

	[TCInstance sendData];

For compatibility reasons, we can still use TCAppVars to pass those information to TagCommander.

	:::objectivec
	TCAppVars *appVar = [[TCAppVars alloc] init];
	[appVar set: @"#EVENT#" withValue: @"click"];
	[appVar set: @"#PAGE#" withValue: @"order"];
	[appVar set: @"#AMOUNT#" withValue: @"584.46"];

	[self.TCInstance execute: appVar];

<div class="warning"></div>
> Always handle values as NSStrings !

Example
-------

Let's say that the URL you are using in your server-side container uses the following url:

	:::url
	http://engage.commander1.com/dms?tc_s=3109&tc_type=dms&data_sysname=#TC_SYSNAME#
	&data_sysversion=#TC_SYSVERSION#&page=#SCREEN_NAME#&event=#EVENT#

In order to be executed, the tag needs two values:

- `#EVENT#`
- `#SCREEN_NAME#`

With the code from the previous section, this tag could be fired from TagCommander's server. The application sends two dynamic variables (`#EVENT#` and `#SCREEN_NAME#`) and the SDK adds all information available to it (like #TC_SYSVERSION# and #TC_SYSNAME# in this hit).


Product tags
------------

There are some tags that need to be passed a list of dictionaries, usually representing products. By passing complex information, we are able to create and send complex hits or many hits at the same time.

Tags that needs to be passed a list of dictionaries are easy to spot in the configuration. They have appended to the name of the dynamic variable the name of the key that is retrieved from the dictionary.

Most of the time the data are provided ready to use, but we provide a TCProduct class representing a product and its possible values.

    :::objectivec
    + (void) sendViewCart: (NSString *) screenName
    {
        [TCInstance addData: @"#EVENT#" withValue: @"viewCart"];
        [TCInstance addData: @"#PARTNER_ID#" withValue: @"868"];
        [TCInstance addData: @"#REGIONAL_CODE#" withValue: @"eu"];

        TCProduct *product1 = [[TCProduct alloc] init];
        product1.ID = @"22561563";
        product1.priceATI = @"1.2";
        product1.quantity = @"1";
        [TCInstance addData: @"#ORDER_PRODUCTS#" withProduct: product1];

        TCProduct *product2 = [[TCProduct alloc] init];
        product2.ID = @"21669790";
        product2.priceATI = @"3.4";
        product2.quantity = @"2";
        [TCInstance addData: @"#ORDER_PRODUCTS#" withProduct: product2];

        TCProduct *product3 = [[TCProduct alloc] init];
        product3.ID = @"3886822";
        product3.priceATI = @"5.4";
        product3.quantity = @"3";
        [TCInstance addData: @"#ORDER_PRODUCTS#" withProduct: product3];

        [TCInstance sendData];
    }

The following properties can be used with the TCProduct class:

 - ID
 - name
 - quantity
 - category
 - priceATI
 - discountATI
 - priceTF
 - discountTF
 - trademark
 - URLPage
 - URLPicture
 - rating
 - inStock

 If you want to add more properties, please use the method on your TCProduct instance:

    :::objectivec
    [product.customProperties setValue: @"12" forKey: @"Menu"];
    [product.customProperties setValue: @"0" forKey: @"TakeOut"];

<div class="warning"></div>
>  If you are updating from an old version of TagCommander you can still use old functions with TCAppVars and a list of products.

Troubleshooting
===============

The TagCommander SDK also offers methods to help you with the Quality Assessment of the SDK implementation.


Debugging
---------

We recommend using TCLogLevel_Verbose while developing your application:

	:::objectivec
	// Put it before the TagCommander initialization
	#ifdef DEBUG
	[[TCState sharedInstance] setDebugForLevel: TCLogLevel_Verbose
									 andOutput: TCLogOutput_Console];

	[[TCLogger sharedInstance] setDebugVerboseNotificationLog: YES];
	#end

- The first line allows you to select the verbosity of TagCommander's logs, alongside the desired outputs.

	- Verbosity

	Constant Name | Verbosity
	--------------|----------
	TCLogLevel_Verbose | Print everything.
	TCLogLevel_Debug | Most useful information for debugging.
	TCLogLevel_Info | Basic information about TagCommander's state.
	TCLogLevel_Warn | Warnings only.
	TCLogLevel_Error | Errors only.
	TCLogLevel_Assert | Asserts only.
	TCLogLevel_None | No print at all.

-   The internal architecture is working with internal notifications. You can ask the Logger to display all the internal notifications with setDebugVerboseNotificationLog: YES.

Testing
-------

There are three ways to verify that TagCommander executes the tags in your application:

 - By reading the debug messages in the console.
 - By going to your vendor's platform and check that the hits are displayed and that the data is correct. Please be aware that hits may not display immediately in the vendor account. This delay differs widely between vendors and may also vary for the type of hit under the same vendor.
 - You can also use a network monitor like Wireshark or Charles to check directly what is being sent on the wire to your vendors.

Common errors
-------------

<div class="warning"></div>
>  - Enable the debug logs if you have any doubt.
>  - Check if TagCommander is called when you think it is. You should see it in the console logs.
>  - Make sure you have the latest version.

Common errors with the tagging plan
-----------------------------------

<div class="warning"></div>
>  - Don't forget the # at the beginning and the end of each dynamic variable.
>  - Always use the String type for the value of each dynamic variable.
>  - Always use upper case dynamic variables.
>  - The dynamic variables are case sensitive.
>  - If you don't set the correct value for one dynamic variable, an empty string will replace it.


Helpers
=======

Persisting variables
--------------------

TagCommander permits storing of variables that remain the same in the whole application, such as vendors ID, in a TagCommander instance, instead of sending them each time you want to send data.

These variables will have a lower priority to the one given by the addData method but will persist for the whole run of the application.

	:::objectivec
	[self.TagCommanderInstance addPermanentData: @"#VENDOR_ID#" withValue: @"UE-556XXXXX-01"];

They can also be removed if necessary.

	:::objectivec
	[self.TagCommanderInstance removePermanentData: @"#VENDOR_ID#"];

TCPredefinedVariables
---------------------

TagCommander collects a great deal of information to function with accuracy.
You can ask for any variables computed by TagCommander through a simple getData on TCPredefinedVariables.

The two following line are doing exactly the same thing, one using the constants declared in the SDK, the second using the name of the variable as defined in PredefinedVariables.xlsx. You can use either one.

	:::objectivec
	TCPredefinedVariables *predefVariables = [TCPredefinedVariables sharedInstance];
	NSString *currentVisit = [predefVariables getData: kTCPredefinedVariable_CurrentVisitMs];
	NSString *currentVisit = [predefVariables getData: @"#TC_CURRENT_VISIT_MS#"];

Example: TCDemo
===============

Below is an example of how to integrate TagCommander:

TCDemo is a mobile application displaying a list of nearby restaurants. It is tagged with analytics. Please read the TCAppDelegate.m and TagCommanderExample.m files to see a typical integration.

Migration from v2 and v3 to v4
==============================

The way we are doing thing in v4 is quite different as we can only send data in post and to TagCommander's servers. But the code didn't change much and we can still use the old basic integration for the v4.

Remove all function not existing anymore like forceReload and the rest should still work.
To use new methods you can check in this document how to.

> You don't have to update your tagging plan in the application ! You should be able to keep your previous execute as is.
What needs to be changed is the container in your TagCommander interface, please check with your consultant.


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