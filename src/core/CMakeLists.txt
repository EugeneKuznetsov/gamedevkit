set(TARGET_NAME core)
set(TARGET_SOURCES
    Application.cpp
    Window.cpp
    WindowBuilder.cpp
    KeyboardHelper.cpp
    AbstractGame.cpp
    WindowPropertiesSubscriber.cpp
    KeyboardInputSubscriber.cpp)
set(TARGET_DEPENDENCIES "PRIVATE glfwcxx::core" "PRIVATE glfwcxx::window" "PRIVATE GLEW::GLEW")

add_gdk_target(${TARGET_NAME} TARGET_SOURCES ${TARGET_SOURCES} TARGET_DEPENDENCIES
               ${TARGET_DEPENDENCIES})
install_gdk_target(${TARGET_NAME})
