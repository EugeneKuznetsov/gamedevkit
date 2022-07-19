#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <glfwcxx/CoreStub.hpp>
#include <glfwcxx/KeyboardHelper.hpp>
#include <glfwcxx/KeyboardInput.hpp>
#include <glfwcxx/WindowStub.hpp>

#include <GL/glew.h>

#include <GDK/AbstractGame.hpp>
#include <GDK/AbstractRenderer.hpp>
#include <GDK/Application.hpp>
#include <GDK/Keyboard.hpp>
#include <GDK/WindowBuilder.hpp>

namespace keyboard = gamedevkit::input::keyboard;
namespace windows = gamedevkit::windows;

class MockedGame : public gamedevkit::AbstractGame {
public:
    MOCK_METHOD(void, setup, (), (override));
    MOCK_METHOD(void, update, (), (override));
    MOCK_METHOD(void, input, (const keyboard::Key&, const keyboard::Action&, const std::set<keyboard::Modifier>&), (override));
};

class QuitEventGame : public gamedevkit::AbstractGame {
public:
    MOCK_METHOD(void, setup, (), (override));
    MOCK_METHOD(void, update, (), (override));
    MOCK_METHOD(void, input, (const keyboard::Key&, const keyboard::Action&, const std::set<keyboard::Modifier>&), (override));

    auto request_quit() -> void { quit(); }
};

class MockedRenderer : public gamedevkit::AbstractRenderer {
public:
    MOCK_METHOD(void, setup, (std::shared_ptr<gamedevkit::AbstractGame>), (override));
    MOCK_METHOD(void, render, (), (override));

    MOCK_METHOD(void, window_size, (const windows::WindowSize& new_window_size), (override));
    MOCK_METHOD(void, frame_buffer_size, (const windows::FrameBufferSize& new_frame_buffer_size), (override));
    MOCK_METHOD(void, window_content_scale, (const windows::WindowContentScale& new_window_content_scale), (override));
};

class gamedevkit_application : public testing::Test {
public:
    auto SetUp() -> void
    {
        gamedevkit::GlewStub::reset();
        glfwcxx::CoreStub::reset();
        glfwcxx::WindowStub::reset();
        application_ = std::make_unique<gamedevkit::Application>();
        window_ = gamedevkit::WindowBuilder{}.build("", {0, 0});
        game_ = std::make_shared<MockedGame>();
        renderer_ = std::make_shared<MockedRenderer>();
    }

    std::unique_ptr<gamedevkit::Application> application_{nullptr};
    std::unique_ptr<gamedevkit::Window> window_{nullptr};
    std::shared_ptr<MockedGame> game_{nullptr};
    std::shared_ptr<MockedRenderer> renderer_{nullptr};
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

TEST_F(gamedevkit_application, throws_runtime_error_when_game_was_not_set_before_setup)
{
    ASSERT_THROW(application_->window(std::move(window_)).setup(), std::runtime_error);
}

TEST_F(gamedevkit_application, throws_runtime_error_when_renderer_was_not_set_before_setup)
{
    ASSERT_THROW(application_->window(std::move(window_)).game(game_).setup(), std::runtime_error);
}

TEST_F(gamedevkit_application, throws_runtime_error_when_trying_to_run_application_without_window_and_game_and_renderer_setup)
{
    ASSERT_THROW(application_->run(), std::runtime_error);
}

TEST_F(gamedevkit_application, throws_runtime_error_when_gl_functions_were_not_initialized)
{
    gamedevkit::GlewStub::glew_init_return_value(GLEW_OK + 1u);
    application_->window(std::move(window_)).game(game_).renderer(renderer_);

    ASSERT_THROW(application_->setup(), std::runtime_error);
}

TEST_F(gamedevkit_application, throws_runtime_error_when_window_making_context_current_fails)
{
    glfwcxx::WindowStub::make_context_current_failure();
    application_->window(std::move(window_)).game(game_).renderer(renderer_);

    ASSERT_THROW(application_->setup(), std::runtime_error);
}

TEST_F(gamedevkit_application, successfully_configures_window_and_game_and_renderer_when_setup_invoked)
{
    EXPECT_CALL(*game_, setup).Times(testing::Exactly(1));
    EXPECT_CALL(*renderer_, setup(testing::_)).Times(testing::Exactly(1));

    ASSERT_NO_THROW(application_->window(std::move(window_)).game(game_).renderer(renderer_).setup());
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

    EXPECT_CALL(*game_, update).Times(testing::Exactly(1));
    EXPECT_CALL(*renderer_, render).Times(testing::Exactly(2));

    application_->window(std::move(window_)).game(game_).renderer(renderer_).setup();

    // TODO: it might stuck, move it to a separate thread of execution with timeout
    EXPECT_EQ(EXIT_SUCCESS, application_->run());
    EXPECT_EQ(expected_game_loops_count, glfwcxx::WindowStub::poll_events_call_count());
    EXPECT_EQ(expected_game_loops_count, glfwcxx::WindowStub::swap_buffers_call_count());
}

// TODO: can be parametrized test
TEST_F(gamedevkit_application, successfully_passes_pressed_alt_escape_keys_to_game)
{
    const auto actual_key = glfwcxx::input::KeyboardKey::key_escape;
    const auto actual_action = glfwcxx::input::KeyboardAction::press;
    const auto actual_modifier = glfwcxx::input::KeyboardKeyModifier::mod_alt;

    const auto expected_key = gamedevkit::input::keyboard::Key::key_escape;
    const auto expected_action = gamedevkit::input::keyboard::Action::press;
    const auto expected_modifier = gamedevkit::input::keyboard::Modifier::mod_alt;

    auto modifier_was_set = [&expected_modifier](const auto& mods) { return mods.find(expected_modifier) != mods.cend(); };

    EXPECT_CALL(*game_, input(testing::Eq(expected_key), testing::Eq(expected_action), testing::Truly(modifier_was_set)))
        .Times(testing::Exactly(1));

    application_->window(std::move(window_)).game(game_).renderer(renderer_).setup();
    glfwcxx::WindowStub::keyboard_input(glfwcxx::helpers::glfw_keyboard_key(actual_key),
                                        glfwcxx::helpers::glfw_keyboard_action(actual_action),
                                        {glfwcxx::helpers::glfw_keyboard_modifier(actual_modifier)});
}

TEST_F(gamedevkit_application, successfully_closes_window_on_game_exit_callback_request)
{
    const auto expected_game_loops_count = 0u;
    const auto maximum_game_loops_count = 2u;
    auto game_loop_count = 0u;
    glfwcxx::WindowStub::poll_events_call_callback([&game_loop_count, &maximum_game_loops_count]() -> void {
        game_loop_count++;
        if (maximum_game_loops_count == game_loop_count)
            glfwcxx::WindowStub::close_window();
    });

    auto quit_game_ = std::make_shared<QuitEventGame>();
    application_->window(std::move(window_)).game(quit_game_).renderer(renderer_).setup();
    quit_game_->request_quit();

    EXPECT_EQ(EXIT_SUCCESS, application_->run());
    EXPECT_EQ(glfwcxx::WindowStub::poll_events_call_count(), expected_game_loops_count);
}

TEST_F(gamedevkit_application, successfully_passes_window_size_property_to_renderer_during_setup)
{
    const int actual_width{10};
    const int actual_height{10};
    const auto expected_size = gamedevkit::windows::WindowSize{10, 10};

    EXPECT_CALL(*renderer_, window_size(testing::Eq(expected_size))).Times(testing::Exactly(1));

    glfwcxx::WindowStub::set_window_size(actual_width, actual_height);
    application_->window(std::move(window_)).game(game_).renderer(renderer_).setup();
}

TEST_F(gamedevkit_application, successfully_passes_window_size_property_to_renderer_after_setup)
{
    const int actual_width{15};
    const int actual_height{15};
    const auto expected_size = gamedevkit::windows::WindowSize{15, 15};

    EXPECT_CALL(*renderer_, window_size(testing::Eq(expected_size))).Times(testing::Exactly(2));

    glfwcxx::WindowStub::set_window_size(actual_width, actual_height);
    application_->window(std::move(window_)).game(game_).renderer(renderer_).setup();
    glfwcxx::WindowStub::notify_window_size();
}

TEST_F(gamedevkit_application, successfully_passes_frame_buffer_size_property_to_renderer_during_setup)
{
    const int actual_width{20};
    const int actual_height{20};
    const auto expected_size = gamedevkit::windows::FrameBufferSize{20, 20};

    EXPECT_CALL(*renderer_, frame_buffer_size(testing::Eq(expected_size))).Times(testing::Exactly(1));

    glfwcxx::WindowStub::set_frame_buffer_size(actual_width, actual_height);
    application_->window(std::move(window_)).game(game_).renderer(renderer_).setup();
}

TEST_F(gamedevkit_application, successfully_passes_frame_buffer_size_property_to_renderer_after_setup)
{
    const int actual_width{25};
    const int actual_height{25};
    const auto expected_size = gamedevkit::windows::FrameBufferSize{25, 25};

    EXPECT_CALL(*renderer_, frame_buffer_size(testing::Eq(expected_size))).Times(testing::Exactly(2));

    glfwcxx::WindowStub::set_frame_buffer_size(actual_width, actual_height);
    application_->window(std::move(window_)).game(game_).renderer(renderer_).setup();
    glfwcxx::WindowStub::notify_frame_buffer_size();
}

TEST_F(gamedevkit_application, successfully_passes_window_content_scale_property_to_renderer_during_setup)
{
    const float actual_xscale{30.0f};
    const float actual_yscale{30.0f};
    const auto expected_scale = gamedevkit::windows::WindowContentScale{30.0f, 30.0f};

    EXPECT_CALL(*renderer_, window_content_scale(testing::Eq(expected_scale))).Times(testing::Exactly(1));

    glfwcxx::WindowStub::set_window_content_scale(actual_xscale, actual_yscale);
    application_->window(std::move(window_)).game(game_).renderer(renderer_).setup();
}

TEST_F(gamedevkit_application, successfully_passes_window_content_scale_property_to_renderer_after_setup)
{
    const float actual_xscale{30.5f};
    const float actual_yscale{30.5f};
    const auto expected_scale = gamedevkit::windows::WindowContentScale{30.5f, 30.5f};

    EXPECT_CALL(*renderer_, window_content_scale(testing::Eq(expected_scale))).Times(testing::Exactly(2));

    glfwcxx::WindowStub::set_window_content_scale(actual_xscale, actual_yscale);
    application_->window(std::move(window_)).game(game_).renderer(renderer_).setup();
    glfwcxx::WindowStub::notify_window_content_scale();
}
