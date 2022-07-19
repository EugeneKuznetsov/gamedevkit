#pragma once

#include <memory>
#include <string>

#include <GDK/Window.hpp>
#include <GDK/WindowProperties.hpp>

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
    explicit WindowBuilder(const std::string& title, const windows::WindowSize& resolution);
    ~WindowBuilder();

public:
    [[nodiscard]] auto build() -> std::unique_ptr<Window>;
    [[nodiscard]] auto build(const std::string& title, const windows::WindowSize& resolution) -> std::unique_ptr<Window>;

public:
    [[nodiscard]] auto title(const std::string& title) -> WindowBuilder&;
    [[nodiscard]] auto resolution(const windows::WindowSize& resolution) -> WindowBuilder&;

public:
    [[nodiscard]] auto accum_alpha_bits(int value = 0) -> WindowBuilder&;
    [[nodiscard]] auto accum_blue_bits(int value = 0) -> WindowBuilder&;
    [[nodiscard]] auto accum_green_bits(int value = 0) -> WindowBuilder&;
    [[nodiscard]] auto accum_red_bits(int value = 0) -> WindowBuilder&;
    [[nodiscard]] auto alpha_bits(int value = 8) -> WindowBuilder&;
    [[nodiscard]] auto auto_iconify(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto aux_buffers(int value = 0) -> WindowBuilder&;
    [[nodiscard]] auto blue_bits(int value = 8) -> WindowBuilder&;
    [[nodiscard]] auto center_cursor(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto client_api_none() -> WindowBuilder&;
    [[nodiscard]] auto client_api_opengl() -> WindowBuilder&;
    [[nodiscard]] auto client_api_opengl_es() -> WindowBuilder&;
    [[nodiscard]] auto cocoa_graphics_switching(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto cocoa_frame_name(const std::string& value = {}) -> WindowBuilder&;
    [[nodiscard]] auto cocoa_retina_framebuffer(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto context_creation_api_egl() -> WindowBuilder&;
    [[nodiscard]] auto context_creation_api_native() -> WindowBuilder&;
    [[nodiscard]] auto context_creation_api_osmesa() -> WindowBuilder&;
    [[nodiscard]] auto context_release_behavior_any() -> WindowBuilder&;
    [[nodiscard]] auto context_release_behavior_flush() -> WindowBuilder&;
    [[nodiscard]] auto context_release_behavior_none() -> WindowBuilder&;
    [[nodiscard]] auto context_robustness_lose_context_on_reset() -> WindowBuilder&;
    [[nodiscard]] auto context_robustness_no_reset_notification() -> WindowBuilder&;
    [[nodiscard]] auto context_robustness_none() -> WindowBuilder&;
    [[nodiscard]] auto context_version(int major, int minor) -> WindowBuilder&;
    [[nodiscard]] auto decorated(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto depth_bits(int value = 24) -> WindowBuilder&;
    [[nodiscard]] auto doublebuffer(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto focus_on_show(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto focused(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto floating(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto green_bits(int value = 8) -> WindowBuilder&;
    [[nodiscard]] auto maximized(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto opengl_debug_context(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto opengl_forward_compat(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto opengl_profile_any() -> WindowBuilder&;
    [[nodiscard]] auto opengl_profile_compat() -> WindowBuilder&;
    [[nodiscard]] auto opengl_profile_core() -> WindowBuilder&;
    [[nodiscard]] auto red_bits(int value = 8) -> WindowBuilder&;
    [[nodiscard]] auto refresh_rate(int value = dont_care) -> WindowBuilder&;
    [[nodiscard]] auto resizable(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto samples(int value = 0) -> WindowBuilder&;
    [[nodiscard]] auto scale_to_monitor(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto stencil_bits(int value = 8) -> WindowBuilder&;
    [[nodiscard]] auto stereo(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto srgb_capable(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto transparent_framebuffer(bool value = false) -> WindowBuilder&;
    [[nodiscard]] auto visible(bool value = true) -> WindowBuilder&;
    [[nodiscard]] auto x11_class_name(const std::string& value = {}) -> WindowBuilder&;
    [[nodiscard]] auto x11_instance_name(const std::string& value = {}) -> WindowBuilder&;

public:
    static const int dont_care;

private:
    std::string title_;
    std::unique_ptr<windows::WindowSize> resolution_;
    std::unique_ptr<glfwcxx::WindowHints> window_hints_;
};

}  // namespace gamedevkit
