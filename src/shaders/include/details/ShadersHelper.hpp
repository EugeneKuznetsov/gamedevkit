#pragma once

#include <GL/glew.h>

namespace gamedevkit {

namespace shaders {
enum class Type;
}

namespace helpers::shaders {

auto gl_shader_type(const gamedevkit::shaders::Type& type) -> GLenum;

}

}  // namespace gamedevkit
