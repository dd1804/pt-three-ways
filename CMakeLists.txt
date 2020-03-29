cmake_minimum_required(VERSION 3.12)
project(pt_three_ways)

find_program(CONAN conan)
if (NOT CONAN)
    message(FATAL_ERROR "Needs conan package manager: please visit https://conan.io and install")
endif ()

include(${CMAKE_SOURCE_DIR}/scripts/conan.cmake)

conan_check(version 1.14.4 REQUIRED)
conan_add_remote(NAME bincrafters URL "https://api.bintray.com/conan/bincrafters/public-conan")
conan_cmake_run(CONANFILE conanfile.txt
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_compile_options(-Wall -Werror -Wextra -march=native -g)

add_subdirectory(src)
add_subdirectory(test)

find_package(Threads)
add_executable(pt_three_ways src/main/main.cpp src/main/Progressifier.cpp src/main/Progressifier.h src/main/WorkQueue.h)
target_link_libraries(pt_three_ways math oo ${CMAKE_THREAD_LIBS_INIT} CONAN_PKG::clara)

if (NOT ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug"))
    include(CheckIPOSupported)
    check_ipo_supported(RESULT LTOAvailable)
endif ()

if (LTOAvailable)
    message("Link-time optimization enabled")

    set_property(TARGET oo PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
    set_property(TARGET math PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
    set_property(TARGET pt_three_ways PROPERTY INTERPROCEDURAL_OPTIMIZATION True)
endif ()