#pragma once

namespace gamedevkit {

class AbstractGame {
public:
    virtual ~AbstractGame() = default;

    virtual auto setup() -> void = 0;
    virtual auto update() -> void = 0;
};

}  // namespace gamedevkit
