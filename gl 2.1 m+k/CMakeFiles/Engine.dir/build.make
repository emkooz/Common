# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k"

# Include any dependencies generated for this target.
include CMakeFiles/Engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Engine.dir/flags.make

CMakeFiles/Engine.dir/test.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/test.cpp.o: test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Engine.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/test.cpp.o -c "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/test.cpp"

CMakeFiles/Engine.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/test.cpp" > CMakeFiles/Engine.dir/test.cpp.i

CMakeFiles/Engine.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/test.cpp" -o CMakeFiles/Engine.dir/test.cpp.s

CMakeFiles/Engine.dir/test.cpp.o.requires:
.PHONY : CMakeFiles/Engine.dir/test.cpp.o.requires

CMakeFiles/Engine.dir/test.cpp.o.provides: CMakeFiles/Engine.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/Engine.dir/build.make CMakeFiles/Engine.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/Engine.dir/test.cpp.o.provides

CMakeFiles/Engine.dir/test.cpp.o.provides.build: CMakeFiles/Engine.dir/test.cpp.o

CMakeFiles/Engine.dir/Camera.cpp.o: CMakeFiles/Engine.dir/flags.make
CMakeFiles/Engine.dir/Camera.cpp.o: Camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Engine.dir/Camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Engine.dir/Camera.cpp.o -c "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/Camera.cpp"

CMakeFiles/Engine.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Engine.dir/Camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/Camera.cpp" > CMakeFiles/Engine.dir/Camera.cpp.i

CMakeFiles/Engine.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Engine.dir/Camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/Camera.cpp" -o CMakeFiles/Engine.dir/Camera.cpp.s

CMakeFiles/Engine.dir/Camera.cpp.o.requires:
.PHONY : CMakeFiles/Engine.dir/Camera.cpp.o.requires

CMakeFiles/Engine.dir/Camera.cpp.o.provides: CMakeFiles/Engine.dir/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/Engine.dir/build.make CMakeFiles/Engine.dir/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/Engine.dir/Camera.cpp.o.provides

CMakeFiles/Engine.dir/Camera.cpp.o.provides.build: CMakeFiles/Engine.dir/Camera.cpp.o

# Object files for target Engine
Engine_OBJECTS = \
"CMakeFiles/Engine.dir/test.cpp.o" \
"CMakeFiles/Engine.dir/Camera.cpp.o"

# External object files for target Engine
Engine_EXTERNAL_OBJECTS =

Engine: CMakeFiles/Engine.dir/test.cpp.o
Engine: CMakeFiles/Engine.dir/Camera.cpp.o
Engine: CMakeFiles/Engine.dir/build.make
Engine: /usr/lib/libGLU.so
Engine: /usr/lib/libGL.so
Engine: /usr/lib/libSM.so
Engine: /usr/lib/libICE.so
Engine: /usr/lib/libX11.so
Engine: /usr/lib/libXext.so
Engine: /usr/lib/libGLEW.so
Engine: /usr/lib/libglfw.so
Engine: /usr/lib/libSOIL.a
Engine: CMakeFiles/Engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Engine.dir/build: Engine
.PHONY : CMakeFiles/Engine.dir/build

CMakeFiles/Engine.dir/requires: CMakeFiles/Engine.dir/test.cpp.o.requires
CMakeFiles/Engine.dir/requires: CMakeFiles/Engine.dir/Camera.cpp.o.requires
.PHONY : CMakeFiles/Engine.dir/requires

CMakeFiles/Engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Engine.dir/clean

CMakeFiles/Engine.dir/depend:
	cd "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k" "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k" "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k" "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k" "/home/bumrang/dump v2/dump/Open.gl/matrix stuff/gl 2.1 m+k/CMakeFiles/Engine.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Engine.dir/depend

