
<html>
<body>
<p><img alt="alt tag" src="../res/logo.png" /></p>
<h1 id="segments-implementation-guide">Segment's Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>20/01/2017</em><br />
Release version : <em>4.0.0</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#segments-implementation-guide">Segment's Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a></li>
<li><a href="#creating-segments">Creating Segments</a></li>
<li><a href="#getting-segments">Getting Segments</a><ul>
<li><a href="#fetching">Fetching</a></li>
<li><a href="#getting-the-notification">Getting the notification</a></li>
<li><a href="#asking-for-the-list">Asking for the List</a></li>
</ul>
</li>
<li><a href="#demo-application">Demo Application</a></li>
<li><a href="#support-and-contacts">Support and contacts</a></li>
</ul>
</div>
<h1 id="introduction">Introduction</h1>
<p>By using TagCommander's Engage product you will be able to store a lot of data and create segments of users. With those segments you can target precisely your offers to your customers or server personalized content in your application.</p>
<p>TCSegment is a small module especially made to get the segment of your user from within your application.</p>
<h1 id="creating-segments">Creating Segments</h1>
<p>For the creation of segments, please check the documentation of the Engage product.</p>
<h1 id="getting-segments">Getting Segments</h1>
<p>The module needs some information to be able to fetch segments. It will need your siteID and also your security token. Your siteID and token are provided by TagCommander.</p>
<p>For debugging purpose, we recommand the use of TCDebug which will help you seeing what's happening inside the modules.</p>
<div class="codehilite"><pre><span class="p">[</span><span class="n">TCDebug</span> <span class="nl">setDebugLevel</span><span class="p">:</span> <span class="n">TCLogLevel_Verbose</span><span class="p">];</span>
<span class="p">[</span><span class="n">TCDebug</span> <span class="nl">setNotificationLog</span><span class="p">:</span> <span class="nb">YES</span><span class="p">];</span>
<span class="p">[[</span><span class="n">TCSegmentation</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="nl">setSiteID</span><span class="p">:</span> <span class="mi">3311</span>
                                  <span class="nl">andToken</span><span class="p">:</span> <span class="s">@&quot;e2032376eca5533858b7d6616d40802be54d221db1b75e1b&quot;</span><span class="p">];</span>
</pre></div>


<p>Since fetching segments needs internet and is not instantaneous, getting the segments require two steps. First you will ask the module to fetch the segmentation, then you will be able to get the list of segment once the first operation ended by either registering to a notification or by asking directly the segment list.</p>
<h2 id="fetching">Fetching</h2>
<p>To ask the module to fetch the segments, simply call the following line. Call it back each time you want to refresh the value.</p>
<div class="codehilite"><pre><span class="p">[[</span><span class="n">TCSegmentation</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="n">fetchSegment</span><span class="p">];</span>
</pre></div>


<h2 id="getting-the-notification">Getting the notification</h2>
<p>The simplest way to have the segment list as soon as possible is by listening to the notification sent by the module.
First you need to listen to the kTCNotification_SegmentAvailable notification like this:</p>
<div class="codehilite"><pre><span class="bp">NSNotificationCenter</span> <span class="o">*</span><span class="n">notificationCenter</span> <span class="o">=</span> <span class="p">[</span><span class="bp">NSNotificationCenter</span> <span class="n">defaultCenter</span><span class="p">];</span>
<span class="p">[</span><span class="n">notificationCenter</span> <span class="nl">addObserver</span><span class="p">:</span> <span class="nb">self</span>
                       <span class="nl">selector</span><span class="p">:</span> <span class="p">(</span><span class="k">@selector</span><span class="p">(</span><span class="nl">onNotification</span><span class="p">:))</span>
                           <span class="nl">name</span><span class="p">:</span> <span class="n">kTCNotification_SegmentAvailable</span>
                         <span class="nl">object</span><span class="p">:</span> <span class="nb">nil</span><span class="p">];</span>
</pre></div>


<p>Then declare the function that will treat the notification:</p>
<div class="codehilite"><pre><span class="p">-</span> <span class="p">(</span><span class="kt">void</span><span class="p">)</span> <span class="nf">onNotification:</span> <span class="p">(</span><span class="bp">NSNotification</span> <span class="o">*</span><span class="p">)</span> <span class="nv">incomingNotification</span>
<span class="p">{</span>
    <span class="bp">NSString</span> <span class="o">*</span><span class="n">name</span> <span class="o">=</span> <span class="n">incomingNotification</span><span class="p">.</span><span class="n">name</span><span class="p">;</span>
    <span class="k">if</span> <span class="p">([</span><span class="n">name</span> <span class="nl">isEqualToString</span><span class="p">:</span> <span class="n">kTCNotification_SegmentAvailable</span><span class="p">])</span>
    <span class="p">{</span>
        <span class="c1">// Do anything you want here</span>
    <span class="p">}</span>
<span class="p">}</span>
</pre></div>


<h2 id="asking-for-the-list">Asking for the List</h2>
<p>If you don't want to or can't register to the notification, you can also simply call a method from the module that will give you the current list. Be carefull as it not synchroneous, the list may get updated after you asked for it.</p>
<div class="codehilite"><pre><span class="bp">NSArray</span> <span class="o">*</span><span class="n">segments</span> <span class="o">=</span> <span class="p">[[</span><span class="n">TCSegmentation</span> <span class="n">sharedInstance</span><span class="p">]</span> <span class="n">getSegments</span><span class="p">];</span>
</pre></div>


<p>If no segment are found or they were never fetched, the list will be empty and not null.</p>
<h1 id="demo-application">Demo Application</h1>
<p>To check an example of how to use this module, please check: </p>
<p><a href="https://github.com/TagCommander/Segment-Demo/tree/master/iOS">Segment Demo</a></p>
<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="../res/logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@tagcommander.com</em></p>
<p>http://www.tagcommander.com</p>
<p>TagCommander | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 20/01/2017 17:09:55</p>
</body>
</html>