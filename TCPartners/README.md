
<html>
<body>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<h1 id="partners-implementation-guide">Partners' Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>17/05/2019</em><br />
Release version : <em>4.3.1</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#partners-implementation-guide">Partners' Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a></li>
<li><a href="#partners">Partners</a></li>
<li><a href="#adobe-audience-manager-aam">Adobe Audience Manager (AAM)</a><ul>
<li><a href="#hit">Hit</a></li>
</ul>
</li>
<li><a href="#freewheel">Freewheel</a></li>
<li><a href="#support-and-contacts">Support and contacts</a></li>
</ul>
</div>
<h1 id="introduction">Introduction</h1>
<p>In some specific cases we need to have a direct connection from the phone to a vendor.</p>
<p>In this case hits need to be sent from the phone and we need to treat the response from the server inside the app.</p>
<h1 id="partners">Partners</h1>
<p>TCPartners or TCMobilePartners is the class used as the super-type of all partners.</p>
<p>A TCPartner is by default a partner that will listen to all hits you're passing to the SDK so he can work on them.
You can change this activation by using on of the 3 following functions:</p>
<div class="codehilite"><pre><span></span><span class="cm">/**</span>
<span class="cm"> * This function tells the partner to activate on all hits.</span>
<span class="cm"> */</span>
<span class="p">-</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="nf">activateOnAllHits</span>

<span class="cm">/**</span>
<span class="cm"> * This function tells the partner to only treat hit when the specified key is in the datalayer.</span>
<span class="cm"> * @param key the key to activate the treatment.</span>
<span class="cm"> */</span>
<span class="p">-</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="nf">activateOnKey:</span> <span class="p">(</span><span class="bp">NSString</span> <span class="o">*</span><span class="p">)</span> <span class="nv">key</span>

<span class="cm">/**</span>
<span class="cm">* This function tells the partner to only treat hit when the specified key/value pair is in the datalayer.</span>
<span class="cm">* @param key the specific key.</span>
<span class="cm">* @param value the specific value.</span>
<span class="cm">*/</span>
<span class="p">-</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="nf">activateOnKey:</span> <span class="p">(</span><span class="bp">NSString</span> <span class="o">*</span><span class="p">)</span> <span class="nv">key</span> <span class="nf">andValue:</span> <span class="p">(</span><span class="bp">NSString</span> <span class="o">*</span><span class="p">)</span> <span class="nv">value</span>
</pre></div>


<p>So think carefully about which activation method you want for your partners.</p>
<h1 id="adobe-audience-manager-aam">Adobe Audience Manager (AAM)</h1>
<p>The point of this connector is the send information to Adobe Audience Manager and get back the segments corresponding to the app user.</p>
<div class="codehilite"><pre><span></span><span class="p">[[</span><span class="n">TCPartners_AdobeAudienceManager</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">setDataSourceID</span><span class="p">:</span> <span class="mi">81811</span> <span class="nl">andPlatformID</span><span class="p">:</span> <span class="mi">20201</span><span class="p">];</span>
<span class="p">[[</span><span class="n">TCPartners_AdobeAudienceManager</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="n">initSegmentation</span><span class="p">];</span>
</pre></div>


<p>This connector only works if we have and IDFA or AAID.</p>
<h2 id="hit">Hit</h2>
<p>Since we're potentially sending information to several partners we need to differentiate the data for AAM.
We're basing ourselves on the datalayer and are taking all the keys prefixed "c_" as keys to add to the hits sent to AAM.</p>
<p>If among the data layer, the connector finds the key #USER_ID#, we will send an "identified" hit. Which simply behave slightly differently, but has the same use.</p>
<h1 id="freewheel">Freewheel</h1>
<p>Our Freewheel implementation is only made to forward the segments computed in Adobe for them.</p>
<p>This means we only need 2 things to make it work.</p>
<p>The first one is the callback function that should be called when we parsed the segment information.</p>
<p>The second is the domain which correspond to the application. This is needed because AAM can send information from several different app domains when you have several configured.</p>
<p>You will have to register to a callback to receive the content of the segments.</p>
<p>And will receive a response of the format:</p>
<div class="codehilite"><pre><span></span><span class="p">{</span>
    <span class="err">aam_fr=sid=81025,</span>
    <span class="err">aam_oas=PYT_63359=Y,</span>
    <span class="err">aam_fw=PYT_63359=Y&amp;PYT_619=Y&amp;PYT_7398=Y&amp;PYT_94221</span>
<span class="p">}</span>
</pre></div>


<p>To initialize Freewheel:</p>
<div class="codehilite"><pre><span></span><span class="p">[[</span><span class="n">TCPartners_Freewheel</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">setDomain</span><span class="p">:</span> <span class="s">@&quot;.tf1.fr&quot;</span><span class="p">];</span>
<span class="p">[[</span><span class="n">TCPartners_Freewheel</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">setCallback</span><span class="p">:</span> <span class="nb">self</span><span class="p">];</span>
</pre></div>


<p>And to recover the segments:</p>
<div class="codehilite"><pre><span></span><span class="p">-</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="nf">onSegmentReceived:</span> <span class="p">(</span><span class="bp">NSDictionary</span> <span class="o">*</span><span class="p">)</span> <span class="nv">segments</span>
<span class="p">{</span>
    <span class="p">[[</span><span class="n">TCLogger</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">logMessage</span><span class="p">:</span> <span class="p">[</span><span class="bp">NSString</span> <span class="nl">stringWithFormat</span><span class="p">:</span> <span class="s">@&quot;onSegmentReceived: %@&quot;</span><span class="p">,</span> <span class="n">segments</span><span class="p">]</span> <span class="nl">withLevel</span><span class="p">:</span> <span class="n">TCLogLevel_Error</span><span class="p">];</span>
<span class="p">}</span>
</pre></div>


<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@commandersact.com</em></p>
<p>http://www.commandersact.com</p>
<p>Commanders Act | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 17/05/2019 16:31:07</p>
</body>
</html>