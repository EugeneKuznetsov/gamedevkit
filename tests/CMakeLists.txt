add_subdirectory(glewstub)

include(TestUtils)

add_test_suite(
    NAME
    test_core_Application
    TARGET_UNDER_TEST
    core
    TEST_SUITE_DEPENDENCY_LIBS
    glfwcxx::core-stub
    glfwcxx::window-stub
    TARGET_UNDER_TEST_STUB_LIBS
    glewstub)

add_test_suite(
    NAME
    test_core_WindowBuilder
    TARGET_UNDER_TEST
    core
    TEST_SUITE_DEPENDENCY_LIBS
    glfwcxx::core-stub
    glfwcxx::window-stub
    TARGET_UNDER_TEST_STUB_LIBS
    glewstub)

add_test_suite(NAME test_shaders_GenericShader TARGET_UNDER_TEST shaders
               TARGET_UNDER_TEST_STUB_LIBS glewstub)

add_test_suite(NAME test_shaders_GenericProgram TARGET_UNDER_TEST shaders
               TARGET_UNDER_TEST_STUB_LIBS glewstub)

add_test_suite(NAME test_utils_ImageLoader TARGET_UNDER_TEST utils TARGET_UNDER_TEST_STUB_LIBS
               pngpp::pngpp)
set(EXISTING_PNG_IMAGE_DEFINITION
    "IMAGE_LOADER_EXISTING_PNG_IMAGE=\"${CMAKE_CURRENT_LIST_DIR}/testdata/image.png\"")
set(EXISTING_JPEG_IMAGE_DEFINITION
    "IMAGE_LOADER_EXISTING_JPEG_IMAGE=\"${CMAKE_CURRENT_LIST_DIR}/testdata/image.jpeg\"")
target_compile_definitions(test_utils_ImageLoader PRIVATE ${EXISTING_PNG_IMAGE_DEFINITION}
                                                          ${EXISTING_JPEG_IMAGE_DEFINITION})
