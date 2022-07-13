#pragma once

namespace glfwcxx::input {
enum class KeyboardKey;
enum class KeyboardKeyModifier;
enum class KeyboardAction;
}  // namespace glfwcxx::input

namespace gamedevkit {

namespace input::keyboard {
enum class Key;
enum class Action;
enum class Modifier;
}  // namespace input::keyboard

namespace helpers::input {

auto keyboard_key(const glfwcxx::input::KeyboardKey& key) -> gamedevkit::input::keyboard::Key;
auto keyboard_action(const glfwcxx::input::KeyboardAction& action) -> gamedevkit::input::keyboard::Action;
auto keyboard_modifier(const glfwcxx::input::KeyboardKeyModifier& modifier) -> gamedevkit::input::keyboard::Modifier;

}  // namespace helpers::input

}  // namespace gamedevkit
