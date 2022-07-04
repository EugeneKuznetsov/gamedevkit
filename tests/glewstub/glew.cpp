#include "GL/glew.h"

extern auto glewInit() -> GLenum
{
    return gamedevkit::GlewStub::glew_init_return_value_;
}

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

}  // namespace gamedevkit
