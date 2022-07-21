#include "GDK/KeyboardInputSubscriber.hpp"

namespace gamedevkit::input {

auto KeyboardInputSubscriber::input(const input::keyboard::Key& /*key*/,
                                    const input::keyboard::Action& /*action*/,
                                    const std::set<input::keyboard::Modifier>& /*modifiers*/) -> void
{
}

}  // namespace gamedevkit::input
