#pragma once

#include <memory>

namespace gamedevkit {

class Application final {
    Application(const Application&) = delete;
    Application(Application&&) = delete;
    Application& operator=(const Application&) = delete;
    Application& operator=(Application&&) = delete;

public:
    explicit Application();
    explicit Application(int argc, char* argv[]);
    ~Application();

private:
    class Details;
    const std::unique_ptr<Details> details_;
};

}  // namespace gamedevkit
