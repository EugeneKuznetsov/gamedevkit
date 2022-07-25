#pragma once

#include <memory>
#include <string>

#include <GDK/Image.hpp>

namespace gamedevkit::utils {

class ImageLoader {
public:
    static auto load(const std::string& filepath) -> std::unique_ptr<Image>;
};

}  // namespace gamedevkit::utils
