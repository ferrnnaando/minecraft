cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME Minecraft)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)
find_package(OpenGL)

file(GLOB source_files
	"src/*.cpp"
	"src/Engine/*.cpp"
	"src/Screens/TittleScreen/*.cpp"
	"src/Utils/ResourceRandomizer/*.cpp"
)

set(SOURCES ${source_files})
set(CMAKE_CXX_STANDARD 20)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "include" "lib")
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)

# Copy data dir to the binary directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
