# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/rrosmaninho/Repos/IT/vanetza

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rrosmaninho/Repos/IT/vanetza

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rrosmaninho/Repos/IT/vanetza/CMakeFiles /home/rrosmaninho/Repos/IT/vanetza//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rrosmaninho/Repos/IT/vanetza/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named access

# Build rule for target.
access: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 access
.PHONY : access

# fast build rule for target.
access/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/access/CMakeFiles/access.dir/build.make vanetza/access/CMakeFiles/access.dir/build
.PHONY : access/fast

#=============================================================================
# Target rules for targets named asn1

# Build rule for target.
asn1: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asn1
.PHONY : asn1

# fast build rule for target.
asn1/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/asn1/CMakeFiles/asn1.dir/build.make vanetza/asn1/CMakeFiles/asn1.dir/build
.PHONY : asn1/fast

#=============================================================================
# Target rules for targets named asn1_pki

# Build rule for target.
asn1_pki: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asn1_pki
.PHONY : asn1_pki

# fast build rule for target.
asn1_pki/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/asn1/CMakeFiles/asn1_pki.dir/build.make vanetza/asn1/CMakeFiles/asn1_pki.dir/build
.PHONY : asn1_pki/fast

#=============================================================================
# Target rules for targets named asn1_security

# Build rule for target.
asn1_security: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asn1_security
.PHONY : asn1_security

# fast build rule for target.
asn1_security/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/asn1/CMakeFiles/asn1_security.dir/build.make vanetza/asn1/CMakeFiles/asn1_security.dir/build
.PHONY : asn1_security/fast

#=============================================================================
# Target rules for targets named asn1_its

# Build rule for target.
asn1_its: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asn1_its
.PHONY : asn1_its

# fast build rule for target.
asn1_its/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/asn1/CMakeFiles/asn1_its.dir/build.make vanetza/asn1/CMakeFiles/asn1_its.dir/build
.PHONY : asn1_its/fast

#=============================================================================
# Target rules for targets named asn1_support

# Build rule for target.
asn1_support: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 asn1_support
.PHONY : asn1_support

# fast build rule for target.
asn1_support/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/asn1/CMakeFiles/asn1_support.dir/build.make vanetza/asn1/CMakeFiles/asn1_support.dir/build
.PHONY : asn1_support/fast

#=============================================================================
# Target rules for targets named btp

# Build rule for target.
btp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 btp
.PHONY : btp

# fast build rule for target.
btp/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/btp/CMakeFiles/btp.dir/build.make vanetza/btp/CMakeFiles/btp.dir/build
.PHONY : btp/fast

#=============================================================================
# Target rules for targets named common

# Build rule for target.
common: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 common
.PHONY : common

# fast build rule for target.
common/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/common/CMakeFiles/common.dir/build.make vanetza/common/CMakeFiles/common.dir/build
.PHONY : common/fast

#=============================================================================
# Target rules for targets named dcc

# Build rule for target.
dcc: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 dcc
.PHONY : dcc

# fast build rule for target.
dcc/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/dcc/CMakeFiles/dcc.dir/build.make vanetza/dcc/CMakeFiles/dcc.dir/build
.PHONY : dcc/fast

#=============================================================================
# Target rules for targets named facilities

# Build rule for target.
facilities: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 facilities
.PHONY : facilities

# fast build rule for target.
facilities/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/facilities/CMakeFiles/facilities.dir/build.make vanetza/facilities/CMakeFiles/facilities.dir/build
.PHONY : facilities/fast

#=============================================================================
# Target rules for targets named geonet

# Build rule for target.
geonet: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 geonet
.PHONY : geonet

# fast build rule for target.
geonet/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/geonet/CMakeFiles/geonet.dir/build.make vanetza/geonet/CMakeFiles/geonet.dir/build
.PHONY : geonet/fast

#=============================================================================
# Target rules for targets named gnss

# Build rule for target.
gnss: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gnss
.PHONY : gnss

# fast build rule for target.
gnss/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/gnss/CMakeFiles/gnss.dir/build.make vanetza/gnss/CMakeFiles/gnss.dir/build
.PHONY : gnss/fast

#=============================================================================
# Target rules for targets named net

# Build rule for target.
net: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 net
.PHONY : net

# fast build rule for target.
net/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/net/CMakeFiles/net.dir/build.make vanetza/net/CMakeFiles/net.dir/build
.PHONY : net/fast

#=============================================================================
# Target rules for targets named security

# Build rule for target.
security: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 security
.PHONY : security

# fast build rule for target.
security/fast:
	$(MAKE) $(MAKESILENT) -f vanetza/security/CMakeFiles/security.dir/build.make vanetza/security/CMakeFiles/security.dir/build
.PHONY : security/fast

#=============================================================================
# Target rules for targets named proxy_fake_feed

# Build rule for target.
proxy_fake_feed: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 proxy_fake_feed
.PHONY : proxy_fake_feed

# fast build rule for target.
proxy_fake_feed/fast:
	$(MAKE) $(MAKESILENT) -f tools/proxy_fake_feed/CMakeFiles/proxy_fake_feed.dir/build.make tools/proxy_fake_feed/CMakeFiles/proxy_fake_feed.dir/build
.PHONY : proxy_fake_feed/fast

#=============================================================================
# Target rules for targets named socktap

# Build rule for target.
socktap: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 socktap
.PHONY : socktap

# fast build rule for target.
socktap/fast:
	$(MAKE) $(MAKESILENT) -f tools/socktap/CMakeFiles/socktap.dir/build.make tools/socktap/CMakeFiles/socktap.dir/build
.PHONY : socktap/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... access"
	@echo "... asn1"
	@echo "... asn1_its"
	@echo "... asn1_pki"
	@echo "... asn1_security"
	@echo "... asn1_support"
	@echo "... btp"
	@echo "... common"
	@echo "... dcc"
	@echo "... facilities"
	@echo "... geonet"
	@echo "... gnss"
	@echo "... net"
	@echo "... proxy_fake_feed"
	@echo "... security"
	@echo "... socktap"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

