#pragma once

#include <set>

namespace gamedevkit {

namespace input::keyboard {
enum class Key;
enum class Action;
enum class Modifier;
}  // namespace input::keyboard

class AbstractGame {
public:
    virtual ~AbstractGame() = default;

    virtual auto setup() -> void = 0;
    virtual auto update() -> void = 0;
    virtual auto input(const input::keyboard::Key& key,
                       const input::keyboard::Action& acction,
                       const std::set<input::keyboard::Modifier>& modifiers) -> void = 0;
};

}  // namespace gamedevkit
