# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build

# Include any dependencies generated for this target.
include examples/CMakeFiles/splitview.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/splitview.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/splitview.dir/flags.make

examples/splitview.app/Contents/Resources/glfw.icns: /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content examples/splitview.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/examples/glfw.icns examples/splitview.app/Contents/Resources/glfw.icns

examples/CMakeFiles/splitview.dir/splitview.c.o: examples/CMakeFiles/splitview.dir/flags.make
examples/CMakeFiles/splitview.dir/splitview.c.o: /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/examples/splitview.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/splitview.dir/splitview.c.o"
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/splitview.dir/splitview.c.o   -c /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/examples/splitview.c

examples/CMakeFiles/splitview.dir/splitview.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/splitview.c.i"
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/examples/splitview.c > CMakeFiles/splitview.dir/splitview.c.i

examples/CMakeFiles/splitview.dir/splitview.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/splitview.c.s"
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/examples/splitview.c -o CMakeFiles/splitview.dir/splitview.c.s

examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o: examples/CMakeFiles/splitview.dir/flags.make
examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o: /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o"
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/splitview.dir/__/deps/glad_gl.c.o   -c /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/deps/glad_gl.c

examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/__/deps/glad_gl.c.i"
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/deps/glad_gl.c > CMakeFiles/splitview.dir/__/deps/glad_gl.c.i

examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/__/deps/glad_gl.c.s"
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/deps/glad_gl.c -o CMakeFiles/splitview.dir/__/deps/glad_gl.c.s

# Object files for target splitview
splitview_OBJECTS = \
"CMakeFiles/splitview.dir/splitview.c.o" \
"CMakeFiles/splitview.dir/__/deps/glad_gl.c.o"

# External object files for target splitview
splitview_EXTERNAL_OBJECTS =

examples/splitview.app/Contents/MacOS/splitview: examples/CMakeFiles/splitview.dir/splitview.c.o
examples/splitview.app/Contents/MacOS/splitview: examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o
examples/splitview.app/Contents/MacOS/splitview: examples/CMakeFiles/splitview.dir/build.make
examples/splitview.app/Contents/MacOS/splitview: src/libglfw3.a
examples/splitview.app/Contents/MacOS/splitview: examples/CMakeFiles/splitview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable splitview.app/Contents/MacOS/splitview"
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splitview.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/splitview.dir/build: examples/splitview.app/Contents/MacOS/splitview
examples/CMakeFiles/splitview.dir/build: examples/splitview.app/Contents/Resources/glfw.icns

.PHONY : examples/CMakeFiles/splitview.dir/build

examples/CMakeFiles/splitview.dir/clean:
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples && $(CMAKE_COMMAND) -P CMakeFiles/splitview.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/splitview.dir/clean

examples/CMakeFiles/splitview.dir/depend:
	cd /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw/examples /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples /Users/kirillmezrin/dev/UralEngine/UralEngine/vendor/glfw-build/examples/CMakeFiles/splitview.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/splitview.dir/depend

