cmake_minimum_required(VERSION 2.8.9)
project(marwinPi)
set(CMAKE_CXX_STANDARD 11)

include_directories(
	Platform/Headers
	Diodes/Headers
	Sensors/Headers
	Sound/Headers
)

file(GLOB SOURCES 
	"Platform/Sources/*.cpp" 
	"Diodes/Sources/*.cpp"
	"Sensors/Sources/*.cpp"
	"Sound/Sources/*.cpp"
)

add_library(marwinPi STATIC ${SOURCES})
