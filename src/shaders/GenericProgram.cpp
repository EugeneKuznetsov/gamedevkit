#include "GDK/GenericProgram.hpp"

#include <sstream>

#include <GL/glew.h>

#include "GDK/GenericShader.hpp"

namespace gamedevkit::shaders {

GenericProgram::GenericProgram()
    : object_id_{glCreateProgram()}
    , was_built_already_{false}
{
    if (0u == object_id_)
        throw std::runtime_error("Failed to create Program");
}

GenericProgram::~GenericProgram()
{
    glDeleteProgram(object_id_);
}

auto GenericProgram::build() -> GenericProgram&
{
    auto program_vertex_shader{vertex_shader()};
    auto program_fragment_shader{fragment_shader()};

    if (nullptr == program_vertex_shader)
        throw std::runtime_error("Vertex shader was not instantiated");

    if (nullptr == program_fragment_shader)
        throw std::runtime_error("Fragment shader was not instantiated");

    glAttachShader(object_id_, program_vertex_shader->compile().object_id());
    glAttachShader(object_id_, program_fragment_shader->compile().object_id());
    glLinkProgram(object_id_);

    raise_link_errors();

    was_built_already_ = true;

    return *this;
}

auto GenericProgram::activate() -> GenericProgram&
{
    if (false == was_built_already_)
        throw std::runtime_error("Program cannot be activated without building it first");

    glUseProgram(object_id_);

    return *this;
}

auto GenericProgram::raise_link_errors() const -> void
{
    auto success{0};
    glGetProgramiv(object_id_, GL_LINK_STATUS, &success);
    if (success)
        return;

    char link_error[1024];
    glGetProgramInfoLog(object_id_, sizeof(link_error), nullptr, link_error);

    std::stringstream error_stream;
    error_stream << "program linkage error" << std::endl;
    error_stream << "---------------------" << std::endl;
    error_stream << link_error << std::endl;

    throw std::runtime_error(error_stream.str());
}

}  // namespace gamedevkit::shaders
