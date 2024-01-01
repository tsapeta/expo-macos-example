
#if TARGET_OS_OSX

#import <AppKit/AppKit.h>
#import <React/RCTUIKit.h>

@compatibility_alias UIView NSView;
@compatibility_alias UIResponder NSResponder;
@compatibility_alias UIColor NSColor;

#else

#import <UIKit/UIKit.h>

#endif // TARGET_OS_OSX
