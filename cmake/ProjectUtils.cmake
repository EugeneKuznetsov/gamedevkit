function(add_gdk_target GDK_TARGET_NAME)
    set(options)
    set(oneValueArgs)
    set(multiValueArgs TARGET_SOURCES TARGET_DEPENDENCIES)
    cmake_parse_arguments(GDK "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT GDK_TARGET_SOURCES)
        message(FATAL_ERROR "Source files were not provided for ${GDK_TARGET_NAME} target")
    endif()

    add_library(${GDK_TARGET_NAME} STATIC ${GDK_TARGET_SOURCES})
    target_sources(${GDK_TARGET_NAME} INTERFACE ${GDK_TARGET_SOURCES})
    target_include_directories(
        ${GDK_TARGET_NAME}
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/${GDK_TARGET_NAME}>)

    if("GLEW::GLEW" IN_LIST TARGET_DEPENDENCIES)
        target_compile_definitions(${GDK_TARGET_NAME} PRIVATE "GLEW_STATIC")
    endif()

    if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/include/details)
        target_include_directories(
            ${GDK_TARGET_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include/details>)
    endif()

    foreach(DEPENDENCY_TARGET IN LISTS GDK_TARGET_DEPENDENCIES)
        string(REGEX MATCH "^(PRIVATE|PUBLIC|INTERFACE) (.*)" _ ${DEPENDENCY_TARGET})
        if(NOT TARGET ${CMAKE_MATCH_2})
            message(FATAL_ERROR "${CMAKE_MATCH_2} is not a target")
        endif()
        target_link_libraries(${GDK_TARGET_NAME} ${CMAKE_MATCH_1} ${CMAKE_MATCH_2})
    endforeach()

    add_library(GameDevKit::${GDK_TARGET_NAME} ALIAS ${GDK_TARGET_NAME})
endfunction()

function(install_gdk_target GDK_TARGET_NAME)
    install(
        TARGETS ${GDK_TARGET_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
    install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/${GDK_TARGET_NAME}/GDK
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endfunction()
