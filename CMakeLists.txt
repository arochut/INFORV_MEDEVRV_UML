# CMakeList.txt : CMake project for TestVTK, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


project ("Battleships")

include_directories(src)
include_directories(src/Enums)

# Collect all source files in src and src/Enums
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/Enums/*.cpp" "src/*.h" "src/Enums/*.h")

# Define a global variable for the source files : USE_COLOR_IN_CONSOLE
add_compile_definitions(USE_COLOR_IN_CONSOLE) # Comment this line to disable color in console

# Add source to this project's executable.
add_executable (Battleships ${SOURCES})



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Battleships PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.