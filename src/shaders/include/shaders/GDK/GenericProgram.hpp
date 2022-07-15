#pragma once

#include <string>
#include <memory>

namespace gamedevkit::shaders {

class GenericShader;

class GenericProgram {
    GenericProgram(const GenericProgram&) = delete;
    GenericProgram(GenericProgram&&) = delete;
    GenericProgram& operator=(const GenericProgram&) = delete;
    GenericProgram& operator=(GenericProgram&&) = delete;

public:
    explicit GenericProgram();
    virtual ~GenericProgram();

public:
    inline auto object_id() const -> const auto { return object_id_; }

public:
    auto build() -> GenericProgram&;
    auto activate() -> GenericProgram&;

protected:
    virtual auto vertex_shader() const -> std::unique_ptr<GenericShader> = 0;
    virtual auto fragment_shader() const -> std::unique_ptr<GenericShader> = 0;

private:
    auto raise_link_errors() const -> void;

private:
    unsigned int object_id_;
    bool was_built_already_;
};

}  // namespace gamedevkit::shaders
