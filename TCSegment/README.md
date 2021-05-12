
<html>
<body>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<h1 id="segments-implementation-guide">Segment's Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>12/05/2021</em><br />
Release version : <em>4.3.1</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#segments-implementation-guide">Segment's Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a></li>
<li><a href="#dependencies">Dependencies</a></li>
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
<p>By using Data Commander product you will be able to store a lot of data and create segments of users. With those segments you can target precisely your offers to your customers or server personalized content in your application.</p>
<p>TCSegment is a small module especially made to get the segment of your user from within your application.</p>
<h1 id="dependencies">Dependencies</h1>
<p>The Segment module is compiled with the following dependencies :</p>
<pre><code>:::ruby
compile project(':core')
compile 'com.android.support:appcompat-v7:25.1.0'
</code></pre>
<h1 id="creating-segments">Creating Segments</h1>
<p>For the creation of segments, please check the documentation of the Data Commander product.</p>
<h1 id="getting-segments">Getting Segments</h1>
<p>The module needs some information to be able to fetch segments. It will need your siteID and also your security token. Your siteID and token are provided by Commanders Act.</p>
<p>For debugging purpose, we recommend the use of TCDebug which will help you seeing what's happening inside the modules.</p>
<pre><code>:::objectivec
[TCDebug setDebugLevel: TCLogLevel_Verbose];
[TCDebug setNotificationLog: YES];
[[TCSegmentation sharedInstance] setSiteID: 3311
                                  andToken: @"e2032376eca5533858b7d6616d40802be54d221db1b75e1b"];
</code></pre>
<p>Since fetching segments needs internet and is not instantaneous, getting the segments require two steps. First you will ask the module to fetch the segmentation, then you will be able to get the list of segment once the first operation ended by either registering to a notification or by asking directly the segment list.</p>
<h2 id="fetching">Fetching</h2>
<p>To ask the module to fetch the segments, simply call the following line. Call it back each time you want to refresh the value.</p>
<pre><code>:::objectivec
[[TCSegmentation sharedInstance] fetchSegment];
</code></pre>
<h2 id="getting-the-notification">Getting the notification</h2>
<p>The simplest way to have the segment list as soon as possible is by listening to the notification sent by the module.
First you need to listen to the kTCNotification_SegmentAvailable notification like this:</p>
<pre><code>:::objectivec
NSNotificationCenter *notificationCenter = [NSNotificationCenter defaultCenter];
[notificationCenter addObserver: self
                       selector: (@selector(onNotification:))
                           name: kTCNotification_SegmentAvailable
                         object: nil];
</code></pre>
<p>Then declare the function that will treat the notification:</p>
<pre><code>:::objectivec
- (void) onNotification: (NSNotification *) incomingNotification
{
    NSString *name = incomingNotification.name;
    if ([name isEqualToString: kTCNotification_SegmentAvailable])
    {
        // Do anything you want here
    }
}
</code></pre>
<h2 id="asking-for-the-list">Asking for the List</h2>
<p>If you don't want to or can't register to the notification, you can also simply call a method from the module that will give you the current list. Be careful as it not synchronous, the list may get updated after you asked for it.</p>
<pre><code>:::objectivec
NSArray *segments = [[TCSegmentation sharedInstance] getSegments];
</code></pre>
<p>If no segment are found or they were never fetched, the list will be empty and not null.</p>
<h1 id="demo-application">Demo Application</h1>
<p>To check an example of how to use this module, please check: </p>
<p><a href="https://github.com/TagCommander/Segment-Demo/tree/master/iOS">Segment Demo</a></p>
<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@commandersact.com</em></p>
<p>http://www.commandersact.com</p>
<p>Commanders Act | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 12/05/2021 14:45:56</p>
</body>
</html>