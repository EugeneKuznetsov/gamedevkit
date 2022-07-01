#include <gtest/gtest.h>

#include <glfwcxx/CoreStub.hpp>

#include <GDK/Application.hpp>

class gamedevkit_application : public testing::Test {
public:
    auto SetUp() -> void
    {
        glfwcxx::CoreStub::reset();
        application_ = std::make_unique<gamedevkit::Application>();
    }

private:
    std::unique_ptr<gamedevkit::Application> application_{nullptr};
};

TEST_F(gamedevkit_application, throws_runtime_error_when_glfwcxx_cannot_be_initialized)
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
