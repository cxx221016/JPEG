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
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/includes_CXX.rsp
CMakeFiles/main.dir/main.cpp.obj: D:/MY_CODE/JPG/main.cpp
CMakeFiles/main.dir/main.cpp.obj: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MY_CODE\JPG\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.obj"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.obj -MF CMakeFiles\main.dir\main.cpp.obj.d -o CMakeFiles\main.dir\main.cpp.obj -c D:\MY_CODE\JPG\main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\MY_CODE\JPG\main.cpp > CMakeFiles\main.dir\main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\MY_CODE\JPG\main.cpp -o CMakeFiles\main.dir\main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

D:/MY_CODE/JPG/bin/main.exe: CMakeFiles/main.dir/main.cpp.obj
D:/MY_CODE/JPG/bin/main.exe: CMakeFiles/main.dir/build.make
D:/MY_CODE/JPG/bin/main.exe: D:/MY_CODE/JPG/lib/libparsejpeg.a
D:/MY_CODE/JPG/bin/main.exe: D:/MY_CODE/JPG/lib/libAPP0.a
D:/MY_CODE/JPG/bin/main.exe: D:/MY_CODE/JPG/lib/libDQT.a
D:/MY_CODE/JPG/bin/main.exe: D:/MY_CODE/JPG/lib/libSOF.a
D:/MY_CODE/JPG/bin/main.exe: D:/MY_CODE/JPG/lib/libDHT.a
D:/MY_CODE/JPG/bin/main.exe: D:/MY_CODE/JPG/lib/libSOS.a
D:/MY_CODE/JPG/bin/main.exe: D:/MY_CODE/JPG/lib/libSerial.a
D:/MY_CODE/JPG/bin/main.exe: CMakeFiles/main.dir/linkLibs.rsp
D:/MY_CODE/JPG/bin/main.exe: CMakeFiles/main.dir/objects1.rsp
D:/MY_CODE/JPG/bin/main.exe: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MY_CODE\JPG\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable D:\MY_CODE\JPG\bin\main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: D:/MY_CODE/JPG/bin/main.exe
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MY_CODE\JPG D:\MY_CODE\JPG D:\MY_CODE\JPG\build D:\MY_CODE\JPG\build D:\MY_CODE\JPG\build\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

