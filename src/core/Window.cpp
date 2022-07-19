#include "GDK/Window.hpp"

#include <glfwcxx/Window.hpp>

#include "GDK/KeyboardInputSubscriber.hpp"
#include "GDK/WindowProperties.hpp"
#include "GDK/WindowPropertiesSubscriber.hpp"
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

auto Window::close() -> void
{
    window_->close();
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

auto Window::subscribe(std::weak_ptr<windows::WindowPropertiesSubscriber> subscriber_ptr, bool trigger_on_subscribe /*= true*/) -> void
{
    if (auto subscriber = subscriber_ptr.lock(); nullptr != subscriber && trigger_on_subscribe) {
        const auto window_size = window_->window_size();
        const auto frame_buffer_size = window_->frame_buffer_size();
        const auto window_content_scale = window_->window_content_scale();

        subscriber->window_size(windows::WindowSize{window_size.width, window_size.height});
        subscriber->frame_buffer_size(windows::FrameBufferSize{frame_buffer_size.width, frame_buffer_size.height});
        subscriber->window_content_scale(windows::WindowContentScale{window_content_scale.xscale, window_content_scale.yscale});
    }

    window_->window_size([subscriber_ptr](const auto& new_window_size) -> void {
        if (auto subscriber = subscriber_ptr.lock(); nullptr != subscriber)
            subscriber->window_size(windows::WindowSize{new_window_size.width, new_window_size.height});
    });
    window_->frame_buffer_size([subscriber_ptr](const auto& new_frame_buffer_size) -> void {
        if (auto subscriber = subscriber_ptr.lock(); nullptr != subscriber)
            subscriber->frame_buffer_size(windows::FrameBufferSize{new_frame_buffer_size.width, new_frame_buffer_size.height});
    });
    window_->window_content_scale([subscriber_ptr](const auto& new_window_content_scale) -> void {
        if (auto subscriber = subscriber_ptr.lock(); nullptr != subscriber)
            subscriber->window_content_scale(windows::WindowContentScale{new_window_content_scale.xscale, new_window_content_scale.yscale});
    });
}

auto Window::should_close() const -> bool
{
    return window_->should_close();
}

}  // namespace gamedevkit
