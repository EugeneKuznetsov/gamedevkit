#include "GDK/Window.hpp"

#include <glfwcxx/Window.hpp>

#include "GDK/KeyboardInputSubscriber.hpp"
#include "KeyboardHelper.hpp"

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

auto Window::subscribe(std::weak_ptr<input::KeyboardInputSubscriber> subscriber_ptr) -> void
{
    window_->keyboard_input([subscriber_ptr](auto key, auto action, auto modifiers) -> void {
        if (auto subscriber = subscriber_ptr.lock(); nullptr != subscriber) {
            namespace helper = gamedevkit::helpers::input;
            std::set<gamedevkit::input::keyboard::Modifier> gdk_modifiers;
            for (const auto& modifier : modifiers)
                gdk_modifiers.insert(helper::keyboard_modifier(modifier));
            subscriber->input(helper::keyboard_key(key), helper::keyboard_action(action), gdk_modifiers);
        }
    });
}

auto Window::should_close() const -> bool
{
    return window_->should_close();
}

}  // namespace gamedevkit
