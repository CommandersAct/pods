
<html>
<body>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<h1 id="beacons-implementation-guide">Beacon's Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>31/03/2017</em><br />
Release version : <em>4.1.0</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#beacons-implementation-guide">Beacon's Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a><ul>
<li><a href="#beacon-101">Beacon 101</a></li>
<li><a href="#types-of-beacons">Types of beacons</a></li>
<li><a href="#good-practice">Good practice</a></li>
<li><a href="#limitations">Limitations</a></li>
</ul>
</li>
<li><a href="#implementation">Implementation</a><ul>
<li><a href="#dependencies">Dependencies</a></li>
<li><a href="#compatibility">Compatibility</a></li>
</ul>
</li>
<li><a href="#scanning-for-beacons">Scanning for beacons</a><ul>
<li><a href="#background-scanning">Background scanning</a></li>
<li><a href="#tcdemo">TCDemo</a></li>
</ul>
</li>
<li><a href="#support-and-contacts">Support and contacts</a></li>
</ul>
</div>
<h1 id="introduction">Introduction</h1>
<p>The Beacon module helps you scan your surrounding and parse the data from the beacons found.</p>
<h2 id="beacon-101">Beacon 101</h2>
<p>Beacons are devices that use the Bluetooth Low Energy (BLE) protocol to repeatedly send short transmissions. Those short transmissions depends on the type of Beacon, basic iBeacons and EddyStone UUID beacons only sends a simple UUID, while Eddystone's URL type sends a complete URL as it's name states.</p>
<p>It allows us to discover when a user is physically close to one of your beacon.</p>
<h2 id="types-of-beacons">Types of beacons</h2>
<p>Here is the list of the types of beacons currently supported by Commanders Act's module:</p>
<ul>
<li>iBeacons : Which broadcast an UUID with a Major and a Minor.</li>
<li>Eddystone : Exist with 4 types of frames, UUID, URL, Telemetry and EID.</li>
</ul>
<p>When you use a beacon, it is recommended that you only access information from your network of beacons. To do that the scan are filtered by an ID (beside with Eddystone's URL beacons), on iBeacon we use the full UUID of the beacon, on Eddystone we use the first part of it (called the namespace).</p>
<p>As an example for our demo application we filter on "397180b5-be24-4090-8af5-8237f4e17248" when we are dealing with our iBeacons and on "017180B5-BE24-4090-8AF5" for our Eddystone ones.</p>
<p><a href="https://github.com/google/eddystone/blob/master/protocol-specification.md">If you want specific technical documentation on Eddystone's protocol, please check this link</a></p>
<h2 id="good-practice">Good practice</h2>
<p>Scanning in itself doesn't use too much of your battery (but still use some of course). It is <em>recommended</em> that you ask the user to opt-in for beacon scanning and also explain how it will be beneficial for him. As bluetooth must be enabled, explaining everything to him will also push him to activate the bluetooth more often.</p>
<h2 id="limitations">Limitations</h2>
<p>Right now, we only allow to scan and filter on one UUID. It is the classic implementation to rely on one UUID and have major/minors depending on your shops and where your beacons are placed. (or one namespace and several instances).
If you need a specific implementation or information, please contact support.</p>
<h1 id="implementation">Implementation</h1>
<p><a href="../README.md">Please check the Developers Implementation Guide to choose the best way to implement this module in your project.</a></p>
<h2 id="dependencies">Dependencies</h2>
<p>Beacon requires the following frameworks:</p>
<ul>
<li>CoreLocation.framework</li>
<li>CoreBluetooth.framework</li>
<li>TCCore.framework</li>
</ul>
<h2 id="compatibility">Compatibility</h2>
<ul>
<li>Architecture: armv7, arm64, i386 and x86_64, bitcode sections</li>
<li>deployement target: 8.0</li>
<li>Compiled with ARC enabled</li>
</ul>
<h1 id="scanning-for-beacons">Scanning for beacons</h1>
<p>Scanning for beacon is pretty easy, tell us what we need to scan for, and we'll give you updates.</p>
<p>The first thing you want to do is to listen to the events we will send you when we found, update or lost a beacon.</p>
<p>You can use an helper class we created for notifications or do it all by yourself. The following lines show you how to do it and give you the names of the notifications.</p>
<div class="codehilite"><pre><span class="nb">self</span><span class="p">.</span><span class="n">listenerDelegate</span> <span class="o">=</span> <span class="p">[[</span><span class="n">TCEventListener</span> <span class="n">alloc</span><span class="p">]</span> <span class="n">init</span><span class="p">];</span>
<span class="nb">self</span><span class="p">.</span><span class="n">listenerDelegate</span><span class="p">.</span><span class="n">parent</span> <span class="o">=</span> <span class="nb">self</span><span class="p">;</span>
<span class="p">[</span><span class="nb">self</span><span class="p">.</span><span class="n">listenerDelegate</span> <span class="nl">listen</span><span class="p">:</span> <span class="n">kTCNotification_BeaconFound</span><span class="p">];</span>
<span class="p">[</span><span class="nb">self</span><span class="p">.</span><span class="n">listenerDelegate</span> <span class="nl">listen</span><span class="p">:</span> <span class="n">kTCNotification_BeaconUpdate</span><span class="p">];</span>
<span class="p">[</span><span class="nb">self</span><span class="p">.</span><span class="n">listenerDelegate</span> <span class="nl">listen</span><span class="p">:</span> <span class="n">kTCNotification_BeaconLost</span><span class="p">];</span>
</pre></div>


<p>When you have your user consent to scan for beacons, you can call the following code to scan for an Eddystone beacon:</p>
<div class="codehilite"><pre><span class="p">[</span><span class="n">TCDebug</span> <span class="nl">setDebugLevel</span><span class="p">:</span> <span class="n">TCLogLevel_Verbose</span><span class="p">];</span>
<span class="p">[[</span><span class="n">TCBeacons</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">startWithBeaconType</span><span class="p">:</span> <span class="n">kTCEddystoneServiceID</span> <span class="nl">andID</span><span class="p">:</span> <span class="s">@&quot;017180B5-BE24-4090-8AF5&quot;</span><span class="p">];</span>
</pre></div>


<p>Or if you want to scann for an iBeacon:</p>
<div class="codehilite"><pre><span class="p">[[</span><span class="n">TCBeacons</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">startWithBeaconType</span><span class="p">:</span> <span class="n">kTCiBeaconServiceID</span> <span class="nl">andID</span><span class="p">:</span> <span class="s">@&quot;397180b5-be24-4090-8af5-8237f4e17248&quot;</span><span class="p">];</span>
</pre></div>


<p>If you only want to scan URL type beacons, no need to pass the module any UUID at all.</p>
<p>And then create the delegate method for the notifications (here simply logging the result):</p>
<div class="codehilite"><pre><span class="p">-</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="nf">onNotificationReceived:</span> <span class="p">(</span><span class="bp">NSNotification</span> <span class="o">*</span><span class="p">)</span> <span class="nv">incomingNotification</span>
<span class="p">{</span>
    <span class="bp">NSString</span> <span class="o">*</span><span class="n">notificationName</span> <span class="o">=</span> <span class="n">incomingNotification</span><span class="p">.</span><span class="n">name</span><span class="p">;</span>

    <span class="k">if</span> <span class="p">([</span><span class="n">notificationName</span> <span class="nl">isEqualToString</span><span class="p">:</span> <span class="n">kTCNotification_BeaconFound</span><span class="p">])</span>
    <span class="p">{</span>
        <span class="bp">NSString</span> <span class="o">*</span><span class="n">frameType</span> <span class="o">=</span> <span class="p">[</span><span class="n">incomingNotification</span><span class="p">.</span><span class="n">userInfo</span> <span class="nl">objectForKey</span><span class="p">:</span> <span class="n">kTCUserInfo_FrameType</span><span class="p">];</span>

        <span class="k">if</span> <span class="p">([</span><span class="n">frameType</span> <span class="nl">isEqualToString</span><span class="p">:</span> <span class="n">kTCEddystoneFrameType_UUID</span><span class="p">])</span>
        <span class="p">{</span>
            <span class="n">TCEddyStoneID</span> <span class="o">*</span><span class="n">beaconID</span> <span class="o">=</span> <span class="p">[</span><span class="n">incomingNotification</span><span class="p">.</span><span class="n">userInfo</span> <span class="nl">objectForKey</span><span class="p">:</span> <span class="n">kTCUserInfo_BeaconObject</span><span class="p">];</span>
            <span class="p">[[</span><span class="n">TCLogger</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">logMessage</span><span class="p">:</span> <span class="p">[</span><span class="bp">NSString</span> <span class="nl">stringWithFormat</span><span class="p">:</span> <span class="s">@&quot;%@&quot;</span><span class="p">,</span> <span class="n">beaconID</span><span class="p">]</span> <span class="nl">withLevel</span><span class="p">:</span> <span class="n">TCLogLevel_Debug</span><span class="p">];</span>
            <span class="c1">// treat your beacon here.</span>
        <span class="p">}</span>
    <span class="p">}</span>
<span class="p">}</span>
</pre></div>


<h2 id="background-scanning">Background scanning</h2>
<p>The important thing to do is enable it for your own project. to do that you need to go to your Target, click on the Capabilities button and under Background Modes check "Location updates" and "Uses Bluetooth LE accessories". This will automatically adds the required keys in your plist file.</p>
<p><img alt="alt tag" src="../res/Beacon_BackgroundMode.png" /></p>
<p>/!\ Please take note that Apple is doing things it's way and background scanning won't be as fast and frequent as it is on foreground.</p>
<h2 id="tcdemo">TCDemo</h2>
<p>You can of course check our demo project for a simple implementation example.</p>
<p><a href="https://github.com/TagCommander/Beacon-Demo/tree/master/iOS">Beacon Demo</a></p>
<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@commandersact.com</em></p>
<p>http://www.commandersact.com</p>
<p>Commanders Act | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 31/03/2017 09:39:00</p>
</body>
</html>