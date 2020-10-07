Pod::Spec.new do |s|
  s.name         = "latest-TCSegment-Debug-noIDFA"
  s.version      = "4.3.0"
  s.homepage     = "https://github.com/TagCommander/pods/tree/master/TCSegment"
  s.license      = { :type => 'proprietary', :text => <<-LICENSE
                        Copyright 2013 - present Commanders Act. All rights reserved.
                      LICENSE
                   }
  s.author       = { "Commanders Act" => "support@commandersact.com" }
  s.summary      = "TagCommander pod"
  s.description  = <<-DESC
           Go to https://github.com/TagCommander/pods/tree/master/TCSegment for more details
                   DESC
  s.platform     = :ios, '8.0'
  s.source   = { :http => "https://github.com/TagCommander/pods/raw/master/TCSegment/4/3/0/Debug/TCSegment-noIDFA.zip" }
  s.preserve_paths      = 'TCSegment.xcframework'
  #s.public_header_files = 'TCSegment.framework/Headers/*.h'
  s.vendored_frameworks = 'TCSegment.xcframework'
end