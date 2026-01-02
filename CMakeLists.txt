cmake_minimum_required(VERSION 3.20)

project(kampung_rejo LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/include)
set(SFML_LIB_DIR ${CMAKE_SOURCE_DIR}/external/lib)

file(GLOB_RECURSE GAME_SOURCES
    src/*.cpp
)

set(SQLITE_SOURCE
    ${CMAKE_SOURCE_DIR}/external/include/sqlite/sqlite3.c
)

add_executable(kampung_rejo
    ${GAME_SOURCES}
    ${SQLITE_SOURCE}
)

target_include_directories(kampung_rejo PRIVATE
    ${SFML_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include
)

target_link_directories(kampung_rejo PRIVATE
    ${SFML_LIB_DIR}
)

target_link_libraries(kampung_rejo
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set_source_files_properties(
        ${SQLITE_SOURCE}
        PROPERTIES
        COMPILE_FLAGS "-Wno-stringop-overread"
    )
endif()

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets
)

add_dependencies(kampung_rejo copy_assets)
