set(CURRENT_TRAGET glewstub)
set(SOURCES glew.cpp)

add_library(${CURRENT_TRAGET} STATIC ${SOURCES})
target_include_directories(${CURRENT_TRAGET}
                           PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
