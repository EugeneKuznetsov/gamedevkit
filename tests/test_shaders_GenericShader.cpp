#include <gtest/gtest.h>

#include <GL/glew.h>

#include <GDK/GenericShader.hpp>

class VertexShader final : public gamedevkit::GenericShader {
public:
};

class FragmentShader final : public gamedevkit::GenericShader {
public:
};

class gamedevkit_generic_shader : public testing::Test {
public:
    auto SetUp() -> void { gamedevkit::GlewStub::reset(); }
};

TEST_F(gamedevkit_generic_shader, successfully_creates_and_destroys_vertex_shader)
{
    ASSERT_FALSE(true);
}

TEST_F(gamedevkit_generic_shader, successfully_creates_and_destroys_fragment_shader)
{
    ASSERT_FALSE(true);
}

TEST_F(gamedevkit_generic_shader, successfully_compiles_shader)
{
    ASSERT_FALSE(true);
}

TEST_F(gamedevkit_generic_shader, fails_compiling_shader_when_any_error_occurs)
{
    ASSERT_FALSE(true);
}
