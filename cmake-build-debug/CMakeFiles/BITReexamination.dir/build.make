# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Asoftware2\Software\CLion2019\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Asoftware2\Software\CLion2019\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionFile\BITReexamination

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionFile\BITReexamination\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BITReexamination.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BITReexamination.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BITReexamination.dir/flags.make

CMakeFiles/BITReexamination.dir/test.c.obj: CMakeFiles/BITReexamination.dir/flags.make
CMakeFiles/BITReexamination.dir/test.c.obj: ../test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionFile\BITReexamination\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BITReexamination.dir/test.c.obj"
	D:\Asoftware2\Software\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\BITReexamination.dir\test.c.obj   -c D:\CLionFile\BITReexamination\test.c

CMakeFiles/BITReexamination.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/BITReexamination.dir/test.c.i"
	D:\Asoftware2\Software\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CLionFile\BITReexamination\test.c > CMakeFiles\BITReexamination.dir\test.c.i

CMakeFiles/BITReexamination.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/BITReexamination.dir/test.c.s"
	D:\Asoftware2\Software\x86_64-8.1.0-release-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CLionFile\BITReexamination\test.c -o CMakeFiles\BITReexamination.dir\test.c.s

# Object files for target BITReexamination
BITReexamination_OBJECTS = \
"CMakeFiles/BITReexamination.dir/test.c.obj"

# External object files for target BITReexamination
BITReexamination_EXTERNAL_OBJECTS =

BITReexamination.exe: CMakeFiles/BITReexamination.dir/test.c.obj
BITReexamination.exe: CMakeFiles/BITReexamination.dir/build.make
BITReexamination.exe: CMakeFiles/BITReexamination.dir/linklibs.rsp
BITReexamination.exe: CMakeFiles/BITReexamination.dir/objects1.rsp
BITReexamination.exe: CMakeFiles/BITReexamination.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionFile\BITReexamination\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BITReexamination.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BITReexamination.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BITReexamination.dir/build: BITReexamination.exe

.PHONY : CMakeFiles/BITReexamination.dir/build

CMakeFiles/BITReexamination.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BITReexamination.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BITReexamination.dir/clean

CMakeFiles/BITReexamination.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionFile\BITReexamination D:\CLionFile\BITReexamination D:\CLionFile\BITReexamination\cmake-build-debug D:\CLionFile\BITReexamination\cmake-build-debug D:\CLionFile\BITReexamination\cmake-build-debug\CMakeFiles\BITReexamination.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BITReexamination.dir/depend

