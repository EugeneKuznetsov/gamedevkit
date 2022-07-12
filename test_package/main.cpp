#include <cstdlib>

#include <GDK/AbstractGame.hpp>
#include <GDK/AbstractRenderer.hpp>
#include <GDK/Application.hpp>
#include <GDK/WindowBuilder.hpp>

class Game final : public gamedevkit::AbstractGame {
    auto setup() -> void override {}
    auto update() -> void override {}
};

class Renderer final : public gamedevkit::AbstractRenderer {
    auto setup(std::shared_ptr<gamedevkit::AbstractGame> /*game*/) -> void override {}
    auto render() -> void override {}
};

auto main() -> int
{
    gamedevkit::Application{}
        .window(gamedevkit::WindowBuilder{"GameDevKitApp", {800, 600}}.opengl_profile_core().context_version(4, 0).build())
        .game(std::make_shared<Game>())
        .renderer(std::make_unique<Renderer>())
        .setup();

    return EXIT_SUCCESS;
}
