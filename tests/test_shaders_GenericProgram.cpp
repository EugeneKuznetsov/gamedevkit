#include <gtest/gtest.h>

#include <GL/glew.h>

#include <GDK/GenericProgram.hpp>
#include <GDK/GenericShader.hpp>

class AnyShader final : public gamedevkit::shaders::GenericShader {
public:
    explicit AnyShader(const gamedevkit::shaders::Type& type = gamedevkit::shaders::Type::vertex)
        : gamedevkit::shaders::GenericShader{type}
    {
    }

    auto shader_source() const -> std::string override { return ""; }
};

class AnyProgram : public gamedevkit::shaders::GenericProgram {
public:
    auto vertex_shader() const -> std::unique_ptr<gamedevkit::shaders::GenericShader> override
    {
        return std::make_unique<AnyShader>(gamedevkit::shaders::Type::vertex);
    }

    auto fragment_shader() const -> std::unique_ptr<gamedevkit::shaders::GenericShader> override
    {
        return std::make_unique<AnyShader>(gamedevkit::shaders::Type::fragment);
    }
};

class InvalidVertexProgram final : public AnyProgram {
public:
    auto vertex_shader() const -> std::unique_ptr<gamedevkit::shaders::GenericShader> override { return nullptr; }
};

class InvalidFragmentProgram final : public AnyProgram {
public:
    auto fragment_shader() const -> std::unique_ptr<gamedevkit::shaders::GenericShader> override { return nullptr; }
};

class gamedevkit_generic_program : public testing::Test {
public:
    auto SetUp() -> void { gamedevkit::GlewStub::reset(); }
};

TEST_F(gamedevkit_generic_program, successfully_creates_and_destroys_program)
{
    ASSERT_EQ(gamedevkit::GlewStub::gl_create_program_call_count(), 0);
    ASSERT_EQ(gamedevkit::GlewStub::gl_delete_program_call_count(), 0);
    {
        AnyProgram{};
    }
    EXPECT_EQ(gamedevkit::GlewStub::gl_create_program_call_count(), 1);
    EXPECT_EQ(gamedevkit::GlewStub::gl_delete_program_call_count(), 1);
}

TEST_F(gamedevkit_generic_program, fails_building_program_when_vertex_shader_is_nullptr)
{
    EXPECT_THROW(InvalidVertexProgram{}.build(), std::runtime_error);
}

TEST_F(gamedevkit_generic_program, fails_building_program_when_fragment_shader_is_nullptr)
{
    EXPECT_THROW(InvalidFragmentProgram{}.build(), std::runtime_error);
}

TEST_F(gamedevkit_generic_program, fails_building_program_when_any_error_occurs)
{
    gamedevkit::GlewStub::gl_get_shader_iv_set_success(false);
    EXPECT_THROW(AnyProgram{}.build(), std::runtime_error);
}

TEST_F(gamedevkit_generic_program, successfully_builds_program)
{
    EXPECT_NO_THROW(AnyProgram{}.build());
}

TEST_F(gamedevkit_generic_program, successfully_activates_program)
{
    EXPECT_NO_THROW(AnyProgram{}.build().activate());
}

TEST_F(gamedevkit_generic_program, successfully_destroys_all_shaders_after_build)
{
    ASSERT_EQ(gamedevkit::GlewStub::gl_create_shader_call_count(), 0);
    ASSERT_EQ(gamedevkit::GlewStub::gl_delete_shader_call_count(), 0);
    AnyProgram{}.build();
    EXPECT_EQ(gamedevkit::GlewStub::gl_create_shader_call_count(), 2);
    EXPECT_EQ(gamedevkit::GlewStub::gl_delete_shader_call_count(), 2);
}

TEST_F(gamedevkit_generic_program, fails_activating_program_when_it_was_not_built)
{
    EXPECT_THROW(AnyProgram{}.activate(), std::runtime_error);
}
