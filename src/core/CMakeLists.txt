set(TARGET_NAME core)
set(SOURCES Application.cpp Window.cpp WindowBuilder.cpp KeyboardHelper.cpp AbstractGame.cpp)
set(DEPENDENCIES glfwcxx::core glfwcxx::window GLEW::GLEW)

add_gdk_target(
    NAME
    ${TARGET_NAME}
    SOURCES
    ${SOURCES}
    PRIVATE_DEPENDENCIES
    ${DEPENDENCIES}
    PRIVATE_COMPILE_DEFINITIONS
    "GLEW_STATIC"
    WITH_DETAILS)
install_gdk_target(TARGET_NAME ${TARGET_NAME})
