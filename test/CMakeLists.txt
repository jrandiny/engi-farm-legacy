# https://github.com/google/googletest/blob/master/googletest/README.md
configure_file(CMakeLists-gtest.txt googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

add_subdirectory(
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-src
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
    EXCLUDE_FROM_ALL
)

include(GoogleTest)

file(GLOB ENGI_FARM_TEST "test-*.cpp")

add_executable(tester
    tester.cpp
    ${ENGI_FARM_TEST}
    ${ENGI_FARM_SOURCE}
)

target_link_libraries(tester 
    ${CURSES_LIBRARIES}
)
target_link_libraries(tester gtest_main)
gtest_discover_tests(tester)
