Changelog iOS
=============

<div class="warning"></div>
>  If you want to check the previous version's changelog, you can find it here :

[Previous changelist](../res/changelog_iOS_3.md)

*4.7.0 : 09/24 2020*

	+ Building for iOS 14.
	+ (iOS 14+ only) IDFA is no longer automatically fetched, please check SDK documentation.

*4.6.5 : 09/21/2020*

	+ Added a way to use a custom WKProcessPool when asking for user agent to prevent cookie erasure.

*4.6.4 : 08/31/2020*

	/!\ To benefit from this update you need to also update the SDK module to 4.5.4 or later.
	+ Added a way to wait for the asynchroneous user-agent to be available.

*4.6.3 : 07/30/2020*

	~ Configuration files updates are now raising a notification.

*4.6.2 : 02/19 2020*

	+ Added LICENCE.md in release zips to allow cocoapods to read it automatically

*4.6.1 : 12/19 2019*

	~ issue with User-Agent not saved in the core dictionnary anymore leading it to be missing for other modules.
	~ corrected bug in the initialisation of SDK_ID which would not be saved properly inside the core dictionnary the first app launch.

*4.6.0 : 12/18 2019*

	/!\ With this update you need to also update the SDK module to 4.5.0+
	- Removing armv7s support.
	+ TVOS compatibility.
	+ Fixed useragent on TVOS since it's not compatible with WebKit.
	- Removed battery monitoring.

*4.5.5 : 11/11 2019*

	+ Allow to change the bundle where the module reads the default configuration files on a file per file basis. Please read the Privacy module's documentation.

*4.5.4 : 10/23 2019*

	~ Correction for 4.5.3 where no offline configuration would still cause a crash in preSaveOfflineJSON.

*4.5.3 : 10/14 2019*

	+ Removed the need to have the offline counterpart of configuration files.

*4.5.2 : 10/02 2019*

    ~ Verifying that all WKWebView opererations are done on the main thread.

*4.5.1 : 09/30 2019*

    ~ Removing old UIWebView now deprecated for getting user-agent with WKWebView.


*4.4.1 : 09/20 2019*

    + Refactoring on configuration files which now are in the priority queue.


*4.3.3 : 06/04 2019*

	- Removed useless (and deprecated key) in Info.plist


*4.3.2 : 05/13 2019*

	~ Corrected error in encoding constant resulting in bad display of accents.


*4.3.1 : 03/12 2019*

    + Added route for Partners hits
    ~ Small HTTP notifications refactorisation


*4.3.0 : 12/05 2018*

	+ Moved TCUser_agent in Core


*4.2.3 : 08/06 2018*

	~ Refactoring on consent hits to give them a proper route.


*4.2.2 : 08/01 2018*

	+ We can now modify a TCHTTPOperation to put additional post data.


*4.2.1 : 06/27 2018*
	
	+ Privacy notifications.


*4.2.0 : 06/13 2018*

	+ Allow direct acces to setIDFA and setIDFV to reload those values when the first init came too soon.


*4.1.5 : 12/06 2017*

	+ You can now disable the SDK by calling disableSDK() nothing will be treated by the SDK after this.


*4.1.4 : 11/22 2017*

	+ Added Background Mode, a way to force the SDK to work when the application is in background.
	- Removed the ways to directly touch the DynamicStores used by the system classes.


*4.1.3 : 03/08 2017*

	+ Added TC_SDK_ID and TC_NORMALIZED_ID


*4.1.2 : 03/08 2017*

	~ Correction on ReachabilityChangedNotification.


*4.1.1 : 03/02 2017*

	+ Corrected issue on unrecognized selector in Core with NoIDFA.


*4.1.0 : 02/06 2017*

	+ Beacon module release.


*4.0.0 : 12/12 2016*

	+ Added Cocoapods support.
	~ Modified release format from static library to Framework.
    + Separated all the core functions into a separated and reusable module.
    + Added TCDebug class to clarify the debug options and have equal functionalities as the Android counterpart.
    - Removed the log output "file".
