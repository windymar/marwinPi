cmake_minimum_required(VERSION 2.8.9)
project(marwinPi)
set(CMAKE_CXX_STANDARD 14)

include_directories(
    Platform/Headers
    Diodes/Headers
    Sensors/Headers
    Sound/Headers
    Platform/Tests/Mocks
    Diodes/Tests/Mocks
)

file(GLOB SOURCES 
    "Platform/Sources/*.cpp"
    "Diodes/Sources/*.cpp"
    "Sensors/Sources/*.cpp"
    "Sound/Sources/*.cpp"
)

file(GLOB TEST_SOURCES
    "unittests.cpp"
    "Platform/Tests/*.cpp"
    "Diodes/Tests/*.cpp"
    "Sensors/Tests/*.cpp"
    "Sound/Tests/*.cpp"
)

add_library(marwinPi STATIC ${SOURCES})

add_executable(marwinPiTests ${SOURCES} ${TEST_SOURCES})

target_link_libraries(marwinPiTests gtest gmock wiringPi pthread rt crypt)
