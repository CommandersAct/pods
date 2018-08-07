
<html>
<body>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<h1 id="privacys-implementation-guide">Privacy's Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>07/08/2018</em><br />
Release version : <em>4.2.1</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#privacys-implementation-guide">Privacy's Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a><ul>
<li><a href="#setup">Setup</a></li>
<li><a href="#giving-consent">Giving consent</a></li>
<li><a href="#saving-consent">Saving consent</a></li>
<li><a href="#displaying-consent">Displaying consent</a></li>
<li><a href="#giving-consent_1">Giving consent</a></li>
<li><a href="#tcdemo">TCDemo</a></li>
</ul>
</li>
<li><a href="#support-and-contacts">Support and contacts</a></li>
</ul>
</div>
<h1 id="introduction">Introduction</h1>
<p>Having the user consent is essential to send sensible informations like the IDFA. To prevent having to manually save the consent asked to the user and manually using it with our SDKs, we created a module helping you do it automatically.</p>
<p>You can send to this module the gathered consents, it will then:</p>
<ul>
<li>Save it and reload it everytime the application is launched.</li>
<li>Enable or disable the SDK.</li>
<li>Add the categories automatically to the hits the SDK sends.</li>
<li>Save and check the validity of the consent. The validity duration is set to 13 months.</li>
<li>Send a hit to our servers to record the consent.</li>
</ul>
<h2 id="setup">Setup</h2>
<p>This module can use the same model you are using on the web, if you do so, please start by getting the IDs of the categories you are going to use.
Join those IDs with a "conset version". Default is 001, but if you change the implementation, it's better (but not required) to increment this version.</p>
<p>The setup is really simple, pass to the TCMobilePrivacy object your site ID, application context and a pointer to your TagCommanders' SDK instance. If you want to add your consent version, you can add it to the parameters as a NSString.</p>
<div class="codehilite"><pre><span></span><span class="o">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="o">]</span> <span class="n">setSiteID</span><span class="o">:</span> <span class="mi">3311</span> <span class="n">TCInstance</span><span class="o">:</span> <span class="n">tc</span> <span class="n">AndVersion</span><span class="o">:</span> <span class="err">@</span><span class="s">&quot;001&quot;</span><span class="o">];</span>
</pre></div>


<p>This call will check the saved consent, putting the SDK on hold if nothing is fount, and start/stop the SDK if something is saved.
It will then the check the consent validity, if it's too old, it will send a local notification of type "kTCNotification_ConsentOutdated".</p>
<p>Please note that start and stop also have a notification sent with them, you can listen to them if needed: kTCNotification_StartingTheSDK and kTCNotification_StoppingTheSDK.</p>
<h2 id="giving-consent">Giving consent</h2>
<p>Your application will have (for now) to display a page containing all the information about why the user should consent and what are the categories he can consent to.</p>
<p>Here is where the IDs of the categories matters. Once the user validated his consent, you can the send the information to the Privacy module as follow:</p>
<div class="codehilite"><pre><span></span><span class="bp">NSMutableDictionary</span> <span class="o">*</span><span class="n">consent</span> <span class="o">=</span> <span class="p">[[</span><span class="bp">NSMutableDictionary</span> <span class="n">alloc</span><span class="p">]</span> <span class="nl">initWithCapacity</span><span class="p">:</span> <span class="mi">3</span><span class="p">];</span>
<span class="p">[</span><span class="n">consent</span> <span class="nl">setObject</span><span class="p">:</span> <span class="s">@&quot;1&quot;</span> <span class="nl">forKey</span><span class="p">:</span> <span class="s">@&quot;PRIVACY_CAT_1&quot;</span><span class="p">];</span>
<span class="p">[</span><span class="n">consent</span> <span class="nl">setObject</span><span class="p">:</span> <span class="s">@&quot;0&quot;</span> <span class="nl">forKey</span><span class="p">:</span> <span class="s">@&quot;PRIVACY_CAT_2&quot;</span><span class="p">];</span>
<span class="p">[</span><span class="n">consent</span> <span class="nl">setObject</span><span class="p">:</span> <span class="s">@&quot;1&quot;</span> <span class="nl">forKey</span><span class="p">:</span> <span class="s">@&quot;PRIVACY_CAT_3&quot;</span><span class="p">];</span>
<span class="p">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">saveConsent</span><span class="p">:</span> <span class="n">consent</span><span class="p">];</span>
</pre></div>


<p>Please prefix your IDs with "PRIVACY_CAT_". 1 mean accepting this category, 0 is refusing.</p>
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


<p>This can be used to save displaying of the consent, and giving the consent.</p>
<h2 id="displaying-consent">Displaying consent</h2>
<p>If you are familiar with Commanders Act privacy for web, you know that we actually record two things. The first thing is "displaying the consent form".
This allow you to proove that a user has indeed been shown the consent screen even if he somehow left without accepting/refusing to give his consent.</p>
<p>In some cases, client also use this to infer user consent since he continued using the application after he was shown the consent screen. If you want to do the same, you will need to use the consent method seen right above to consent</p>
<div class="codehilite"><pre><span></span><span class="o">[[</span><span class="n">TCMobilePrivacy</span> <span class="n">sharedInstance</span><span class="o">]</span> <span class="n">viewConsent</span><span class="o">];</span>
</pre></div>


<h2 id="giving-consent_1">Giving consent</h2>
<p>Giving the consent save for the user every categories he accepted.</p>
<h2 id="tcdemo">TCDemo</h2>
<p>You can of course check our demo project for a simple implementation example.</p>
<p><a href="https://github.com/TagCommander/Privacy-Demo/tree/master/iOS">Privacy Demo</a></p>
<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@commandersact.com</em></p>
<p>http://www.commandersact.com</p>
<p>Commanders Act | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 07/08/2018 10:30:24</p>
</body>
</html>