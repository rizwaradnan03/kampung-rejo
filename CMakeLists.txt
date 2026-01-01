cmake_minimum_required(VERSION 3.20)
project(kampung_rejo)

set(CMAKE_CXX_STANDARD 17)

# === PATH SFML SESUAI STRUKTUR KAMU ===
set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/include)
set(SFML_LIB_DIR ${CMAKE_SOURCE_DIR}/external/lib)

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIB_DIR})

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(kampung_rejo ${SOURCES})

target_link_libraries(kampung_rejo
    sfml-graphics
    sfml-window
    sfml-system
)
