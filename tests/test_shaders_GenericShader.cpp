#include <gtest/gtest.h>

#include <GL/glew.h>

#include <GDK/GenericShader.hpp>

class AnyShader final : public gamedevkit::shaders::GenericShader {
public:
    AnyShader(const gamedevkit::shaders::Type& type = gamedevkit::shaders::Type::vertex)
        : gamedevkit::shaders::GenericShader{type}
    {
    }
};

class gamedevkit_generic_shader : public testing::Test {
public:
    auto SetUp() -> void { gamedevkit::GlewStub::reset(); }
};

TEST_F(gamedevkit_generic_shader, successfully_creates_and_destroys_vertex_shader)
{
    ASSERT_EQ(gamedevkit::GlewStub::gl_create_shader_call_count(), 0);
    ASSERT_EQ(gamedevkit::GlewStub::gl_delete_shader_call_count(), 0);
    {
        AnyShader shader{gamedevkit::shaders::Type::vertex};
        EXPECT_EQ(gamedevkit::GlewStub::gl_create_shader_call_arg(), GL_VERTEX_SHADER);
    }
    EXPECT_EQ(gamedevkit::GlewStub::gl_create_shader_call_count(), 1);
    EXPECT_EQ(gamedevkit::GlewStub::gl_delete_shader_call_count(), 1);
}

TEST_F(gamedevkit_generic_shader, successfully_creates_and_destroys_fragment_shader)
{
    ASSERT_EQ(gamedevkit::GlewStub::gl_create_shader_call_count(), 0);
    ASSERT_EQ(gamedevkit::GlewStub::gl_delete_shader_call_count(), 0);
    {
        AnyShader shader{gamedevkit::shaders::Type::fragment};
        EXPECT_EQ(gamedevkit::GlewStub::gl_create_shader_call_arg(), GL_FRAGMENT_SHADER);
    }
    EXPECT_EQ(gamedevkit::GlewStub::gl_create_shader_call_count(), 1);
    EXPECT_EQ(gamedevkit::GlewStub::gl_delete_shader_call_count(), 1);
}

TEST_F(gamedevkit_generic_shader, fails_creating_shader_when_any_error_occurs)
{
    gamedevkit::GlewStub::gl_create_shader_return_value(0u);
    EXPECT_THROW(AnyShader{}, std::runtime_error);
}

TEST_F(gamedevkit_generic_shader, successfully_compiles_shader)
{
    AnyShader shader;
    EXPECT_NO_THROW(shader.compile());
}

TEST_F(gamedevkit_generic_shader, fails_compiling_shader_when_any_error_occurs)
{
    gamedevkit::GlewStub::gl_get_shader_iv_set_success(false);
    AnyShader shader;
    EXPECT_THROW(shader.compile(), std::runtime_error);
}
