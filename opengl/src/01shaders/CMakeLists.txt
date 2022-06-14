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

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE DEBUG)
endif()

message(STATUS "Current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

include(FetchContent)
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG d141cdbeb0fb422a3fb7173b285fd38e0d1772dc # v8.0.1
  SOURCE_DIR ${PROJECT_SOURCE_DIR}/external/fmt)
FetchContent_MakeAvailable(fmt)

# GLM
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  # 0.9.9.8 does not have C++ 20 fix yet, so master branch is currently used
  # GIT_TAG        bf71a834948186f4097caa076cd2663c69a10e1e # 0.9.9.8
  SOURCE_DIR ${PROJECT_SOURCE_DIR}/external/glm)
FetchContent_GetProperties(glm)
if(NOT glm_POPULATED)
  FetchContent_Populate(glm)
endif()

#FetchContent_Declare(
#  webp
#  GIT_REPOSITORY https://github.com/webmproject/libwebp.git
#  SOURCE_DIR ${PROJECT_SOURCE_DIR}/include/libwebp)
#FetchContent_MakeAvailable(webp)

find_package(Freetype REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

function(add_exec)
    set(oneValueArgs SRC)
    set(options BINNAME USEMAIN)
    cmake_parse_arguments(GRAILBIN "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    set(GRAIL_SRC
include/glad/glad.c;opengl/GLWin.cc;opengl/Tab.cc;opengl/Canvas.cc;
opengl/Image.cc;opengl/Tab.cc;opengl/Member.cc;opengl/Shader.cc;opengl/Shape.cc;
opengl/Colors.cc;opengl/GLWinFonts.cc;util/HashMap.cc;opengl/StyledMultiShape2D.cc;
opengl/MultiShape.cc;util/Callbacks.cc;util/Prefs.cc;opengl/ErrNames.cc;opengl/MultiShape2D.cc)

    if(NOT ${GRAILBIN_USEMAIN})
      list(APPEND GRAIL_SRC opengl/Main.cc)
    endif()
    if(NOT GRAILBIN_BINNAME)
        get_filename_component(GRAILBIN_BINNAME ${GRAILBIN_SRC} NAME_WE)
    endif()
    add_executable(${GRAILBIN_BINNAME} ${GRAILBIN_SRC} ${GRAIL_SRC})
    target_include_directories (${GRAILBIN_BINNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_include_directories (${GRAILBIN_BINNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external)
    target_include_directories (${GRAILBIN_BINNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includeshaders)
    target_include_directories (${GRAILBIN_BINNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/glm)
    target_include_directories (${GRAILBIN_BINNAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

    target_link_libraries(${GRAILBIN_BINNAME} fmt::fmt)
    target_link_libraries(${GRAILBIN_BINNAME} ${FREETYPE_LIBRARIES})

    target_include_directories(${GRAILBIN_BINNAME} PRIVATE ${FREETYPE_INCLUDE_DIRS})

    target_include_directories(${GRAILBIN_BINNAME} PRIVATE ${OPENGL_INCLUDE_DIRS})

    target_include_directories(${GRAILBIN_BINNAME} INTERFACE ${GLFW_INCLUDE_DIRS})
    target_link_libraries(${GRAILBIN_BINNAME} glfw)
    target_link_libraries(${GRAILBIN_BINNAME} ${CMAKE_DL_LIBS})

    #target_include_directories(test1 ${WebP_INCLUDE_DIRS})
    target_link_libraries(${GRAILBIN_BINNAME} webp)
endfunction()


add_exec(SRC test1.cc)
add_exec(SRC testLoadWebp.cc USEMAIN FALSE)
add_exec(SRC testCustomShader.cc)
#add_exec(testImage testImage.cc ${GRAILSRC})

# target_include_directories (test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
# target_include_directories (test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includeshaders)
# target_include_directories (test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/glm)
# target_include_directories (test1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# target_link_libraries(test1 fmt::fmt)
# target_link_libraries(test1 ${FREETYPE_LIBRARIES})

# target_include_directories(test1 PRIVATE ${FREETYPE_INCLUDE_DIRS})

# target_include_directories(test1 PRIVATE ${OPENGL_INCLUDE_DIRS})

# target_include_directories(test1 INTERFACE ${GLFW_INCLUDE_DIRS})
# target_link_libraries(test1 glfw)
# target_link_libraries(test1 ${CMAKE_DL_LIBS})

# #target_include_directories(test1 ${WebP_INCLUDE_DIRS})
# target_link_libraries(test1 webp)