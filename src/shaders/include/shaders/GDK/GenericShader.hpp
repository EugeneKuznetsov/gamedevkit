#pragma once

namespace gamedevkit::shaders {

enum class Type { vertex, fragment };

class GenericShader {
    GenericShader(const GenericShader&) = delete;
    GenericShader(GenericShader&&) = delete;
    GenericShader& operator=(const GenericShader&) = delete;
    GenericShader& operator=(GenericShader&&) = delete;

public:
    explicit GenericShader(const Type& type);
    virtual ~GenericShader();

public:
    auto compile() -> void;
};

}  // namespace gamedevkit::shaders
