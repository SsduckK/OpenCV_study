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
CMAKE_SOURCE_DIR = /home/honey/workspace/cvnew

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/honey/workspace/cvnew/build

# Include any dependencies generated for this target.
include CMakeFiles/testcv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testcv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testcv.dir/flags.make

CMakeFiles/testcv.dir/main.cpp.o: CMakeFiles/testcv.dir/flags.make
CMakeFiles/testcv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/honey/workspace/cvnew/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testcv.dir/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testcv.dir/main.cpp.o -c /home/honey/workspace/cvnew/main.cpp

CMakeFiles/testcv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testcv.dir/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/honey/workspace/cvnew/main.cpp > CMakeFiles/testcv.dir/main.cpp.i

CMakeFiles/testcv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testcv.dir/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/honey/workspace/cvnew/main.cpp -o CMakeFiles/testcv.dir/main.cpp.s

# Object files for target testcv
testcv_OBJECTS = \
"CMakeFiles/testcv.dir/main.cpp.o"

# External object files for target testcv
testcv_EXTERNAL_OBJECTS =

testcv: CMakeFiles/testcv.dir/main.cpp.o
testcv: CMakeFiles/testcv.dir/build.make
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: /home/honey/mylib/lib/opencv-4.5.4/lib/libopencv_world.so.4.5.4
testcv: CMakeFiles/testcv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/honey/workspace/cvnew/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testcv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testcv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testcv.dir/build: testcv

.PHONY : CMakeFiles/testcv.dir/build

CMakeFiles/testcv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testcv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testcv.dir/clean

CMakeFiles/testcv.dir/depend:
	cd /home/honey/workspace/cvnew/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/honey/workspace/cvnew /home/honey/workspace/cvnew /home/honey/workspace/cvnew/build /home/honey/workspace/cvnew/build /home/honey/workspace/cvnew/build/CMakeFiles/testcv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testcv.dir/depend
