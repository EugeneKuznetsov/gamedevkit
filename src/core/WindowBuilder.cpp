#include "GDK/WindowBuilder.hpp"

#include "GDK/Window.hpp"

namespace gamedevkit {

WindowBuilder::WindowBuilder() {}

auto WindowBuilder::build() -> std::unique_ptr<Window>
{
    return nullptr;
}

auto WindowBuilder::opengl_profile_compat() -> WindowBuilder&
{
    return *this;
}

auto WindowBuilder::opengl_profile_core() -> WindowBuilder&
{
    return *this;
}

auto WindowBuilder::context_version(int /*major*/, int /*minor*/) -> WindowBuilder&
{
    return *this;
}

}  // namespace gamedevkit
