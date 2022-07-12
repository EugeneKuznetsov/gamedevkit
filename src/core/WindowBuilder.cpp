#include "GDK/WindowBuilder.hpp"

#include <stdexcept>

#include <glfwcxx/Window.hpp>
#include <glfwcxx/WindowHints.hpp>

namespace gamedevkit {

const int WindowBuilder::dont_care{glfwcxx::dont_care};

WindowBuilder::WindowBuilder()
    : title_{}
    , resolution_{nullptr}
    , window_hints_{std::make_unique<glfwcxx::WindowHints>()}
{
}

WindowBuilder::WindowBuilder(const std::string& title, const WindowResolution& resolution)
    : title_{title}
    , resolution_{std::make_unique<WindowResolution>(resolution)}
    , window_hints_{std::make_unique<glfwcxx::WindowHints>()}
{
}

WindowBuilder::~WindowBuilder() = default;

auto WindowBuilder::build() -> std::unique_ptr<Window>
{
    if (nullptr == resolution_)
        throw std::runtime_error("Cannot build GDK window without resolution being set");

    auto window = glfwcxx::Window::create_window({resolution_->width, resolution_->height}, title_, *window_hints_.get());
    return std::unique_ptr<Window>{new Window{std::move(window)}};
}

auto WindowBuilder::build(const std::string& title, const WindowResolution& resolution) -> std::unique_ptr<Window>
{
    auto window = glfwcxx::Window::create_window({resolution.width, resolution.height}, title, *window_hints_.get());
    return std::unique_ptr<Window>{new Window{std::move(window)}};
}

auto WindowBuilder::title(const std::string& title) -> WindowBuilder&
{
    title_ = title;
    return *this;
}

auto WindowBuilder::resolution(const WindowResolution& resolution) -> WindowBuilder&
{
    resolution_ = std::make_unique<WindowResolution>(resolution);
    return *this;
}

auto WindowBuilder::accum_alpha_bits(int value /*= 0*/) -> WindowBuilder&
{
    window_hints_->accum_alpha_bits(value);
    return *this;
}

auto WindowBuilder::accum_blue_bits(int value /*= 0*/) -> WindowBuilder&
{
    window_hints_->accum_blue_bits(value);
    return *this;
}

auto WindowBuilder::accum_green_bits(int value /*= 0*/) -> WindowBuilder&
{
    window_hints_->accum_green_bits(value);
    return *this;
}

auto WindowBuilder::accum_red_bits(int value /*= 0*/) -> WindowBuilder&
{
    window_hints_->accum_red_bits(value);
    return *this;
}

auto WindowBuilder::alpha_bits(int value /*= 8*/) -> WindowBuilder&
{
    window_hints_->alpha_bits(value);
    return *this;
}

auto WindowBuilder::auto_iconify(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->auto_iconify(value);
    return *this;
}

auto WindowBuilder::aux_buffers(int value /*= 0*/) -> WindowBuilder&
{
    window_hints_->aux_buffers(value);
    return *this;
}

auto WindowBuilder::blue_bits(int value /*= 8*/) -> WindowBuilder&
{
    window_hints_->blue_bits(value);
    return *this;
}

auto WindowBuilder::center_cursor(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->center_cursor(value);
    return *this;
}

auto WindowBuilder::client_api_none() -> WindowBuilder&
{
    window_hints_->client_api(glfwcxx::ClientAPI::no_api);
    return *this;
}

auto WindowBuilder::client_api_opengl() -> WindowBuilder&
{
    window_hints_->client_api(glfwcxx::ClientAPI::opengl);
    return *this;
}

auto WindowBuilder::client_api_opengl_es() -> WindowBuilder&
{
    window_hints_->client_api(glfwcxx::ClientAPI::opengl_es);
    return *this;
}

auto WindowBuilder::cocoa_graphics_switching(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->cocoa_graphics_switching(value);
    return *this;
}

auto WindowBuilder::cocoa_frame_name(const std::string& value /*= {}*/) -> WindowBuilder&
{
    window_hints_->cocoa_frame_name(value);
    return *this;
}

auto WindowBuilder::cocoa_retina_framebuffer(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->cocoa_retina_framebuffer(value);
    return *this;
}

auto WindowBuilder::context_creation_api_egl() -> WindowBuilder&
{
    window_hints_->context_creation_api(glfwcxx::ContextCreationAPI::egl);
    return *this;
}

auto WindowBuilder::context_creation_api_native() -> WindowBuilder&
{
    window_hints_->context_creation_api(glfwcxx::ContextCreationAPI::native);
    return *this;
}

auto WindowBuilder::context_creation_api_osmesa() -> WindowBuilder&
{
    window_hints_->context_creation_api(glfwcxx::ContextCreationAPI::osmesa);
    return *this;
}

auto WindowBuilder::context_release_behavior_any() -> WindowBuilder&
{
    window_hints_->context_release_behavior(glfwcxx::ContextReleaseBehavior::any_release_behavior);
    return *this;
}

auto WindowBuilder::context_release_behavior_flush() -> WindowBuilder&
{
    window_hints_->context_release_behavior(glfwcxx::ContextReleaseBehavior::release_behavior_flush);
    return *this;
}

auto WindowBuilder::context_release_behavior_none() -> WindowBuilder&
{
    window_hints_->context_release_behavior(glfwcxx::ContextReleaseBehavior::release_behavior_none);
    return *this;
}

auto WindowBuilder::context_robustness_lose_context_on_reset() -> WindowBuilder&
{
    window_hints_->context_robustness(glfwcxx::ContextRobustness::lose_context_on_reset);
    return *this;
}

auto WindowBuilder::context_robustness_no_reset_notification() -> WindowBuilder&
{
    window_hints_->context_robustness(glfwcxx::ContextRobustness::no_reset_notification);
    return *this;
}

auto WindowBuilder::context_robustness_none() -> WindowBuilder&
{
    window_hints_->context_robustness(glfwcxx::ContextRobustness::no_robustness);
    return *this;
}

auto WindowBuilder::context_version(int major, int minor) -> WindowBuilder&
{
    window_hints_->context_version({major, minor});
    return *this;
}

auto WindowBuilder::decorated(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->decorated(value);
    return *this;
}

auto WindowBuilder::depth_bits(int value /*= 24*/) -> WindowBuilder&
{
    window_hints_->depth_bits(value);
    return *this;
}

auto WindowBuilder::doublebuffer(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->doublebuffer(value);
    return *this;
}

auto WindowBuilder::focus_on_show(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->focus_on_show(value);
    return *this;
}

auto WindowBuilder::focused(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->focused(value);
    return *this;
}

auto WindowBuilder::floating(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->floating(value);
    return *this;
}

auto WindowBuilder::green_bits(int value /*= 8*/) -> WindowBuilder&
{
    window_hints_->green_bits(value);
    return *this;
}

auto WindowBuilder::maximized(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->maximized(value);
    return *this;
}

auto WindowBuilder::opengl_debug_context(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->opengl_debug_context(value);
    return *this;
}

auto WindowBuilder::opengl_forward_compat(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->opengl_forward_compat(value);
    return *this;
}

auto WindowBuilder::opengl_profile_any() -> WindowBuilder&
{
    window_hints_->opengl_profile(glfwcxx::OpenGLProfile::any_profile);
    return *this;
}

auto WindowBuilder::opengl_profile_compat() -> WindowBuilder&
{
    window_hints_->opengl_profile(glfwcxx::OpenGLProfile::compat);
    return *this;
}

auto WindowBuilder::opengl_profile_core() -> WindowBuilder&
{
    window_hints_->opengl_profile(glfwcxx::OpenGLProfile::core);
    return *this;
}

auto WindowBuilder::red_bits(int value /*= 8*/) -> WindowBuilder&
{
    window_hints_->red_bits(value);
    return *this;
}

auto WindowBuilder::refresh_rate(int value /*= dont*/) -> WindowBuilder&
{
    window_hints_->refresh_rate(value);
    return *this;
}

auto WindowBuilder::resizable(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->resizable(value);
    return *this;
}

auto WindowBuilder::samples(int value /*= 0*/) -> WindowBuilder&
{
    window_hints_->samples(value);
    return *this;
}

auto WindowBuilder::scale_to_monitor(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->scale_to_monitor(value);
    return *this;
}

auto WindowBuilder::stencil_bits(int value /*= 8*/) -> WindowBuilder&
{
    window_hints_->stencil_bits(value);
    return *this;
}

auto WindowBuilder::stereo(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->stereo(value);
    return *this;
}

auto WindowBuilder::srgb_capable(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->srgb_capable(value);
    return *this;
}

auto WindowBuilder::transparent_framebuffer(bool value /*= false*/) -> WindowBuilder&
{
    window_hints_->transparent_framebuffer(value);
    return *this;
}

auto WindowBuilder::visible(bool value /*= true*/) -> WindowBuilder&
{
    window_hints_->visible(value);
    return *this;
}

auto WindowBuilder::x11_class_name(const std::string& value /*= {}*/) -> WindowBuilder&
{
    window_hints_->x11_class_name(value);
    return *this;
}

auto WindowBuilder::x11_instance_name(const std::string& value /*= {}*/) -> WindowBuilder&
{
    window_hints_->x11_instance_name(value);
    return *this;
}

}  // namespace gamedevkit
