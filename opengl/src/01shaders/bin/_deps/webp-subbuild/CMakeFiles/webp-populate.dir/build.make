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
CMAKE_SOURCE_DIR = /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild

# Utility rule file for webp-populate.

# Include the progress variables for this target.
include CMakeFiles/webp-populate.dir/progress.make

CMakeFiles/webp-populate: CMakeFiles/webp-populate-complete


CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-install
CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-mkdir
CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-download
CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-update
CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-patch
CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-configure
CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-build
CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-install
CMakeFiles/webp-populate-complete: webp-populate-prefix/src/webp-populate-stamp/webp-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'webp-populate'"
	/usr/bin/cmake -E make_directory /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles
	/usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles/webp-populate-complete
	/usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp/webp-populate-done

webp-populate-prefix/src/webp-populate-stamp/webp-populate-install: webp-populate-prefix/src/webp-populate-stamp/webp-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'webp-populate'"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cmake -E echo_append
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp/webp-populate-install

webp-populate-prefix/src/webp-populate-stamp/webp-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'webp-populate'"
	/usr/bin/cmake -E make_directory /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp
	/usr/bin/cmake -E make_directory /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build
	/usr/bin/cmake -E make_directory /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix
	/usr/bin/cmake -E make_directory /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/tmp
	/usr/bin/cmake -E make_directory /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp
	/usr/bin/cmake -E make_directory /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src
	/usr/bin/cmake -E make_directory /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp
	/usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp/webp-populate-mkdir

webp-populate-prefix/src/webp-populate-stamp/webp-populate-download: webp-populate-prefix/src/webp-populate-stamp/webp-populate-gitinfo.txt
webp-populate-prefix/src/webp-populate-stamp/webp-populate-download: webp-populate-prefix/src/webp-populate-stamp/webp-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'webp-populate'"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/include && /usr/bin/cmake -P /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/tmp/webp-populate-gitclone.cmake
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/include && /usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp/webp-populate-download

webp-populate-prefix/src/webp-populate-stamp/webp-populate-update: webp-populate-prefix/src/webp-populate-stamp/webp-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'webp-populate'"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/include/libwebp && /usr/bin/cmake -P /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/tmp/webp-populate-gitupdate.cmake

webp-populate-prefix/src/webp-populate-stamp/webp-populate-patch: webp-populate-prefix/src/webp-populate-stamp/webp-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'webp-populate'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp/webp-populate-patch

webp-populate-prefix/src/webp-populate-stamp/webp-populate-configure: webp-populate-prefix/tmp/webp-populate-cfgcmd.txt
webp-populate-prefix/src/webp-populate-stamp/webp-populate-configure: webp-populate-prefix/src/webp-populate-stamp/webp-populate-update
webp-populate-prefix/src/webp-populate-stamp/webp-populate-configure: webp-populate-prefix/src/webp-populate-stamp/webp-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'webp-populate'"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cmake -E echo_append
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp/webp-populate-configure

webp-populate-prefix/src/webp-populate-stamp/webp-populate-build: webp-populate-prefix/src/webp-populate-stamp/webp-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'webp-populate'"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cmake -E echo_append
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp/webp-populate-build

webp-populate-prefix/src/webp-populate-stamp/webp-populate-test: webp-populate-prefix/src/webp-populate-stamp/webp-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'webp-populate'"
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cmake -E echo_append
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-build && /usr/bin/cmake -E touch /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/webp-populate-prefix/src/webp-populate-stamp/webp-populate-test

webp-populate: CMakeFiles/webp-populate
webp-populate: CMakeFiles/webp-populate-complete
webp-populate: webp-populate-prefix/src/webp-populate-stamp/webp-populate-install
webp-populate: webp-populate-prefix/src/webp-populate-stamp/webp-populate-mkdir
webp-populate: webp-populate-prefix/src/webp-populate-stamp/webp-populate-download
webp-populate: webp-populate-prefix/src/webp-populate-stamp/webp-populate-update
webp-populate: webp-populate-prefix/src/webp-populate-stamp/webp-populate-patch
webp-populate: webp-populate-prefix/src/webp-populate-stamp/webp-populate-configure
webp-populate: webp-populate-prefix/src/webp-populate-stamp/webp-populate-build
webp-populate: webp-populate-prefix/src/webp-populate-stamp/webp-populate-test
webp-populate: CMakeFiles/webp-populate.dir/build.make

.PHONY : webp-populate

# Rule to build all files generated by this target.
CMakeFiles/webp-populate.dir/build: webp-populate

.PHONY : CMakeFiles/webp-populate.dir/build

CMakeFiles/webp-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/webp-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/webp-populate.dir/clean

CMakeFiles/webp-populate.dir/depend:
	cd /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild /home/dkruger/git/course/workshops/opengl/src/01shaders/bin/_deps/webp-subbuild/CMakeFiles/webp-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/webp-populate.dir/depend
