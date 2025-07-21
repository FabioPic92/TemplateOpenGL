cmake_minimum_required(VERSION 3.14)

project(MinimalSdlOpenGLTest CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(external/SDL3)

include_directories(external/glad/include)

set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Disable Wayland backend in GLFW")
set(GLFW_BUILD_X11     ON  CACHE BOOL "Enable X11 backend in GLFW")
add_subdirectory(external/glfw)

include_directories(external/glm)
include_directories(external/stb) 

file(GLOB PROJECT_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} 
               main.cpp
               ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include # 
    external/SDL3/include
)

target_link_libraries(${PROJECT_NAME}
    SDL3::SDL3 
    GL        
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/libglad.a 
    glfw
)
