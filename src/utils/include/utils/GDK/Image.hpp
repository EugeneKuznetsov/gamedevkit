#pragma once

namespace gamedevkit::utils {

class Image {
public:
    auto width() const -> int;
    auto height() const -> int;
    auto data() const -> unsigned char*;
};

}  // namespace gamedevkit::utils
