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
include CMakeFiles/parsejpeg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/parsejpeg.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/parsejpeg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/parsejpeg.dir/flags.make

CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.obj: CMakeFiles/parsejpeg.dir/flags.make
CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.obj: CMakeFiles/parsejpeg.dir/includes_CXX.rsp
CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.obj: D:/MY_CODE/JPG/src/parsejpeg.cpp
CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.obj: CMakeFiles/parsejpeg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\MY_CODE\JPG\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.obj"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.obj -MF CMakeFiles\parsejpeg.dir\src\parsejpeg.cpp.obj.d -o CMakeFiles\parsejpeg.dir\src\parsejpeg.cpp.obj -c D:\MY_CODE\JPG\src\parsejpeg.cpp

CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.i"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\MY_CODE\JPG\src\parsejpeg.cpp > CMakeFiles\parsejpeg.dir\src\parsejpeg.cpp.i

CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.s"
	D:\CodeBlocks\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\MY_CODE\JPG\src\parsejpeg.cpp -o CMakeFiles\parsejpeg.dir\src\parsejpeg.cpp.s

# Object files for target parsejpeg
parsejpeg_OBJECTS = \
"CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.obj"

# External object files for target parsejpeg
parsejpeg_EXTERNAL_OBJECTS =

D:/MY_CODE/JPG/lib/libparsejpeg.a: CMakeFiles/parsejpeg.dir/src/parsejpeg.cpp.obj
D:/MY_CODE/JPG/lib/libparsejpeg.a: CMakeFiles/parsejpeg.dir/build.make
D:/MY_CODE/JPG/lib/libparsejpeg.a: CMakeFiles/parsejpeg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\MY_CODE\JPG\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library D:\MY_CODE\JPG\lib\libparsejpeg.a"
	$(CMAKE_COMMAND) -P CMakeFiles\parsejpeg.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\parsejpeg.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/parsejpeg.dir/build: D:/MY_CODE/JPG/lib/libparsejpeg.a
.PHONY : CMakeFiles/parsejpeg.dir/build

CMakeFiles/parsejpeg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\parsejpeg.dir\cmake_clean.cmake
.PHONY : CMakeFiles/parsejpeg.dir/clean

CMakeFiles/parsejpeg.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\MY_CODE\JPG D:\MY_CODE\JPG D:\MY_CODE\JPG\build D:\MY_CODE\JPG\build D:\MY_CODE\JPG\build\CMakeFiles\parsejpeg.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/parsejpeg.dir/depend
