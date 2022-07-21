#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

#include <GDK/AbstractGame.hpp>
#include <GDK/AbstractRenderer.hpp>
#include <GDK/Application.hpp>
#include <GDK/Keyboard.hpp>
#include <GDK/WindowBuilder.hpp>
#include <GDK/GenericShader.hpp>
#include <GDK/GenericProgram.hpp>
#include <GDK/GraphicsLibrary.hpp>

namespace keyboard = gamedevkit::input::keyboard;

class Game final : public gamedevkit::AbstractGame {
    auto setup() -> void override {}
    auto update() -> void override
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        unsigned int vao{0u};
        glGenVertexArrays(1, &vao);
        glDeleteVertexArrays(1, &vao);
    }
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
        gamedevkit::Application app;
        auto window = gamedevkit::WindowBuilder{"Package test", {100, 100}}.opengl_profile_core().context_version(4, 0).build();
        app.window(std::move(window)).game(std::make_shared<Game>()).renderer(std::make_shared<Renderer>()).setup();
        auto exit_thread = std::thread([]() {
            std::this_thread::sleep_for(std::chrono::milliseconds{500});
            std::exit(EXIT_SUCCESS);
        });
        return app.run();
    }
    catch (const std::runtime_error& err) {
        const std::string error_string{err.what()};
        std::cerr << error_string << std::endl;
        return error_string.find("The driver does not appear to support OpenGL") != error_string.npos ? EXIT_SUCCESS : EXIT_FAILURE;
    }
}
