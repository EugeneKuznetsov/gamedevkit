#include <chrono>
#include <future>

#include <gtest/gtest.h>

#include <glfwcxx/CoreStub.hpp>
#include <glfwcxx/WindowStub.hpp>

#include <GL/glew.h>

#include <GDK/Application.hpp>
#include <GDK/Window.hpp>

class gamedevkit_application : public testing::Test {
public:
    auto SetUp() -> void
    {
        glew_init_return_value_ = GLEW_OK;
        glfwcxx::CoreStub::reset();
        glfwcxx::WindowStub::reset();
        application_ = std::make_unique<gamedevkit::Application>();
        window_ = std::make_unique<gamedevkit::Window>();
    }

    std::unique_ptr<gamedevkit::Application> application_{nullptr};
    std::unique_ptr<gamedevkit::Window> window_{nullptr};

    inline static unsigned int glew_init_return_value_{GLEW_OK};
};

TEST_F(gamedevkit_application, throws_runtime_error_on_construction_when_glfwcxx_cannot_be_initialized)
{
    glfwcxx::CoreStub::init_failure();
    ASSERT_THROW(gamedevkit::Application{}, std::runtime_error);
    ASSERT_THROW((gamedevkit::Application{0, nullptr}), std::runtime_error);
}

TEST_F(gamedevkit_application, successfully_instantiated_when_glfwcxx_can_be_initialized)
{
    ASSERT_NO_THROW(gamedevkit::Application{});
    ASSERT_NO_THROW((gamedevkit::Application{0, nullptr}));
}

TEST_F(gamedevkit_application, throws_runtime_error_when_window_was_not_set_before_setup)
{
    ASSERT_THROW(application_->setup(), std::runtime_error);
}

TEST_F(gamedevkit_application, throws_runtime_error_when_window_making_context_current_fails)
{
    glfwcxx::WindowStub::make_context_current_failure();
    application_->window(std::move(window_));
    ASSERT_THROW(application_->setup(), std::runtime_error);
}

TEST_F(gamedevkit_application, throws_runtime_error_when_gl_functions_were_not_initialized)
{
    glew_init_return_value_ = GLEW_OK + 1u;
    application_->window(std::move(window_));
    ASSERT_THROW(application_->setup(), std::runtime_error);
}

TEST_F(gamedevkit_application, successfully_configures_window_when_setup_invoked)
{
    ASSERT_NO_THROW(application_->window(std::move(window_)).setup());
}

TEST_F(gamedevkit_application, successfully_runs_two_game_loops_and_returns_exit_success_when_window_should_close)
{
    const auto expected_game_loops_count = 2u;
    auto game_loop_count = 0u;
    glfwcxx::WindowStub::poll_events_call_callback([&game_loop_count, &expected_game_loops_count]() -> void {
        game_loop_count++;
        if (expected_game_loops_count == game_loop_count)
            glfwcxx::WindowStub::close_window();
    });

    application_->window(std::move(window_)).setup();
    auto test_case = std::async(std::launch::async, [&app = application_]() -> int { return app->run(); });

    using namespace std::chrono_literals;
    ASSERT_EQ(std::future_status::ready, test_case.wait_for(1s));
    EXPECT_EQ(EXIT_SUCCESS, test_case.get());
    EXPECT_EQ(expected_game_loops_count, glfwcxx::WindowStub::poll_events_call_count());
    EXPECT_EQ(expected_game_loops_count, glfwcxx::WindowStub::swap_buffers_call_count());
}

auto glewInit() -> unsigned int
{
    return gamedevkit_application::glew_init_return_value_;
}
