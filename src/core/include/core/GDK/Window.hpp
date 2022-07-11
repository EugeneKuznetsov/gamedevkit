#pragma once

#include <string>
#include <memory>

namespace glfwcxx {
class Window;
}

namespace gamedevkit {

class Application;

struct WindowResolution {
    int width;
    int height;
};

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

private:
    auto should_close() const -> bool;

private:
    std::unique_ptr<glfwcxx::Window> window_;

    friend class Application;
    friend class WindowBuilder;
};

}  // namespace gamedevkit
