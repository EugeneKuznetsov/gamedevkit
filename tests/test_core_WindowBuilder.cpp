#include <gtest/gtest.h>

#include <glfwcxx/WindowStub.hpp>
#include <glfwcxx/WindowHints.hpp>
#include <glfwcxx/WindowHelper.hpp>

#include <GDK/Window.hpp>
#include <GDK/WindowBuilder.hpp>

class gamedevkit_window_builder : public testing::Test {
public:
    auto SetUp() -> void
    {
        glfwcxx::WindowStub::reset();
        builder_ = std::make_unique<gamedevkit::WindowBuilder>();
    }

    auto applied_hints_count() const -> std::size_t
    {
        return glfwcxx::WindowStub::window_int_hint_applied_count() + glfwcxx::WindowStub::window_str_hint_applied_count();
    }

    std::unique_ptr<gamedevkit::WindowBuilder> builder_{nullptr};
};

TEST_F(gamedevkit_window_builder, successfully_builds_window_without_hints)
{
    ASSERT_NE(builder_->build(), nullptr);

    ASSERT_EQ(applied_hints_count(), 0);
}

TEST_F(gamedevkit_window_builder, successfully_builds_window_with_opengl_compat_profile_hint)
{
    ASSERT_NE(builder_->opengl_profile_compat().build(), nullptr);

    ASSERT_EQ(applied_hints_count(), 1);
    using namespace glfwcxx::helpers;
    EXPECT_TRUE(glfwcxx::WindowStub::window_int_hint_applied(glfw_hint_key(WindowHintsKeys::opengl_profile),
                                                             glfw_hint_value(glfwcxx::OpenGLProfile::compat)));
}

TEST_F(gamedevkit_window_builder, successfully_builds_window_with_opengl_core_profile_hint_overwriting_compat_profile)
{
    ASSERT_NE(builder_->opengl_profile_compat().opengl_profile_core().build(), nullptr);

    ASSERT_EQ(applied_hints_count(), 1);
    using namespace glfwcxx::helpers;
    EXPECT_TRUE(glfwcxx::WindowStub::window_int_hint_applied(glfw_hint_key(WindowHintsKeys::opengl_profile),
                                                             glfw_hint_value(glfwcxx::OpenGLProfile::core)));
}

TEST_F(gamedevkit_window_builder, successfully_builds_window_with_opengl_core_profile_and_context_version40_hint)
{
    ASSERT_NE(builder_->opengl_profile_core().context_version(4, 0).build(), nullptr);

    ASSERT_EQ(applied_hints_count(), 3);
    using namespace glfwcxx::helpers;
    EXPECT_TRUE(glfwcxx::WindowStub::window_int_hint_applied(glfw_hint_key(WindowHintsKeys::opengl_profile),
                                                             glfw_hint_value(glfwcxx::OpenGLProfile::core)));
    EXPECT_TRUE(glfwcxx::WindowStub::window_int_hint_applied(glfw_hint_key(WindowHintsKeys::context_version_major), 4));
    EXPECT_TRUE(glfwcxx::WindowStub::window_int_hint_applied(glfw_hint_key(WindowHintsKeys::context_version_minor), 0));
}
