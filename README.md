![alt tag](./res/logo.png)


Developers' Implementation Guide
================================
**iOS**

Last update : *02/12/2016*<br />
Release version : *4.0.0*


<p><div id="end_first_page" /></p>

[TOC]

Introduction
============

TagCommander for mobile is a collection of small SDKs each designed to serve a dedicated purpose.
The modules are the following :
	 - [Core : Used as a base by the other modules.](TCCore/README.md)
	 - [SDK : Tag management system collecting data throught a server-side aproach.](TCSDK/README.md)
	 - [Segment : Get your user segmentation from our servers.](TCSegment/README.md)

For each of those modules, please check their respective documentation for more information.


Adding a module to your project
===============================

If you want to add a module to your android project, you have several possibilities.

	- Using cocoapods to manage the dependency.
	- Using directly the framework files in your project.

Whatever the chosen way to add it is, please remember that we have two different versions available.

	- A debug version with the architectures for phones and simulators.
	- A release version with only the architectures for phones.


Cocoapods
---------

Please note that if you are using cocoapod changes that would have you modify your applications are made, we will create new podspec files for the newest versions.

<div class="warning"></div>
>  You will always need to at least add the Core module to your project.

https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-debug-universal.podspec
https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-release-iphoneos.podspec

Framework
---------

The latest version of our modules are always available on our github account: https://github.com/TagCommander/pods

<div class="warning"></div>
>  You will always need to at least add the Core module to your project.

Add the modules you need to your project and confirm that XCode really added them for your Target at the following places:
	- In the "general" tab under "Linked Frameworks and Libraries"
	- In the "Build Phases" tab under "Link Binary With Libraries"
	- That the FRAMEWORK_SEARCH_PATHS do include the places where the frameworks are.

Support and contacts
====================
![alt tag](./res/logo.png)

***
**Support**
*support@tagcommander.com*

http://www.tagcommander.com

TagCommander | 3/5 rue Saint Georges - 75009 PARIS - France
***

This documentation was generated on 02/12/2016 11:23:19
