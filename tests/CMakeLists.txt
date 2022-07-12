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
    glfwcxx::window-stub)
