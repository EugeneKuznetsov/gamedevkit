#pragma once

#include <memory>

namespace gamedevkit {

class AbstractGame;
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
    auto game(std::unique_ptr<AbstractGame> game) -> Application&;

public:
    auto setup() -> void;
    auto run() -> int;

private:
    class Details;
    const std::unique_ptr<Details> details_;

    std::unique_ptr<Window> window_;
};

}  // namespace gamedevkit
