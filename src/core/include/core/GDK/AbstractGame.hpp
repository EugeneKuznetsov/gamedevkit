#pragma once

#include <functional>
#include <list>

#include <GDK/KeyboardInputSubscriber.hpp>

namespace gamedevkit {

class AbstractGame : public input::KeyboardInputSubscriber {
    using quit_callback = std::function<void()>;

public:
    virtual ~AbstractGame() = default;

    virtual auto setup() -> void = 0;
    virtual auto update() -> void = 0;

    auto on_quit(const quit_callback& callback) -> void;

protected:
    auto quit() -> void;

private:
    std::list<quit_callback> quit_callbacks_{};
};

}  // namespace gamedevkit
