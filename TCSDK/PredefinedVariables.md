
<html>
<body>
<p><img alt="alt tag" src="../res/logo.png" /></p>
<h1 id="predefined-variables-guide">Predefined variables Guide</h1>
<p><strong>SDK TagCommander Android and iPhone</strong></p>
<p>Last update : <em>31/05/2022</em><br /></p>
<p><div id="end_first_page" /></p>

<div class="toc">
<ul>
<li><a href="#predefined-variables-guide">Predefined variables Guide</a></li>
<li><a href="#predefined-variables">Predefined variables</a><ul>
<li><a href="#tc_ip-ip">#TC_IP# (#IP#)</a></li>
<li><a href="#tc_empty-empty">#TC_EMPTY# (#EMPTY#)</a></li>
<li><a href="#tc_rand-rand">#TC_RAND# (#RAND#)</a></li>
<li><a href="#tc_language-tc_local_language">#TC_LANGUAGE# (#TC_LOCAL_LANGUAGE#)</a></li>
<li><a href="#tc_language_cs-tc_local_language_cs">#TC_LANGUAGE_CS# (#TC_LOCAL_LANGUAGE_CS#)</a></li>
<li><a href="#tc_language_ga-tc_local_language_ga">#TC_LANGUAGE_GA# (#TC_LOCAL_LANGUAGE_GA#)</a></li>
<li><a href="#tc_sysname-tc_local_sysname">#TC_SYSNAME# (#TC_LOCAL_SYSNAME#)</a></li>
<li><a href="#tc_sysversion-tc_local_sysversion">#TC_SYSVERSION# (#TC_LOCAL_SYSVERSION#)</a></li>
<li><a href="#tc_model-tc_local_model">#TC_MODEL# (#TC_LOCAL_MODEL#)</a></li>
<li><a href="#tc_model_and_version-tc_local_model_and_version">#TC_MODEL_AND_VERSION# (#TC_LOCAL_MODEL_AND_VERSION#)</a></li>
<li><a href="#tc_connexion-tc_local_connexion">#TC_CONNEXION# (#TC_LOCAL_CONNEXION#)</a></li>
<li><a href="#tc_device">#TC_DEVICE</a></li>
<li><a href="#tc_screen-tc_local_screen">#TC_SCREEN# (#TC_LOCAL_SCREEN#)</a></li>
<li><a href="#tc_charset-tc_local_charset">#TC_CHARSET# (#TC_LOCAL_CHARSET#)</a></li>
<li><a href="#tc_currency_code">#TC_CURRENCY_CODE</a></li>
<li><a href="#tc_currency_symbol">#TC_CURRENCY_SYMBOL</a></li>
<li><a href="#tc_application_version-tc_local_appversion">#TC_APPLICATION_VERSION# (#TC_LOCAL_APPVERSION#)</a></li>
<li><a href="#tc_application_previous_version">#TC_APPLICATION_PREVIOUS_VERSION</a></li>
<li><a href="#tc_application_build">#TC_APPLICATION_BUILD</a></li>
<li><a href="#tc_tagcommander_version">#TC_TAGCOMMANDER_VERSION</a></li>
<li><a href="#tc_manufacturer">#TC_MANUFACTURER</a></li>
<li><a href="#tc_user_agent">#TC_USER_AGENT</a></li>
<li><a href="#tc_jailbroken">#TC_JAILBROKEN</a></li>
<li><a href="#tc_application_starts">#TC_APPLICATION_STARTS</a></li>
<li><a href="#tc_foregrounds">#TC_FOREGROUNDS</a></li>
<li><a href="#tc_foreground_time">#TC_FOREGROUND_TIME</a></li>
<li><a href="#tc_delta_foreground_time">#TC_DELTA_FOREGROUND_TIME</a></li>
<li><a href="#tc_background_time">#TC_BACKGROUND_TIME</a></li>
<li><a href="#tc_delta_background_time">#TC_DELTA_BACKGROUND_TIME</a></li>
<li><a href="#tc_background_ux_time">#TC_BACKGROUND_UX_TIME</a></li>
<li><a href="#tc_delta_background_ux_time">#TC_DELTA_BACKGROUND_UX_TIME</a></li>
<li><a href="#tc_current_call-tc_nav_timestamp_current_call">#TC_CURRENT_CALL# (#TC_NAV_TIMESTAMP_CURRENT_CALL#)</a></li>
<li><a href="#tc_current_call_ms-tc_nav_timestamp_current_call_ms">#TC_CURRENT_CALL_MS# (#TC_NAV_TIMESTAMP_CURRENT_CALL_MS#)</a></li>
<li><a href="#tc_last_call-tc_nav_timestamp_last_call">#TC_LAST_CALL# (#TC_NAV_TIMESTAMP_LAST_CALL#)</a></li>
<li><a href="#tc_last_call_ms-tc_nav_timestamp_last_call_ms">#TC_LAST_CALL_MS# (#TC_NAV_TIMESTAMP_LAST_CALL_MS#)</a></li>
<li><a href="#tc_last_session_last_hit">#TC_LAST_SESSION_LAST_HIT</a></li>
<li><a href="#tc_last_session_last_hit_ms">#TC_LAST_SESSION_LAST_HIT_MS</a></li>
<li><a href="#tc_now">#TC_NOW</a></li>
<li><a href="#tc_now_ms">#TC_NOW_MS</a></li>
<li><a href="#tc_uniqueid-tc_local_uniqueid-tc_nav_visitor_id">#TC_UNIQUEID# (#TC_LOCAL_UNIQUEID#, #TC_NAV_VISITOR_ID#)</a></li>
<li><a href="#tc_idfa-android-removed-from-460">#TC_IDFA# (Android : Removed from 4.6.0+)</a></li>
<li><a href="#tc_idfv">#TC_IDFV</a></li>
<li><a href="#tc_is_tracking_enabled-android-removed-from-460">#TC_IS_TRACKING_ENABLED# (Android : Removed from 4.6.0+)</a></li>
<li><a href="#tc_limit_user_tracking_enabled-android-removed-from-460">#TC_LIMIT_USER_TRACKING_ENABLED# (Android : Removed from 4.6.0+)</a></li>
<li><a href="#tc_longitude-ios-before-sdk-441">#TC_LONGITUDE# (iOS: Before SDK 4.4.1)</a></li>
<li><a href="#tc_latitude-ios-before-sdk-441">#TC_LATITUDE# (iOS: Before SDK 4.4.1)</a></li>
<li><a href="#tc_bundle_identifier">#TC_BUNDLE_IDENTIFIER</a></li>
<li><a href="#tc_application_name">#TC_APPLICATION_NAME</a></li>
<li><a href="#tc_runtime_name">#TC_RUNTIME_NAME</a></li>
<li><a href="#tc_first_visit-tc_nav_timestamp_first_visit">#TC_FIRST_VISIT# (#TC_NAV_TIMESTAMP_FIRST_VISIT#)</a></li>
<li><a href="#tc_first_visit_ms-tc_nav_timestamp_first_visit_ms">#TC_FIRST_VISIT_MS# (#TC_NAV_TIMESTAMP_FIRST_VISIT_MS#)</a></li>
<li><a href="#tc_last_visit-tc_nav_timestamp_last_visit">#TC_LAST_VISIT# (#TC_NAV_TIMESTAMP_LAST_VISIT#)</a></li>
<li><a href="#tc_last_visit_ms-tc_nav_timestamp_last_visit_ms">#TC_LAST_VISIT_MS# (#TC_NAV_TIMESTAMP_LAST_VISIT_MS#)</a></li>
<li><a href="#tc_current_session-tc_timestamp_current_visit">#TC_CURRENT_SESSION# (#TC_TIMESTAMP_CURRENT_VISIT#)</a></li>
<li><a href="#tc_current_session_ms-tc_timestamp_current_visit_ms">#TC_CURRENT_SESSION_MS# (#TC_TIMESTAMP_CURRENT_VISIT_MS#)</a></li>
<li><a href="#tc_current_visit-tc_nav_timestamp_current_visit">#TC_CURRENT_VISIT# (#TC_NAV_TIMESTAMP_CURRENT_VISIT#)</a></li>
<li><a href="#tc_current_visit_ms-tc_nav_timestamp_current_visit_ms">#TC_CURRENT_VISIT_MS# (#TC_NAV_TIMESTAMP_CURRENT_VISIT_MS#)</a></li>
<li><a href="#tc_session_duration">#TC_SESSION_DURATION</a></li>
<li><a href="#tc_session_duration_ms">#TC_SESSION_DURATION_MS</a></li>
<li><a href="#tc_version_first_visit_ms-tc_nav_timestamp_version_first_visit_ms">#TC_VERSION_FIRST_VISIT_MS# (#TC_NAV_TIMESTAMP_VERSION_FIRST_VISIT_MS#)</a></li>
<li><a href="#tc_number_visit-tc_nav_number_visits">#TC_NUMBER_VISIT# (#TC_NAV_NUMBER_VISITS#)</a></li>
<li><a href="#tc_number_session">#TC_NUMBER_SESSION</a></li>
<li><a href="#tc_empty_variable_remove_equal">#TC_EMPTY_VARIABLE_REMOVE_EQUAL</a></li>
<li><a href="#tc_is_first_visit">#TC_IS_FIRST_VISIT</a></li>
<li><a href="#tc_first_execute">#TC_FIRST_EXECUTE</a></li>
<li><a href="#tc_install_referrer-40">#TC_INSTALL_REFERRER# 4.0+</a></li>
<li><a href="#tc_sdk_id-core-413">#TC_SDK_ID# Core 4.1.3+</a></li>
<li><a href="#tc_normalized_id-core-413-android-removed-from-460">#TC_NORMALIZED_ID# Core 4.1.3+ (Android : Removed from 4.6.0+)</a></li>
</ul>
</li>
</ul>
</div>
<h1 id="predefined-variables">Predefined variables</h1>
<p>The following document is the complete, up-to-date, list of all predefined variables that Tag Commander's SDK automatically generates.</p>
<p>For each of them we give you a small description of the variable and an example on at least one Android device and one iOS device. We might show more example if needed.</p>
<p>The name in parentheses present the old names. They can still be used in v3 configurations, but are deprecated and such should not be. Starting v4, they have been completely removed.</p>
<h2 id="tc_ip-ip">#TC_IP# (#IP#)</h2>
<p>/!\ Require user consent.</p>
<p>The ip address of the device. Only available if the device is connected to internet.</p>
<ul>
<li>Galaxy Tab 3: 10.144.112.50</li>
<li>iPhone 4s: 10.144.112.88</li>
</ul>
<h2 id="tc_empty-empty">#TC_EMPTY# (#EMPTY#)</h2>
<p>An empty predefined variable if needed. Please note that any variable defined in your configuration will be empty if no value is given during implementation.</p>
<ul>
<li>Nexus 7:</li>
<li>iPhone 5:</li>
</ul>
<h2 id="tc_rand-rand">#TC_RAND# (#RAND#)</h2>
<p>A random number that can be used for various purposes.</p>
<ul>
<li>OnePlus One: 1999907613</li>
<li>iPhone 5: 861518817</li>
</ul>
<h2 id="tc_language-tc_local_language">#TC_LANGUAGE# (#TC_LOCAL_LANGUAGE#)</h2>
<p>The localised language of the device.</p>
<ul>
<li>Nexus 7: fr_CA</li>
<li>iPhone 4s: fr_FR</li>
</ul>
<h2 id="tc_language_cs-tc_local_language_cs">#TC_LANGUAGE_CS# (#TC_LOCAL_LANGUAGE_CS#)</h2>
<p>The localised language of the device formatted especially for ComScore.</p>
<ul>
<li>Nexus 7: fr</li>
<li>iPhone 4s: fr</li>
</ul>
<h2 id="tc_language_ga-tc_local_language_ga">#TC_LANGUAGE_GA# (#TC_LOCAL_LANGUAGE_GA#)</h2>
<p>The localised language of the device formatted especially for Google Analytics.</p>
<ul>
<li>Nexus 7: fr-CA</li>
<li>iPhone 4s: fr-FR</li>
</ul>
<h2 id="tc_sysname-tc_local_sysname">#TC_SYSNAME# (#TC_LOCAL_SYSNAME#)</h2>
<p>The full system name of the device.</p>
<ul>
<li>Galaxy Tab 3: android-4.2.2</li>
<li>iPhone 4s: iPhone OS</li>
</ul>
<h2 id="tc_sysversion-tc_local_sysversion">#TC_SYSVERSION# (#TC_LOCAL_SYSVERSION#)</h2>
<p>Only the system version of the device.</p>
<ul>
<li>Galaxy Tab 3: 4.2.2</li>
<li>iPhone 4s: 8.4.1</li>
</ul>
<h2 id="tc_model-tc_local_model">#TC_MODEL# (#TC_LOCAL_MODEL#)</h2>
<p>The name of the device's model.</p>
<ul>
<li>Nexus 7: Nexus 7</li>
<li>OnePlus One: A0001</li>
<li>Galaxy S3: GT-I9305</li>
<li>iPhone 4s: iPhone</li>
</ul>
<h2 id="tc_model_and_version-tc_local_model_and_version">#TC_MODEL_AND_VERSION# (#TC_LOCAL_MODEL_AND_VERSION#)</h2>
<p>This returns the model and the version of the phone depending on the device code. It only exists in iOS.</p>
<ul>
<li>iPhone 5s: iPhone 5S</li>
</ul>
<h2 id="tc_connexion-tc_local_connexion">#TC_CONNEXION# (#TC_LOCAL_CONNEXION#)</h2>
<p>The way the device is connected to the internet.</p>
<ul>
<li>Galaxy Tab 3: MOBILE</li>
<li>iPhone 5: WIFI</li>
</ul>
<h2 id="tc_device">#TC_DEVICE</h2>
<p>/!\ Require user consent.</p>
<p>The name of the device as given by its owner.</p>
<ul>
<li>Galaxy Tab 3: lt01wifi</li>
<li>Nexus 7: flo</li>
<li>iPhone 4s: iPhone4,1</li>
</ul>
<h2 id="tc_screen-tc_local_screen">#TC_SCREEN# (#TC_LOCAL_SCREEN#)</h2>
<p>The screen resolution of the device.</p>
<ul>
<li>Galaxy Tab 3: 1920x1104</li>
<li>iPhone 4s: 320x480</li>
</ul>
<h2 id="tc_charset-tc_local_charset">#TC_CHARSET# (#TC_LOCAL_CHARSET#)</h2>
<p>The character encoding used by default on the device.</p>
<ul>
<li>OnePlus One: UTF-8</li>
<li>iPhone 5: MacRoman</li>
</ul>
<h2 id="tc_currency_code">#TC_CURRENCY_CODE</h2>
<p>The code of the currency used by default on the user device.</p>
<ul>
<li>OnePlus One: EUR</li>
<li>iPhone 4s: CAD</li>
</ul>
<h2 id="tc_currency_symbol">#TC_CURRENCY_SYMBOL</h2>
<p>The encoded symbol of the currency used by default on the user device.</p>
<ul>
<li>OnePlus One: &euro;</li>
<li>iPhone 4s: &dollar;</li>
</ul>
<h2 id="tc_application_version-tc_local_appversion">#TC_APPLICATION_VERSION# (#TC_LOCAL_APPVERSION#)</h2>
<p>The version of the application which is running the SDK.</p>
<ul>
<li>Nexus 7: 42.2.12</li>
<li>iPhone 5: 2.4</li>
</ul>
<h2 id="tc_application_previous_version">#TC_APPLICATION_PREVIOUS_VERSION</h2>
<p>The previous version number of the application if available. Empty otherwise.</p>
<ul>
<li>Nexus 7: 42.2.10</li>
<li>iPhone 5: 2.1</li>
</ul>
<h2 id="tc_application_build">#TC_APPLICATION_BUILD</h2>
<p>The application build number.</p>
<ul>
<li>Nexus 7: 1536</li>
<li>iPhone 5: 2.3</li>
</ul>
<h2 id="tc_tagcommander_version">#TC_TAGCOMMANDER_VERSION</h2>
<p>The version of Tag Commander's SDK. It's formatted as follow: "version.release-date".</p>
<ul>
<li>OnePlus One: 3.1.2015-10-16</li>
<li>iPhone 4s: 3.1.2015-10-16</li>
</ul>
<h2 id="tc_manufacturer">#TC_MANUFACTURER</h2>
<p>The name of the device's manufacturer.</p>
<ul>
<li>Galaxy Tab 3: samsung</li>
<li>OnePlus One: OnePlus</li>
<li>iPhone 4s: Apple</li>
</ul>
<h2 id="tc_user_agent">#TC_USER_AGENT</h2>
<p>/!\ Require user consent.</p>
<p>The user agent of the device's web browser.</p>
<ul>
<li>OnePlus One: Mozilla/5.0 (Linux; Android 4.4.4; A0001 Build/KTU84Q) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/33.0.0.0 Mobile Safari/537.36</li>
<li>Galaxy Tab 3: Mozilla/5.0 (Linux; U; Android 4.2.2; fr-fr; SM-T310 Build/JDQ39) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0 Safari/534.30</li>
<li>iPhone 5: Mozilla/5.0 (iPhone; CPU iPhone OS 8_4_1 like Mac OS X) AppleWebKit/600.1.4 (KHTML, like Gecko) Mobile/12H321</li>
</ul>
<h2 id="tc_jailbroken">#TC_JAILBROKEN</h2>
<p>Return if the device seems Jailbroken or rooted. There exist many algorythm to detect it, and the methods used to root or jailbreak a phone change over time. This variable is thus not 100% accurate.
Also please note that simulators tends to return that they are jailbroken or rooted.</p>
<ul>
<li>Galaxy S3: 0</li>
<li>iPhone 4s: 0</li>
<li>simulator iPhone 6s: 1</li>
</ul>
<h2 id="tc_application_starts">#TC_APPLICATION_STARTS</h2>
<p>The number of cold launch of the application. A cold start is when the application is launched while it wasn't previously in memory.</p>
<ul>
<li>Galaxy S3: 19</li>
<li>iPhone 4s: 1</li>
</ul>
<h2 id="tc_foregrounds">#TC_FOREGROUNDS</h2>
<p>Indicates how many times the application switch to foreground. An application is in foreground when the user is using it.
Should be at least one, since during launch the application is considered as going into foreground.</p>
<ul>
<li>Nexus 7: 1</li>
<li>iPhone 6: 5</li>
</ul>
<h2 id="tc_foreground_time">#TC_FOREGROUND_TIME</h2>
<p>The duration spent in the application while in foreground. This time is indicated in milliseconds.</p>
<ul>
<li>Galaxy Tab3: 40375</li>
<li>iPhone 5: 125262</li>
</ul>
<h2 id="tc_delta_foreground_time">#TC_DELTA_FOREGROUND_TIME</h2>
<p>The delta between now and the last time a foreground time measurement was sent by Tag Commander. This is also indicated in milliseconds.</p>
<ul>
<li>Galaxy Tab3: 4013</li>
<li>iPhone 5: 1618</li>
</ul>
<h2 id="tc_background_time">#TC_BACKGROUND_TIME</h2>
<p>The duration spent in background. This time is given in milliseconds.</p>
<ul>
<li>Galaxy S3: 13698</li>
<li>iPhone 6: 54691</li>
</ul>
<h2 id="tc_delta_background_time">#TC_DELTA_BACKGROUND_TIME</h2>
<p>The delta between now and the last time a background time measurement was sent by Tag Commander. It is also in milliseconds.</p>
<ul>
<li>Galaxy S3: 733</li>
<li>iPhone 6: 9257</li>
</ul>
<h2 id="tc_background_ux_time">#TC_BACKGROUND_UX_TIME</h2>
<p>The duration the application spent in background while presenting an interactive content to the user. It is presented in milliseconds.</p>
<ul>
<li>Nexus 7: 12001</li>
<li>iPhone 4s: 15354</li>
</ul>
<h2 id="tc_delta_background_ux_time">#TC_DELTA_BACKGROUND_UX_TIME</h2>
<p>The delta between now and the last time an UX background time measurement was sent by Tag Commander. Still in milliseconds.</p>
<ul>
<li>Nexus 7: 1211</li>
<li>iPhone 4s: 871</li>
</ul>
<h2 id="tc_current_call-tc_nav_timestamp_current_call">#TC_CURRENT_CALL# (#TC_NAV_TIMESTAMP_CURRENT_CALL#)</h2>
<p>The timestamp of the hit. It is classic unix timestamp, which is seconds since 1970. It is measured the moment the hit is created, if the device is offline, when the hit is sent, this timestamp will still represent the time the hit was created.</p>
<ul>
<li>Nexus 7: 1444987160</li>
<li>iPhone 4s: 1444987175</li>
</ul>
<h2 id="tc_current_call_ms-tc_nav_timestamp_current_call_ms">#TC_CURRENT_CALL_MS# (#TC_NAV_TIMESTAMP_CURRENT_CALL_MS#)</h2>
<p>Same as the previous one, but in milliseconds.</p>
<ul>
<li>Nexus 7: 1444987160642</li>
<li>iPhone 4s: 1444987175973</li>
</ul>
<h2 id="tc_last_call-tc_nav_timestamp_last_call">#TC_LAST_CALL# (#TC_NAV_TIMESTAMP_LAST_CALL#)</h2>
<p>The time when the previous call was made. Here also it is the time when the hit was recorded which is not necessarily the time when he was sent. This is represented as seconds since 1970.</p>
<ul>
<li>Nexus 7: 1444987141</li>
<li>iPhone 4s: 1444987138</li>
</ul>
<h2 id="tc_last_call_ms-tc_nav_timestamp_last_call_ms">#TC_LAST_CALL_MS# (#TC_NAV_TIMESTAMP_LAST_CALL_MS#)</h2>
<p>Same as the previous one, but in milliseconds.</p>
<ul>
<li>Nexus 7: 1444987141577</li>
<li>iPhone 4s: 1444987138626</li>
</ul>
<h2 id="tc_last_session_last_hit">#TC_LAST_SESSION_LAST_HIT</h2>
<p>This time represents the timestamp of the last hit recorded during the previous session. A changed of session is either defined by a long time spent in background (currently 30 minutes) or by a new cold start.</p>
<ul>
<li>Nexus 7: 1444987089</li>
<li>iPhone 4s: 1444987073</li>
</ul>
<h2 id="tc_last_session_last_hit_ms">#TC_LAST_SESSION_LAST_HIT_MS</h2>
<p>Same as the previous one, but in milliseconds.</p>
<ul>
<li>Nexus 7: 1444987089372</li>
<li>iPhone 4s: 1444987073163</li>
</ul>
<h2 id="tc_now">#TC_NOW</h2>
<p>The unix formatted timestamp (seconds since 1970) from when you ask it.</p>
<ul>
<li>Nexus 7: 1444987160</li>
<li>iPhone 4s: 1444987175</li>
</ul>
<h2 id="tc_now_ms">#TC_NOW_MS</h2>
<p>Same as the previous one, but in milliseconds.</p>
<ul>
<li>Nexus 7: 1444987160642</li>
<li>iPhone 4s: 1444987175973</li>
</ul>
<h2 id="tc_uniqueid-tc_local_uniqueid-tc_nav_visitor_id">#TC_UNIQUEID# (#TC_LOCAL_UNIQUEID#, #TC_NAV_VISITOR_ID#)</h2>
<p>Android: A 64-bit number (as a hex string) that is randomly generated when the user first sets up the device and should remain constant for the lifetime of the user's device. The value may change if a factory reset is performed on the device.</p>
<p>iOS: A unique UUID generated during the first install on the phone. This will change if the application is uninstalled then re-installed. This won't change if the user resets his IDFA.</p>
<ul>
<li>OnePlus One: a284d098fdf1c342</li>
<li>iPhone 4s: 80EF0DC8-AD1B-460A-AC2D-4646FA2356E3</li>
</ul>
<h2 id="tc_idfa-android-removed-from-460">#TC_IDFA# (Android : Removed from 4.6.0+)</h2>
<p>/!\ Require user consent.</p>
<p>The advertising identifier as specified by either Google or Apple.</p>
<ul>
<li>Nexus 7: a4ca013b-218b-4a9b-818e-8d1a751b39bf</li>
<li>iPhone 5: 3385ACC1-D465-2D13-A4E3-9A5A865A232C</li>
</ul>
<p>Can be resetted by the user in the phone's system. If it is, the value will be:
- 00000000-0000-0000-0000-000000000000</p>
<h2 id="tc_idfv">#TC_IDFV</h2>
<p>/!\ Require user consent.</p>
<p>The advertising ID for the vendor (unique by vendor). Only available on iOS and formatted as an UDID.</p>
<ul>
<li>iPhone 4s: 6480CCA0-AEFC-2100-B5C6-ABCF01AA3721</li>
</ul>
<h2 id="tc_is_tracking_enabled-android-removed-from-460">#TC_IS_TRACKING_ENABLED# (Android : Removed from 4.6.0+)</h2>
<p>Is tracking enabled on the device. This can be turned off by the user manually in the device's settings.</p>
<ul>
<li>Galaxy S3: false</li>
<li>iPhone 5: NO</li>
</ul>
<h2 id="tc_limit_user_tracking_enabled-android-removed-from-460">#TC_LIMIT_USER_TRACKING_ENABLED# (Android : Removed from 4.6.0+)</h2>
<p>Is the user limiting the tracking on his device. This is effectively this inverse of #TC_IS_TRACKING_ENABLED#.</p>
<ul>
<li>Galaxy S3: true</li>
<li>iPhone 5: YES</li>
</ul>
<h2 id="tc_longitude-ios-before-sdk-441">#TC_LONGITUDE# (iOS: Before SDK 4.4.1)</h2>
<p>/!\ Require user consent.</p>
<p>The longitudinal position of the user using the device. It won't be available if the user turned off all means of localisation.</p>
<p>This Variable requires you to ask permission to use location to your users.</p>
<ul>
<li>Galaxy Tab3: 2.3263269</li>
<li>iPhone 4s: 2.2311654</li>
</ul>
<h2 id="tc_latitude-ios-before-sdk-441">#TC_LATITUDE# (iOS: Before SDK 4.4.1)</h2>
<p>/!\ Require user consent.</p>
<p>The latitudinal position of the user using the device. It won't be available if the user turned off all means of localisation.</p>
<p>This Variable requires you to ask permission to use location to your users.</p>
<ul>
<li>Galaxy Tab3: 48.8708206</li>
<li>iPhone 4s: 48.8765126</li>
</ul>
<h2 id="tc_bundle_identifier">#TC_BUNDLE_IDENTIFIER</h2>
<p>The bundle identifier of the application running Tag Commander.</p>
<ul>
<li>OnePlus One: com.tagcommander.tcdemo.tcdemo</li>
<li>iPhone 4s: com.tagcommander.test.TCDemo</li>
</ul>
<h2 id="tc_application_name">#TC_APPLICATION_NAME</h2>
<p>The name of the application running Tag Commander.</p>
<ul>
<li>OnePlus One: TCDemo</li>
<li>iPhone 4s: TCDemo</li>
</ul>
<h2 id="tc_runtime_name">#TC_RUNTIME_NAME</h2>
<p>The name of the runtime of the device.</p>
<ul>
<li>Galaxy Tab3: android</li>
<li>iPhone 5: ios</li>
</ul>
<h2 id="tc_first_visit-tc_nav_timestamp_first_visit">#TC_FIRST_VISIT# (#TC_NAV_TIMESTAMP_FIRST_VISIT#)</h2>
<p>The timestamp of the first launch of the application in seconds.</p>
<ul>
<li>Nexus 7: 1426775262</li>
<li>iPhone 4s: 1426775262</li>
</ul>
<h2 id="tc_first_visit_ms-tc_nav_timestamp_first_visit_ms">#TC_FIRST_VISIT_MS# (#TC_NAV_TIMESTAMP_FIRST_VISIT_MS#)</h2>
<p>The timestamp of the first launch of the application in milli-seconds.</p>
<ul>
<li>Nexus 7: 1426775262470</li>
<li>iPhone 4s: 1426775262470</li>
</ul>
<h2 id="tc_last_visit-tc_nav_timestamp_last_visit">#TC_LAST_VISIT# (#TC_NAV_TIMESTAMP_LAST_VISIT#)</h2>
<p>The timestamp of the start of the last visit of the application in seconds. It's equal to the first visit during the fist launch.</p>
<ul>
<li>Nexus 7: 1427449277</li>
<li>iPhone 4s: 1427449277</li>
</ul>
<h2 id="tc_last_visit_ms-tc_nav_timestamp_last_visit_ms">#TC_LAST_VISIT_MS# (#TC_NAV_TIMESTAMP_LAST_VISIT_MS#)</h2>
<p>The timestamp of the start of the last visit of the application in milli-seconds. It's equal to the first visit during the fist launch.</p>
<ul>
<li>Nexus 7: 1427449277881</li>
<li>iPhone 4s: 1427449277881</li>
</ul>
<h2 id="tc_current_session-tc_timestamp_current_visit">#TC_CURRENT_SESSION# (#TC_TIMESTAMP_CURRENT_VISIT#)</h2>
<p>The timestamp of current session in seconds. It's equal to the first visit during the fist launch.</p>
<ul>
<li>Nexus 7: 1427449428</li>
<li>iPhone 4s: 1427449428</li>
</ul>
<h2 id="tc_current_session_ms-tc_timestamp_current_visit_ms">#TC_CURRENT_SESSION_MS# (#TC_TIMESTAMP_CURRENT_VISIT_MS#)</h2>
<p>The timestamp of current session in milli-seconds. It's equal to the first visit during the fist launch.</p>
<ul>
<li>Nexus 7: 1427449428069</li>
<li>iPhone 4s: 1427449428069</li>
</ul>
<h2 id="tc_current_visit-tc_nav_timestamp_current_visit">#TC_CURRENT_VISIT# (#TC_NAV_TIMESTAMP_CURRENT_VISIT#)</h2>
<p>The timestamp of current visit in seconds. It's equal to the first visit during the fist launch.</p>
<ul>
<li>Nexus 7: 1427449428</li>
<li>iPhone 4s: 1427449428</li>
</ul>
<h2 id="tc_current_visit_ms-tc_nav_timestamp_current_visit_ms">#TC_CURRENT_VISIT_MS# (#TC_NAV_TIMESTAMP_CURRENT_VISIT_MS#)</h2>
<p>The timestamp of current visit in milli-seconds. It's equal to the first visit during the fist launch.</p>
<ul>
<li>Nexus 7: 1427449428069</li>
<li>iPhone 4s: 1427449428069</li>
</ul>
<h2 id="tc_session_duration">#TC_SESSION_DURATION</h2>
<p>The duration of current session in seconds. A session is defined as either a new launch or as a foreground after having spent more than 30 minutes in background.</p>
<ul>
<li>Galaxy S3: 40</li>
<li>iPhone 5: 31</li>
</ul>
<h2 id="tc_session_duration_ms">#TC_SESSION_DURATION_MS</h2>
<p>The duration of current session in milli-seconds. A session is defined as either a new launch or as a foreground after having spent more than 30 minutes in background.</p>
<ul>
<li>Galaxy S3: 40613</li>
<li>iPhone 4s: 31664</li>
</ul>
<h2 id="tc_version_first_visit_ms-tc_nav_timestamp_version_first_visit_ms">#TC_VERSION_FIRST_VISIT_MS# (#TC_NAV_TIMESTAMP_VERSION_FIRST_VISIT_MS#)</h2>
<p>The first timestamp (in milli-seconds) of the first session run with the current version of the application. This changes everytime the application gets updated.</p>
<ul>
<li>Galaxy S3: 1427376462695</li>
<li>iPhone 4s: 1427376462695</li>
</ul>
<h2 id="tc_number_visit-tc_nav_number_visits">#TC_NUMBER_VISIT# (#TC_NAV_NUMBER_VISITS#)</h2>
<p>The number of times the user visited the application.</p>
<ul>
<li>OnePlus One: 16</li>
<li>iPhone 4s: 2</li>
</ul>
<h2 id="tc_number_session">#TC_NUMBER_SESSION</h2>
<p>The number of times a session got created for this application.</p>
<ul>
<li>OnePlus One: 21</li>
<li>iPhone 4s: 2</li>
</ul>
<h2 id="tc_empty_variable_remove_equal">#TC_EMPTY_VARIABLE_REMOVE_EQUAL</h2>
<p>This variable only exist in v3 and before of Tag Commander's SDK.</p>
<p>A special predefined variable which removes the '=' sign in the query string if the variable is not defined. It was created to answer a special case for google analytics.</p>
<h2 id="tc_is_first_visit">#TC_IS_FIRST_VISIT</h2>
<p>This is a very simple variable that is TRUE during the whole duration of the fist launch of the application, and FALSE the next times the app will be launched.</p>
<ul>
<li>Galaxy S7: TRUE</li>
<li>iPhone 6s: FALSE</li>
</ul>
<h2 id="tc_first_execute">#TC_FIRST_EXECUTE</h2>
<p>The first time you ask the SDK to either execute() or SendData() each hard launch, this variable is TRUE and it's FALSE otherwise.</p>
<p>It can be combined TC_IS_FIRST_VISIT, to have the very first hit of the first launch of the application.</p>
<ul>
<li>OnePlus One: FALSE</li>
<li>iPhone 4s: TRUE</li>
</ul>
<h2 id="tc_install_referrer-40">#TC_INSTALL_REFERRER# 4.0+</h2>
<p><em>Android Only</em></p>
<p>Two way to get the install referrer exists. The first is to use this variable, it will give you the whole referrer string as given by Google.
The second one is when you know exactly what to expect, all part of the referrer URL will be transformed as variables.</p>
<p>Android:
#TC_INSTALL_REFERRER# = utm_source=google&amp;utm_medium=cpc&amp;utm_term=running%252Bshoes&amp;utm_content=displayAd1&amp;utm_campaign=shoesshoesshoes</p>
<p>#utm_source# = google</p>
<p>#utm_medium# = cpc</p>
<p>#utm_term# = running%252Bshoes</p>
<p>#utm_content# = displayAd1</p>
<p>#utm_campaign# = shoesshoesshoes</p>
<h2 id="tc_sdk_id-core-413">#TC_SDK_ID# Core 4.1.3+</h2>
<p>An ID formatted as an UUID created by the SDK to be unique. It can't be resetted by the user, but if the user remove the application and install it again later, it will have a different ID.</p>
<ul>
<li>OnePlus One: 65343D4C-BE71-47BC-B60A-4A46E49ED87E</li>
<li>iPhone 6: 80EF0DC8-AD1B-460A-AC2D-4646FA2356E3</li>
</ul>
<h2 id="tc_normalized_id-core-413-android-removed-from-460">#TC_NORMALIZED_ID# Core 4.1.3+ (Android : Removed from 4.6.0+)</h2>
<p>/!\ Require user consent.</p>
<p>An special ID mixing IDFA/AAID and TC_SDK_ID. Some user disable the IDFA/AAID, but those IDs are still the most reliable to recognize a user, to remove the need of manually checking the IDs we created a mix.</p>
<p>TC_NORMALIZED_ID will be equal to the IDFA/AAID if the user has one, but if not, instead of having an empty IDFA, you will have the TC_SDK_ID.
Coupled together you can also gain insight on the reliability of those ID when trying to identify users in the long run. Since if this ID is equal to the IDFA, you can match this ID with IDFA from other users coming from different sources.</p>
<ul>
<li>OnePlus One: 65343D4C-BE71-47BC-B60A-4A46E49ED87E</li>
<li>iPhone 6: 3E115C1E-CFC9-4A31-A7AE-D5FD45C9541C</li>
</ul>
</body>
</html>