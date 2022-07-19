#pragma once

#include <memory>

#include <GDK/WindowPropertiesSubscriber.hpp>

namespace gamedevkit {

class AbstractGame;

class AbstractRenderer : public windows::WindowPropertiesSubscriber {
public:
    virtual ~AbstractRenderer() = default;

    virtual auto setup(std::shared_ptr<AbstractGame> game) -> void = 0;
    virtual auto render() -> void = 0;
};

}  // namespace gamedevkit
