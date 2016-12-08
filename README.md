
<html>
<body>
<p><img alt="alt tag" src="res/logo.png" /></p>
<h1 id="developers-implementation-guide">Developers' Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>08/12/2016</em><br />
Release version : <em>4.0.0</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#developers-implementation-guide">Developers' Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a></li>
<li><a href="#adding-a-module-to-your-project">Adding a module to your project</a><ul>
<li><a href="#cocoapods">Cocoapods</a></li>
<li><a href="#framework">Framework</a></li>
</ul>
</li>
<li><a href="#support-and-contacts">Support and contacts</a></li>
</ul>
</div>
<h1 id="introduction">Introduction</h1>
<p>TagCommander for mobile is a collection of small SDKs each designed to serve a dedicated purpose.
The modules are the following :</p>
<p><a href="TCCore/README.md">Core : Used as a base by the other modules.</a></p>
<p><a href="TCSDK/README.md">SDK : Tag management system collecting data throught a server-side aproach.</a></p>
<p><a href="TCSegment/README.md">Segment : Get your user segmentation from our servers.</a></p>
<p>For each of those modules, please check their respective documentation for more information.</p>
<h1 id="adding-a-module-to-your-project">Adding a module to your project</h1>
<p>If you want to add a module to your android project, you have several possibilities.</p>
<div class="codehilite"><pre>- Using cocoapods to manage the dependency.
- Using directly the framework files in your project.
</pre></div>


<p>Whatever the chosen way to add it is, please remember that we have two different versions available.</p>
<div class="codehilite"><pre>- A debug version with the architectures for phones and simulators.
- A release version with only the architectures for phones.
</pre></div>


<h2 id="cocoapods">Cocoapods</h2>
<p>Please note that if you are using cocoapod changes that would have you modify your applications are made, we will create new podspec files for the newest versions.</p>
<div class="warning"></div>

<blockquote>
<p>You will always need to at least add the Core module to your project.</p>
</blockquote>
<p>https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-debug-universal.podspec
https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-release-iphoneos.podspec</p>
<h2 id="framework">Framework</h2>
<p>The latest version of our modules are always available on our github account: https://github.com/TagCommander/pods</p>
<div class="warning"></div>

<blockquote>
<p>You will always need to at least add the Core module to your project.</p>
</blockquote>
<p>Add the modules you need to your project and confirm that XCode really added them for your Target at the following places:
    - In the "general" tab under "Linked Frameworks and Libraries"
    - In the "Build Phases" tab under "Link Binary With Libraries"
    - That the FRAMEWORK_SEARCH_PATHS do include the places where the frameworks are.</p>
<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="res/logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@tagcommander.com</em></p>
<p>http://www.tagcommander.com</p>
<p>TagCommander | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 08/12/2016 17:40:26</p>
</body>
</html>