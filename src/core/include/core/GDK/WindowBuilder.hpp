#pragma once

#include <memory>
#include <string>

#include <GDK/Window.hpp>

namespace glfwcxx {
class WindowHints;
}

namespace gamedevkit {

class WindowBuilder final {
    WindowBuilder(const WindowBuilder&) = delete;
    WindowBuilder(WindowBuilder&&) = delete;
    WindowBuilder& operator=(const WindowBuilder&) = delete;
    WindowBuilder& operator=(WindowBuilder&&) = delete;

public:
    explicit WindowBuilder();
    explicit WindowBuilder(const std::string& title, const WindowResolution& resolution);
    ~WindowBuilder();

public:
    [[nodiscard]] auto build() -> std::unique_ptr<Window>;
    [[nodiscard]] auto build(const std::string& title, const WindowResolution& resolution) -> std::unique_ptr<Window>;

public:
    [[nodiscard]] auto title(const std::string& title) -> WindowBuilder&;
    [[nodiscard]] auto resolution(const WindowResolution& resolution) -> WindowBuilder&;

public:
    [[nodiscard]] auto opengl_profile_compat() -> WindowBuilder&;
    [[nodiscard]] auto opengl_profile_core() -> WindowBuilder&;
    [[nodiscard]] auto context_version(int major, int minor) -> WindowBuilder&;

private:
    std::string title_;
    std::unique_ptr<WindowResolution> resolution_;
    std::unique_ptr<glfwcxx::WindowHints> window_hints_;
};

}  // namespace gamedevkit
