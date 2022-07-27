set(TARGET_NAME shaders)
set(TARGET_SOURCES GenericShader.cpp GenericProgram.cpp ShadersHelper.cpp)
set(TARGET_DEPENDENCIES "PRIVATE GLEW::GLEW")

add_gdk_target(${TARGET_NAME} TARGET_SOURCES ${TARGET_SOURCES} TARGET_DEPENDENCIES
               ${TARGET_DEPENDENCIES})
install_gdk_target(${TARGET_NAME})
