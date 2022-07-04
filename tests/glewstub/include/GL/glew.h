#pragma once

typedef unsigned int GLenum;

static constexpr unsigned int GLEW_OK = 0;

extern auto glewInit() -> GLenum;

namespace gamedevkit {

class GlewStub {
public:
    static auto reset() -> void;

    static auto glew_init_return_value(const unsigned int value) -> void;

private:
    static unsigned int glew_init_return_value_;

    friend auto ::glewInit() -> GLenum;
};

}  // namespace gamedevkit
