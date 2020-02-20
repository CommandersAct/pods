
<html>
<body>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<h1 id="privacys-implementation-guide">Privacy's Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>20/02/2020</em><br />
Release version : <em>4.5.4</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#privacys-implementation-guide">Privacy's Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a><ul>
<li><a href="#choose-your-privacy">Choose your privacy</a></li>
<li><a href="#setup">Setup</a><ul>
<li><a href="#with-the-sdk">With the SDK</a></li>
<li><a href="#standalone">Standalone</a></li>
</ul>
</li>
<li><a href="#saving-consent">Saving consent</a><ul>
<li><a href="#with-the-privacy-center">With the Privacy Center</a></li>
<li><a href="#manually-displayed-consent">Manually displayed consent</a></li>
</ul>
</li>
<li><a href="#using-iab-consent-string">Using IAB Consent String</a><ul>
<li><a href="#iab-with-privacy-center">IAB with Privacy Center</a></li>
</ul>
</li>
<li><a href="#retaining-consent">Retaining consent</a><ul>
<li><a href="#using-user-id">Using user ID</a></li>
<li><a href="#using-tc_normalized_id">Using TC_NORMALIZED_ID</a></li>
<li><a href="#using-tc_sdk_id">Using TC_SDK_ID</a></li>
</ul>
</li>
<li><a href="#displaying-consent">Displaying consent</a><ul>
<li><a href="#global-consent">Global consent</a></li>
</ul>
</li>
<li><a href="#reacting-to-consent">Reacting to consent</a></li>
<li><a href="#consent-internal-api">Consent internal API</a></li>
<li><a href="#tcdemo">TCDemo</a></li>
<li><a href="#privacy-center">Privacy Center</a><ul>
<li><a href="#change-the-default-state-of-the-switch-button-to-disabled">Change the default state of the switch button to disabled:</a></li>
</ul>
</li>
</ul>
</li>
<li><a href="#support-and-contacts">Support and contacts</a></li>
</ul>
</div>
<h1 id="introduction">Introduction</h1>
<p>Having the user consent is essential to send sensible information like the IDFA/AAID.
To prevent having to manually save the consent asked to the user and manually using it with our SDKs, we created a module helping you do it automatically.</p>
<p>This module will gather the consent and will:</p>
<pre><code>- Display a consent page (if needed)
- Save consent and reload it every time the application is launched.
- Save and check the validity of the consent. The validity duration is set to 13 months.
- Send a hit to our servers to record the consent.
- Enable or disable the SDK. (if used alongside the SDK)
- Add the categories automatically to the hits the SDK sends. (if used alongside the SDK)
</code></pre>
<h2 id="choose-your-privacy">Choose your privacy</h2>
<p>Privacy come with 2 major flavors:</p>
<pre><code>- With Tag Management (With SDK)
- Standalone
</code></pre>
<p>And 2 ways to display it inside your app:</p>
<pre><code>- Manually and send us the information
- Using our Privacy Center
</code></pre>
<h2 id="setup">Setup</h2>
<p>After initialisation the Privacy module will check the consent validity. If the consent is too old a callback will be called. Please check the Callback part.</p>
<h3 id="with-the-sdk">With the SDK</h3>
<p>Modules: Core, Privacy, SDK</p>
<p>This module can use the same model you are using on the web, if you do so, please start by getting the IDs of the categories you are going to use.
Join those IDs with a "consent version". Default is 001, but if you change the implementation, it's better to increment this version.</p>
<p>/!\ This will be very simplified as we will generate a JSON from the Tag Commander interface describing your privacy and categories. (2nd Quarter 2019)</p>
<p>The setup is really simple, pass to the TCMobilePrivacy object your site ID, application context and a pointer to your TagCommanders' SDK instance. If you want to add your consent version, you can add it to the parameters as a NSString.</p>
<pre><code>[[TCMobilePrivacy sharedInstance] setSiteID: 3311 TCInstance: tc AndVersion: @"001"];
</code></pre>
<p>If you're using you're own Privacy Center, use the following function instead:</p>
<pre><code>[[TCMobilePrivacy sharedInstance] customPCMSetSiteID: siteID privacyID: privacyID andTCInstance: tc];
</code></pre>
<p>This call will check the saved consent, putting the SDK on hold if nothing is fount, and start/stop the SDK if something is saved.
It will then the check the consent validity, if it's too old, you can implement a callback treating what to do then. Please check the Callback part.</p>
<p>Please note that start and stop have a notification sent with them, you can listen to them if needed: kTCNotification_StartingTheSDK and kTCNotification_StoppingTheSDK.</p>
<p>If you need to store configuration files in another bundle than the main one, you can call the following line:</p>
<pre><code>[[TCConfigurationFileFactory sharedInstance] setBundle: myBundle forConfiguration: @"vendorlist"];
</code></pre>
<p>But please call this <em>before</em> calling [TCMobilePrivacy sharedInstance].</p>
<h3 id="standalone">Standalone</h3>
<p>Modules: Core, Privacy</p>
<p>You won't need the SDK module, and will need to implement a callback to manage your solutions when consent is given or re-loaded.</p>
<p>The setup is really simple, pass to the TCPrivacy object your site ID  application context. If you want to add your consent version, you can add it to the parameters as a String.</p>
<pre><code>[[TCMobilePrivacy sharedInstance] setSiteID: siteID andPrivacyID: privacyID];
</code></pre>
<p>If you're using you're own Privacy Center, use the following function instead:</p>
<pre><code>[[TCMobilePrivacy sharedInstance] customPCMSetSiteID: siteID privacyID: privacyID];
</code></pre>
<h2 id="saving-consent">Saving consent</h2>
<p>Here is where the IDs of the categories matters.</p>
<h3 id="with-the-privacy-center">With the Privacy Center</h3>
<p>If you're using the Privacy Center, nothing has to be done here, it will automatically propagate the consent to all other systems. And the ID will be the one used in the configuration file. Please check the Privacy Center part for more information.</p>
<p>Please keep your category IDs between 1 and 999.</p>
<h3 id="manually-displayed-consent">Manually displayed consent</h3>
<p>Once the user validated his consent, you can the send the information to the Privacy module as follow:</p>
<pre><code>NSMutableDictionary *consent = [[NSMutableDictionary alloc] initWithCapacity: 3];
[consent setObject: @"1" forKey: @"PRIVACY_CAT_1"];
[consent setObject: @"0" forKey: @"PRIVACY_CAT_2"];
[consent setObject: @"1" forKey: @"PRIVACY_CAT_3"];
[[TCMobilePrivacy sharedInstance] saveConsent: consent];
</code></pre>
<p>Please prefix your category IDs with "PRIVACY_CAT_" and your vendor IDs with "PRIVACY_VEN_. 1 mean accepting this category or vendor, 0 is refusing.</p>
<p>Passing vendor information is crucial for IAB.</p>
<p>If you're using the SDK, this will propagate the information to the SDK and manage its state.</p>
<h2 id="using-iab-consent-string">Using IAB Consent String</h2>
<p>For now we can create a consent string, but we can't display the privacy center with information from the vendor list. We're creating a first release with only the consent string before so that all our client that don't use the Privacy Center can use IAB.</p>
<p>If you want to have an offline version of the official vendor list, please add it to your project named "vendorlist.json" at the same place as you would with the privacy.json of the PCM (please check the PCM part).</p>
<p>First you will need to add the consent library to your project. You will find it in the same repository.</p>
<p>This library is the TCIAB module, you will find the usual podspecs in the repository. Please beware that depending on your XCode version the universal versions might not be working.</p>
<p>When you init the Privacy module it will check if this library is present in your project. If so, it will save in the phone that a CMP is present.</p>
<p>Then later, when you save the consent, the consent string will automatically be created and saved.</p>
<p>Everything saved is saved with keys defined under the IAB standards. We use mainly IABConsent_CMPPresent and IABConsent_ConsentString.</p>
<h3 id="iab-with-privacy-center">IAB with Privacy Center</h3>
<p>As explained above IAB is not made to work with the privacy center for now, so if you still want to use the privacy center, please do it like this:</p>
<p>You first need to remove the automatic link between the module and IAB by disabling IAB:</p>
<pre><code>[TCMobilePrivacy sharedInstance].enableIAB = NO;
[TCMobilePrivacy sharedInstance].vendorListVersion = 146;
</code></pre>
<p>You need to manually set the vendorListVersion also as this is required during the creation of the consent string (we default at 146 which is the version )</p>
<p>Then when you want to save the consent you will need to manually send information:</p>
<pre><code>NSDictionary *consent = [[NSMutableDictionary alloc] init];
[consent setValue: @"1" forKey: @"PRIVACY_CAT_1"];
[consent setValue: @"1" forKey: @"PRIVACY_CAT_2"];
[consent setValue: @"1" forKey: @"PRIVACY_VEN_52"];
[consent setValue: @"1" forKey: @"PRIVACY_VEN_141"];
[[TCMobilePrivacy sharedInstance] saveConsentString: consent];
</code></pre>
<p>You can put this inside the "consentUpdated" callback and you need to map the ID you're using inside the privacy center to either a purpose id or a vendor id.
For now we can't do better since we're not distinguishing vendors and category inside the privacy center. An evolution will be done after the support of IAB v2.</p>
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
<p>You will be able to get the information more easily since this is an ID available by several means for you.</p>
<h3 id="using-tc_normalized_id">Using TC_NORMALIZED_ID</h3>
<p>You will get the IDFA/AAID most of the time (as long as the user is not opt-out) and a generated ID the rest of the time. This might allow you to get the information if you know the device identifier.
Otherwise, you will have to get the ID stored in the app memory. See TC_SDK_ID.</p>
<h3 id="using-tc_sdk_id">Using TC_SDK_ID</h3>
<p>In this case the only place where the ID exists is inside the application memory.
If you're looking for a way to proove consent or reset saved information, you'll need to create a specific screen in app for this.</p>
<h2 id="displaying-consent">Displaying consent</h2>
<p>If you are familiar with Commanders Act privacy for web, you know that we actually record two things. The first thing is "displaying the consent form".
This allow you to prove that a user has indeed been shown the consent screen even if he somehow left without accepting/refusing to give his consent.</p>
<p>In some cases, client also use this to infer user consent since he continued using the application after he was shown the consent screen.
We don't recommend this behaviour, please discuss it with your setup team first.</p>
<p>Either way it's interesting to be able to log the fact that the consent screen has been viewed. If you're not using the Privacy Center, please call:</p>
<pre><code>[[TCMobilePrivacy sharedInstance] viewConsent];
</code></pre>
<h3 id="global-consent">Global consent</h3>
<p>We integrated an On/Off switch so that the user can consent to all categories at the same time.
It's not mandatory yet, but recommended.</p>
<h2 id="reacting-to-consent">Reacting to consent</h2>
<p>Some of the event happening in the SDK have callbacks associated with them in the case you need to do specific actions at this specific moment.</p>
<p>Currently we have a callback function that lets you get back the categories and setup your other partners accordingly.
This is the function where you would tell your ad partner "the user don't wan't to receive personalized ads" for example.</p>
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
<h2 id="consent-internal-api">Consent internal API</h2>
<p>We created several methods to check given consent. They are simple, but make it easier to work with consent information at any given time.</p>
<pre><code>/**
 * Checks if consent has already been given by checking if consent information is saved.
 * @return YES if the consent was already given, NO otherwise.
 */
+ (BOOL) isConsentAlreadyGiven;
</code></pre>
<p>&nbsp;</p>
<pre><code>/**
 * Return the epochformatted timestamp of the last time the consent was saved.
 * @return epochformatted timestamp or 0.
 */
+ (unsigned long long) getLastTimeConsentWasSaved;
</code></pre>
<p>&nbsp;</p>
<pre><code>/**
 * Check if a Category has been accepted.
 * @param ID the category ID.
 * @return YES or NO.
 */
+ (BOOL) isCategoryAccepted: (int) catID;
</code></pre>
<p>&nbsp;</p>
<pre><code>/**
 * Check if a vendor has been accepted.
 * @param ID the vendor ID.
 * @return YES or NO.
 */
+ (BOOL) isVendorAccepted: (int) venID;
</code></pre>
<p>&nbsp;</p>
<pre><code>/**
 * Get the list of all accepted vendors.
 * @return a List of PRIVACY_VEN_IDs.
 */
+ (NSArray&lt;NSString *&gt; *) getAcceptedCategories;
</code></pre>
<p>&nbsp;</p>
<pre><code>/**
 * Get the list of all accepted vendors.
 * @return a List of PRIVACY_VEN_IDs.
 */
+ (NSArray&lt;NSString *&gt; *) getAcceptedVendors;
</code></pre>
<p>&nbsp;</p>
<pre><code>/**
 * Get the list of everything that was accepted.
 * @return a List of PRIVACY_VEN_IDs and PRIVACY_CAT_IDs.
 */
+ (NSArray&lt;NSString *&gt; *) getAllAcceptedConsent;
</code></pre>
<p>&nbsp;</p>
<pre><code>/**
 * /!\ Only if you're using the IAB module.
 * Get the generated consent string.
 * @return the generated consent string. Ex. BOrufEYOrufEYBaABLFRCSuAAAA-eADAFEABIAHo
 */
+ (NSString *) getIABConsentString;
</code></pre>
<p>&nbsp;</p>
<h2 id="tcdemo">TCDemo</h2>
<p>You can, of course, check our demo project for a simple implementation example.</p>
<p><a href="https://github.com/TagCommander/Privacy-Demo/tree/master/iOS">Privacy Demo</a></p>
<h2 id="privacy-center">Privacy Center</h2>
<p>The Privacy Center is represented by a JSON file that describes the interfaces that will be created by native code inside the application.</p>
<p>We create an UIViewController to create the privacy center view.
The offline JSON should be inside the project code folder.</p>
<pre><code>TCPrivacyCenterViewController *PCM = [[TCPrivacyCenterViewController alloc] init];
UIBarButtonItem *backButton = [[UIBarButtonItem alloc] initWithTitle: [PCM getSaveButtonText]
                                                               style: UIBarButtonItemStylePlain
                                                              target: nil
                                                              action: nil];

self.navigationItem.backBarButtonItem = backButton;
[self.navigationController pushViewController: PCM animated: YES];
</code></pre>
<p>Since we have a view controller, you can call it by pushing it. It's quite easy, but this mean we have to add code if we want to customize the name of the save/back button.</p>
<p>Some part of the Privacy Center can be customised with your code.</p>
<h3 id="change-the-default-state-of-the-switch-button-to-disabled">Change the default state of the switch button to disabled:</h3>
<pre><code>[TCMobilePrivacy sharedInstance].switchDefaultState = NO;
</code></pre>
<p>For now this JSON has to be created and managed manually. But soon, this will be created by our interfaces. And the SDK will check for updates of the file automatically.
Meanwhile the configuration has to be done manually and you can find the definition of the file here.</p>
<pre><code>:::json
{
    "information": {
        "update": "2018-10-23",
        "version": "1",
        "content": "\nThis is your sample privacy center.",
        "saveButton": "Save",
        "privacy_policy_url": "https://www.commandersact.com/en/privacy/",
        "privacy_policy_text": "Privacy policy"
    },
    "customisation": {
        "content": {
            "fontcolor": "#ffffff",
            "backgroundcolor": "#333333"
        },
        "button": {
            "fontcolor": "#ffffff",
            "backgroundcolor": "#6faae5"
        }
    },
    "global_consent" : {
        "name" : "All categories", "ID": "0", "description" : "Preferences for all services\n\n"
    },
    "categories": [
        { "name" : "Statistics", "ID" : "1234", "description" : "These cookies allow us analyze user behavior on the site, measure and improve performance and the quality of our service." },
        { "name" : "Advertising", "ID" : "1444", "description" : "These cookies allow us display adverts matching your interests on the websites you visit.", "privacy_policy_url": "https://www.commandersact.com/en/privacy/1", "privacy_policy_text": "Privacy policy" },
        { "name" : "Details", "ID" : "4", "description" : "Here you can select the vendors.", "subcategories": [
            { "name" : "GA", "ID" : "5", "description" : "Should we send information to GA.", "privacy_policy_url": "https://www.google.com/analytics/terms/us.html", "privacy_policy_text": "Privacy policy" },
            { "name" : "Xiti", "ID" : "6", "description" : "Should we send information to AT Internet." },
            { "name" : "Vendor3", "ID" : "7", "description" : "Should we send information to this vendor3." }
        ]}
    ]
}
</code></pre>
<p>The <em>information</em> part contain information about the date of the configuration, the version of the file (not of the consent), the global text introducing the Privacy and the name of the save/back button.</p>
<p>The <em>customisation</em> part defines colors for the content and the buttons, if not present, no style will be applied to your buttons.</p>
<p>The <em>global_consent</em> let you customize the text alongside the global consent button. If not present, no global consent button will appear inside your app.</p>
<p>The <em>categories</em> let you give all the categories to accept or refuse and define their names, IDs and description. If a category has sub categories, you can define them in <em>subcategories</em>.</p>
<p>If you want to display a link to you privacy policies (or anything else in fact), you can add together "privacy_policy_url" and "privacy_policy_text" that will form a linkable text the line after the description.</p>
<p>Example:</p>
<p><img alt="alt tag" src="../res/privacy_example.png" /></p>
<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@commandersact.com</em></p>
<p>http://www.commandersact.com</p>
<p>Commanders Act | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 20/02/2020 09:12:43</p>
</body>
</html>