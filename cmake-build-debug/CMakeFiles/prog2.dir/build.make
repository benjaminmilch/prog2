# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/ben/Desktop/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ben/Desktop/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ben/CLionProjects/prog2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ben/CLionProjects/prog2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/prog2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prog2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prog2.dir/flags.make

CMakeFiles/prog2.dir/main.cpp.o: CMakeFiles/prog2.dir/flags.make
CMakeFiles/prog2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/prog2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prog2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog2.dir/main.cpp.o -c /home/ben/CLionProjects/prog2/main.cpp

CMakeFiles/prog2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/prog2/main.cpp > CMakeFiles/prog2.dir/main.cpp.i

CMakeFiles/prog2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/prog2/main.cpp -o CMakeFiles/prog2.dir/main.cpp.s

CMakeFiles/prog2.dir/MySerialServer.cpp.o: CMakeFiles/prog2.dir/flags.make
CMakeFiles/prog2.dir/MySerialServer.cpp.o: ../MySerialServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/prog2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/prog2.dir/MySerialServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog2.dir/MySerialServer.cpp.o -c /home/ben/CLionProjects/prog2/MySerialServer.cpp

CMakeFiles/prog2.dir/MySerialServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog2.dir/MySerialServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/prog2/MySerialServer.cpp > CMakeFiles/prog2.dir/MySerialServer.cpp.i

CMakeFiles/prog2.dir/MySerialServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog2.dir/MySerialServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/prog2/MySerialServer.cpp -o CMakeFiles/prog2.dir/MySerialServer.cpp.s

CMakeFiles/prog2.dir/MyTestClientHandler.cpp.o: CMakeFiles/prog2.dir/flags.make
CMakeFiles/prog2.dir/MyTestClientHandler.cpp.o: ../MyTestClientHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/prog2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/prog2.dir/MyTestClientHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog2.dir/MyTestClientHandler.cpp.o -c /home/ben/CLionProjects/prog2/MyTestClientHandler.cpp

CMakeFiles/prog2.dir/MyTestClientHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog2.dir/MyTestClientHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/prog2/MyTestClientHandler.cpp > CMakeFiles/prog2.dir/MyTestClientHandler.cpp.i

CMakeFiles/prog2.dir/MyTestClientHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog2.dir/MyTestClientHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/prog2/MyTestClientHandler.cpp -o CMakeFiles/prog2.dir/MyTestClientHandler.cpp.s

CMakeFiles/prog2.dir/FileCacheManager.cpp.o: CMakeFiles/prog2.dir/flags.make
CMakeFiles/prog2.dir/FileCacheManager.cpp.o: ../FileCacheManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/prog2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/prog2.dir/FileCacheManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prog2.dir/FileCacheManager.cpp.o -c /home/ben/CLionProjects/prog2/FileCacheManager.cpp

CMakeFiles/prog2.dir/FileCacheManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prog2.dir/FileCacheManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/prog2/FileCacheManager.cpp > CMakeFiles/prog2.dir/FileCacheManager.cpp.i

CMakeFiles/prog2.dir/FileCacheManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prog2.dir/FileCacheManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/prog2/FileCacheManager.cpp -o CMakeFiles/prog2.dir/FileCacheManager.cpp.s

# Object files for target prog2
prog2_OBJECTS = \
"CMakeFiles/prog2.dir/main.cpp.o" \
"CMakeFiles/prog2.dir/MySerialServer.cpp.o" \
"CMakeFiles/prog2.dir/MyTestClientHandler.cpp.o" \
"CMakeFiles/prog2.dir/FileCacheManager.cpp.o"

# External object files for target prog2
prog2_EXTERNAL_OBJECTS =

prog2: CMakeFiles/prog2.dir/main.cpp.o
prog2: CMakeFiles/prog2.dir/MySerialServer.cpp.o
prog2: CMakeFiles/prog2.dir/MyTestClientHandler.cpp.o
prog2: CMakeFiles/prog2.dir/FileCacheManager.cpp.o
prog2: CMakeFiles/prog2.dir/build.make
prog2: CMakeFiles/prog2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/CLionProjects/prog2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable prog2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prog2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prog2.dir/build: prog2

.PHONY : CMakeFiles/prog2.dir/build

CMakeFiles/prog2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prog2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prog2.dir/clean

CMakeFiles/prog2.dir/depend:
	cd /home/ben/CLionProjects/prog2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/CLionProjects/prog2 /home/ben/CLionProjects/prog2 /home/ben/CLionProjects/prog2/cmake-build-debug /home/ben/CLionProjects/prog2/cmake-build-debug /home/ben/CLionProjects/prog2/cmake-build-debug/CMakeFiles/prog2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prog2.dir/depend

