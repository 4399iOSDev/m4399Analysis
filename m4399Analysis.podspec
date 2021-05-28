#
# Be sure to run `pod lib lint m4399Analysis.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'm4399Analysis'
  s.version          = '0.3.6'
  s.summary          = '4399分析平台iOS版本SDK'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
#4399分析平台iOS版本SDK
                       DESC

  s.homepage         = 'https://github.com/4399iOSDev/m4399Analysis.git'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'hecong@4399inc.com' => 'hecong@4399inc.com' }
  s.source           = { :git => 'https://github.com/4399iOSDev/m4399Analysis.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'

  s.vendored_frameworks = 'Framework/**/*.xcframework'
  
  s.libraries   =  "z"
  s.framework    = "CoreFoundation", "UIKit", "AdSupport"
end
