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
CMAKE_SOURCE_DIR = /home/hl/github/data-structure/alg_cpp_code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hl/github/data-structure/alg_cpp_code/build

# Include any dependencies generated for this target.
include demo/CMakeFiles/array_struct_pointer.dir/depend.make

# Include the progress variables for this target.
include demo/CMakeFiles/array_struct_pointer.dir/progress.make

# Include the compile flags for this target's objects.
include demo/CMakeFiles/array_struct_pointer.dir/flags.make

demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o: demo/CMakeFiles/array_struct_pointer.dir/flags.make
demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o: ../demo/array_struct_pointer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hl/github/data-structure/alg_cpp_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o"
	cd /home/hl/github/data-structure/alg_cpp_code/build/demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o -c /home/hl/github/data-structure/alg_cpp_code/demo/array_struct_pointer.cpp

demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.i"
	cd /home/hl/github/data-structure/alg_cpp_code/build/demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hl/github/data-structure/alg_cpp_code/demo/array_struct_pointer.cpp > CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.i

demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.s"
	cd /home/hl/github/data-structure/alg_cpp_code/build/demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hl/github/data-structure/alg_cpp_code/demo/array_struct_pointer.cpp -o CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.s

demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o.requires:

.PHONY : demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o.requires

demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o.provides: demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o.requires
	$(MAKE) -f demo/CMakeFiles/array_struct_pointer.dir/build.make demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o.provides.build
.PHONY : demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o.provides

demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o.provides.build: demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o


# Object files for target array_struct_pointer
array_struct_pointer_OBJECTS = \
"CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o"

# External object files for target array_struct_pointer
array_struct_pointer_EXTERNAL_OBJECTS =

../bin/array_struct_pointer: demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o
../bin/array_struct_pointer: demo/CMakeFiles/array_struct_pointer.dir/build.make
../bin/array_struct_pointer: demo/CMakeFiles/array_struct_pointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hl/github/data-structure/alg_cpp_code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/array_struct_pointer"
	cd /home/hl/github/data-structure/alg_cpp_code/build/demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/array_struct_pointer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
demo/CMakeFiles/array_struct_pointer.dir/build: ../bin/array_struct_pointer

.PHONY : demo/CMakeFiles/array_struct_pointer.dir/build

demo/CMakeFiles/array_struct_pointer.dir/requires: demo/CMakeFiles/array_struct_pointer.dir/array_struct_pointer.cpp.o.requires

.PHONY : demo/CMakeFiles/array_struct_pointer.dir/requires

demo/CMakeFiles/array_struct_pointer.dir/clean:
	cd /home/hl/github/data-structure/alg_cpp_code/build/demo && $(CMAKE_COMMAND) -P CMakeFiles/array_struct_pointer.dir/cmake_clean.cmake
.PHONY : demo/CMakeFiles/array_struct_pointer.dir/clean

demo/CMakeFiles/array_struct_pointer.dir/depend:
	cd /home/hl/github/data-structure/alg_cpp_code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hl/github/data-structure/alg_cpp_code /home/hl/github/data-structure/alg_cpp_code/demo /home/hl/github/data-structure/alg_cpp_code/build /home/hl/github/data-structure/alg_cpp_code/build/demo /home/hl/github/data-structure/alg_cpp_code/build/demo/CMakeFiles/array_struct_pointer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/CMakeFiles/array_struct_pointer.dir/depend

