add_subdirectory(glewstub)

include(TestUtils)

add_test_suite(
    NAME
    test_core_Application
    TARGET_UNDER_TEST
    core
    DEPENDENCY_LIBS
    glfwcxx::core-stub
    glfwcxx::window-stub)
