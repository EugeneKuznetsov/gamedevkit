#pragma once

#include <tuple>

namespace gamedevkit::windows {

struct WindowSize {
    int width;
    int height;
};

struct FrameBufferSize {
    int width;
    int height;
};

struct WindowContentScale {
    float xscale;
    float yscale;
};

constexpr auto operator==(const WindowSize& left, const WindowSize& right) -> bool
{
    return std::tie(left.width, left.height) == std::tie(right.width, right.height);
}

constexpr auto operator==(const FrameBufferSize& left, const FrameBufferSize& right) -> bool
{
    return std::tie(left.width, left.height) == std::tie(right.width, right.height);
}

constexpr auto operator==(const WindowContentScale& left, const WindowContentScale& right) -> bool
{
    return std::tie(left.xscale, left.yscale) == std::tie(right.xscale, right.yscale);
}

}  // namespace gamedevkit::windows
