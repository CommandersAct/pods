Pod::Spec.new do |s|
  s.name         = "TCBeacon"
  s.version      = "4.0.0"
  s.homepage     = "https://github.com/tagcommander/pods/TCBeacon"
#  s.license      = { :type => 'MIT', :file => 'TCBeacon.framework/LICENSE' }
  s.author       = { "TagCommander" => "support@tagcommander.com" }
  s.summary      = "TagCommander pod"
  s.description  = <<-DESC
           Go to https://github.com/TagCommander/pods/TCBeacon for more details
                   DESC
  s.platform     = :ios, '8.0'
  s.source   = { :http => "https://github.com/TagCommander/pods/raw/master/TCBeacon/Debug-universal/4.0.0.zip" }
  s.preserve_paths      = 'TCBeacon.framework'
  s.public_header_files = 'TCBeacon.framework/Headers/*.h'
  s.vendored_frameworks = 'TCBeacon.framework'
#  s.framworks   = 'SystemConfiguration', 'CoreLocation' 
end