#pragma once

#include <string>
#include <memory>

namespace glfwcxx {
class Window;
}

namespace gamedevkit {

struct WindowResolution {
    int width;
    int height;
};

class Window final {
    Window(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) = delete;

public:
    explicit Window(const std::string& title, const WindowResolution& resolution);
    ~Window();

public:
    auto activate() -> void;
    auto poll_events() -> void;
    auto swap_buffers() -> void;

public:
    auto should_close() const -> bool;

private:
    std::unique_ptr<glfwcxx::Window> window_;
};

}  // namespace gamedevkit
