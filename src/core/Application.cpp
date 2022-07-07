#include "GDK/Application.hpp"

#include <cstdlib>
#include <stdexcept>

#include <GL/glew.h>

#include <glfwcxx/Core.hpp>

#include "ApplicationDetails.hpp"
#include "GDK/AbstractGame.hpp"
#include "GDK/AbstractRenderer.hpp"
#include "GDK/Window.hpp"

namespace gamedevkit {

Application::Application()
    : details_{std::make_unique<Details>()}
    , window_{nullptr}
    , game_{nullptr}
    , renderer_{nullptr}
{
}

Application::Application(int /*argc*/, char** /*argv[]*/)
    : Application()
{
}

Application::~Application() = default;

auto Application::window(std::unique_ptr<Window> window) -> Application&
{
    window_ = std::move(window);
    return *this;
}

auto Application::game(std::shared_ptr<AbstractGame> game) -> Application&
{
    game_ = std::move(game);
    return *this;
}

auto Application::renderer(std::unique_ptr<AbstractRenderer> renderer) -> Application&
{
    return *this;
}

auto Application::setup() -> void
{
    if (nullptr == window_)
        throw std::runtime_error("Cannot setup Application without Window being set");

    if (nullptr == game_)
        throw std::runtime_error("Cannot setup Application without Game being set");

    window_->activate();

    if (GLEW_OK != glewInit())
        throw std::runtime_error("Failed to initialize GLEW");

    game_->setup();
}

auto Application::run() -> int
{
    while (false == window_->should_close()) {
        window_->poll_events();

        game_->update();

        window_->swap_buffers();
    }

    return EXIT_SUCCESS;
}

Application::Details::Details()
    : glfwcxx_{glfwcxx::Core::init()}
{
}

}  // namespace gamedevkit
