#include <cstdlib>

#include <GL/gl.h>
#include <GDK/AbstractGame.hpp>
#include <GDK/AbstractRenderer.hpp>
#include <GDK/Application.hpp>
#include <GDK/Keyboard.hpp>
#include <GDK/WindowBuilder.hpp>
#include <GDK/GenericShader.hpp>
#include <GDK/GenericProgram.hpp>

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
public:
    explicit Shader(gamedevkit::shaders::Type type = gamedevkit::shaders::Type::vertex)
        : gamedevkit::shaders::GenericShader{type}
    {
    }

    auto shader_source() const -> std::string override { return ""; }
};

class Program final : public gamedevkit::shaders::GenericProgram {
    auto vertex_shader() const -> std::unique_ptr<gamedevkit::shaders::GenericShader> override
    {
        return std::make_unique<Shader>(gamedevkit::shaders::Type::vertex);
    }

    auto fragment_shader() const -> std::unique_ptr<gamedevkit::shaders::GenericShader> override
    {
        return std::make_unique<Shader>(gamedevkit::shaders::Type::fragment);
    }
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
