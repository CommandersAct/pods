
<html>
<body>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<h1 id="tciabs-implementation-guide">TCIAB's Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>07/05/2021</em><br />
Release version : <em>4.6.1</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#tciabs-implementation-guide">TCIAB's Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a></li>
<li><a href="#setup">Setup</a></li>
<li><a href="#iab-21">IAB 2.1</a><ul>
<li><a href="#json-configurations">JSON Configurations</a><ul>
<li><a href="#vendor-listjson">Vendor-list.json</a></li>
<li><a href="#purposes-xxjson">purposes-xx.json</a></li>
<li><a href="#privacyjson">privacy.json</a></li>
<li><a href="#tciabpublisherrestrictionsjson">TCIABPublisherRestrictions.json</a></li>
</ul>
</li>
<li><a href="#filtering-vendors">Filtering vendors</a></li>
<li><a href="#selecting-buttons">Selecting buttons</a></li>
<li><a href="#initialisation">Initialisation</a></li>
<li><a href="#with-the-sdk">With the SDK</a></li>
<li><a href="#retaining-consent">Retaining consent</a><ul>
<li><a href="#using-user-id">Using user ID</a></li>
<li><a href="#using-tc_normalized_id">Using TC_NORMALIZED_ID</a></li>
<li><a href="#using-tc_sdk_id">Using TC_SDK_ID</a></li>
</ul>
</li>
<li><a href="#reacting-to-consent">Reacting to consent</a></li>
<li><a href="#generating-publisher-tc-in-consent-string">Generating publisher TC in consent String</a></li>
<li><a href="#loading-a-specific-screen-directly">Loading a specific screen directly</a></li>
</ul>
</li>
<li><a href="#support-and-contacts">Support and contacts</a></li>
</ul>
</div>
<h1 id="introduction">Introduction</h1>
<p>This module has been made especially to support the creation of the IAB consent string.</p>
<p>/!\ It only supports the version 2 of the consent string. Namely TCF v2.</p>
<h1 id="setup">Setup</h1>
<p>You need to have this module alongside the Privacy Module in your project.</p>
<p>You will need several configuration files to use this module.
All of those configurations will update automatically but having an offline version will prevent any hasardeous behaviour over bad internet connection.</p>
<h1 id="iab-21">IAB 2.1</h1>
<p>We suport IAB 2.1 but you will need to add some translation in your privacy.json file. Hereafter are the lines you need to add in order to display the new informations properly.</p>
<pre><code>:::json
 "texts": {
  "generic": {
        "month": "months",
        "day": "days",
        "seconds": "seconds",
        "hours": "hours"
  },

  "vendors": {
        "deviceStorageTitle": "Storage Type:",
        "deviceStorageCookieLifetime": "Cookie lifetime: ",
        "deviceStorageOther": "Others",
        "deviceStorageCookies": "Cookies"
  },
</code></pre>
<h2 id="json-configurations">JSON Configurations</h2>
<h3 id="vendor-listjson">Vendor-list.json</h3>
<p>This file contains all vendors that have a partnership with IAB. It also contains the definition (in English only) for all purposes, special purposes, features, special features and what the vendors are using.
This files is created and supported by IAB.</p>
<p>Please download and put an offline copy in your project of https://vendorlist.consensu.org/v2/vendor-list.json
Keeping the same name.</p>
<h3 id="purposes-xxjson">purposes-xx.json</h3>
<p>If you are using more than one language in your application you will need to also have a copy of those files. Those files are created and supported by IAB.
For example, our IAB demo is using purposes-fr.json.</p>
<p>If you need translation files, download them from https://register.consensu.org/translation under "List of translations for purpose descriptions v2.0". Also keeping the same file name.</p>
<p>Call this line right after the initialisation of the TCPrivacy module:</p>
<pre><code>:::java
[[TCMobilePrivacy sharedInstance] setLanguage: @"fr"];
</code></pre>
<h3 id="privacyjson">privacy.json</h3>
<p>This file declares information used to save the privacy in our dashboards as well as texts present in the interface that are not declared officially by IAB.</p>
<p>/!\ This file should be provided by one of our consultant.</p>
<p>If you are using several languages, you should find, in addition to "texts" which have the default values, "texts_xx" for each language.</p>
<h3 id="tciabpublisherrestrictionsjson">TCIABPublisherRestrictions.json</h3>
<p>/!\ This file is a bit more specific and not mandatory.</p>
<p>It is here to represent the restrictions a publisher (your company) is applying its partners.</p>
<p>If you have a file, you need to put it with the other json configurations and add a small line later in the code.</p>
<p>[[TCMobilePrivacy sharedInstance] useCustomPublisherRestrictions];</p>
<p>/!\ This should normally decided by your project manager and the file should be created by your Commanders Act contact.</p>
<h2 id="filtering-vendors">Filtering vendors</h2>
<p>It is possible that instead of displaying all the hundreds of vendors in the vendor list, you'd rather display only the one your company needs. This will also filter all purposes and special features that we ask the user to consent to.</p>
<p>If you want to filter, nothing has to be done inside the code, but you should find inside the privacy.json in "information" a field like : "vendors": "8,18,467,310".</p>
<p>This tells that you are only using the vendors which IDs are 8, 18, 467 and 310. Those ID refers to the IDs they are given inside the vendor-list.</p>
<p>/!\ This should normally decided by your project manager and added inside the json by your Commanders Act contact.</p>
<h2 id="selecting-buttons">Selecting buttons</h2>
<p>The IAB interface is separated in 2 layers. The first layer is the first screen you'll see when opening the privacy center.
The second layer is the purpose screen as well as the vendor screen.</p>
<p>In those 2 interfaces, the default buttons are defined as followed:</p>
<p>First layer: "Detail" (lead to the purpose detail screen), "Accept All" and "Refuse All"
Second layer: "Save" (use the current state of all switches), "Accept All" and "Refuse All"</p>
<p>IAB asks that you have at least a "Detail" button on the first layer, and a "Save" on the second.
Starting September 2020 the CNIL asks that if you have a "Accept all" button, you need a "Refuse all" button with an identical visual.</p>
<p>Meanwhile you can select the button you want to see as well as the order they'll appear in among the default ones by changing part of the privacy JSON.</p>
<pre><code>"components": {
    "firstLayerButton": ["Detail", "AcceptAll", "RefuseAll"],
    "secondLayerButton": ["Save", "AcceptAll", "RefuseAll"],
},
</code></pre>
<p>You can add those lines and select the needing ones. For example, if you don't want a refuse all button, just remove "RefuseAll".</p>
<h2 id="initialisation">Initialisation</h2>
<pre><code>:::java
// If you need to use callbacks.
[[TCMobilePrivacy sharedInstance] registerCallback: self];

// a. This is for the stand-alone version
[[TCMobilePrivacy sharedInstance] setSiteID: 3311 andPrivacyID: 320];
// b. Instead use this line if you're using the SDK at the same time.
[[TCMobilePrivacy sharedInstance] setSiteID: 3311 containerID: 7 privacyID: 320 andTCInstance: tc];

// Use this if you need to use a specific language
[[TCMobilePrivacy sharedInstance] setLanguage: @"fr"];
</code></pre>
<h2 id="with-the-sdk">With the SDK</h2>
<p>You can use classic Tag Management with IAB if needed. Doing this is really simple as all saved information used for IAB configuration will be forwarded to each server-side call.
This mean that you can use any IAB purpose as a category and create rules in your container accordingly.    </p>
<h2 id="retaining-consent">Retaining consent</h2>
<p>The saving of the consent on our servers is done automatically.</p>
<p>But since we are saving the consent in our servers, we need to identify the user one way or another. By default the variable used to identify the user consenting is #TC_SDK_ID#, but you can change it to anything you'd like.</p>
<p>If you want to use an ID already inside the SDK:</p>
<pre><code>[[TCMobilePrivacy sharedInstance] setConsentUser: @"#TC_IDFA#"];
</code></pre>
<p>If you want to use an ID from your data layer, please first add it to the permanant store:</p>
<pre><code>[tc addPermanentData: @"MY_ID" withValue: @"12345"];
[[TCMobilePrivacy sharedInstance] setConsentUser: @"MY_ID"];
</code></pre>
<p>and if you simply want to simply pass the information:</p>
<pre><code>[[TCMobilePrivacy sharedInstance] setConsentUser: @"123456765432"];
</code></pre>
<p>This can be used to save the display of the consent, and giving the consent.</p>
<p>This ID is very important because it will be the basic information used to get back the consent when you need a proof.</p>
<h3 id="using-user-id">Using user ID</h3>
<p>You will be able to get the information more easily since this is an ID available by several means for you.
The possible issue here is that you usually ask for consent before asking for the user to log in.</p>
<h3 id="using-tc_normalized_id">Using TC_NORMALIZED_ID</h3>
<p>You will get the IDFA/AAID most of the time (as long as the user is not opt-out) and a generated ID the rest of the time. This might allow you to get the information if you know the device identifier.
Otherwise, you will have to get the ID stored in the app memory. See TC_SDK_ID.</p>
<h3 id="using-tc_sdk_id">Using TC_SDK_ID</h3>
<p>In this case the only place where the ID exists is inside the application memory.
If you're looking for a way to prove consent or reset saved information, you'll need to create a specific screen in app for this.</p>
<h2 id="reacting-to-consent">Reacting to consent</h2>
<p>Some of the event happening in the Privacy have callbacks associated with them in the case you need to do specific actions at this specific moment.</p>
<p>Currently we have a callback function that lets you get back the categories and setup your other partners accordingly.
This is the function where you would tell your ad partner (not included in IAB) "the user don't wan't to receive personalized ads" for example.</p>
<p>/!\ Don't forget to register to the callbacks <em>before</em> the initialisation of the Privacy Module since the module will check consent at init and use the callback at this step.</p>
<pre><code>- (void) consentUpdated: (NSDictionary *) consent;
</code></pre>
<p>Called when you give us the user selected consents, or when we load the saved consent from the SDK.
We have a Dictionnary which is the same as the one given to our SDK with keys PRIVACY_CAT_n and value @"0" or @"1".</p>
<pre><code>- (void) consentOutdated;
</code></pre>
<p>This is called after 13 months without change in the user consent. This can allow you to force displaying the consent the same way you would on first launch.</p>
<pre><code>- (void) consentCategoryChanged;
</code></pre>
<p>When you make a change in the JSON, there is nothing special to do.
But when this change is adding or removing a category, or changing an ID, we should re-display the Privacy Center.</p>
<pre><code>- (void) significantChangesInPrivacy;
</code></pre>
<p>This one is slightly different from the last one, it was created for IAB and will not be sent automatically. It is conditionned by the field "significantChanges" in the privacy.json so that it will only launch when you need it to.</p>
<h2 id="generating-publisher-tc-in-consent-string">Generating publisher TC in consent String</h2>
<p>By default, as some clients asked, the publisher TC part of the consent string is not generated.
But you a simple boolean in TCPrivacy/TCMobilePrivacy which is named generatePublisherTC.</p>
<h2 id="loading-a-specific-screen-directly">Loading a specific screen directly</h2>
<p>By default, the screen loaded is what we call the first layer screen (or pop-up screen). Then from this screen you'll be able to go to the purpose screen and from the purpose screen to the vendor screen. Both of which are called the second layer.</p>
<p>if you want to have your own first layer, you'll want to be able to open from this page either of our second layer pages.</p>
<p>To do this, we created other ways to open the privacy center as follow:</p>
<pre><code>TCIABPrivacyCenterViewController *PCM = [[TCIABPrivacyCenterViewController alloc] init];
[PCM startWithPurposeScreen];
[self.navigationController pushViewController: PCM animated: NO];
</code></pre>
<p>or for the vendor screen:</p>
<pre><code>[PCM startWithVendorScreen];
</code></pre>
<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@commandersact.com</em></p>
<p>http://www.commandersact.com</p>
<p>Commanders Act | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 07/05/2021 10:16:54</p>
</body>
</html>