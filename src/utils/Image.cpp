#include "GDK/Image.hpp"

#if defined(_MSC_VER)
#include <png++/png.hpp>
#elif defined(__GNUC__) || defined(__GNUG__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <png++/png.hpp>
#pragma GCC diagnostic pop
#endif

namespace gamedevkit::utils {

class Image::ImageDetails {
    using image_bytes_t = unsigned char;

public:
    explicit ImageDetails(const std::string& filepath);
    ~ImageDetails();

    auto data() const -> image_bytes_t*;

public:
    png::image<png::rgba_pixel, png::solid_pixel_buffer<png::rgba_pixel>> png_;

private:
    image_bytes_t* data_;
};

Image::Image(const std::string& filepath)
    : image_{std::make_unique<ImageDetails>(filepath)}
{
}

Image::~Image() = default;

auto Image::width() const -> int
{
    return image_->png_.get_width();
}

auto Image::height() const -> int
{
    return image_->png_.get_height();
}

auto Image::data() const -> unsigned char*
{
    return image_->data();
}

Image::ImageDetails::ImageDetails(const std::string& filepath)
    : png_{filepath}
    , data_{nullptr}
{
    const auto& bytes = png_.get_pixbuf().get_bytes();
    data_ = new image_bytes_t[bytes.size()];
    auto data_ptr = data_;
    for (const auto& byte : bytes)
        *(data_ptr++) = byte;
}

Image::ImageDetails::~ImageDetails()
{
    delete[] data_;
}

auto Image::ImageDetails::data() const -> Image::ImageDetails::image_bytes_t*
{
    return data_;
}

}  // namespace gamedevkit::utils
