Changelog iOS
=============

<div class="warning"></div>
>  If you want to check the previous version's changelog, you can find it here :

[Previous changelist](../res/changelog_iOS_3.md)

*4.2.1 : 06/13 2018*

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
