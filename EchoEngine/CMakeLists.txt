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

# Source files
set(SOURCES
    EchoEngine/main.cpp
    EchoEngine/shader.cpp
    EchoEngine/texture.cpp
    EchoEngine/window.cpp
)

set(HEADERS
    EchoEngine/camera.h
    EchoEngine/shader.h
    EchoEngine/texture.h
    EchoEngine/window.h
    EchoEngine/stb_image.h
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/EchoEngine
    ${CMAKE_SOURCE_DIR}/EchoEngine/glm
    ${GLFW_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME}
    glad
    ${GLFW_LIBRARY}
    opengl32
)

# Copy shader files to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/EchoEngine/vertexShader.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/vertexShader.txt
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/EchoEngine/fragmentShader.txt
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/fragmentShader.txt
)

# Copy texture files if they exist
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/EchoEngine/assets/container.jpg
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/container.jpg
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/EchoEngine/assets/awesomeface.png
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/awesomeface.png
    COMMENT "Copying resources..."
)