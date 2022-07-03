#include "GDK/Application.hpp"

#include <cstdlib>

#include <glfwcxx/Core.hpp>

#include "ApplicationDetails.hpp"
#include "GDK/Window.hpp"

namespace gamedevkit {

Application::Application()
    : details_{std::make_unique<Details>()}
{
}

Application::Application(int /*argc*/, char** /*argv[]*/)
    : Application()
{
}

Application::~Application() = default;

auto Application::window(std::unique_ptr<Window>&& /*window*/) -> Application&
{
    return *this;
}

auto Application::setup() -> void {}

auto Application::run() -> int
{
    return EXIT_SUCCESS;
}

Application::Details::Details()
    : glfwcxx_{glfwcxx::Core::init()}
{
}

}  // namespace gamedevkit
