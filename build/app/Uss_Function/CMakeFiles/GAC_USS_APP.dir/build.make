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
CMAKE_SOURCE_DIR = /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build

# Include any dependencies generated for this target.
include app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/depend.make

# Include the progress variables for this target.
include app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/progress.make

# Include the compile flags for this target's objects.
include app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/flags.make

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/flags.make
app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o: ../app/Uss_Function/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc -lang-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o -c /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/main.cpp

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GAC_USS_APP.dir/src/main.cpp.i"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/main.cpp > CMakeFiles/GAC_USS_APP.dir/src/main.cpp.i

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GAC_USS_APP.dir/src/main.cpp.s"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/main.cpp -o CMakeFiles/GAC_USS_APP.dir/src/main.cpp.s

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o.requires:

.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o.requires

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o.provides: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o.requires
	$(MAKE) -f app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/build.make app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o.provides.build
.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o.provides

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o.provides.build: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o


app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/flags.make
app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o: ../app/Uss_Function/src/uss_obs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc -lang-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o -c /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/uss_obs.cpp

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.i"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/uss_obs.cpp > CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.i

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.s"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/uss_obs.cpp -o CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.s

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o.requires:

.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o.requires

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o.provides: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o.requires
	$(MAKE) -f app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/build.make app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o.provides.build
.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o.provides

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o.provides.build: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o


app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/flags.make
app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o: ../app/Uss_Function/src/data_sub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc -lang-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o -c /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/data_sub.cpp

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.i"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/data_sub.cpp > CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.i

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.s"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/data_sub.cpp -o CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.s

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o.requires:

.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o.requires

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o.provides: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o.requires
	$(MAKE) -f app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/build.make app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o.provides.build
.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o.provides

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o.provides.build: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o


app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/flags.make
app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o: ../app/Uss_Function/src/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc -lang-c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o -c /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/client.cpp

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GAC_USS_APP.dir/src/client.cpp.i"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/client.cpp > CMakeFiles/GAC_USS_APP.dir/src/client.cpp.i

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GAC_USS_APP.dir/src/client.cpp.s"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && /home/uss/qnx710_sdp_desay/qnx710/host/linux/x86_64/usr/bin/qcc $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function/src/client.cpp -o CMakeFiles/GAC_USS_APP.dir/src/client.cpp.s

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o.requires:

.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o.requires

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o.provides: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o.requires
	$(MAKE) -f app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/build.make app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o.provides.build
.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o.provides

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o.provides.build: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o


# Object files for target GAC_USS_APP
GAC_USS_APP_OBJECTS = \
"CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o" \
"CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o" \
"CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o" \
"CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o"

# External object files for target GAC_USS_APP
GAC_USS_APP_EXTERNAL_OBJECTS =

app/Uss_Function/GAC_USS_APP: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o
app/Uss_Function/GAC_USS_APP: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o
app/Uss_Function/GAC_USS_APP: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o
app/Uss_Function/GAC_USS_APP: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o
app/Uss_Function/GAC_USS_APP: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/build.make
app/Uss_Function/GAC_USS_APP: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable GAC_USS_APP"
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GAC_USS_APP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/build: app/Uss_Function/GAC_USS_APP

.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/build

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/requires: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/main.cpp.o.requires
app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/requires: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/uss_obs.cpp.o.requires
app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/requires: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/data_sub.cpp.o.requires
app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/requires: app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/src/client.cpp.o.requires

.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/requires

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/clean:
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function && $(CMAKE_COMMAND) -P CMakeFiles/GAC_USS_APP.dir/cmake_clean.cmake
.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/clean

app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/depend:
	cd /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/app/Uss_Function /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function /home/uss/A8E.X3V.B1.20230117.S.E04.PS/App/pps_a8e_test_v36/pps_a8e_test/build/app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : app/Uss_Function/CMakeFiles/GAC_USS_APP.dir/depend

