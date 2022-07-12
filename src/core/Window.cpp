#include "GDK/Window.hpp"

#include <glfwcxx/Window.hpp>

namespace gamedevkit {

Window::Window(std::unique_ptr<glfwcxx::Window> window)
    : window_{std::move(window)}
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
