#pragma once

#include <string>

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
    inline auto object_id() const -> const auto { return object_id_; }

public:
    auto compile() -> GenericShader&;

protected:
    virtual auto shader_source() const -> std::string = 0;

private:
    auto raise_compile_errors() const -> void;

private:
    unsigned int object_id_;
};

}  // namespace gamedevkit::shaders
