set(TARGET_NAME core)
set(SOURCES Application.cpp)
set(LIBS glfwcxx::core glfwcxx::window)

add_gdk_target(
    NAME
    ${TARGET_NAME}
    SOURCES
    ${SOURCES}
    PRIVATE_LIBS
    ${LIBS}
    WITH_DETAILS)
