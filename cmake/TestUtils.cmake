function(add_test_suite)
    set(options)
    set(oneValueArgs NAME TARGET_UNDER_TEST)
    set(multiValueArgs DEPENDENCY_LIBS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(MAIN_TARGET ${ARG_NAME})
    set(SOURCES "${MAIN_TARGET}.cpp")
    set(TARGET_UNDER_TEST ${ARG_TARGET_UNDER_TEST})
    set(TARGET_UNDER_TEST_OBJECTS ${TARGET_UNDER_TEST}-object)
    set(TARGET_UNDER_TEST_API ${TARGET_UNDER_TEST}-api)

    add_executable(${MAIN_TARGET} ${SOURCES} $<TARGET_OBJECTS:${TARGET_UNDER_TEST_OBJECTS}>)
    target_include_directories(${MAIN_TARGET} PRIVATE ${GLEWSTUB_INCLUDE_DIRECTORIES})
    target_link_libraries(${MAIN_TARGET} PRIVATE GTest::gtest_main glewstub
                                                 ${TARGET_UNDER_TEST_API})
    foreach(DEPENDENCY_TARGET IN LISTS ARG_DEPENDENCY_LIBS)
        target_link_libraries(${MAIN_TARGET} PRIVATE ${DEPENDENCY_TARGET})
    endforeach()
    add_test(NAME ${MAIN_TARGET} COMMAND $<TARGET_FILE:${MAIN_TARGET}>)
endfunction()
