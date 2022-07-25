#include "GDK/Image.hpp"

#include <png++/png.hpp>

namespace gamedevkit::utils {

auto Image::width() const -> int
{
    return 0;
}

auto Image::height() const -> int
{
    return 0;
}

auto Image::data() const -> unsigned char*
{
    return nullptr;
}

}  // namespace gamedevkit::utils
