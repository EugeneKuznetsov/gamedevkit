#include "GDK/WindowBuilder.hpp"

#include <stdexcept>

#include <glfwcxx/Window.hpp>
#include <glfwcxx/WindowHints.hpp>

namespace gamedevkit {

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

auto WindowBuilder::context_version(int major, int minor) -> WindowBuilder&
{
    window_hints_->context_version({major, minor});
    return *this;
}

}  // namespace gamedevkit
