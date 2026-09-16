cmake_minimum_required(VERSION 3.24)
project(undertale VERSION 0.1 LANGUAGES CXX)

add_subdirectory(deps/raylib deps/raylib/build)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)



add_executable(undertale

	include/pugiconfig.hpp
	include/pugixml.hpp
	src/pugixml.cpp

	include/undertale/undertale.hpp
	include/undertale/sprite.hpp
	include/undertale/instance.hpp
	include/undertale/objects/introimage.hpp
	include/undertale/objects/ruinsmusic.hpp
	include/undertale/objects/spiketile2.hpp
	include/undertale/objects/spiketile1.hpp
	include/undertale/objects/mainchara.hpp
	include/undertale/sheetloader.hpp
	include/undertale/tile.hpp
	include/undertale/room.hpp
	include/undertale.hpp


	src/undertale.cpp
	src/sprite.cpp
	src/instance.cpp
	src/objects/introimage.cpp
	src/objects/ruinsmusic.cpp
	src/objects/spiketile2.cpp
	src/objects/spiketile1.cpp
	src/objects/mainchara.cpp
	src/sheetloader.cpp
	src/tile.cpp
	src/room.cpp
	src/main.cpp

)


target_include_directories(undertale PUBLIC "include")
target_link_libraries(undertale PUBLIC raylib)

