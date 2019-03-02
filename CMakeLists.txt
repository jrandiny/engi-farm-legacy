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

add_executable(testerList
  ${ENGI_FARM_SOURCE}
  test/testList.cpp
)

add_executable(testerCB
  ${ENGI_FARM_SOURCE}
  test/testCB.cpp
)

add_executable(testerAnimal
  ${ENGI_FARM_SOURCE}
  test/testAnimal.cpp
)

add_executable(testerPlayer
  ${ENGI_FARM_SOURCE}
  test/testPlayer.cpp
)