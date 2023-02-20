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
include CMakeFiles/wiscAFS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wiscAFS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wiscAFS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wiscAFS.dir/flags.make

wiscAFS.pb.cc: wiscAFS.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating wiscAFS.pb.cc, wiscAFS.pb.h, wiscAFS.grpc.pb.cc, wiscAFS.grpc.pb.h"
	/mnt/.local/bin/protoc-3.21.6.0 --grpc_out /mnt/g10 --cpp_out /mnt/g10 -I /mnt/g10 --plugin=protoc-gen-grpc="/mnt/.local/bin/grpc_cpp_plugin" /mnt/g10/wiscAFS.proto

wiscAFS.pb.h: wiscAFS.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate wiscAFS.pb.h

wiscAFS.grpc.pb.cc: wiscAFS.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate wiscAFS.grpc.pb.cc

wiscAFS.grpc.pb.h: wiscAFS.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate wiscAFS.grpc.pb.h

CMakeFiles/wiscAFS.dir/conf.c.o: CMakeFiles/wiscAFS.dir/flags.make
CMakeFiles/wiscAFS.dir/conf.c.o: conf.c
CMakeFiles/wiscAFS.dir/conf.c.o: CMakeFiles/wiscAFS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/wiscAFS.dir/conf.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/wiscAFS.dir/conf.c.o -MF CMakeFiles/wiscAFS.dir/conf.c.o.d -o CMakeFiles/wiscAFS.dir/conf.c.o -c /mnt/g10/conf.c

CMakeFiles/wiscAFS.dir/conf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wiscAFS.dir/conf.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/g10/conf.c > CMakeFiles/wiscAFS.dir/conf.c.i

CMakeFiles/wiscAFS.dir/conf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wiscAFS.dir/conf.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/g10/conf.c -o CMakeFiles/wiscAFS.dir/conf.c.s

CMakeFiles/wiscAFS.dir/unreliablefs.c.o: CMakeFiles/wiscAFS.dir/flags.make
CMakeFiles/wiscAFS.dir/unreliablefs.c.o: unreliablefs.c
CMakeFiles/wiscAFS.dir/unreliablefs.c.o: CMakeFiles/wiscAFS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/wiscAFS.dir/unreliablefs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/wiscAFS.dir/unreliablefs.c.o -MF CMakeFiles/wiscAFS.dir/unreliablefs.c.o.d -o CMakeFiles/wiscAFS.dir/unreliablefs.c.o -c /mnt/g10/unreliablefs.c

CMakeFiles/wiscAFS.dir/unreliablefs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wiscAFS.dir/unreliablefs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/g10/unreliablefs.c > CMakeFiles/wiscAFS.dir/unreliablefs.c.i

CMakeFiles/wiscAFS.dir/unreliablefs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wiscAFS.dir/unreliablefs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/g10/unreliablefs.c -o CMakeFiles/wiscAFS.dir/unreliablefs.c.s

CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o: CMakeFiles/wiscAFS.dir/flags.make
CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o: unreliablefs_errinj.c
CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o: CMakeFiles/wiscAFS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o -MF CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o.d -o CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o -c /mnt/g10/unreliablefs_errinj.c

CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/g10/unreliablefs_errinj.c > CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.i

CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/g10/unreliablefs_errinj.c -o CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.s

CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o: CMakeFiles/wiscAFS.dir/flags.make
CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o: unreliablefs_ops.c
CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o: CMakeFiles/wiscAFS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o -MF CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o.d -o CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o -c /mnt/g10/unreliablefs_ops.c

CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/g10/unreliablefs_ops.c > CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.i

CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/g10/unreliablefs_ops.c -o CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.s

CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o: CMakeFiles/wiscAFS.dir/flags.make
CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o: connect_grpc_fuse.cpp
CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o: CMakeFiles/wiscAFS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o -MF CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o.d -o CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o -c /mnt/g10/connect_grpc_fuse.cpp

CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g10/connect_grpc_fuse.cpp > CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.i

CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g10/connect_grpc_fuse.cpp -o CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.s

CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o: CMakeFiles/wiscAFS.dir/flags.make
CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o: wiscAFS_client.cpp
CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o: CMakeFiles/wiscAFS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o -MF CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o.d -o CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o -c /mnt/g10/wiscAFS_client.cpp

CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g10/wiscAFS_client.cpp > CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.i

CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g10/wiscAFS_client.cpp -o CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.s

CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o: CMakeFiles/wiscAFS.dir/flags.make
CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o: wiscAFS.pb.cc
CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o: CMakeFiles/wiscAFS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o -MF CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o.d -o CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o -c /mnt/g10/wiscAFS.pb.cc

CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g10/wiscAFS.pb.cc > CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.i

CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g10/wiscAFS.pb.cc -o CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.s

CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o: CMakeFiles/wiscAFS.dir/flags.make
CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o: wiscAFS.grpc.pb.cc
CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o: CMakeFiles/wiscAFS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o -MF CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o.d -o CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o -c /mnt/g10/wiscAFS.grpc.pb.cc

CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g10/wiscAFS.grpc.pb.cc > CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.i

CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g10/wiscAFS.grpc.pb.cc -o CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.s

# Object files for target wiscAFS
wiscAFS_OBJECTS = \
"CMakeFiles/wiscAFS.dir/conf.c.o" \
"CMakeFiles/wiscAFS.dir/unreliablefs.c.o" \
"CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o" \
"CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o" \
"CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o" \
"CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o" \
"CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o" \
"CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o"

# External object files for target wiscAFS
wiscAFS_EXTERNAL_OBJECTS =

wiscAFS: CMakeFiles/wiscAFS.dir/conf.c.o
wiscAFS: CMakeFiles/wiscAFS.dir/unreliablefs.c.o
wiscAFS: CMakeFiles/wiscAFS.dir/unreliablefs_errinj.c.o
wiscAFS: CMakeFiles/wiscAFS.dir/unreliablefs_ops.c.o
wiscAFS: CMakeFiles/wiscAFS.dir/connect_grpc_fuse.cpp.o
wiscAFS: CMakeFiles/wiscAFS.dir/wiscAFS_client.cpp.o
wiscAFS: CMakeFiles/wiscAFS.dir/wiscAFS.pb.cc.o
wiscAFS: CMakeFiles/wiscAFS.dir/wiscAFS.grpc.pb.cc.o
wiscAFS: CMakeFiles/wiscAFS.dir/build.make
wiscAFS: /mnt/.local/lib/libgrpc++.a
wiscAFS: /usr/lib/x86_64-linux-gnu/libfuse.so
wiscAFS: /mnt/.local/lib/libprotobuf.a
wiscAFS: /mnt/.local/lib/libgrpc.a
wiscAFS: /mnt/.local/lib/libcares.a
wiscAFS: /mnt/.local/lib/libaddress_sorting.a
wiscAFS: /mnt/.local/lib/libre2.a
wiscAFS: /mnt/.local/lib/libupb.a
wiscAFS: /mnt/.local/lib/libabsl_raw_hash_set.a
wiscAFS: /mnt/.local/lib/libabsl_hashtablez_sampler.a
wiscAFS: /mnt/.local/lib/libabsl_hash.a
wiscAFS: /mnt/.local/lib/libabsl_city.a
wiscAFS: /mnt/.local/lib/libabsl_low_level_hash.a
wiscAFS: /mnt/.local/lib/libabsl_statusor.a
wiscAFS: /mnt/.local/lib/libgpr.a
wiscAFS: /mnt/.local/lib/libz.a
wiscAFS: /mnt/.local/lib/libabsl_bad_variant_access.a
wiscAFS: /mnt/.local/lib/libabsl_status.a
wiscAFS: /mnt/.local/lib/libabsl_strerror.a
wiscAFS: /mnt/.local/lib/libabsl_random_distributions.a
wiscAFS: /mnt/.local/lib/libabsl_random_seed_sequences.a
wiscAFS: /mnt/.local/lib/libabsl_random_internal_pool_urbg.a
wiscAFS: /mnt/.local/lib/libabsl_random_internal_randen.a
wiscAFS: /mnt/.local/lib/libabsl_random_internal_randen_hwaes.a
wiscAFS: /mnt/.local/lib/libabsl_random_internal_randen_hwaes_impl.a
wiscAFS: /mnt/.local/lib/libabsl_random_internal_randen_slow.a
wiscAFS: /mnt/.local/lib/libabsl_random_internal_platform.a
wiscAFS: /mnt/.local/lib/libabsl_random_internal_seed_material.a
wiscAFS: /mnt/.local/lib/libabsl_random_seed_gen_exception.a
wiscAFS: /mnt/.local/lib/libabsl_cord.a
wiscAFS: /mnt/.local/lib/libabsl_bad_optional_access.a
wiscAFS: /mnt/.local/lib/libabsl_cordz_info.a
wiscAFS: /mnt/.local/lib/libabsl_cord_internal.a
wiscAFS: /mnt/.local/lib/libabsl_cordz_functions.a
wiscAFS: /mnt/.local/lib/libabsl_exponential_biased.a
wiscAFS: /mnt/.local/lib/libabsl_cordz_handle.a
wiscAFS: /mnt/.local/lib/libabsl_str_format_internal.a
wiscAFS: /mnt/.local/lib/libabsl_synchronization.a
wiscAFS: /mnt/.local/lib/libabsl_stacktrace.a
wiscAFS: /mnt/.local/lib/libabsl_symbolize.a
wiscAFS: /mnt/.local/lib/libabsl_debugging_internal.a
wiscAFS: /mnt/.local/lib/libabsl_demangle_internal.a
wiscAFS: /mnt/.local/lib/libabsl_graphcycles_internal.a
wiscAFS: /mnt/.local/lib/libabsl_malloc_internal.a
wiscAFS: /mnt/.local/lib/libabsl_time.a
wiscAFS: /mnt/.local/lib/libabsl_strings.a
wiscAFS: /mnt/.local/lib/libabsl_throw_delegate.a
wiscAFS: /mnt/.local/lib/libabsl_int128.a
wiscAFS: /mnt/.local/lib/libabsl_strings_internal.a
wiscAFS: /mnt/.local/lib/libabsl_base.a
wiscAFS: /mnt/.local/lib/libabsl_spinlock_wait.a
wiscAFS: /mnt/.local/lib/libabsl_raw_logging_internal.a
wiscAFS: /mnt/.local/lib/libabsl_log_severity.a
wiscAFS: /mnt/.local/lib/libabsl_civil_time.a
wiscAFS: /mnt/.local/lib/libabsl_time_zone.a
wiscAFS: /mnt/.local/lib/libssl.a
wiscAFS: /mnt/.local/lib/libcrypto.a
wiscAFS: CMakeFiles/wiscAFS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g10/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable wiscAFS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wiscAFS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wiscAFS.dir/build: wiscAFS
.PHONY : CMakeFiles/wiscAFS.dir/build

CMakeFiles/wiscAFS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wiscAFS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wiscAFS.dir/clean

CMakeFiles/wiscAFS.dir/depend: wiscAFS.grpc.pb.cc
CMakeFiles/wiscAFS.dir/depend: wiscAFS.grpc.pb.h
CMakeFiles/wiscAFS.dir/depend: wiscAFS.pb.cc
CMakeFiles/wiscAFS.dir/depend: wiscAFS.pb.h
	cd /mnt/g10 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g10 /mnt/g10 /mnt/g10 /mnt/g10 /mnt/g10/CMakeFiles/wiscAFS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wiscAFS.dir/depend

