# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mr_knownothing/github/network-jammer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mr_knownothing/github/network-jammer

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/opt/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/opt/cmake/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mr_knownothing/github/network-jammer/CMakeFiles /home/mr_knownothing/github/network-jammer/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mr_knownothing/github/network-jammer/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named network-jammer

# Build rule for target.
network-jammer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 network-jammer
.PHONY : network-jammer

# fast build rule for target.
network-jammer/fast:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/build
.PHONY : network-jammer/fast

command_line.o: command_line.cpp.o

.PHONY : command_line.o

# target to build an object file
command_line.cpp.o:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/command_line.cpp.o
.PHONY : command_line.cpp.o

command_line.i: command_line.cpp.i

.PHONY : command_line.i

# target to preprocess a source file
command_line.cpp.i:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/command_line.cpp.i
.PHONY : command_line.cpp.i

command_line.s: command_line.cpp.s

.PHONY : command_line.s

# target to generate assembly for a file
command_line.cpp.s:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/command_line.cpp.s
.PHONY : command_line.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/main.cpp.s
.PHONY : main.cpp.s

network.o: network.cpp.o

.PHONY : network.o

# target to build an object file
network.cpp.o:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/network.cpp.o
.PHONY : network.cpp.o

network.i: network.cpp.i

.PHONY : network.i

# target to preprocess a source file
network.cpp.i:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/network.cpp.i
.PHONY : network.cpp.i

network.s: network.cpp.s

.PHONY : network.s

# target to generate assembly for a file
network.cpp.s:
	$(MAKE) -f CMakeFiles/network-jammer.dir/build.make CMakeFiles/network-jammer.dir/network.cpp.s
.PHONY : network.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... network-jammer"
	@echo "... command_line.o"
	@echo "... command_line.i"
	@echo "... command_line.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... network.o"
	@echo "... network.i"
	@echo "... network.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

