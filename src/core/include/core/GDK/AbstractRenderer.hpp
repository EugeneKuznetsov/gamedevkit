#pragma once

#include <memory>

namespace gamedevkit {

class AbstractGame;

class AbstractRenderer {
public:
    virtual ~AbstractRenderer() = default;

    virtual auto setup(std::shared_ptr<AbstractGame> game) -> void = 0;
    virtual auto render() -> void = 0;
};

}  // namespace gamedevkit
