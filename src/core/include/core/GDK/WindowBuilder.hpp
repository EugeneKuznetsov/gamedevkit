#pragma once

#include <memory>

namespace gamedevkit {

class Window;

class WindowBuilder final {
    WindowBuilder(const WindowBuilder&) = delete;
    WindowBuilder(WindowBuilder&&) = delete;
    WindowBuilder& operator=(const WindowBuilder&) = delete;
    WindowBuilder& operator=(WindowBuilder&&) = delete;

public:
    explicit WindowBuilder();

public:
    [[nodiscard]] auto build() -> std::unique_ptr<Window>;

public:
    [[nodiscard]] auto opengl_profile_compat() -> WindowBuilder&;
    [[nodiscard]] auto opengl_profile_core() -> WindowBuilder&;
    [[nodiscard]] auto context_version(int major, int minor) -> WindowBuilder&;
};

}  // namespace gamedevkit
