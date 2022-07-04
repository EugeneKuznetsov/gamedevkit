function(add_test_suite)
    set(options)
    set(oneValueArgs NAME TARGET_UNDER_TEST)
    set(multiValueArgs TEST_SUITE_DEPENDENCY_LIBS TARGET_UNDER_TEST_STUB_LIBS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    set(MAIN_TARGET ${ARG_NAME})
    set(SOURCES "${MAIN_TARGET}.cpp")
    set(TARGET_UNDER_TEST ${ARG_TARGET_UNDER_TEST})
    set(TARGET_UNDER_TEST_OBJECTS ${TARGET_UNDER_TEST}-object)
    set(TARGET_UNDER_TEST_API ${TARGET_UNDER_TEST}-api)
    set(TARGET_UNDER_TEST_DETAILS_API ${TARGET_UNDER_TEST}-details-api)
    get_target_property(TARGET_UNDER_TEST_SOURCES ${TARGET_UNDER_TEST_OBJECTS} INTERFACE_SOURCES)

    add_executable(${MAIN_TARGET} ${SOURCES} ${TARGET_UNDER_TEST_SOURCES})
    target_link_libraries(
        ${MAIN_TARGET}
        PRIVATE
            GTest::gtest_main glewstub ${TARGET_UNDER_TEST_API}
            $<$<TARGET_EXISTS:${TARGET_UNDER_TEST_DETAILS_API}>:${TARGET_UNDER_TEST_DETAILS_API}>)
    foreach(DEPENDENCY_TARGET IN LISTS ARG_TEST_SUITE_DEPENDENCY_LIBS)
        target_link_libraries(${MAIN_TARGET} PRIVATE ${DEPENDENCY_TARGET})
    endforeach()
    add_test(NAME ${MAIN_TARGET} COMMAND $<TARGET_FILE:${MAIN_TARGET}>)
endfunction()
