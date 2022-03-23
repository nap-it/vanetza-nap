# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/rrosmaninho/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/rrosmaninho/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rrosmaninho/playground/vanetza

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rrosmaninho/playground/vanetza/cmake-build-debug

# Include any dependencies generated for this target.
include vanetza/gnss/CMakeFiles/gnss.dir/depend.make
# Include the progress variables for this target.
include vanetza/gnss/CMakeFiles/gnss.dir/progress.make

# Include the compile flags for this target's objects.
include vanetza/gnss/CMakeFiles/gnss.dir/flags.make

vanetza/gnss/CMakeFiles/gnss.dir/nmea.cpp.o: vanetza/gnss/CMakeFiles/gnss.dir/flags.make
vanetza/gnss/CMakeFiles/gnss.dir/nmea.cpp.o: ../vanetza/gnss/nmea.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rrosmaninho/playground/vanetza/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object vanetza/gnss/CMakeFiles/gnss.dir/nmea.cpp.o"
	cd /home/rrosmaninho/playground/vanetza/cmake-build-debug/vanetza/gnss && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gnss.dir/nmea.cpp.o -c /home/rrosmaninho/playground/vanetza/vanetza/gnss/nmea.cpp

vanetza/gnss/CMakeFiles/gnss.dir/nmea.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gnss.dir/nmea.cpp.i"
	cd /home/rrosmaninho/playground/vanetza/cmake-build-debug/vanetza/gnss && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rrosmaninho/playground/vanetza/vanetza/gnss/nmea.cpp > CMakeFiles/gnss.dir/nmea.cpp.i

vanetza/gnss/CMakeFiles/gnss.dir/nmea.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gnss.dir/nmea.cpp.s"
	cd /home/rrosmaninho/playground/vanetza/cmake-build-debug/vanetza/gnss && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rrosmaninho/playground/vanetza/vanetza/gnss/nmea.cpp -o CMakeFiles/gnss.dir/nmea.cpp.s

# Object files for target gnss
gnss_OBJECTS = \
"CMakeFiles/gnss.dir/nmea.cpp.o"

# External object files for target gnss
gnss_EXTERNAL_OBJECTS =

lib/static/libvanetza_gnss.a: vanetza/gnss/CMakeFiles/gnss.dir/nmea.cpp.o
lib/static/libvanetza_gnss.a: vanetza/gnss/CMakeFiles/gnss.dir/build.make
lib/static/libvanetza_gnss.a: vanetza/gnss/CMakeFiles/gnss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rrosmaninho/playground/vanetza/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/static/libvanetza_gnss.a"
	cd /home/rrosmaninho/playground/vanetza/cmake-build-debug/vanetza/gnss && $(CMAKE_COMMAND) -P CMakeFiles/gnss.dir/cmake_clean_target.cmake
	cd /home/rrosmaninho/playground/vanetza/cmake-build-debug/vanetza/gnss && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gnss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vanetza/gnss/CMakeFiles/gnss.dir/build: lib/static/libvanetza_gnss.a
.PHONY : vanetza/gnss/CMakeFiles/gnss.dir/build

vanetza/gnss/CMakeFiles/gnss.dir/clean:
	cd /home/rrosmaninho/playground/vanetza/cmake-build-debug/vanetza/gnss && $(CMAKE_COMMAND) -P CMakeFiles/gnss.dir/cmake_clean.cmake
.PHONY : vanetza/gnss/CMakeFiles/gnss.dir/clean

vanetza/gnss/CMakeFiles/gnss.dir/depend:
	cd /home/rrosmaninho/playground/vanetza/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rrosmaninho/playground/vanetza /home/rrosmaninho/playground/vanetza/vanetza/gnss /home/rrosmaninho/playground/vanetza/cmake-build-debug /home/rrosmaninho/playground/vanetza/cmake-build-debug/vanetza/gnss /home/rrosmaninho/playground/vanetza/cmake-build-debug/vanetza/gnss/CMakeFiles/gnss.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vanetza/gnss/CMakeFiles/gnss.dir/depend

