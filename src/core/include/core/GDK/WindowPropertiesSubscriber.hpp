#pragma once

namespace gamedevkit::windows {

struct WindowSize;
struct FrameBufferSize;
struct WindowContentScale;

class WindowPropertiesSubscriber {
public:
    virtual ~WindowPropertiesSubscriber() = default;

    virtual auto window_size(const WindowSize& new_window_size) -> void{};
    virtual auto frame_buffer_size(const FrameBufferSize& new_frame_buffer_size) -> void{};
    virtual auto window_content_scale(const WindowContentScale& new_window_content_scale) -> void{};
};

}  // namespace gamedevkit::windows
