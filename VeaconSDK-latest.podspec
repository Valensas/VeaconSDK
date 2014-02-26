Pod::Spec.new do |s|
  s.name         = "VeaconSDK"
  s.version      = "0.0.1"
  s.homepage     = "http://getveacon.com"
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.author       = { "Valensas" => "info@getveacon.com" }
  s.summary      = "VeaconSDK"

  s.platform     = :ios, '6.0'
  s.source       = { :git => "https://github.com/Valensas/VeaconSDK.git", :branch => "master" }

  s.preserve_paths      = 'Veacon.framework'
  s.public_header_files = 'Veacon.framework/Versions/A/Headers/*.h'
  s.vendored_frameworks = 'Veacon.framework'

  s.xcconfig      = { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/VeaconSDK/**"' }
  s.requires_arc = true
end