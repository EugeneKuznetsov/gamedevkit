#include "GDK/Application.hpp"

#include <glfwcxx/Core.hpp>

#include "ApplicationDetails.hpp"

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

Application::Details::Details()
    : glfwcxx_{glfwcxx::Core::init()}
{
}

}  // namespace gamedevkit
