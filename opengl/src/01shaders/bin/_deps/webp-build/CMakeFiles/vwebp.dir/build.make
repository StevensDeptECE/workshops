# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dkruger/git/course/workshops/opengl/src/01shaders

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dkruger/git/course/workshops/opengl/src/01shaders/build

# Include any dependencies generated for this target.
include ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/depend.make

# Include the progress variables for this target.
include ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/progress.make

# Include the compile flags for this target's objects.
include ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/flags.make

../bin/_deps/webp-build/CMakeFiles/vwebp.dir/examples/vwebp.c.o: ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/vwebp.dir/examples/vwebp.c.o: ../include/libwebp/examples/vwebp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/examples/vwebp.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/vwebp.dir/examples/vwebp.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/examples/vwebp.c

../bin/_deps/webp-build/CMakeFiles/vwebp.dir/examples/vwebp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/vwebp.dir/examples/vwebp.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/examples/vwebp.c > CMakeFiles/vwebp.dir/examples/vwebp.c.i

../bin/_deps/webp-build/CMakeFiles/vwebp.dir/examples/vwebp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/vwebp.dir/examples/vwebp.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/examples/vwebp.c -o CMakeFiles/vwebp.dir/examples/vwebp.c.s

# Object files for target vwebp
vwebp_OBJECTS = \
"CMakeFiles/vwebp.dir/examples/vwebp.c.o"

# External object files for target vwebp
vwebp_EXTERNAL_OBJECTS =

../bin/vwebp: ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/examples/vwebp.c.o
../bin/vwebp: ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/build.make
../bin/vwebp: /usr/lib/x86_64-linux-gnu/libOpenGL.so
../bin/vwebp: /usr/lib/x86_64-linux-gnu/libGLX.so
../bin/vwebp: /usr/lib/x86_64-linux-gnu/libGLU.so
../bin/vwebp: ../bin/_deps/webp-build/libexampleutil.a
../bin/vwebp: /usr/lib/x86_64-linux-gnu/libglut.so
../bin/vwebp: ../bin/_deps/webp-build/libimageioutil.a
../bin/vwebp: ../bin/_deps/webp-build/libwebp.a
../bin/vwebp: ../bin/_deps/webp-build/libwebpdemux.a
../bin/vwebp: ../bin/_deps/webp-build/libwebp.a
../bin/vwebp: ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../vwebp"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/vwebp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
../bin/_deps/webp-build/CMakeFiles/vwebp.dir/build: ../bin/vwebp

.PHONY : ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/build

../bin/_deps/webp-build/CMakeFiles/vwebp.dir/clean:
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && $(CMAKE_COMMAND) -P CMakeFiles/vwebp.dir/cmake_clean.cmake
.PHONY : ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/clean

../bin/_deps/webp-build/CMakeFiles/vwebp.dir/depend:
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dkruger/git/course/workshops/opengl/src/01shaders /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp /home/dkruger/git/course/workshops/opengl/src/01shaders/build /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build/CMakeFiles/vwebp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ../bin/_deps/webp-build/CMakeFiles/vwebp.dir/depend
