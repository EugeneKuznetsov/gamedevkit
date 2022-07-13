#include "GDK/GenericShader.hpp"

#include <sstream>
#include <stdexcept>

#include <GL/glew.h>

#include "ShadersHelper.hpp"

namespace gamedevkit::shaders {

GenericShader::GenericShader(const Type& type)
    : object_id_{glCreateShader(gamedevkit::helpers::shaders::gl_shader_type(type))}
{
    if (0u == object_id_)
        throw std::runtime_error("Failed to create GenericShader");
}

GenericShader::~GenericShader()
{
    glDeleteShader(object_id_);
}

auto GenericShader::compile() -> GenericShader&
{
    const auto shader_str = shader_source();
    const auto source = &shader_str[0];
    glShaderSource(object_id_, 1, const_cast<const char**>(&source), nullptr);
    glCompileShader(object_id_);

    raise_compile_errors();

    return *this;
}

auto GenericShader::raise_compile_errors() const -> void
{
    auto success{0};
    glGetShaderiv(object_id_, GL_COMPILE_STATUS, &success);
    if (success)
        return;

    char compile_error[1024];
    glGetShaderInfoLog(object_id_, sizeof(compile_error), nullptr, compile_error);

    std::stringstream error_stream;
    error_stream << "shader compilation error" << std::endl;
    error_stream << "-------------------------" << std::endl;
    error_stream << compile_error << std::endl;

    throw std::runtime_error(error_stream.str());
}

}  // namespace gamedevkit::shaders
