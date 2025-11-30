cmake_minimum_required(VERSION 3.15)
project(EchoEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# GLAD
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# GLFW
set(GLFW_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/external/glfw/include)
set(GLFW_LIBRARY ${CMAKE_SOURCE_DIR}/external/glfw/lib-vc2022/glfw3.lib)

# IMGUI
add_library(imgui STATIC
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_demo.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC
    external/imgui
    external/imgui/backends
    ${GLFW_INCLUDE_DIR}
    external/glad/include
)

# Source files
set(SOURCES
    src/main.cpp
    src/shader.cpp
    src/texture.cpp
    src/window.cpp
)

set(HEADERS
    src/camera.h
    src/shader.h
    src/texture.h
    src/window.h
    src/stb_image.h
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/external
    ${GLFW_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    glad
    ${GLFW_LIBRARY}
    imgui
    opengl32
)

# Copy shader files to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/src/shaders/vertexShader.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders/vertexShader.txt
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/src/shaders/fragmentShader.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders/fragmentShader.txt
)

# Copy texture files if they exist
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/src/assets/container.jpg
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets/container.jpg
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/src/assets/awesomeface.png
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets/awesomeface.png
    COMMENT "Copying resources..."
)