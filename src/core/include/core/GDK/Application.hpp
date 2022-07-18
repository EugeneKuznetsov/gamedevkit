#pragma once

#include <memory>
#include <string>

namespace gamedevkit {

class AbstractGame;
class AbstractRenderer;
class Window;

class Application final {
    Application(const Application&) = delete;
    Application(Application&&) = delete;
    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&) = delete;

public:
    explicit Application();
    explicit Application(int argc, char* argv[]);
    ~Application();

public:
    auto window(std::unique_ptr<Window> window) -> Application&;
    auto game(std::shared_ptr<AbstractGame> game) -> Application&;
    auto renderer(std::unique_ptr<AbstractRenderer> renderer) -> Application&;

public:
    auto setup() -> void;
    auto run() -> int;

private:
    auto check_application_readiness(const std::string& stage) -> void;

private:
    class Details;
    const std::unique_ptr<Details> details_;

    std::unique_ptr<Window> window_;
    std::shared_ptr<AbstractGame> game_;
    std::unique_ptr<AbstractRenderer> renderer_;
};

}  // namespace gamedevkit
