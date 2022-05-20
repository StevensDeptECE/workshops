cmake_minimum_required(VERSION 3.16.1)

project(
  Demos
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_FILES_DIRECTORY build)
set(CMAKE_CXX_STANDARD 20)
option(CMAKE_CXX_STANDARD_REQUIRED ON)
option(CMAKE_CXX_EXTENSIONS OFF)

message(STATUS "Current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")
message(WARNING "This is a warning")
message(STATUS "Check out the CMake documentation! https://cmake.org/cmake/help/latest/command/message.html")

include(FetchContent)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG d141cdbeb0fb422a3fb7173b285fd38e0d1772dc # v8.0.1
  SOURCE_DIR ${PROJECT_SOURCE_DIR}/include/fmt)
FetchContent_MakeAvailable(fmt)

#FetchContent_Declare(
#  webp
#  GIT_REPOSITORY https://github.com/webmproject/libwebp.git
#  SOURCE_DIR ${PROJECT_SOURCE_DIR}/include/libwebp)
#FetchContent_MakeAvailable(webp)

find_package(Freetype REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)


add_executable(test1 test1.cc include/glad/glad.c opengl/Main.cc opengl/GLWin.cc opengl/Tab.cc opengl/Canvas.cc 
                opengl/Image.cc opengl/Tab.cc opengl/Member.cc opengl/Shader.cc opengl/Shape.cc
                opengl/Colors.cc opengl/GLWinFonts.cc util/HashMap.cc opengl/StyledMultiShape2D.cc
                opengl/MultiShape.cc util/Callbacks.cc util/Prefs.cc opengl/ErrNames.cc opengl/MultiShape2D.cc)

target_include_directories (test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories (test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includeshaders)
target_include_directories (test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/glm)
target_include_directories (test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(test1 fmt::fmt)
target_link_libraries(test1 ${FREETYPE_LIBRARIES})

target_include_directories(test1 PRIVATE ${FREETYPE_INCLUDE_DIRS})

target_include_directories(test1 PRIVATE ${OPENGL_INCLUDE_DIRS})

target_include_directories(test1 INTERFACE ${GLFW_INCLUDE_DIRS})
target_link_libraries(test1 glfw)
target_link_libraries(test1 ${CMAKE_DL_LIBS})

#target_include_directories(test1 ${WebP_INCLUDE_DIRS})
target_link_libraries(test1 webp)