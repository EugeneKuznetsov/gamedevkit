#pragma once

using GLenum = unsigned int;
using GLuint = unsigned int;
using GLsizei = int;
using GLint = int;
using GLchar = char;

static unsigned int gl_vars = 0u;
static const unsigned int GL_COMPILE_STATUS = gl_vars++;
static const unsigned int GL_FRAGMENT_SHADER = gl_vars++;
static const unsigned int GL_VERTEX_SHADER = gl_vars++;
static const unsigned int GLEW_OK = gl_vars++;
static const unsigned int GL_LINK_STATUS = gl_vars++;

extern auto glewInit() -> GLenum;
extern auto glCreateShader(GLenum shaderType) -> GLuint;
extern auto glDeleteShader(GLuint shader) -> void;
extern auto glShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length) -> void;
extern auto glCompileShader(GLuint shader) -> void;
extern auto glGetShaderiv(GLuint shader, GLenum pname, GLint* params) -> void;
extern auto glGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog) -> void;
extern auto glCreateProgram() -> GLuint;
extern auto glDeleteProgram(GLuint program) -> void;
extern auto glAttachShader(GLuint program, GLuint shader) -> void;
extern auto glLinkProgram(GLuint program) -> void;
extern auto glUseProgram(GLuint program) -> void;
extern auto glGetProgramiv(GLuint shader, GLenum pname, GLint* params) -> void;
extern auto glGetProgramInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog) -> void;

namespace gamedevkit {
class GlewStub {
public:
    static auto reset() -> void;

    static auto glew_init_return_value(GLenum value) -> void;

    static auto gl_create_shader_return_value(GLuint value) -> void;
    static auto gl_create_shader_call_arg() -> GLenum;

    static auto gl_create_program_return_value(GLuint value) -> void;

    static auto gl_get_shader_iv_set_success(bool success) -> void;
    static auto gl_get_program_iv_set_success(bool success) -> void;

public:
    static auto gl_create_shader_call_count() -> int;
    static auto gl_delete_shader_call_count() -> int;
    static auto gl_create_program_call_count() -> int;
    static auto gl_delete_program_call_count() -> int;

private:
    static GLenum glew_init_return_value_;
    static GLuint gl_create_shader_return_value_;
    static GLenum gl_create_shader_call_arg_;
    static GLuint gl_create_program_return_value_;
    static int gl_create_shader_call_count_;
    static int gl_delete_shader_call_count_;
    static int gl_create_program_call_count_;
    static int gl_delete_program_call_count_;
    static bool gl_get_shader_iv_set_success_;
    static bool gl_get_program_iv_set_success_;

    friend auto ::glewInit() -> GLenum;
    friend auto ::glCreateShader(GLenum shaderType) -> GLuint;
    friend auto ::glDeleteShader(GLuint shader) -> void;
    friend auto ::glShaderSource(GLuint shader, GLsizei count, const GLchar** string, const GLint* length) -> void;
    friend auto ::glCompileShader(GLuint shader) -> void;
    friend auto ::glGetShaderiv(GLuint shader, GLenum pname, GLint* params) -> void;
    friend auto ::glGetShaderInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog) -> void;
    friend auto ::glCreateProgram() -> GLuint;
    friend auto ::glDeleteProgram(GLuint program) -> void;
    friend auto ::glAttachShader(GLuint program, GLuint shader) -> void;
    friend auto ::glLinkProgram(GLuint program) -> void;
    friend auto ::glUseProgram(GLuint program) -> void;
    friend auto ::glGetProgramiv(GLuint shader, GLenum pname, GLint* params) -> void;
    friend auto ::glGetProgramInfoLog(GLuint shader, GLsizei maxLength, GLsizei* length, GLchar* infoLog) -> void;
};

}  // namespace gamedevkit
