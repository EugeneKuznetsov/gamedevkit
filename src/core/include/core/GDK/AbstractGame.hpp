#pragma once

#include <GDK/KeyboardInputSubscriber.hpp>

namespace gamedevkit {

class AbstractGame : public input::KeyboardInputSubscriber {
public:
    virtual ~AbstractGame() = default;

    virtual auto setup() -> void = 0;
    virtual auto update() -> void = 0;

protected:
    auto quit() -> void;
};

}  // namespace gamedevkit
