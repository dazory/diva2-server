# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/dahye/diva2-server-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dahye/diva2-server-1/build

# Include any dependencies generated for this target.
include CMakeFiles/diva2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/diva2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/diva2.dir/flags.make

CMakeFiles/diva2.dir/main.cpp.o: CMakeFiles/diva2.dir/flags.make
CMakeFiles/diva2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dahye/diva2-server-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/diva2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/diva2.dir/main.cpp.o -c /home/dahye/diva2-server-1/main.cpp

CMakeFiles/diva2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/diva2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dahye/diva2-server-1/main.cpp > CMakeFiles/diva2.dir/main.cpp.i

CMakeFiles/diva2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/diva2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dahye/diva2-server-1/main.cpp -o CMakeFiles/diva2.dir/main.cpp.s

CMakeFiles/diva2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/diva2.dir/main.cpp.o.requires

CMakeFiles/diva2.dir/main.cpp.o.provides: CMakeFiles/diva2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/diva2.dir/build.make CMakeFiles/diva2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/diva2.dir/main.cpp.o.provides

CMakeFiles/diva2.dir/main.cpp.o.provides.build: CMakeFiles/diva2.dir/main.cpp.o


# Object files for target diva2
diva2_OBJECTS = \
"CMakeFiles/diva2.dir/main.cpp.o"

# External object files for target diva2
diva2_EXTERNAL_OBJECTS =

diva2: CMakeFiles/diva2.dir/main.cpp.o
diva2: CMakeFiles/diva2.dir/build.make
diva2: /usr/local/lib/libzmq.so
diva2: /usr/share/c++-mscl/libmscl.so
diva2: /usr/local/lib/libzmq.so
diva2: /usr/share/c++-mscl/libmscl.so
diva2: CMakeFiles/diva2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dahye/diva2-server-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable diva2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/diva2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/diva2.dir/build: diva2

.PHONY : CMakeFiles/diva2.dir/build

CMakeFiles/diva2.dir/requires: CMakeFiles/diva2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/diva2.dir/requires

CMakeFiles/diva2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/diva2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/diva2.dir/clean

CMakeFiles/diva2.dir/depend:
	cd /home/dahye/diva2-server-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dahye/diva2-server-1 /home/dahye/diva2-server-1 /home/dahye/diva2-server-1/build /home/dahye/diva2-server-1/build /home/dahye/diva2-server-1/build/CMakeFiles/diva2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/diva2.dir/depend

