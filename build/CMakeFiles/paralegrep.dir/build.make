# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Giovanni/Documents/IFB/SO/paralegrep

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Giovanni/Documents/IFB/SO/paralegrep/build

# Include any dependencies generated for this target.
include CMakeFiles/paralegrep.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/paralegrep.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/paralegrep.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/paralegrep.dir/flags.make

CMakeFiles/paralegrep.dir/codegen:
.PHONY : CMakeFiles/paralegrep.dir/codegen

CMakeFiles/paralegrep.dir/src/main.c.o: CMakeFiles/paralegrep.dir/flags.make
CMakeFiles/paralegrep.dir/src/main.c.o: /home/Giovanni/Documents/IFB/SO/paralegrep/src/main.c
CMakeFiles/paralegrep.dir/src/main.c.o: CMakeFiles/paralegrep.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/Giovanni/Documents/IFB/SO/paralegrep/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/paralegrep.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/paralegrep.dir/src/main.c.o -MF CMakeFiles/paralegrep.dir/src/main.c.o.d -o CMakeFiles/paralegrep.dir/src/main.c.o -c /home/Giovanni/Documents/IFB/SO/paralegrep/src/main.c

CMakeFiles/paralegrep.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/paralegrep.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/Giovanni/Documents/IFB/SO/paralegrep/src/main.c > CMakeFiles/paralegrep.dir/src/main.c.i

CMakeFiles/paralegrep.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/paralegrep.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/Giovanni/Documents/IFB/SO/paralegrep/src/main.c -o CMakeFiles/paralegrep.dir/src/main.c.s

CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o: CMakeFiles/paralegrep.dir/flags.make
CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o: /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_dispatcher.c
CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o: CMakeFiles/paralegrep.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/Giovanni/Documents/IFB/SO/paralegrep/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o -MF CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o.d -o CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o -c /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_dispatcher.c

CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_dispatcher.c > CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.i

CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_dispatcher.c -o CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.s

CMakeFiles/paralegrep.dir/src/thread_worker.c.o: CMakeFiles/paralegrep.dir/flags.make
CMakeFiles/paralegrep.dir/src/thread_worker.c.o: /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_worker.c
CMakeFiles/paralegrep.dir/src/thread_worker.c.o: CMakeFiles/paralegrep.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/Giovanni/Documents/IFB/SO/paralegrep/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/paralegrep.dir/src/thread_worker.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/paralegrep.dir/src/thread_worker.c.o -MF CMakeFiles/paralegrep.dir/src/thread_worker.c.o.d -o CMakeFiles/paralegrep.dir/src/thread_worker.c.o -c /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_worker.c

CMakeFiles/paralegrep.dir/src/thread_worker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/paralegrep.dir/src/thread_worker.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_worker.c > CMakeFiles/paralegrep.dir/src/thread_worker.c.i

CMakeFiles/paralegrep.dir/src/thread_worker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/paralegrep.dir/src/thread_worker.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_worker.c -o CMakeFiles/paralegrep.dir/src/thread_worker.c.s

CMakeFiles/paralegrep.dir/src/thread_ranking.c.o: CMakeFiles/paralegrep.dir/flags.make
CMakeFiles/paralegrep.dir/src/thread_ranking.c.o: /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_ranking.c
CMakeFiles/paralegrep.dir/src/thread_ranking.c.o: CMakeFiles/paralegrep.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/Giovanni/Documents/IFB/SO/paralegrep/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/paralegrep.dir/src/thread_ranking.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/paralegrep.dir/src/thread_ranking.c.o -MF CMakeFiles/paralegrep.dir/src/thread_ranking.c.o.d -o CMakeFiles/paralegrep.dir/src/thread_ranking.c.o -c /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_ranking.c

CMakeFiles/paralegrep.dir/src/thread_ranking.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/paralegrep.dir/src/thread_ranking.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_ranking.c > CMakeFiles/paralegrep.dir/src/thread_ranking.c.i

CMakeFiles/paralegrep.dir/src/thread_ranking.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/paralegrep.dir/src/thread_ranking.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/Giovanni/Documents/IFB/SO/paralegrep/src/thread_ranking.c -o CMakeFiles/paralegrep.dir/src/thread_ranking.c.s

CMakeFiles/paralegrep.dir/src/utils.c.o: CMakeFiles/paralegrep.dir/flags.make
CMakeFiles/paralegrep.dir/src/utils.c.o: /home/Giovanni/Documents/IFB/SO/paralegrep/src/utils.c
CMakeFiles/paralegrep.dir/src/utils.c.o: CMakeFiles/paralegrep.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/Giovanni/Documents/IFB/SO/paralegrep/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/paralegrep.dir/src/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/paralegrep.dir/src/utils.c.o -MF CMakeFiles/paralegrep.dir/src/utils.c.o.d -o CMakeFiles/paralegrep.dir/src/utils.c.o -c /home/Giovanni/Documents/IFB/SO/paralegrep/src/utils.c

CMakeFiles/paralegrep.dir/src/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/paralegrep.dir/src/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/Giovanni/Documents/IFB/SO/paralegrep/src/utils.c > CMakeFiles/paralegrep.dir/src/utils.c.i

CMakeFiles/paralegrep.dir/src/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/paralegrep.dir/src/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/Giovanni/Documents/IFB/SO/paralegrep/src/utils.c -o CMakeFiles/paralegrep.dir/src/utils.c.s

# Object files for target paralegrep
paralegrep_OBJECTS = \
"CMakeFiles/paralegrep.dir/src/main.c.o" \
"CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o" \
"CMakeFiles/paralegrep.dir/src/thread_worker.c.o" \
"CMakeFiles/paralegrep.dir/src/thread_ranking.c.o" \
"CMakeFiles/paralegrep.dir/src/utils.c.o"

# External object files for target paralegrep
paralegrep_EXTERNAL_OBJECTS =

paralegrep: CMakeFiles/paralegrep.dir/src/main.c.o
paralegrep: CMakeFiles/paralegrep.dir/src/thread_dispatcher.c.o
paralegrep: CMakeFiles/paralegrep.dir/src/thread_worker.c.o
paralegrep: CMakeFiles/paralegrep.dir/src/thread_ranking.c.o
paralegrep: CMakeFiles/paralegrep.dir/src/utils.c.o
paralegrep: CMakeFiles/paralegrep.dir/build.make
paralegrep: CMakeFiles/paralegrep.dir/compiler_depend.ts
paralegrep: CMakeFiles/paralegrep.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/Giovanni/Documents/IFB/SO/paralegrep/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable paralegrep"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/paralegrep.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/paralegrep.dir/build: paralegrep
.PHONY : CMakeFiles/paralegrep.dir/build

CMakeFiles/paralegrep.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/paralegrep.dir/cmake_clean.cmake
.PHONY : CMakeFiles/paralegrep.dir/clean

CMakeFiles/paralegrep.dir/depend:
	cd /home/Giovanni/Documents/IFB/SO/paralegrep/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Giovanni/Documents/IFB/SO/paralegrep /home/Giovanni/Documents/IFB/SO/paralegrep /home/Giovanni/Documents/IFB/SO/paralegrep/build /home/Giovanni/Documents/IFB/SO/paralegrep/build /home/Giovanni/Documents/IFB/SO/paralegrep/build/CMakeFiles/paralegrep.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/paralegrep.dir/depend

