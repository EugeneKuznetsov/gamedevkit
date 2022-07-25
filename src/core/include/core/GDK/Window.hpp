#pragma once

#include <string>
#include <memory>

namespace glfwcxx {
class Window;
}

namespace gamedevkit {

namespace input {
class KeyboardInputSubscriber;
}

namespace windows {
class WindowPropertiesSubscriber;
}

class Window final {
    Window(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) = delete;

    explicit Window(std::unique_ptr<glfwcxx::Window> window);

public:
    ~Window();

private:
    auto activate() -> void;
    auto poll_events() -> void;
    auto swap_buffers() -> void;
    auto close() -> void;

private:
    auto subscribe(std::weak_ptr<input::KeyboardInputSubscriber> subscriber_ptr) -> void;
    auto subscribe(std::weak_ptr<windows::WindowPropertiesSubscriber> subscriber_ptr, bool trigger_on_subscribe = true) -> void;

private:
    auto should_close() const -> bool;

private:
    std::unique_ptr<glfwcxx::Window> window_;

    friend class Application;
    friend class WindowBuilder;
};

}  // namespace gamedevkit
