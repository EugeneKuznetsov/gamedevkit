#include "GDK/Window.hpp"

#include <glfwcxx/Window.hpp>

namespace gamedevkit {

Window::Window(const std::string& title, const WindowResolution& resolution)
    : window_{glfwcxx::Window::create_window({resolution.width, resolution.height}, title)}
{
}

Window::~Window() = default;

auto Window::activate() -> void
{
    window_->make_context_current();
}

auto Window::poll_events() -> void
{
    window_->poll_events();
}

auto Window::swap_buffers() -> void
{
    window_->swap_buffers();
}

auto Window::should_close() const -> bool
{
    return window_->should_close();
}

}  // namespace gamedevkit
