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
CMAKE_SOURCE_DIR = "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\build"

# Include any dependencies generated for this target.
include CMakeFiles/huffman_tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/huffman_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huffman_tree.dir/flags.make

CMakeFiles/huffman_tree.dir/main.cc.obj: CMakeFiles/huffman_tree.dir/flags.make
CMakeFiles/huffman_tree.dir/main.cc.obj: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huffman_tree.dir/main.cc.obj"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\huffman_tree.dir\main.cc.obj -c "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\main.cc"

CMakeFiles/huffman_tree.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman_tree.dir/main.cc.i"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\main.cc" > CMakeFiles\huffman_tree.dir\main.cc.i

CMakeFiles/huffman_tree.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman_tree.dir/main.cc.s"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\main.cc" -o CMakeFiles\huffman_tree.dir\main.cc.s

CMakeFiles/huffman_tree.dir/huffman_tree.cc.obj: CMakeFiles/huffman_tree.dir/flags.make
CMakeFiles/huffman_tree.dir/huffman_tree.cc.obj: ../huffman_tree.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/huffman_tree.dir/huffman_tree.cc.obj"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\huffman_tree.dir\huffman_tree.cc.obj -c "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\huffman_tree.cc"

CMakeFiles/huffman_tree.dir/huffman_tree.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huffman_tree.dir/huffman_tree.cc.i"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\huffman_tree.cc" > CMakeFiles\huffman_tree.dir\huffman_tree.cc.i

CMakeFiles/huffman_tree.dir/huffman_tree.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huffman_tree.dir/huffman_tree.cc.s"
	C:\installation\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\huffman_tree.cc" -o CMakeFiles\huffman_tree.dir\huffman_tree.cc.s

# Object files for target huffman_tree
huffman_tree_OBJECTS = \
"CMakeFiles/huffman_tree.dir/main.cc.obj" \
"CMakeFiles/huffman_tree.dir/huffman_tree.cc.obj"

# External object files for target huffman_tree
huffman_tree_EXTERNAL_OBJECTS =

huffman_tree.exe: CMakeFiles/huffman_tree.dir/main.cc.obj
huffman_tree.exe: CMakeFiles/huffman_tree.dir/huffman_tree.cc.obj
huffman_tree.exe: CMakeFiles/huffman_tree.dir/build.make
huffman_tree.exe: CMakeFiles/huffman_tree.dir/linklibs.rsp
huffman_tree.exe: CMakeFiles/huffman_tree.dir/objects1.rsp
huffman_tree.exe: CMakeFiles/huffman_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable huffman_tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\huffman_tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huffman_tree.dir/build: huffman_tree.exe

.PHONY : CMakeFiles/huffman_tree.dir/build

CMakeFiles/huffman_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\huffman_tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/huffman_tree.dir/clean

CMakeFiles/huffman_tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\build" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\build" "D:\Box\Processing Unclassified\cpp\DataStructureAlgorithm\BinaryTree\huffman_tree\build\CMakeFiles\huffman_tree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/huffman_tree.dir/depend

