function(add_test_suite GDK_TEST_SUITE_NAME)
    set(options)
    set(oneValueArgs TARGET_UNDER_TEST)
    set(multiValueArgs TEST_SUITE_DEPENDENCIES)
    cmake_parse_arguments(GDK "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    if(NOT TARGET ${GDK_TARGET_UNDER_TEST})
        message(FATAL_ERROR "Target under test ${GDK_TARGET_UNDER_TEST} is not a target")
    endif()

    get_target_property(GDK_TARGET_UNDER_TEST_SOURCES ${GDK_TARGET_UNDER_TEST} INTERFACE_SOURCES)
    if(NOT GDK_TARGET_UNDER_TEST_SOURCES)
        message(
            FATAL_ERROR
                "Property INTERFACE_SOURCES of target under test ${GDK_TARGET_UNDER_TEST} is empty")
    endif()

    set(GDK_TEST_SUITE_SOURCES "${GDK_TEST_SUITE_NAME}.cpp")

    add_executable(${GDK_TEST_SUITE_NAME} ${GDK_TEST_SUITE_SOURCES}
                                          ${GDK_TARGET_UNDER_TEST_SOURCES})
    target_link_libraries(${GDK_TEST_SUITE_NAME} PRIVATE GTest::gtest_main GTest::gmock glewstub)

    get_target_property(TARGET_UNDER_TEST_INCLUDE_DIRECTORIES ${GDK_TARGET_UNDER_TEST}
                        INTERFACE_INCLUDE_DIRECTORIES)
    target_include_directories(${GDK_TEST_SUITE_NAME}
                               PRIVATE ${TARGET_UNDER_TEST_INCLUDE_DIRECTORIES})

    foreach(DEPENDENCY_TARGET IN LISTS GDK_TEST_SUITE_DEPENDENCIES)
        string(REGEX MATCH "^(PRIVATE|PUBLIC|INTERFACE) (.*)" _ ${DEPENDENCY_TARGET})
        if(NOT TARGET ${CMAKE_MATCH_2})
            message(FATAL_ERROR "${CMAKE_MATCH_2} is not a target")
        endif()
        target_link_libraries(${GDK_TEST_SUITE_NAME} ${CMAKE_MATCH_1} ${CMAKE_MATCH_2})
    endforeach()

    add_test(NAME ${GDK_TEST_SUITE_NAME} COMMAND $<TARGET_FILE:${GDK_TEST_SUITE_NAME}>)
endfunction()
