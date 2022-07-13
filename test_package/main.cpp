#include <cstdlib>

#include <GDK/AbstractGame.hpp>
#include <GDK/AbstractRenderer.hpp>
#include <GDK/Application.hpp>
#include <GDK/Keyboard.hpp>
#include <GDK/WindowBuilder.hpp>
#include <GDK/GenericShader.hpp>

namespace keyboard = gamedevkit::input::keyboard;

class Game final : public gamedevkit::AbstractGame {
    auto setup() -> void override {}
    auto update() -> void override {}
    auto input(const keyboard::Key&, const keyboard::Action&, const std::set<keyboard::Modifier>&) -> void override {}
};

class Renderer final : public gamedevkit::AbstractRenderer {
    auto setup(std::shared_ptr<gamedevkit::AbstractGame> /*game*/) -> void override {}
    auto render() -> void override {}
};

class Shader final : public gamedevkit::shaders::GenericShader {
    explicit Shader()
        : gamedevkit::shaders::GenericShader{gamedevkit::shaders::Type::vertex}
    {
    }

    auto shader_source() const -> std::string override { return ""; }
};

auto main() -> int
{
    try {
        gamedevkit::Application{}.game(std::make_shared<Game>()).renderer(std::make_unique<Renderer>()).setup();
    }
    catch (...) {
    }
    return EXIT_SUCCESS;
}
