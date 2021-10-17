cmake_minimum_required(VERSION 3.16)

project(MultimediaWrapper)

file(GLOB_RECURSE MW_HEADERS CONFIGURE_DEPENDS include/MW/*.hpp include/MW/*.inl)
file(GLOB_RECURSE MW_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_library(MultimediaWrapper ${MW_HEADERS} ${MW_SOURCES})

target_include_directories(MultimediaWrapper
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MW
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)