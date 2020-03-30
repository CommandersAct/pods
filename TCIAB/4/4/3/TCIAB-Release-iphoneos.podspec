Pod::Spec.new do |s|
  s.name         = "TCIAB-Release-iphoneos"
  s.version      = "4.4.3"
  s.homepage     = "https://github.com/TagCommander/pods/tree/master/TCIAB"
  s.license      = { :type => 'proprietary', :file => 'LICENSE.md' }
  s.author       = { "Commanders Act" => "support@commandersact.com" }
  s.summary      = "TagCommander pod"
  s.description  = <<-DESC
           Go to https://github.com/TagCommander/pods/tree/master/TCIAB for more details
                   DESC
  s.platform     = :ios, '8.0'
  s.source   = { :http => "https://github.com/TagCommander/pods/raw/master/TCIAB/4/4/3/Release-iphoneos/TCIAB.zip" }
  s.preserve_paths      = 'TCIAB.framework'
  #s.public_header_files = 'TCIAB.framework/Headers/*.h'
  s.vendored_frameworks = 'TCIAB.framework'
end