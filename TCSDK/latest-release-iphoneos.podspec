Pod::Spec.new do |s|
  s.name         = "TCSDK"
  s.version      = "4.1.0"
  s.homepage     = "https://github.com/tagcommander/pods/TCSDK"
#  s.license      = { :type => 'MIT', :file => 'TCSDK.framework/LICENSE' }
  s.author       = { "TagCommander" => "support@tagcommander.com" }
  s.summary      = "TagCommander pod"
  s.description  = <<-DESC
           Go to https://github.com/TagCommander/pods/TCSDK for more details
                   DESC
  s.platform     = :ios, '8.0'
  s.source   = { :http => "https://github.com/TagCommander/pods/raw/master/TCSDK/Release-iphoneos/4.1.0.zip" }
  s.preserve_paths      = 'TCSDK.framework'
  s.public_header_files = 'TCSDK.framework/Headers/*.h'
  s.vendored_frameworks = 'TCSDK.framework'
#  s.framworks   = 'SystemConfiguration', 'CoreLocation' 
end