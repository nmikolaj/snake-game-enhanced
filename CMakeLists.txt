# CMakeList.txt: projekt CMake dla elementu Snake, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("Snake")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (Snake "src/Snake.cpp" "headers/snakeInfo.hpp"  "headers/engine.hpp" "headers/jablko.hpp" "headers/sciana.hpp" "src/engine.cpp" "src/draw.cpp" "src/snakeInfo.cpp" "src/jablko.cpp" "src/sciana.cpp" "src/menu.cpp"  "src/przeszkoda.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Snake PROPERTY CXX_STANDARD 20)
endif()

include_directories(headers c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)

if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(Snake ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# kopiuj dlls do siezki build

if(WIN32)
	file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
	file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()


# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
