#include <gtest/gtest.h>

#include <GDK/Image.hpp>

TEST(image_loader, successfully_loads_an_existing_png_image)
{
    const auto image = gamedevkit::utils::Image{IMAGE_LOADER_EXISTING_PNG_IMAGE};
    EXPECT_EQ(image.width(), 101);
    EXPECT_EQ(image.height(), 95);
    EXPECT_NE(image.data(), nullptr);
}

TEST(image_loader, throws_runtime_error_when_trying_to_load_not_supported_existing_image)
{
    EXPECT_THROW(gamedevkit::utils::Image{IMAGE_LOADER_EXISTING_JPEG_IMAGE}, std::runtime_error);
}

TEST(image_loader, throws_runtime_error_when_trying_to_load_non_existing_image)
{
    EXPECT_THROW(gamedevkit::utils::Image{"non_existing_image"}, std::runtime_error);
}
