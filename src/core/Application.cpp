#include "GDK/Application.hpp"

#include <chrono>
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

Application::~Application()
{
    window_ = nullptr;
}

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
    renderer_ = std::move(renderer);
    return *this;
}

auto Application::setup() -> void
{
    check_application_readiness("setup");

    window_->activate();

    if (GLEW_OK != glewInit())
        throw std::runtime_error("Failed to initialize GLEW");

    game_->setup();
    renderer_->setup(game_);

    window_->subscribe(std::static_pointer_cast<input::KeyboardInputSubscriber>(game_));
    game_->on_quit([&window = window_]() {
        if (nullptr != window)
            window->close();
    });
}

auto Application::run() -> int
{
    check_application_readiness("run");

    constexpr auto frames_per_second = 60;
    constexpr auto ms_per_update = std::chrono::milliseconds{1000} / frames_per_second;

    auto previous_update = std::chrono::high_resolution_clock::now();
    auto lag = std::chrono::duration_cast<std::chrono::nanoseconds>(ms_per_update);

    while (false == window_->should_close()) {
        const auto current_update = std::chrono::high_resolution_clock::now();
        const auto update_duration = current_update - previous_update;
        previous_update = current_update;
        lag += update_duration;

        window_->poll_events();

        for (; lag >= ms_per_update; lag -= ms_per_update)
            game_->update();

        renderer_->render();

        window_->swap_buffers();
    }

    return EXIT_SUCCESS;
}

auto Application::check_application_readiness(const std::string& stage) -> void
{
    if (nullptr == window_)
        throw std::runtime_error("Cannot " + stage + " Application without Window being set");

    if (nullptr == game_)
        throw std::runtime_error("Cannot " + stage + " Application without Game being set");

    if (nullptr == renderer_)
        throw std::runtime_error("Cannot " + stage + " Application without Renderer being set");
}

Application::Details::Details()
    : glfwcxx_{glfwcxx::Core::init()}
{
}

}  // namespace gamedevkit
