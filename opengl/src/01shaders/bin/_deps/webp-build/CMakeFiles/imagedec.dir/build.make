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
include ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/depend.make

# Include the progress variables for this target.
include ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/progress.make

# Include the compile flags for this target's objects.
include ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/image_dec.c.o: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/image_dec.c.o: ../include/libwebp/imageio/image_dec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/image_dec.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imagedec.dir/imageio/image_dec.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/image_dec.c

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/image_dec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imagedec.dir/imageio/image_dec.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/image_dec.c > CMakeFiles/imagedec.dir/imageio/image_dec.c.i

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/image_dec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imagedec.dir/imageio/image_dec.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/image_dec.c -o CMakeFiles/imagedec.dir/imageio/image_dec.c.s

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/jpegdec.c.o: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/jpegdec.c.o: ../include/libwebp/imageio/jpegdec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/jpegdec.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imagedec.dir/imageio/jpegdec.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/jpegdec.c

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/jpegdec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imagedec.dir/imageio/jpegdec.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/jpegdec.c > CMakeFiles/imagedec.dir/imageio/jpegdec.c.i

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/jpegdec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imagedec.dir/imageio/jpegdec.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/jpegdec.c -o CMakeFiles/imagedec.dir/imageio/jpegdec.c.s

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/metadata.c.o: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/metadata.c.o: ../include/libwebp/imageio/metadata.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/metadata.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imagedec.dir/imageio/metadata.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/metadata.c

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/metadata.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imagedec.dir/imageio/metadata.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/metadata.c > CMakeFiles/imagedec.dir/imageio/metadata.c.i

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/metadata.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imagedec.dir/imageio/metadata.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/metadata.c -o CMakeFiles/imagedec.dir/imageio/metadata.c.s

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pngdec.c.o: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pngdec.c.o: ../include/libwebp/imageio/pngdec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pngdec.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imagedec.dir/imageio/pngdec.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/pngdec.c

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pngdec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imagedec.dir/imageio/pngdec.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/pngdec.c > CMakeFiles/imagedec.dir/imageio/pngdec.c.i

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pngdec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imagedec.dir/imageio/pngdec.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/pngdec.c -o CMakeFiles/imagedec.dir/imageio/pngdec.c.s

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pnmdec.c.o: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pnmdec.c.o: ../include/libwebp/imageio/pnmdec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pnmdec.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imagedec.dir/imageio/pnmdec.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/pnmdec.c

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pnmdec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imagedec.dir/imageio/pnmdec.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/pnmdec.c > CMakeFiles/imagedec.dir/imageio/pnmdec.c.i

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pnmdec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imagedec.dir/imageio/pnmdec.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/pnmdec.c -o CMakeFiles/imagedec.dir/imageio/pnmdec.c.s

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/tiffdec.c.o: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/tiffdec.c.o: ../include/libwebp/imageio/tiffdec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/tiffdec.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imagedec.dir/imageio/tiffdec.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/tiffdec.c

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/tiffdec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imagedec.dir/imageio/tiffdec.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/tiffdec.c > CMakeFiles/imagedec.dir/imageio/tiffdec.c.i

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/tiffdec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imagedec.dir/imageio/tiffdec.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/tiffdec.c -o CMakeFiles/imagedec.dir/imageio/tiffdec.c.s

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/webpdec.c.o: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/webpdec.c.o: ../include/libwebp/imageio/webpdec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/webpdec.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imagedec.dir/imageio/webpdec.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/webpdec.c

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/webpdec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imagedec.dir/imageio/webpdec.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/webpdec.c > CMakeFiles/imagedec.dir/imageio/webpdec.c.i

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/webpdec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imagedec.dir/imageio/webpdec.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/webpdec.c -o CMakeFiles/imagedec.dir/imageio/webpdec.c.s

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/wicdec.c.o: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/flags.make
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/wicdec.c.o: ../include/libwebp/imageio/wicdec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/wicdec.c.o"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/imagedec.dir/imageio/wicdec.c.o   -c /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/wicdec.c

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/wicdec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/imagedec.dir/imageio/wicdec.c.i"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/wicdec.c > CMakeFiles/imagedec.dir/imageio/wicdec.c.i

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/wicdec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/imagedec.dir/imageio/wicdec.c.s"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp/imageio/wicdec.c -o CMakeFiles/imagedec.dir/imageio/wicdec.c.s

# Object files for target imagedec
imagedec_OBJECTS = \
"CMakeFiles/imagedec.dir/imageio/image_dec.c.o" \
"CMakeFiles/imagedec.dir/imageio/jpegdec.c.o" \
"CMakeFiles/imagedec.dir/imageio/metadata.c.o" \
"CMakeFiles/imagedec.dir/imageio/pngdec.c.o" \
"CMakeFiles/imagedec.dir/imageio/pnmdec.c.o" \
"CMakeFiles/imagedec.dir/imageio/tiffdec.c.o" \
"CMakeFiles/imagedec.dir/imageio/webpdec.c.o" \
"CMakeFiles/imagedec.dir/imageio/wicdec.c.o"

# External object files for target imagedec
imagedec_EXTERNAL_OBJECTS =

../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/image_dec.c.o
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/jpegdec.c.o
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/metadata.c.o
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pngdec.c.o
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/pnmdec.c.o
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/tiffdec.c.o
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/webpdec.c.o
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/imageio/wicdec.c.o
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/build.make
../bin/_deps/webp-build/libimagedec.a: ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C static library libimagedec.a"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && $(CMAKE_COMMAND) -P CMakeFiles/imagedec.dir/cmake_clean_target.cmake
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imagedec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
../bin/_deps/webp-build/CMakeFiles/imagedec.dir/build: ../bin/_deps/webp-build/libimagedec.a

.PHONY : ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/build

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/clean:
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && $(CMAKE_COMMAND) -P CMakeFiles/imagedec.dir/cmake_clean.cmake
.PHONY : ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/clean

../bin/_deps/webp-build/CMakeFiles/imagedec.dir/depend:
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dkruger/git/course/workshops/opengl/src/01shaders /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp /home/dkruger/git/course/workshops/opengl/src/01shaders/build /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build/CMakeFiles/imagedec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ../bin/_deps/webp-build/CMakeFiles/imagedec.dir/depend
