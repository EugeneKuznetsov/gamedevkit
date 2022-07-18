#include "GDK/AbstractGame.hpp"

namespace gamedevkit {

auto AbstractGame::on_quit(const quit_callback& callback) -> void
{
    quit_callbacks_.push_back(callback);
}

auto AbstractGame::quit() -> void
{
    for (const auto& callback : quit_callbacks_)
        callback();
}

}  // namespace gamedevkit
