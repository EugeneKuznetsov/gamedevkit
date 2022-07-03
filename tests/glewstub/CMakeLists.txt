set(CURRENT_TRAGET glewstub)

add_library(${CURRENT_TRAGET} INTERFACE)
target_include_directories(${CURRENT_TRAGET}
                           INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
