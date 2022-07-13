#pragma once

#include <set>

namespace gamedevkit::input {

namespace keyboard {
enum class Key;
enum class Action;
enum class Modifier;
}  // namespace keyboard

class KeyboardInputSubscriber {
public:
    virtual ~KeyboardInputSubscriber() = default;

    virtual auto input(const input::keyboard::Key& key,
                       const input::keyboard::Action& action,
                       const std::set<input::keyboard::Modifier>& modifiers) -> void = 0;
};

}  // namespace gamedevkit::input
