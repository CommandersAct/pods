Pod::Spec.new do |s|
  s.name         = "TCSegment"
  s.version      = "4.1.0"
  s.homepage     = "https://github.com/tagcommander/pods/TCSegment"
#  s.license      = { :type => 'MIT', :file => 'TCSegment.framework/LICENSE' }
  s.author       = { "TagCommander" => "support@tagcommander.com" }
  s.summary      = "TagCommander pod"
  s.description  = <<-DESC
           Go to https://github.com/TagCommander/pods/TCSegment for more details
                   DESC
  s.platform     = :ios, '8.0'
  s.source   = { :http => "https://github.com/TagCommander/pods/raw/master/TCSegment/Release-iphoneos/4.1.0.zip" }
  s.preserve_paths      = 'TCSegment.framework'
  s.public_header_files = 'TCSegment.framework/Headers/*.h'
  s.vendored_frameworks = 'TCSegment.framework'
#  s.framworks   = 'SystemConfiguration', 'CoreLocation' 
end