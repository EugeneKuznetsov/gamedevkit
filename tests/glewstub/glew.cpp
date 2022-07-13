#include "GL/glew.h"

extern auto glewInit() -> GLenum
{
    return gamedevkit::GlewStub::glew_init_return_value_;
}

extern auto glCreateShader(GLenum /*shaderType*/) -> GLuint
{
    return 0u;
}

extern auto glDeleteShader(GLuint /*shader*/) -> void {}

extern auto glShaderSource(GLuint /*shader*/, GLsizei /*count*/, const GLchar** /*string*/, const GLint* /*length*/) -> void {}

extern auto glCompileShader(GLuint /*shader*/) -> void {}

extern auto glGetShaderiv(GLuint /*shader*/, GLenum /*pname*/, GLint* /*params*/) -> void {}

extern auto glGetShaderInfoLog(GLuint /*shader*/, GLsizei /*maxLength*/, GLsizei* /*length*/, GLchar* /*infoLog*/) -> void {}

namespace gamedevkit {

unsigned int GlewStub::glew_init_return_value_ = GLEW_OK;

auto GlewStub::reset() -> void
{
    glew_init_return_value_ = GLEW_OK;
}

auto GlewStub::glew_init_return_value(const unsigned int value) -> void
{
    glew_init_return_value_ = value;
}

auto GlewStub::gl_create_shader_return_value(unsigned int /*value*/) -> void {}

auto GlewStub::gl_create_shader_call_arg() -> unsigned int
{
    return 0u;
}

auto GlewStub::gl_get_shader_iv_set_success(bool) -> void {}

auto GlewStub::gl_create_shader_call_count() -> int
{
    return 0;
}

auto GlewStub::gl_delete_shader_call_count() -> int
{
    return 0;
}

}  // namespace gamedevkit
