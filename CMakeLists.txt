cmake_minimum_required(VERSION 3.10)
project(engiFarm VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -pedantic -Wall -Wextra ${CMAKE_CXX_FLAGS_RELEASE}")

include_directories(include)

file(GLOB_RECURSE ENGI_FARM_SOURCE "src/*.cpp")

list(REMOVE_ITEM ENGI_FARM_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(main
  src/main.cpp
  ${ENGI_FARM_SOURCE}
)

enable_testing()
add_subdirectory(test)

