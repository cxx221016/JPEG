# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\MY_CODE\JPG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\MY_CODE\JPG\build

# Include any dependencies generated for this target.
include CMakeFiles/SOS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SOS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SOS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SOS.dir/flags.make

CMakeFiles/SOS.dir/src/SOS.cpp.obj: CMakeFiles/SOS.dir/flags.make
CMakeFiles/SOS.dir/src/SOS.cpp.obj: CMakeFiles/SOS.dir/includes_CXX.rsp
CMakeFiles/SOS.dir/src/SOS.cpp.obj: D:/MY_CODE/JPG/src/SOS.cpp
CMakeFiles/SOS.dir/src/SOS.cpp.obj: CMakeFiles/SOS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MY_CODE\JPG\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SOS.dir/src/SOS.cpp.obj"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SOS.dir/src/SOS.cpp.obj -MF CMakeFiles\SOS.dir\src\SOS.cpp.obj.d -o CMakeFiles\SOS.dir\src\SOS.cpp.obj -c D:\MY_CODE\JPG\src\SOS.cpp

CMakeFiles/SOS.dir/src/SOS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SOS.dir/src/SOS.cpp.i"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\MY_CODE\JPG\src\SOS.cpp > CMakeFiles\SOS.dir\src\SOS.cpp.i

CMakeFiles/SOS.dir/src/SOS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SOS.dir/src/SOS.cpp.s"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\MY_CODE\JPG\src\SOS.cpp -o CMakeFiles\SOS.dir\src\SOS.cpp.s

# Object files for target SOS
SOS_OBJECTS = \
"CMakeFiles/SOS.dir/src/SOS.cpp.obj"

# External object files for target SOS
SOS_EXTERNAL_OBJECTS =

D:/MY_CODE/JPG/lib/libSOS.a: CMakeFiles/SOS.dir/src/SOS.cpp.obj
D:/MY_CODE/JPG/lib/libSOS.a: CMakeFiles/SOS.dir/build.make
D:/MY_CODE/JPG/lib/libSOS.a: CMakeFiles/SOS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MY_CODE\JPG\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library D:\MY_CODE\JPG\lib\libSOS.a"
	$(CMAKE_COMMAND) -P CMakeFiles\SOS.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SOS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SOS.dir/build: D:/MY_CODE/JPG/lib/libSOS.a
.PHONY : CMakeFiles/SOS.dir/build

CMakeFiles/SOS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SOS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SOS.dir/clean

CMakeFiles/SOS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MY_CODE\JPG D:\MY_CODE\JPG D:\MY_CODE\JPG\build D:\MY_CODE\JPG\build D:\MY_CODE\JPG\build\CMakeFiles\SOS.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SOS.dir/depend

