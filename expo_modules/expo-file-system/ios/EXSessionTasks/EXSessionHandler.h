// Copyright 2015-present 650 Industries. All rights reserved.

#import <Foundation/Foundation.h>
#import <ExpoModulesCore/Platform.h>
#import <ExpoModulesCore/EXSingletonModule.h>

NS_ASSUME_NONNULL_BEGIN

@protocol EXSessionHandler

- (void)invokeCompletionHandlerForSessionIdentifier:(NSString *)identifier;

@end

#if TARGET_OS_OSX
@interface EXSessionHandler : EXSingletonModule <NSApplicationDelegate, EXSessionHandler>
#else
@interface EXSessionHandler : EXSingletonModule <UIApplicationDelegate, EXSessionHandler>
#endif // TARGET_OS_OSX

@end

NS_ASSUME_NONNULL_END
