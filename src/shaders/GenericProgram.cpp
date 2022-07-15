#include "GDK/GenericProgram.hpp"

namespace gamedevkit::shaders {

GenericProgram::GenericProgram()
    : object_id_{0u}
{
}

GenericProgram::~GenericProgram() {}

auto GenericProgram::build() -> GenericProgram&
{
    return *this;
}

auto GenericProgram::activate() -> GenericProgram&
{
    return *this;
}

auto GenericProgram::raise_link_errors() const -> void {}

}  // namespace gamedevkit::shaders
