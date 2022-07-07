#include <gtest/gtest.h>

#include <glfwcxx/WindowStub.hpp>

#include <GDK/Window.hpp>

class gamedevkit_window : public testing::Test {
public:
    auto SetUp() -> void
    {
        glfwcxx::WindowStub::reset();
        window_ = std::make_unique<gamedevkit::Window>("", gamedevkit::WindowResolution{100, 100});
    }

    std::unique_ptr<gamedevkit::Window> window_{nullptr};
};

TEST_F(gamedevkit_window, throws_runtime_error_when_window_making_context_current_fails)
{
    glfwcxx::WindowStub::make_context_current_failure();
    ASSERT_THROW(window_->activate(), std::runtime_error);
}

TEST_F(gamedevkit_window, successfully_makes_context_current_when_activated)
{
    ASSERT_NO_THROW(window_->activate());
}
