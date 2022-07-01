function(add_gdk_target)
    set(options WITH_DETAILS)
    set(oneValueArgs NAME)
    set(multiValueArgs SOURCES PRIVATE_LIBS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(MAIN_TARGET ${ARG_NAME})
    set(API_TARGET ${MAIN_TARGET}-api)
    set(DETAILS_API_TARGET ${MAIN_TARGET}-details-api)
    set(OBJECT_TARGET ${MAIN_TARGET}-object)

    add_library(${API_TARGET} INTERFACE)
    target_include_directories(
        ${API_TARGET} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/${ARG_NAME}>)

    if(DEFINED ARG_WITH_DETAILS)
        add_library(${DETAILS_API_TARGET} INTERFACE)
        target_include_directories(
            ${DETAILS_API_TARGET}
            INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/details>)
    endif()

    add_library(${OBJECT_TARGET} OBJECT ${ARG_SOURCES})
    target_link_libraries(
        ${OBJECT_TARGET}
        PRIVATE $<BUILD_INTERFACE:${API_TARGET}>
                $<$<TARGET_EXISTS:${DETAILS_API_TARGET}>:$<BUILD_INTERFACE:${DETAILS_API_TARGET}>>)
    foreach(DEPENDENCY_TARGET IN LISTS ARG_PRIVATE_LIBS)
        if(NOT TARGET ${DEPENDENCY_TARGET})
            message(FATAL_ERROR "${DEPENDENCY_TARGET} is not a real target")
        endif()
        get_target_property(DEPENDENCY_HEADERS ${DEPENDENCY_TARGET} INTERFACE_INCLUDE_DIRECTORIES)
        target_include_directories(${OBJECT_TARGET}
                                   PRIVATE $<BUILD_INTERFACE:${DEPENDENCY_HEADERS}>)
    endforeach()

    add_library(${MAIN_TARGET} STATIC $<TARGET_OBJECTS:${OBJECT_TARGET}>)
    target_link_libraries(
        ${MAIN_TARGET}
        PUBLIC $<BUILD_INTERFACE:${API_TARGET}>
        PRIVATE $<$<TARGET_EXISTS:${DETAILS_API_TARGET}>:$<BUILD_INTERFACE:${DETAILS_API_TARGET}>>)
    foreach(DEPENDENCY_TARGET IN LISTS ARG_PRIVATE_LIBS)
        target_link_libraries(${MAIN_TARGET} PRIVATE $<BUILD_INTERFACE:${DEPENDENCY_TARGET}>)
    endforeach()

    add_library(GDK::${MAIN_TARGET} ALIAS ${MAIN_TARGET})
endfunction()
