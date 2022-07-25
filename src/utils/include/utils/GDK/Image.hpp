#pragma once

#include <memory>
#include <string>

namespace gamedevkit::utils {

class Image {
    class ImageDetails;

public:
    explicit Image(const std::string& filepath);
    ~Image();

public:
    auto width() const -> int;
    auto height() const -> int;
    auto data() const -> unsigned char*;

private:
    std::unique_ptr<ImageDetails> image_;
};

}  // namespace gamedevkit::utils
