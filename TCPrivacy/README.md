
<html>
<body>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<h1 id="privacys-implementation-guide">Privacy's Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>13/03/2019</em><br />
Release version : <em>4.3.1</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#privacys-implementation-guide">Privacy's Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a><ul>
<li><a href="#choose-your-privacy">Choose your privacy</a><ul>
<li><a href="#with-the-sdk">With the SDK</a></li>
<li><a href="#standalone">Standalone</a></li>
</ul>
</li>
<li><a href="#setup">Setup</a><ul>
<li><a href="#with-the-sdk_1">With the SDK</a></li>
<li><a href="#standalone_1">Standalone</a></li>
</ul>
</li>
<li><a href="#giving-consent">Giving consent</a><ul>
<li><a href="#with-the-privacy-center">With the Privacy Center</a></li>
<li><a href="#mannually-displayed-consent">Mannually displayed consent</a></li>
</ul>
</li>
<li><a href="#saving-consent">Saving consent</a></li>
<li><a href="#displaying-consent">Displaying consent</a><ul>
<li><a href="#global-consent">Global consent</a></li>
</ul>
</li>
<li><a href="#reacting-to-consent">Reacting to consent</a></li>
<li><a href="#tcdemo">TCDemo</a></li>
<li><a href="#privacy-center">Privacy Center</a></li>
</ul>
</li>
<li><a href="#support-and-contacts">Support and contacts</a></li>
</ul>
</div>
<h1 id="introduction">Introduction</h1>
<p>Having the user consent is essential to send sensible information like the IDFA/AAID.
To prevent having to manually save the consent asked to the user and manually using it with our SDKs, we created a module helping you do it automatically.</p>
<p>This module will gather the consent and will:</p>
<div class="codehilite"><pre><span></span>- Save it and reload it every time the application is launched.
- Save and check the validity of the consent. The validity duration is set to 13 months.
- Send a hit to our servers to record the consent.
- Enable or disable the SDK. (if used alongside the SDK)
- Add the categories automatically to the hits the SDK sends. (if used alongside the SDK)
</pre></div>


<h2 id="choose-your-privacy">Choose your privacy</h2>
<p>Privacy come with 2 major flavors:</p>
<h3 id="with-the-sdk">With the SDK</h3>
<p>With the SDK, you will need to have the SDK module in your app and will have to initialize the Privacy module with an instance of the TagCommander class.</p>
<h3 id="standalone">Standalone</h3>
<p>You won't need the SDK module, and will need to implement a callback to manage your solutions when consent is given or re-loaded.</p>
<p>And 2 ways to display it inside your app:</p>
<div class="codehilite"><pre><span></span>- Manually and send us the information
- Using our Privacy Center
</pre></div>


<h2 id="setup">Setup</h2>
<p>After initialisation the Privacy module will check the consent validity. If the consent is too old a callback will be called. Please check the Callback part.</p>
<h3 id="with-the-sdk_1">With the SDK</h3>
<p>This module can use the same model you are using on the web, if you do so, please start by getting the IDs of the categories you are going to use.
Join those IDs with a "consent version". Default is 001, but if you change the implementation, it's better to increment this version.</p>
<p>/!\ This will be very simplified as we will generate a JSON from the Tag Commander interface describing your privacy and categories. (2nd Quarter 2019)</p>
<p>The setup is really simple, pass to the TCMobilePrivacy object your site ID, application context and a pointer to your TagCommanders' SDK instance. If you want to add your consent version, you can add it to the parameters as a NSString.</p>
<div class="codehilite"><pre><span></span><span class="o">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="o">]</span> <span class="n">setSiteID</span><span class="o">:</span> <span class="mi">3311</span> <span class="n">TCInstance</span><span class="o">:</span> <span class="n">tc</span> <span class="n">AndVersion</span><span class="o">:</span> <span class="err">@</span><span class="s">&quot;001&quot;</span><span class="o">];</span>
</pre></div>


<p>This call will check the saved consent, putting the SDK on hold if nothing is fount, and start/stop the SDK if something is saved.
It will then the check the consent validity, if it's too old, you can implement a callback treating what to do then. Please check the Callback part.</p>
<p>Please note that start and stop have a notification sent with them, you can listen to them if needed: kTCNotification_StartingTheSDK and kTCNotification_StoppingTheSDK.</p>
<h3 id="standalone_1">Standalone</h3>
<p>The setup is really simple, pass to the TCPrivacy object your site ID  application context. If you want to add your consent version, you can add it to the parameters as a String.</p>
<div class="codehilite"><pre><span></span><span class="o">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="o">]</span> <span class="n">setSiteID</span><span class="o">:</span> <span class="n">siteID</span> <span class="n">andPrivacyID</span><span class="o">:</span> <span class="n">privacyID</span><span class="o">];</span>
</pre></div>


<p>A lot of things are hidden behind this call:</p>
<div class="codehilite"><pre><span></span>- it will check saved consent
- try to update and replace the JSON configuration
</pre></div>


<h2 id="giving-consent">Giving consent</h2>
<p>Here is where the IDs of the categories matters.</p>
<h3 id="with-the-privacy-center">With the Privacy Center</h3>
<p>If you're using the Privacy Center, nothing has to be done here, it will automatically propagate the consent to all other systems.</p>
<h3 id="mannually-displayed-consent">Mannually displayed consent</h3>
<p>Once the user validated his consent, you can the send the information to the Privacy module as follow:</p>
<div class="codehilite"><pre><span></span><span class="bp">NSMutableDictionary</span> <span class="o">*</span><span class="n">consent</span> <span class="o">=</span> <span class="p">[[</span><span class="bp">NSMutableDictionary</span> <span class="n">alloc</span><span class="p">]</span> <span class="nl">initWithCapacity</span><span class="p">:</span> <span class="mi">3</span><span class="p">];</span>
<span class="p">[</span><span class="n">consent</span> <span class="nl">setObject</span><span class="p">:</span> <span class="s">@&quot;1&quot;</span> <span class="nl">forKey</span><span class="p">:</span> <span class="s">@&quot;PRIVACY_CAT_1&quot;</span><span class="p">];</span>
<span class="p">[</span><span class="n">consent</span> <span class="nl">setObject</span><span class="p">:</span> <span class="s">@&quot;0&quot;</span> <span class="nl">forKey</span><span class="p">:</span> <span class="s">@&quot;PRIVACY_CAT_2&quot;</span><span class="p">];</span>
<span class="p">[</span><span class="n">consent</span> <span class="nl">setObject</span><span class="p">:</span> <span class="s">@&quot;1&quot;</span> <span class="nl">forKey</span><span class="p">:</span> <span class="s">@&quot;PRIVACY_CAT_3&quot;</span><span class="p">];</span>
<span class="p">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">saveConsent</span><span class="p">:</span> <span class="n">consent</span><span class="p">];</span>
</pre></div>


<p>Please prefix your IDs with "PRIVACY_CAT_". 1 mean accepting this category, 0 is refusing.</p>
<p>If you're using the SDK, this will propagate the information to the SDK and manage its state.</p>
<h2 id="saving-consent">Saving consent</h2>
<p>The saving of the consent on our servers is done automatically.</p>
<p>But since we are saving the consent in our servers, we need to identify the user one way or another. By default the variable used to identify the user consenting is #TC_NORMALIZED_ID#, but you can change it to anything you'd like.
If you want to use an ID already inside the SDK:</p>
<div class="codehilite"><pre><span></span><span class="p">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">setConsentUser</span><span class="p">:</span> <span class="s">@&quot;#TC_IDFA#&quot;</span><span class="p">];</span>
</pre></div>


<p>If you want to use an ID from your data layer, please first add it to the permanant store:</p>
<div class="codehilite"><pre><span></span><span class="p">[</span><span class="n">tc</span> <span class="nl">addPermanentData</span><span class="p">:</span> <span class="s">@&quot;MY_ID&quot;</span> <span class="nl">withValue</span><span class="p">:</span> <span class="s">@&quot;12345&quot;</span><span class="p">];</span>
<span class="p">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">setConsentUser</span><span class="p">:</span> <span class="s">@&quot;MY_ID&quot;</span><span class="p">];</span>
</pre></div>


<p>This can be used to save the display of the consent, and giving the consent.</p>
<h2 id="displaying-consent">Displaying consent</h2>
<p>If you are familiar with Commanders Act privacy for web, you know that we actually record two things. The first thing is "displaying the consent form".
This allow you to prove that a user has indeed been shown the consent screen even if he somehow left without accepting/refusing to give his consent.</p>
<p>In some cases, client also use this to infer user consent since he continued using the application after he was shown the consent screen.
We don't recommend this behaviour, please discuss it with your setup team first.</p>
<p>Either way it's interesting to be able to log the fact that the consent screen has been viewed. If you're not using the Privacy Center, please call:</p>
<div class="codehilite"><pre><span></span><span class="o">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="o">]</span> <span class="n">viewConsent</span><span class="o">];</span>
</pre></div>


<h3 id="global-consent">Global consent</h3>
<p>While not yet available in the web part, we already integrated an On/Off switch so that the user can consent to all categories at the same time.
It's not mandatory but recommended.</p>
<h2 id="reacting-to-consent">Reacting to consent</h2>
<p>Some of the event happening in the SDK have callbacks associated with them in the case you need to do specific actions at this specific moment.
Currently we have a callback function that lets you get back the categories and setup your other partners accordingly.
This is the function where you would tell your ad partner "the user don't wan't to receive personalized ads" for example.</p>
<div class="codehilite"><pre><span></span><span class="o">-</span> <span class="o">(</span><span class="kt">void</span><span class="o">)</span> <span class="n">consentUpdated</span><span class="o">:</span> <span class="o">(</span><span class="n">NSDictionary</span> <span class="o">*)</span> <span class="n">consent</span><span class="o">;</span>
</pre></div>


<p>Called when you give us the user selected consents, or when we load the saved consent from the SDK.
We have a Dictionnary which is the same as the one given to our SDK with keys PRIVACY_CAT_n and value @"0" or @"1".</p>
<div class="codehilite"><pre><span></span><span class="o">-</span> <span class="o">(</span><span class="kt">void</span><span class="o">)</span> <span class="n">consentOutdated</span><span class="o">;</span>
</pre></div>


<p>This is called after 13 months without change in the user consent. This can allow you to force displaying the consent the same way you would on first launch.</p>
<h2 id="tcdemo">TCDemo</h2>
<p>You can, of course, check our demo project for a simple implementation example.</p>
<p><a href="https://github.com/TagCommander/Privacy-Demo/tree/master/iOS">Privacy Demo</a></p>
<h2 id="privacy-center">Privacy Center</h2>
<p>The Privacy Center is represented by a JSON file that describes the interfaces that will be created by native code inside the application.</p>
<p>We create an UIViewController to create the privacy center view.
The offline JSON should be inside the project code folder.</p>
<div class="codehilite"><pre><span></span><span class="n">TCPrivacyCenterViewController</span> <span class="o">*</span><span class="n">PCM</span> <span class="o">=</span> <span class="p">[[</span><span class="n">TCPrivacyCenterViewController</span> <span class="n">alloc</span><span class="p">]</span> <span class="n">init</span><span class="p">];</span>
<span class="bp">UIBarButtonItem</span> <span class="o">*</span><span class="n">backButton</span> <span class="o">=</span> <span class="p">[[</span><span class="bp">UIBarButtonItem</span> <span class="n">alloc</span><span class="p">]</span> <span class="nl">initWithTitle</span><span class="p">:</span> <span class="p">[</span><span class="n">PCM</span> <span class="n">getSaveButtonText</span><span class="p">]</span>
                                                               <span class="nl">style</span><span class="p">:</span> <span class="n">UIBarButtonItemStylePlain</span>
                                                              <span class="nl">target</span><span class="p">:</span> <span class="nb">nil</span>
                                                              <span class="nl">action</span><span class="p">:</span> <span class="nb">nil</span><span class="p">];</span>

<span class="nb">self</span><span class="p">.</span><span class="n">navigationItem</span><span class="p">.</span><span class="n">backBarButtonItem</span> <span class="o">=</span> <span class="n">backButton</span><span class="p">;</span>
<span class="p">[</span><span class="nb">self</span><span class="p">.</span><span class="n">navigationController</span> <span class="nl">pushViewController</span><span class="p">:</span> <span class="n">PCM</span> <span class="nl">animated</span><span class="p">:</span> <span class="nb">YES</span><span class="p">];</span>
</pre></div>


<p>Since we have a view controller, you can call it by pushing it. It's quite easy, but this mean we have to add code if we want to customize the name of the save/back button.</p>
<p>For now this JSON has to be created and managed manually. But soon, this will be created by our interfaces. And the SDK will check for updates of the file automatically.
Meanwhile the configuration has to be done manually and you can find the definition of the file here.</p>
<div class="codehilite"><pre><span></span><span class="p">{</span>
    <span class="nt">&quot;information&quot;</span><span class="p">:</span> <span class="p">{</span>
        <span class="nt">&quot;update&quot;</span><span class="p">:</span> <span class="s2">&quot;2018-10-23&quot;</span><span class="p">,</span>
        <span class="nt">&quot;version&quot;</span><span class="p">:</span> <span class="s2">&quot;1&quot;</span><span class="p">,</span>
        <span class="nt">&quot;content&quot;</span><span class="p">:</span> <span class="s2">&quot;\nThis is your sample privacy center\n&quot;</span><span class="p">,</span>
        <span class="nt">&quot;saveButton&quot;</span><span class="p">:</span> <span class="s2">&quot;Save&quot;</span>
    <span class="p">},</span>
    <span class="nt">&quot;customisation&quot;</span><span class="p">:</span> <span class="p">{</span>
        <span class="nt">&quot;content&quot;</span><span class="p">:</span> <span class="p">{</span>
            <span class="nt">&quot;fontcolor&quot;</span><span class="p">:</span> <span class="s2">&quot;#ffffff&quot;</span><span class="p">,</span>
            <span class="nt">&quot;backgroundcolor&quot;</span><span class="p">:</span> <span class="s2">&quot;#333333&quot;</span>
        <span class="p">},</span>
        <span class="nt">&quot;button&quot;</span><span class="p">:</span> <span class="p">{</span>
            <span class="nt">&quot;fontcolor&quot;</span><span class="p">:</span> <span class="s2">&quot;#ffffff&quot;</span><span class="p">,</span>
            <span class="nt">&quot;backgroundcolor&quot;</span><span class="p">:</span> <span class="s2">&quot;#6faae5&quot;</span>
        <span class="p">}</span>
    <span class="p">},</span>
    <span class="nt">&quot;global_consent&quot;</span> <span class="p">:</span> <span class="p">{</span>
        <span class="nt">&quot;name&quot;</span> <span class="p">:</span> <span class="s2">&quot;All categories&quot;</span><span class="p">,</span> <span class="nt">&quot;ID&quot;</span><span class="p">:</span> <span class="s2">&quot;0&quot;</span><span class="p">,</span> <span class="nt">&quot;description&quot;</span> <span class="p">:</span> <span class="s2">&quot;Preferences for all services\n\n&quot;</span>
    <span class="p">},</span>
    <span class="nt">&quot;categories&quot;</span><span class="p">:</span> <span class="p">[</span>
        <span class="p">{</span> <span class="nt">&quot;name&quot;</span> <span class="p">:</span> <span class="s2">&quot;Statistics&quot;</span><span class="p">,</span> <span class="nt">&quot;ID&quot;</span> <span class="p">:</span> <span class="s2">&quot;1234&quot;</span><span class="p">,</span> <span class="nt">&quot;description&quot;</span> <span class="p">:</span> <span class="s2">&quot;These cookies allow us analyze user behavior on the site, measure and improve performance and the quality of our service.&quot;</span> <span class="p">},</span>
        <span class="p">{</span> <span class="nt">&quot;name&quot;</span> <span class="p">:</span> <span class="s2">&quot;Advertising&quot;</span><span class="p">,</span> <span class="nt">&quot;ID&quot;</span> <span class="p">:</span> <span class="s2">&quot;1444&quot;</span><span class="p">,</span> <span class="nt">&quot;description&quot;</span> <span class="p">:</span> <span class="s2">&quot;These cookies allow us display adverts matching your interests on the websites you visit.&quot;</span> <span class="p">},</span>
        <span class="p">{</span> <span class="nt">&quot;name&quot;</span> <span class="p">:</span> <span class="s2">&quot;Details&quot;</span><span class="p">,</span> <span class="nt">&quot;ID&quot;</span> <span class="p">:</span> <span class="s2">&quot;4&quot;</span><span class="p">,</span> <span class="nt">&quot;description&quot;</span> <span class="p">:</span> <span class="s2">&quot;Here you can select the vendors.&quot;</span><span class="p">,</span> <span class="nt">&quot;subcategories&quot;</span><span class="p">:</span> <span class="p">[</span>
            <span class="p">{</span> <span class="nt">&quot;name&quot;</span> <span class="p">:</span> <span class="s2">&quot;GA&quot;</span><span class="p">,</span> <span class="nt">&quot;ID&quot;</span> <span class="p">:</span> <span class="s2">&quot;5&quot;</span><span class="p">,</span> <span class="nt">&quot;description&quot;</span> <span class="p">:</span> <span class="s2">&quot;Should we send information to GA&quot;</span> <span class="p">},</span>
            <span class="p">{</span> <span class="nt">&quot;name&quot;</span> <span class="p">:</span> <span class="s2">&quot;Xiti&quot;</span><span class="p">,</span> <span class="nt">&quot;ID&quot;</span> <span class="p">:</span> <span class="s2">&quot;6&quot;</span><span class="p">,</span> <span class="nt">&quot;description&quot;</span> <span class="p">:</span> <span class="s2">&quot;Should we send information to AT Internet&quot;</span> <span class="p">},</span>
            <span class="p">{</span> <span class="nt">&quot;name&quot;</span> <span class="p">:</span> <span class="s2">&quot;Vendor3&quot;</span><span class="p">,</span> <span class="nt">&quot;ID&quot;</span> <span class="p">:</span> <span class="s2">&quot;7&quot;</span><span class="p">,</span> <span class="nt">&quot;description&quot;</span> <span class="p">:</span> <span class="s2">&quot;Should we send information to this vendor3&quot;</span> <span class="p">}</span>
        <span class="p">]}</span>
    <span class="p">]</span>
<span class="p">}</span>
</pre></div>


<p>The <em>information</em> part contain information about the date of the configuration, the version of the file (not of the consent), the global text introducing the Privacy and the name of the save/back button.</p>
<p>The <em>customisation</em> part defines colors for the content and the buttons, if not present, no style will be applied to your buttons.</p>
<p>The <em>global_consent</em> let you customize the text alongside the global consent button. If not present, no global consent button will appear inside your app.</p>
<p>The <em>categories</em> let you give all the categories to accept or refuse and define their names, IDs and description. If a category has sub categories, you can define them in <em>subcategories</em>.</p>
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
<p>This documentation was generated on 13/03/2019 12:00:11</p>
</body>
</html>