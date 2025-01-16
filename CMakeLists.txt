# CMakeLists.txt project file for Raylib projects
#
cmake_minimum_required(VERSION 3.29)
project(bp C)

set(CMAKE_C_STANDARD 23)

# Include the command that downloads libraries
include(FetchContent)

# define a function for adding git dependencies
function(include_dependency libName gitURL gitTag)
    # setup the declare
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG ${gitTag}
            GIT_SHALLOW TRUE
            GIT_PROGRESS TRUE
    )

    FetchContent_MakeAvailable(${libName})
endfunction()

# add raylib support
set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    message(STATUS "Getting ${LIB1} from Github")
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.5)
else ()
    message(STATUS "Using local ${LIB1}")
endif ()

add_executable(bp src/main.c
        src/map.h
        src/map.c
        src/temp.c
        src/pacman.h
        src/pacman.c
        src/screen.h
        src/screen_menu.c
        src/screen_gameplay.c
        src/screen_score.c
        src/screen_ending.c
        src/screen_name.c
)

# set the include directory
target_include_directories(bp PRIVATE ${raylib_INCLUDE_DIRS})

# link all libraries to the project
target_link_libraries(bp PRIVATE ${LIB1})