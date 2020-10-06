Changelog iOS
=============

<div class="warning"></div>
>  If you want to check the previous version's changelog, you can find it here :

[Previous changelist](../res/changelog_iOS_3.md)

*4.6.0 : 09/24 2020*

	+ Building for iOS 14.

*4.5.4 : 08/31 2020*

	/!\ To benefit from this update you need to also update the core module to 4.6.4 or later.
	+ Added a method to force the SDK to wait for the user_agent.

*4.5.3 : 03/26 2020*

	~ Modified TagCommander's activateSDK and deactivateSDK to throw the corresponding notification to propagate it to the whole system.

*4.5.2 : 02/19 2020*

	+ Added LICENCE.md in release zips to allow cocoapods to read it automatically.

*4.5.1 : 02/10 2020*

	~ Modified the way we are copying the predefined variables in TCPostData to prevent synchronisation issues provoked by the fact that getting the user-agent with WKWebView is slower than before.

*4.5.0 : 12/18 2019*

	/!\ With this update you need to also update the core module to 4.6.0+
	- Removing armv7s support.
	- Removed didEnterBackground and willEnterForeground as public method, they should not be used outside the of the SDK.
	- Removed battery monitoring.

*4.4.1 : 09/30 2019*

	- Removed all functions linked to Location update. Users not using it might be refused submission otherwise.

*4.3.1 : 02/04 2019*

	~ Put back function to deactivate the SDK manually in the case we don't need the full privacy module and still want to deactivate the SDK.

*4.3.0 : 12/05 2018*

	- Moved TCUser_agent in Core

*4.2.3 : 08/06 2018*

	~ Refactoring on consent hits to give them a proper route.

*4.2.2 : 08/01 2018*

	+ Protecting the addition of data in the datalayer when the SDK is disabled.

*4.2.1 : 06/13 2018*

	 /!\ With this update you need to also update the core module as it changes the accessibility of 2 important functions.
	+ Checking the value of TC_IDFA as it can be unavailable on very rare cases.

*4.1.5 : 01/08 2018*

	~ Corrected wrong format for TC_LAST_VISIT/MS

*4.1.4 : 01/05 2018*

	~ Corrected wrong memory management attributes in TCProduct

*4.1.3 : 12/06 2017*

	+ You can now disable the SDK by calling disableSDK() nothing will be treated by the SDK after this.

*4.1.2 : 11/22 2017*

	+ Added Background Mode, a way to force the SDK to work when the application is in background.
	- Removed the ways to directly touch the DynamicStores used by the system classes.

*4.1.1 : 03/08 2017*

	~ Correction on ReachabilityChangedNotification.

*4.1.0 : 02/06 2017*

	+ Beacon module release.

*4.0.0 : 12/12 2016*

    + Added Cocoapods support
    ~ Modified release format from static library to Framework.
    ~ Transformed the SDK from a light SDK to a "Server-side" only SDK. We will now only send information to our server to manage the reste of the treatment.
    - Removed functionalities for managing tags (Conditions and Exernal configuration)
