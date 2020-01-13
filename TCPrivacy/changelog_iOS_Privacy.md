Changelog iOS
=============

*4.5.3 : 01/13/2020*

	~ Issue on TCPrivacyAPI header not visible.

*4.5.2 : 12/19 2019*

	~ corrected empty Vendor list due to prefix parsing error.

*4.5.1 : 12/19 2019*

	~ The variable userID used to specify a specific userID for privacy was not initialised to nil leading to hazardous behaviours.

*4.5.0 : 12/18 2019*

	- Removing armv7s support.
	+ Added an API class to check the content or status of the consent. Please check the TCPrivacy documentation on github.

*4.4.5 : 11/11 2019*

	+ Changing the switch tint color.

*4.4.4 : 10/29 2019*

	+ All the switch positions of the Privacy Center can now default to the off position by using : [TCMobilePrivacy sharedInstance].switchDefaultState = NO;

*4.4.3 : 10/14 2019*

	~ Correction on vendorlist.json usage.
	/!\ the file should be named vendorlist.json like in Android.

*4.4.2 : 09/25 2019*

    ~ Correction on TCConfigurationFactory initialisation when not using CMP

*4.4.1 : 09/20 2019*

    ~ /!\ Update Core module alongside this module.
    ~ /!\ Function to initialize Privacy have changed
    ~ Refactoring on file configurations
    + We now have a class to manage distant configuration and privacy versions are taken from the configuration. 

*4.3.10 : 08/05 2019*

    ~ User-agent encoding error in stand alone privacy. 


*4.3.9 : 08/02 2019*

    ~ Only passing categories ID related IAB for Consent String generation. 
    

*4.3.8 : 06/07 2019*

	~ Corrected merge error preventing some consent hit to be sent.


*4.3.7 : 05/15 2019*

	+ Generating consent string for IAB version 1.


*4.3.6 : 05/13 2019*

	~ Corrected error in encoding constant resulting in bad display of accents.


*4.3.5 : 04/11 2019*

	~ Privacy Policy: Don't take into account the /n into the link zone.


*4.3.4 : 03/25 2019*

    ~ Refactoring and better documentation for the ID used to save the privacy.


*4.3.3 : 03/19 2019*

	+ Callback if there is an important change in configuration update.


*4.3.2 : 01/22 2019*

    + Privacy policies can be added in the descriptions.
    + Better privacy metrics


*4.3.1 : 01/04 2019*

	~ Corrected callback not called when saving consent standalone.
	~ Corrected a bug where sending nil to saveConsent would not disable the SDK.


*4.3.0 : 12/05 2018*

	+ Privacy Center to display the privacy inside the app.
	+ Managing offline configuration and checking for updates
	+ Possibility to use Privacy as a standalone module (with core, but withtout the SDK module).
	+ Possibility to give a global consent in the Privacy Center.
	~ Updated consent saving hits to use TCPID instead of the TCID.


*4.2.2 : 10/23 2018*

	+ Added callbacks for "updatedConsent" and "outdatedConsent"


*4.2.1 : 08/01 2018*

	+ You can call the "viewConsent" method to log it.
	~ Corrected the consent update hits that sometimes would be created after the disabling of the SDK.
	+ Propagating the validated categories to the hit that where waiting for consent.


*4.2.0 : 02/01 2018*

    + Give your user's privacy settings to the SDK.
