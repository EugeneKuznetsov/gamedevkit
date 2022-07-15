#include "GL/glew.h"

extern auto glewInit() -> GLenum
{
    return gamedevkit::GlewStub::glew_init_return_value_;
}

extern auto glCreateShader(GLenum shaderType) -> GLuint
{
    gamedevkit::GlewStub::gl_create_shader_call_count_++;
    gamedevkit::GlewStub::gl_create_shader_call_arg_ = shaderType;
    return gamedevkit::GlewStub::gl_create_shader_return_value_;
}

extern auto glDeleteShader(GLuint /*shader*/) -> void
{
    gamedevkit::GlewStub::gl_delete_shader_call_count_++;
}

extern auto glShaderSource(GLuint /*shader*/, GLsizei /*count*/, const GLchar** /*string*/, const GLint* /*length*/) -> void {}

extern auto glCompileShader(GLuint /*shader*/) -> void {}

extern auto glGetShaderiv(GLuint /*shader*/, GLenum /*pname*/, GLint* params) -> void
{
    *params = gamedevkit::GlewStub::gl_get_shader_iv_set_success_ ? 1 : 0;
}

extern auto glGetShaderInfoLog(GLuint /*shader*/, GLsizei /*maxLength*/, GLsizei* /*length*/, GLchar* infoLog) -> void
{
    *infoLog = '\0';
}

namespace gamedevkit {

GLenum GlewStub::glew_init_return_value_ = GLEW_OK;
GLuint GlewStub::gl_create_shader_return_value_ = 1u;
GLenum GlewStub::gl_create_shader_call_arg_ = 0u;
int GlewStub::gl_create_shader_call_count_ = 0;
int GlewStub::gl_delete_shader_call_count_ = 0;
bool GlewStub::gl_get_shader_iv_set_success_ = true;

auto GlewStub::reset() -> void
{
    glew_init_return_value_ = GLEW_OK;
    gl_create_shader_return_value_ = 1u;
    gl_create_shader_call_arg_ = 0u;
    gl_create_shader_call_count_ = 0;
    gl_delete_shader_call_count_ = 0;
    gl_get_shader_iv_set_success_ = true;
}

auto GlewStub::glew_init_return_value(GLenum value) -> void
{
    glew_init_return_value_ = value;
}

auto GlewStub::gl_create_shader_return_value(GLuint value) -> void
{
    gl_create_shader_return_value_ = value;
}

auto GlewStub::gl_create_shader_call_arg() -> GLenum
{
    return gl_create_shader_call_arg_;
}

auto GlewStub::gl_get_shader_iv_set_success(bool success) -> void
{
    gl_get_shader_iv_set_success_ = success;
}

auto GlewStub::gl_create_shader_call_count() -> int
{
    return gl_create_shader_call_count_;
}

auto GlewStub::gl_delete_shader_call_count() -> int
{
    return gl_delete_shader_call_count_;
}

auto GlewStub::gl_create_program_call_count() -> int
{
    return 0;
}

auto GlewStub::gl_delete_program_call_count() -> int
{
    return 0;
}

}  // namespace gamedevkit
