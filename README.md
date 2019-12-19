
<html>
<body>
<p><img alt="alt tag" src="res/ca_logo.png" /></p>
<h1 id="developers-implementation-guide">Developers' Implementation Guide</h1>
<p><strong>iOS</strong></p>
<p>Last update : <em>19/12/2019</em><br />
Release version : <em>4</em></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#developers-implementation-guide">Developers' Implementation Guide</a></li>
<li><a href="#introduction">Introduction</a></li>
<li><a href="#latest-available-versions">Latest available versions</a></li>
<li><a href="#adding-a-module-to-your-project">Adding a module to your project</a></li>
<li><a href="#cocoapods-renaming-warning">Cocoapods renaming warning</a><ul>
<li><a href="#build-variants">Build Variants</a></li>
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
<p><a href="TCSDK/README.md">SDK : Tag management system collecting data through a server-side approach.</a></p>
<p><a href="TCSegment/README.md">Segment : Get your user segmentation from our servers.</a></p>
<p><a href="TCPrivacy/README.md">Privacy : Pass the Privacy settings to our tag system</a></p>
<p>For each of those modules, please check their respective documentation for more information.</p>
<h1 id="latest-available-versions">Latest available versions</h1>
<p>Core : <em>4.6.1</em></p>
<p>SDK : <em>4.5.0</em></p>
<p>Privacy : <em>4.5.1</em></p>
<p>IAB : <em>4.4.0</em></p>
<p>Partners : <em>4.5.0</em></p>
<p>Segment : <em>4.2.0</em></p>
<h1 id="adding-a-module-to-your-project">Adding a module to your project</h1>
<p>If you want to add a module to your android project, you have several possibilities.</p>
<pre><code>- Using cocoapods to manage the dependency.
- Using directly the framework files in your project.
</code></pre>
<h1 id="cocoapods-renaming-warning">Cocoapods renaming warning</h1>
<div class="warning"></div>

<blockquote>
<p>We renamed all our pods to be able to use them depending on your configurations.</p>
</blockquote>
<p>The names of the pod changed to be able to reflect the exact content of the podspec (and thus preventing the name warning). And by having different names we also allow you to use several of them depending on your configurations directly in the podfile.</p>
<p><a href="https://lookback.io/blog/cocoapods-by-configuration">The basic idea is explained here</a></p>
<p>You will then be able to modify your podfiles like this:</p>
<pre><code>#TC libs for debug
pod 'latest-TCCore-Debug-universal', :podspec =&gt; 'https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-TCCore-Debug-universal.podspec', :configuration =&gt; ['Debug Prod', 'Debug Test', 'Debug Stubs']
pod 'latest-TCSDK-Debug-universal', :podspec =&gt; 'https://raw.githubusercontent.com/TagCommander/pods/master/TCSDK/latest-TCSDK-Debug-universal.podspec', :configuration =&gt; ['Debug Prod', 'Debug Test', 'Debug Stubs']
#TC libs for Release
pod 'latest-TCCore-Release-iphoneos', :podspec =&gt; 'https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-TCCore-Release-iphoneos.podspec', :configuration =&gt; ['Release Prod', 'Release Test', 'Store Prod']
pod 'latest-TCSDK-Release-iphoneos', :podspec =&gt; 'https://raw.githubusercontent.com/TagCommander/pods/master/TCSDK/latest-TCSDK-Release-iphoneos.podspec', :configuration =&gt; ['Release Prod', 'Release Test', 'Store Prod']
</code></pre>
<p>You can also point on a specific version (only for the latests builds):</p>
<pre><code>#TC libs for Release
pod 'TCCore-Release-universal', :podspec =&gt; 'https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/4/5/4/TCCore-Release-universal.podspec', :configuration =&gt; ['Release Prod', 'Release Test', 'Store Prod']
pod 'TCSDK-Release-universal', :podspec =&gt; 'https://raw.githubusercontent.com/TagCommander/pods/master/TCSDK/4/4/1/TCSDK-Release-universal.podspec', :configuration =&gt; ['Release Prod', 'Release Test', 'Store Prod']
</code></pre>
<h2 id="build-variants">Build Variants</h2>
<p>Whatever the chosen way to add it is, please remember that we have three different versions available.</p>
<pre><code>- A debug version with the architectures for phones and simulators.
- A release version with the architectures for phones and simulators.
- A release version with only the architectures for phones.
</code></pre>
<p>In addition to those three variants also come a release version with BITCODE enabled. Since BITCODE is only used when submitting your application on the store, only a release version is available with BITCODE.</p>
<p>And also if you don't want to use the IDFA/IDFV in your application (thus don't want to check the case in the application submission form), you can get another variant that is noIDFA. This variant will not compile anything linked with ASIdentifierManager.</p>
<h2 id="cocoapods">Cocoapods</h2>
<p>Please note that if you are using cocoapod and important changes occur in our SDK that would have you modify your applications, we will create new podspec files for the newest versions to prevent any issues in your project.</p>
<div class="warning"></div>

<blockquote>
<p>You will always need to at least add the Core module to your project.</p>
</blockquote>
<p>https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-TCCore-Debug-universal.podspec</p>
<p>https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-TCCore-Release-iphoneos.podspec</p>
<p>https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-TCCore-Release-iphoneos-Bitcode.podspec</p>
<p>Your podfile should look something like this :</p>
<pre><code>use_frameworks!
target 'TCDemo' do
    pod 'latest-TCCore-Debug-universal', podspec: 'https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/latest-TCCore-Debug-universal.podspec'
    pod 'latest-TCSDK-Debug-universal', podspec: 'https://raw.githubusercontent.com/TagCommander/pods/master/TCSDK/latest-TCSDK-Debug-universal.podspec'
end
</code></pre>
<p>You can also point on a specific version (only for the latests builds):</p>
<p>https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/4/5/4/TCCore-Release-universal.podspec
https://raw.githubusercontent.com/TagCommander/pods/master/TCCore/4/5/4/TCCore-Debug-universal.podspec</p>
<p>https://raw.githubusercontent.com/TagCommander/pods/master/TCSDK/4/4/1/TCSDK-Release-universal.podspec</p>
<h2 id="framework">Framework</h2>
<p>The latest version of our modules are always available on our github account: https://github.com/TagCommander/pods</p>
<div class="warning"></div>

<blockquote>
<p>You will always need to at least add the Core module to your project.</p>
</blockquote>
<p>Add the modules you need to your project and confirm that XCode really added them for your Target at the following places:</p>
<pre><code>- In the "general" tab under "Linked Frameworks and Libraries"
- In the "Build Phases" tab under "Link Binary With Libraries"
- That the FRAMEWORK_SEARCH_PATHS do include the places where the frameworks are.
</code></pre>
<h1 id="support-and-contacts">Support and contacts</h1>
<p><img alt="alt tag" src="../res/ca_logo.png" /></p>
<hr />
<p><strong>Support</strong>
<em>support@commandersact.com</em></p>
<p>http://www.commandersact.com</p>
<p>Commanders Act | 3/5 rue Saint Georges - 75009 PARIS - France</p>
<hr />
<p>This documentation was generated on 19/12/2019 15:31:24</p>
</body>
</html>