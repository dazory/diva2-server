# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cvlab2/DIVA2/diva2-server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cvlab2/DIVA2/diva2-server/build

# Include any dependencies generated for this target.
include test/storing_raw/CMakeFiles/storingraw.dir/depend.make

# Include the progress variables for this target.
include test/storing_raw/CMakeFiles/storingraw.dir/progress.make

# Include the compile flags for this target's objects.
include test/storing_raw/CMakeFiles/storingraw.dir/flags.make

test/storing_raw/CMakeFiles/storingraw.dir/main.cpp.o: test/storing_raw/CMakeFiles/storingraw.dir/flags.make
test/storing_raw/CMakeFiles/storingraw.dir/main.cpp.o: ../test/storing_raw/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cvlab2/DIVA2/diva2-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/storing_raw/CMakeFiles/storingraw.dir/main.cpp.o"
	cd /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/storingraw.dir/main.cpp.o -c /home/cvlab2/DIVA2/diva2-server/test/storing_raw/main.cpp

test/storing_raw/CMakeFiles/storingraw.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/storingraw.dir/main.cpp.i"
	cd /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cvlab2/DIVA2/diva2-server/test/storing_raw/main.cpp > CMakeFiles/storingraw.dir/main.cpp.i

test/storing_raw/CMakeFiles/storingraw.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/storingraw.dir/main.cpp.s"
	cd /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cvlab2/DIVA2/diva2-server/test/storing_raw/main.cpp -o CMakeFiles/storingraw.dir/main.cpp.s

test/storing_raw/CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.o: test/storing_raw/CMakeFiles/storingraw.dir/flags.make
test/storing_raw/CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.o: ../test/storing_raw/GpsRawStoringThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cvlab2/DIVA2/diva2-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/storing_raw/CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.o"
	cd /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.o -c /home/cvlab2/DIVA2/diva2-server/test/storing_raw/GpsRawStoringThread.cpp

test/storing_raw/CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.i"
	cd /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cvlab2/DIVA2/diva2-server/test/storing_raw/GpsRawStoringThread.cpp > CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.i

test/storing_raw/CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.s"
	cd /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cvlab2/DIVA2/diva2-server/test/storing_raw/GpsRawStoringThread.cpp -o CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.s

# Object files for target storingraw
storingraw_OBJECTS = \
"CMakeFiles/storingraw.dir/main.cpp.o" \
"CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.o"

# External object files for target storingraw
storingraw_EXTERNAL_OBJECTS =

test/storing_raw/storingraw: test/storing_raw/CMakeFiles/storingraw.dir/main.cpp.o
test/storing_raw/storingraw: test/storing_raw/CMakeFiles/storingraw.dir/GpsRawStoringThread.cpp.o
test/storing_raw/storingraw: test/storing_raw/CMakeFiles/storingraw.dir/build.make
test/storing_raw/storingraw: /usr/local/lib/libzmq.so
test/storing_raw/storingraw: /usr/lib/x86_64-linux-gnu/libpqxx.so
test/storing_raw/storingraw: /usr/lib/x86_64-linux-gnu/libpq.so
test/storing_raw/storingraw: test/storing_raw/CMakeFiles/storingraw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cvlab2/DIVA2/diva2-server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable storingraw"
	cd /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/storingraw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/storing_raw/CMakeFiles/storingraw.dir/build: test/storing_raw/storingraw

.PHONY : test/storing_raw/CMakeFiles/storingraw.dir/build

test/storing_raw/CMakeFiles/storingraw.dir/clean:
	cd /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw && $(CMAKE_COMMAND) -P CMakeFiles/storingraw.dir/cmake_clean.cmake
.PHONY : test/storing_raw/CMakeFiles/storingraw.dir/clean

test/storing_raw/CMakeFiles/storingraw.dir/depend:
	cd /home/cvlab2/DIVA2/diva2-server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cvlab2/DIVA2/diva2-server /home/cvlab2/DIVA2/diva2-server/test/storing_raw /home/cvlab2/DIVA2/diva2-server/build /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw /home/cvlab2/DIVA2/diva2-server/build/test/storing_raw/CMakeFiles/storingraw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/storing_raw/CMakeFiles/storingraw.dir/depend
