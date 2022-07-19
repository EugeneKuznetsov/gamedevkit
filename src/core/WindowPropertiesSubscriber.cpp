#include "GDK/WindowPropertiesSubscriber.hpp"

namespace gamedevkit::windows {

auto WindowPropertiesSubscriber::window_size(const WindowSize& /*new_window_size*/) -> void {}

auto WindowPropertiesSubscriber::frame_buffer_size(const FrameBufferSize& /*new_frame_buffer_size*/) -> void {}

auto WindowPropertiesSubscriber::window_content_scale(const WindowContentScale& /*new_window_content_scale*/) -> void {}

}  // namespace gamedevkit::windows
