# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = C:\installation\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\installation\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\build"

# Include any dependencies generated for this target.
include CMakeFiles/isomorphism.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/isomorphism.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/isomorphism.dir/flags.make

CMakeFiles/isomorphism.dir/main.cc.obj: CMakeFiles/isomorphism.dir/flags.make
CMakeFiles/isomorphism.dir/main.cc.obj: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/isomorphism.dir/main.cc.obj"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\isomorphism.dir\main.cc.obj -c "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\main.cc"

CMakeFiles/isomorphism.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/isomorphism.dir/main.cc.i"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\main.cc" > CMakeFiles\isomorphism.dir\main.cc.i

CMakeFiles/isomorphism.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/isomorphism.dir/main.cc.s"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\main.cc" -o CMakeFiles\isomorphism.dir\main.cc.s

# Object files for target isomorphism
isomorphism_OBJECTS = \
"CMakeFiles/isomorphism.dir/main.cc.obj"

# External object files for target isomorphism
isomorphism_EXTERNAL_OBJECTS =

isomorphism.exe: CMakeFiles/isomorphism.dir/main.cc.obj
isomorphism.exe: CMakeFiles/isomorphism.dir/build.make
isomorphism.exe: CMakeFiles/isomorphism.dir/linklibs.rsp
isomorphism.exe: CMakeFiles/isomorphism.dir/objects1.rsp
isomorphism.exe: CMakeFiles/isomorphism.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable isomorphism.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\isomorphism.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/isomorphism.dir/build: isomorphism.exe

.PHONY : CMakeFiles/isomorphism.dir/build

CMakeFiles/isomorphism.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\isomorphism.dir\cmake_clean.cmake
.PHONY : CMakeFiles/isomorphism.dir/clean

CMakeFiles/isomorphism.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\build" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\build" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\isomorphism\build\CMakeFiles\isomorphism.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/isomorphism.dir/depend

