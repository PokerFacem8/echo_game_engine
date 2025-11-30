# Echo Game Engine

A simple OpenGL game engine built with C++, GLFW, GLAD, GLM, and ImGui.

## Features

- 3D rendering with OpenGL
- Camera system with WASD movement and mouse look
- Texture loading support
- ImGui integration for debug UI

## Prerequisites

### Windows
- **CMake** 3.15 or higher
  - Download: https://cmake.org/download/
- **Visual Studio 2022** (with C++ Desktop Development)
  - Download: https://visualstudio.microsoft.com/downloads/
  - During installation, select "Desktop development with C++"

## Dependencies

All dependencies are included in the repository:
- **GLAD** - OpenGL loader
- **GLFW** - Windowing and input handling
- **GLM** - Mathematics library for graphics
- **ImGui** - Immediate mode GUI library

## Quick Start

### Clone the Repository

```bash
git clone https://github.com/PokerFacem8/echo_game_engine.git
cd echo_game_engine/EchoEngine
```

### Build the Project

**Windows (Visual Studio):**
```bash
mkdir build
cd build
cmake ..
cmake --build . --config Debug
```

### Run the Application

**Windows:**
```bash
.\build\bin\Debug\EchoEngine.exe
```

## Controls

- **W/A/S/D** - Move camera forward/left/backward/right
- **Mouse** - Look around (first-person camera)
- **ESC** - Exit application

## Project Structure

```
echo_game_engine/
├── EchoEngine/
│   ├── CMakeLists.txt          # Build configuration
│   ├── src/                    # Source code
│   │   ├── main.cpp           # Entry point
│   │   ├── window.cpp/h       # Window management
│   │   ├── shader.cpp/h       # Shader handling
│   │   ├── texture.cpp/h      # Texture loading
│   │   ├── camera.h           # Camera system
│   │   ├── assets/            # Textures and resources
│   │   └── shaders/           # GLSL shaders
│   ├── external/              # Third-party libraries
│   │   ├── glad/              # OpenGL loader
│   │   ├── glfw/              # Window library
│   │   ├── glm/               # Math library
│   │   └── imgui/             # GUI library
│   └── build/                 # Build output (generated)
├── .vscode/                   # VS Code configuration
└── README.md                  # This file
```

## Building from Source

### Requirements

- C++17 compatible compiler
- CMake 3.15+
- OpenGL 3.3+ support

### Build Configuration

The project uses CMake for cross-platform builds. Key configurations:

- **Debug build:** `cmake --build . --config Debug`
- **Release build:** `cmake --build . --config Release`

### Customization

Edit `CMakeLists.txt` to:
- Change compiler flags
- Add new source files
- Modify output directories
- Configure dependencies

## License

See [LICENSE](LICENSE) file for details.

## Credits

Built with:
- [GLFW](https://www.glfw.org/) - Window management
- [GLAD](https://glad.dav1d.de/) - OpenGL loading
- [GLM](https://github.com/g-truc/glm) - Mathematics
- [ImGui](https://github.com/ocornut/imgui) - GUI system
- [stb_image](https://github.com/nothings/stb) - Image loading
