# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/frykol/Pulpit/Graph/GraphCProj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/frykol/Pulpit/Graph/GraphCProj/build

# Include any dependencies generated for this target.
include CMakeFiles/GraphProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GraphProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GraphProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GraphProject.dir/flags.make

CMakeFiles/GraphProject.dir/src/main.c.o: CMakeFiles/GraphProject.dir/flags.make
CMakeFiles/GraphProject.dir/src/main.c.o: /home/frykol/Pulpit/Graph/GraphCProj/src/main.c
CMakeFiles/GraphProject.dir/src/main.c.o: CMakeFiles/GraphProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/frykol/Pulpit/Graph/GraphCProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GraphProject.dir/src/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GraphProject.dir/src/main.c.o -MF CMakeFiles/GraphProject.dir/src/main.c.o.d -o CMakeFiles/GraphProject.dir/src/main.c.o -c /home/frykol/Pulpit/Graph/GraphCProj/src/main.c

CMakeFiles/GraphProject.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GraphProject.dir/src/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/frykol/Pulpit/Graph/GraphCProj/src/main.c > CMakeFiles/GraphProject.dir/src/main.c.i

CMakeFiles/GraphProject.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GraphProject.dir/src/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/frykol/Pulpit/Graph/GraphCProj/src/main.c -o CMakeFiles/GraphProject.dir/src/main.c.s

CMakeFiles/GraphProject.dir/src/parser.c.o: CMakeFiles/GraphProject.dir/flags.make
CMakeFiles/GraphProject.dir/src/parser.c.o: /home/frykol/Pulpit/Graph/GraphCProj/src/parser.c
CMakeFiles/GraphProject.dir/src/parser.c.o: CMakeFiles/GraphProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/frykol/Pulpit/Graph/GraphCProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GraphProject.dir/src/parser.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GraphProject.dir/src/parser.c.o -MF CMakeFiles/GraphProject.dir/src/parser.c.o.d -o CMakeFiles/GraphProject.dir/src/parser.c.o -c /home/frykol/Pulpit/Graph/GraphCProj/src/parser.c

CMakeFiles/GraphProject.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GraphProject.dir/src/parser.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/frykol/Pulpit/Graph/GraphCProj/src/parser.c > CMakeFiles/GraphProject.dir/src/parser.c.i

CMakeFiles/GraphProject.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GraphProject.dir/src/parser.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/frykol/Pulpit/Graph/GraphCProj/src/parser.c -o CMakeFiles/GraphProject.dir/src/parser.c.s

CMakeFiles/GraphProject.dir/src/renderer.c.o: CMakeFiles/GraphProject.dir/flags.make
CMakeFiles/GraphProject.dir/src/renderer.c.o: /home/frykol/Pulpit/Graph/GraphCProj/src/renderer.c
CMakeFiles/GraphProject.dir/src/renderer.c.o: CMakeFiles/GraphProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/frykol/Pulpit/Graph/GraphCProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/GraphProject.dir/src/renderer.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GraphProject.dir/src/renderer.c.o -MF CMakeFiles/GraphProject.dir/src/renderer.c.o.d -o CMakeFiles/GraphProject.dir/src/renderer.c.o -c /home/frykol/Pulpit/Graph/GraphCProj/src/renderer.c

CMakeFiles/GraphProject.dir/src/renderer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GraphProject.dir/src/renderer.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/frykol/Pulpit/Graph/GraphCProj/src/renderer.c > CMakeFiles/GraphProject.dir/src/renderer.c.i

CMakeFiles/GraphProject.dir/src/renderer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GraphProject.dir/src/renderer.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/frykol/Pulpit/Graph/GraphCProj/src/renderer.c -o CMakeFiles/GraphProject.dir/src/renderer.c.s

CMakeFiles/GraphProject.dir/src/shader.c.o: CMakeFiles/GraphProject.dir/flags.make
CMakeFiles/GraphProject.dir/src/shader.c.o: /home/frykol/Pulpit/Graph/GraphCProj/src/shader.c
CMakeFiles/GraphProject.dir/src/shader.c.o: CMakeFiles/GraphProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/frykol/Pulpit/Graph/GraphCProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/GraphProject.dir/src/shader.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GraphProject.dir/src/shader.c.o -MF CMakeFiles/GraphProject.dir/src/shader.c.o.d -o CMakeFiles/GraphProject.dir/src/shader.c.o -c /home/frykol/Pulpit/Graph/GraphCProj/src/shader.c

CMakeFiles/GraphProject.dir/src/shader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GraphProject.dir/src/shader.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/frykol/Pulpit/Graph/GraphCProj/src/shader.c > CMakeFiles/GraphProject.dir/src/shader.c.i

CMakeFiles/GraphProject.dir/src/shader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GraphProject.dir/src/shader.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/frykol/Pulpit/Graph/GraphCProj/src/shader.c -o CMakeFiles/GraphProject.dir/src/shader.c.s

CMakeFiles/GraphProject.dir/src/texture.c.o: CMakeFiles/GraphProject.dir/flags.make
CMakeFiles/GraphProject.dir/src/texture.c.o: /home/frykol/Pulpit/Graph/GraphCProj/src/texture.c
CMakeFiles/GraphProject.dir/src/texture.c.o: CMakeFiles/GraphProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/frykol/Pulpit/Graph/GraphCProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/GraphProject.dir/src/texture.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GraphProject.dir/src/texture.c.o -MF CMakeFiles/GraphProject.dir/src/texture.c.o.d -o CMakeFiles/GraphProject.dir/src/texture.c.o -c /home/frykol/Pulpit/Graph/GraphCProj/src/texture.c

CMakeFiles/GraphProject.dir/src/texture.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GraphProject.dir/src/texture.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/frykol/Pulpit/Graph/GraphCProj/src/texture.c > CMakeFiles/GraphProject.dir/src/texture.c.i

CMakeFiles/GraphProject.dir/src/texture.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GraphProject.dir/src/texture.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/frykol/Pulpit/Graph/GraphCProj/src/texture.c -o CMakeFiles/GraphProject.dir/src/texture.c.s

CMakeFiles/GraphProject.dir/src/vertex.c.o: CMakeFiles/GraphProject.dir/flags.make
CMakeFiles/GraphProject.dir/src/vertex.c.o: /home/frykol/Pulpit/Graph/GraphCProj/src/vertex.c
CMakeFiles/GraphProject.dir/src/vertex.c.o: CMakeFiles/GraphProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/frykol/Pulpit/Graph/GraphCProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/GraphProject.dir/src/vertex.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/GraphProject.dir/src/vertex.c.o -MF CMakeFiles/GraphProject.dir/src/vertex.c.o.d -o CMakeFiles/GraphProject.dir/src/vertex.c.o -c /home/frykol/Pulpit/Graph/GraphCProj/src/vertex.c

CMakeFiles/GraphProject.dir/src/vertex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/GraphProject.dir/src/vertex.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/frykol/Pulpit/Graph/GraphCProj/src/vertex.c > CMakeFiles/GraphProject.dir/src/vertex.c.i

CMakeFiles/GraphProject.dir/src/vertex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/GraphProject.dir/src/vertex.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/frykol/Pulpit/Graph/GraphCProj/src/vertex.c -o CMakeFiles/GraphProject.dir/src/vertex.c.s

# Object files for target GraphProject
GraphProject_OBJECTS = \
"CMakeFiles/GraphProject.dir/src/main.c.o" \
"CMakeFiles/GraphProject.dir/src/parser.c.o" \
"CMakeFiles/GraphProject.dir/src/renderer.c.o" \
"CMakeFiles/GraphProject.dir/src/shader.c.o" \
"CMakeFiles/GraphProject.dir/src/texture.c.o" \
"CMakeFiles/GraphProject.dir/src/vertex.c.o"

# External object files for target GraphProject
GraphProject_EXTERNAL_OBJECTS =

GraphProject: CMakeFiles/GraphProject.dir/src/main.c.o
GraphProject: CMakeFiles/GraphProject.dir/src/parser.c.o
GraphProject: CMakeFiles/GraphProject.dir/src/renderer.c.o
GraphProject: CMakeFiles/GraphProject.dir/src/shader.c.o
GraphProject: CMakeFiles/GraphProject.dir/src/texture.c.o
GraphProject: CMakeFiles/GraphProject.dir/src/vertex.c.o
GraphProject: CMakeFiles/GraphProject.dir/build.make
GraphProject: /usr/lib/x86_64-linux-gnu/libglfw.so.3.3
GraphProject: /usr/lib/x86_64-linux-gnu/libOpenGL.so
GraphProject: /usr/lib/x86_64-linux-gnu/libGLX.so
GraphProject: /usr/lib/x86_64-linux-gnu/libGLU.so
GraphProject: CMakeFiles/GraphProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/frykol/Pulpit/Graph/GraphCProj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable GraphProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GraphProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GraphProject.dir/build: GraphProject
.PHONY : CMakeFiles/GraphProject.dir/build

CMakeFiles/GraphProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GraphProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GraphProject.dir/clean

CMakeFiles/GraphProject.dir/depend:
	cd /home/frykol/Pulpit/Graph/GraphCProj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/frykol/Pulpit/Graph/GraphCProj /home/frykol/Pulpit/Graph/GraphCProj /home/frykol/Pulpit/Graph/GraphCProj/build /home/frykol/Pulpit/Graph/GraphCProj/build /home/frykol/Pulpit/Graph/GraphCProj/build/CMakeFiles/GraphProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GraphProject.dir/depend

