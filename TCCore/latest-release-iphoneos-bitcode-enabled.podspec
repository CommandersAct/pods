Pod::Spec.new do |s|
  s.name         = "TCCore"
  s.version      = "4.0.0"
  s.homepage     = "https://github.com/tagcommander/pods/TCCore"
#  s.license      = { :type => 'MIT', :file => 'TCCore.framework/LICENSE' }
  s.author       = { "TagCommander" => "support@tagcommander.com" }
  s.summary      = "TagCommander pod"
  s.description  = <<-DESC
           Go to https://github.com/TagCommander/pods/TCCore for more details
                   DESC
  s.platform     = :ios, '8.0'
  s.source   = { :http => "https://github.com/TagCommander/pods/raw/master/TCCore/Release-iphoneos/4.0.0-BITCODE.zip" }
  s.preserve_paths      = 'TCCore.framework'
  s.public_header_files = 'TCCore.framework/Headers/*.h'
  s.vendored_frameworks = 'TCCore.framework'
#  s.framworks   = 'SystemConfiguration', 'CoreLocation' 
end