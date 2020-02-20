Pod::Spec.new do |s|
  s.name         = "TCCore-Release-universal"
  s.version      = "4.6.1"
  s.homepage     = "https://github.com/TagCommander/pods/tree/master/Beta/podspecs"
  s.license      = { :type => 'proprietary', :file => 'LICENSE.md'}
  s.author       = { "Commanders Act" => "support@commandersact.com" }
  s.summary      = "TagCommander pod"
  s.description  = <<-DESC
           Go to https://github.com/TagCommander/pods/tree/master/TCCore for more details
                   DESC
  s.platform     = :ios, '8.0'
  s.source   = { :http => "https://github.com/TagCommander/pods/raw/master/Beta/podspecs/TCCore.zip" }
  s.preserve_paths      = 'TCCore.framework'
  #s.public_header_files = 'TCCore.framework/Headers/*.h'
  s.vendored_frameworks = 'TCCore.framework'
end