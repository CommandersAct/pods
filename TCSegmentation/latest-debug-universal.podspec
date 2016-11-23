Pod::Spec.new do |s|
  s.name         = "TCSegmentation"
  s.version      = "4.0.0"
  s.homepage     = "https://github.com/tagcommander/pods/TCSegmentation"
#  s.license      = { :type => 'MIT', :file => 'TCSegmentation.framework/LICENSE' }
  s.author       = { "TagCommander" => "support@tagcommander.com" }
  s.summary      = "TagCommander pod"
  s.description  = <<-DESC
           Go to https://github.com/TagCommander/pods/TCSegmentation for more details
                   DESC
  s.platform     = :ios, '8.0'
  s.source   = { :http => "https://github.com/TagCommander/pods/raw/master/TCSegmentation/Debug-universal/4.0.0.zip" }
  s.preserve_paths      = 'TCSegmentation.framework'
  s.public_header_files = 'TCSegmentation.framework/Headers/*.h'
  s.vendored_frameworks = 'TCSegmentation.framework'
#  s.framworks   = 'SystemConfiguration', 'CoreLocation' 
end