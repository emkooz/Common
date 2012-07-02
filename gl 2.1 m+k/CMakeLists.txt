cmake_minimum_required(VERSION 2.8)
project(Engine)

SET(CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel."
    FORCE)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CSS_FLAGS
        "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic-errors")
        # -Wall:   Enable all warnings.
        # -Wextra: Enable some more warnings.
        # -Werror: Have errors on warnings.
        # -pedantic-errors: Error on non-standard ISO C++ code.
        # -std=c++0x: Compile C++0x code.

    add_definitions(-D_CMAKE_LINUX_)
elseif(MSVC)
    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} /W4 /WX /wd4355 /wd4512")
        # /W4: Maximum warnings.
        # /WX: Have errors on warnings.
        # /wd4355: Disable warning 4355:
        #          Using the 'this' pointer in initializer lists.
        # /wd4512: Disable warning 4512:
        #          Assignment operators NOT being able to be generated.

    add_definitions(-D_CMAKE_WINDOWS_)
endif()

# SOURCE FILES

set(source
    test.cpp
    Camera.cpp)

# GAME
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmakemodules")

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)
find_package(SOIL REQUIRED)
find_package(GLM REQUIRED)


include_directories(${OPENGL_INCLUDE_DIR}
                    ${GLEW_INCLUDE_PATH}
                    ${GLFW_INCLUDE_DIRS}
                    ${SOIL_INCLUDE_DIR}
                    ${GLM_INCLUDE_DIR})

set(GAME_TARGET "Engine")
add_executable(${GAME_TARGET} ${source})
target_link_libraries(${GAME_TARGET}
                      ${OPENGL_LIBRARIES}
                      ${GLEW_LIBRARY}
                      ${GLFW_LIBRARIES}
                      ${SOIL_LIBRARIES}
                )
