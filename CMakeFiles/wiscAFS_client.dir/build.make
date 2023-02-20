# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/g10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/g10

# Include any dependencies generated for this target.
include CMakeFiles/wiscAFS_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wiscAFS_client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wiscAFS_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wiscAFS_client.dir/flags.make

wiscAFS.pb.cc: wiscAFS.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating wiscAFS.pb.cc, wiscAFS.pb.h, wiscAFS.grpc.pb.cc, wiscAFS.grpc.pb.h"
	/mnt/.local/bin/protoc-3.21.6.0 --grpc_out /mnt/g10 --cpp_out /mnt/g10 -I /mnt/g10 --plugin=protoc-gen-grpc="/mnt/.local/bin/grpc_cpp_plugin" /mnt/g10/wiscAFS.proto

wiscAFS.pb.h: wiscAFS.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate wiscAFS.pb.h

wiscAFS.grpc.pb.cc: wiscAFS.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate wiscAFS.grpc.pb.cc

wiscAFS.grpc.pb.h: wiscAFS.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate wiscAFS.grpc.pb.h

CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o: CMakeFiles/wiscAFS_client.dir/flags.make
CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o: wiscAFS_client.cpp
CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o: CMakeFiles/wiscAFS_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o -MF CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o.d -o CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o -c /mnt/g10/wiscAFS_client.cpp

CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g10/wiscAFS_client.cpp > CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.i

CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g10/wiscAFS_client.cpp -o CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.s

CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o: CMakeFiles/wiscAFS_client.dir/flags.make
CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o: wiscAFS.pb.cc
CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o: CMakeFiles/wiscAFS_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o -MF CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o.d -o CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o -c /mnt/g10/wiscAFS.pb.cc

CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g10/wiscAFS.pb.cc > CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.i

CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g10/wiscAFS.pb.cc -o CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.s

CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o: CMakeFiles/wiscAFS_client.dir/flags.make
CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o: wiscAFS.grpc.pb.cc
CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o: CMakeFiles/wiscAFS_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o -MF CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o.d -o CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o -c /mnt/g10/wiscAFS.grpc.pb.cc

CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g10/wiscAFS.grpc.pb.cc > CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.i

CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g10/wiscAFS.grpc.pb.cc -o CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.s

# Object files for target wiscAFS_client
wiscAFS_client_OBJECTS = \
"CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o" \
"CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o" \
"CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o"

# External object files for target wiscAFS_client
wiscAFS_client_EXTERNAL_OBJECTS =

wiscAFS_client: CMakeFiles/wiscAFS_client.dir/wiscAFS_client.cpp.o
wiscAFS_client: CMakeFiles/wiscAFS_client.dir/wiscAFS.pb.cc.o
wiscAFS_client: CMakeFiles/wiscAFS_client.dir/wiscAFS.grpc.pb.cc.o
wiscAFS_client: CMakeFiles/wiscAFS_client.dir/build.make
wiscAFS_client: /mnt/.local/lib/libgrpc++.a
wiscAFS_client: /mnt/.local/lib/libprotobuf.a
wiscAFS_client: /mnt/.local/lib/libgrpc.a
wiscAFS_client: /mnt/.local/lib/libcares.a
wiscAFS_client: /mnt/.local/lib/libaddress_sorting.a
wiscAFS_client: /mnt/.local/lib/libre2.a
wiscAFS_client: /mnt/.local/lib/libupb.a
wiscAFS_client: /mnt/.local/lib/libabsl_raw_hash_set.a
wiscAFS_client: /mnt/.local/lib/libabsl_hashtablez_sampler.a
wiscAFS_client: /mnt/.local/lib/libabsl_hash.a
wiscAFS_client: /mnt/.local/lib/libabsl_city.a
wiscAFS_client: /mnt/.local/lib/libabsl_low_level_hash.a
wiscAFS_client: /mnt/.local/lib/libabsl_statusor.a
wiscAFS_client: /mnt/.local/lib/libgpr.a
wiscAFS_client: /mnt/.local/lib/libz.a
wiscAFS_client: /mnt/.local/lib/libabsl_bad_variant_access.a
wiscAFS_client: /mnt/.local/lib/libabsl_status.a
wiscAFS_client: /mnt/.local/lib/libabsl_strerror.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_distributions.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_seed_sequences.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_internal_pool_urbg.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_internal_randen.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_internal_randen_hwaes.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_internal_randen_hwaes_impl.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_internal_randen_slow.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_internal_platform.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_internal_seed_material.a
wiscAFS_client: /mnt/.local/lib/libabsl_random_seed_gen_exception.a
wiscAFS_client: /mnt/.local/lib/libabsl_cord.a
wiscAFS_client: /mnt/.local/lib/libabsl_bad_optional_access.a
wiscAFS_client: /mnt/.local/lib/libabsl_cordz_info.a
wiscAFS_client: /mnt/.local/lib/libabsl_cord_internal.a
wiscAFS_client: /mnt/.local/lib/libabsl_cordz_functions.a
wiscAFS_client: /mnt/.local/lib/libabsl_exponential_biased.a
wiscAFS_client: /mnt/.local/lib/libabsl_cordz_handle.a
wiscAFS_client: /mnt/.local/lib/libabsl_str_format_internal.a
wiscAFS_client: /mnt/.local/lib/libabsl_synchronization.a
wiscAFS_client: /mnt/.local/lib/libabsl_stacktrace.a
wiscAFS_client: /mnt/.local/lib/libabsl_symbolize.a
wiscAFS_client: /mnt/.local/lib/libabsl_debugging_internal.a
wiscAFS_client: /mnt/.local/lib/libabsl_demangle_internal.a
wiscAFS_client: /mnt/.local/lib/libabsl_graphcycles_internal.a
wiscAFS_client: /mnt/.local/lib/libabsl_malloc_internal.a
wiscAFS_client: /mnt/.local/lib/libabsl_time.a
wiscAFS_client: /mnt/.local/lib/libabsl_strings.a
wiscAFS_client: /mnt/.local/lib/libabsl_throw_delegate.a
wiscAFS_client: /mnt/.local/lib/libabsl_int128.a
wiscAFS_client: /mnt/.local/lib/libabsl_strings_internal.a
wiscAFS_client: /mnt/.local/lib/libabsl_base.a
wiscAFS_client: /mnt/.local/lib/libabsl_spinlock_wait.a
wiscAFS_client: /mnt/.local/lib/libabsl_raw_logging_internal.a
wiscAFS_client: /mnt/.local/lib/libabsl_log_severity.a
wiscAFS_client: /mnt/.local/lib/libabsl_civil_time.a
wiscAFS_client: /mnt/.local/lib/libabsl_time_zone.a
wiscAFS_client: /mnt/.local/lib/libssl.a
wiscAFS_client: /mnt/.local/lib/libcrypto.a
wiscAFS_client: CMakeFiles/wiscAFS_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable wiscAFS_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wiscAFS_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wiscAFS_client.dir/build: wiscAFS_client
.PHONY : CMakeFiles/wiscAFS_client.dir/build

CMakeFiles/wiscAFS_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wiscAFS_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wiscAFS_client.dir/clean

CMakeFiles/wiscAFS_client.dir/depend: wiscAFS.grpc.pb.cc
CMakeFiles/wiscAFS_client.dir/depend: wiscAFS.grpc.pb.h
CMakeFiles/wiscAFS_client.dir/depend: wiscAFS.pb.cc
CMakeFiles/wiscAFS_client.dir/depend: wiscAFS.pb.h
	cd /mnt/g10 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g10 /mnt/g10 /mnt/g10 /mnt/g10 /mnt/g10/CMakeFiles/wiscAFS_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wiscAFS_client.dir/depend

