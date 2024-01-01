// Copyright 2021-present 650 Industries. All rights reserved.

import ExpoModulesCore

public final class KeepAwakeModule: Module {
  private var activeTags = Set<String>()

  public func definition() -> ModuleDefinition {
    Name("ExpoKeepAwake")

    AsyncFunction("activate") { (tag: String) -> Bool in
      if self.activeTags.isEmpty {
        setActivated(true)
      }
      self.activeTags.insert(tag)
      return true
    }

    AsyncFunction("deactivate") { (tag: String) -> Bool in
      self.activeTags.remove(tag)
      if self.activeTags.isEmpty {
        setActivated(false)
      }
      return true
    }

    AsyncFunction("isActivated") { () -> Bool in
      #if os(OSX)
      return false
      #else // os(OSX)
      return DispatchQueue.main.sync {
        return UIApplication.shared.isIdleTimerDisabled
      }
      #endif // !os(OSX)
    }

    OnAppEntersForeground {
      if !self.activeTags.isEmpty {
        setActivated(true)
      }
    }

    OnAppEntersBackground {
      if !self.activeTags.isEmpty {
        setActivated(false)
      }
    }
  }
}

private func setActivated(_ activated: Bool) {
  #if os(iOS)
  DispatchQueue.main.async {
    UIApplication.shared.isIdleTimerDisabled = activated
  }
  #endif
}
