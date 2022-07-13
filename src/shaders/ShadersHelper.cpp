#include "ShadersHelper.hpp"

#include "GDK/GenericShader.hpp"

namespace gamedevkit::helpers::shaders {

auto gl_shader_type(const gamedevkit::shaders::Type& type) -> GLenum
{
    switch (type) {
        case gamedevkit::shaders::Type::vertex:
            return GL_VERTEX_SHADER;
        case gamedevkit::shaders::Type::fragment:
            return GL_FRAGMENT_SHADER;
        default:
            return 0u;
    }
}

}  // namespace gamedevkit::helpers::shaders
