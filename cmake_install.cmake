# Install script for directory: /home/rrosmaninho/Repos/IT/vanetza

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Vanetza" TYPE FILE FILES
    "/home/rrosmaninho/Repos/IT/vanetza/cmake-config/VanetzaConfig.cmake"
    "/home/rrosmaninho/Repos/IT/vanetza/cmake-config/VanetzaConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Vanetza" TYPE DIRECTORY FILES "/home/rrosmaninho/Repos/IT/vanetza/cmake/" FILES_MATCHING REGEX "/MacroFindDependencyComponents\\.cmake$" REGEX "/Find[^/]*\\.cmake$" REGEX "/Compat[^/]*Targets\\.cmake$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Vanetza/VanetzaTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Vanetza/VanetzaTargets.cmake"
         "/home/rrosmaninho/Repos/IT/vanetza/CMakeFiles/Export/lib/cmake/Vanetza/VanetzaTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Vanetza/VanetzaTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/Vanetza/VanetzaTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Vanetza" TYPE FILE FILES "/home/rrosmaninho/Repos/IT/vanetza/CMakeFiles/Export/lib/cmake/Vanetza/VanetzaTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/Vanetza" TYPE FILE FILES "/home/rrosmaninho/Repos/IT/vanetza/CMakeFiles/Export/lib/cmake/Vanetza/VanetzaTargets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/rrosmaninho/Repos/IT/vanetza/vanetza" FILES_MATCHING REGEX "/[^/]*\\.hpp$" REGEX "/\\/tests\\/[^/]*\\.hpp$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/access/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/asn1/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/btp/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/common/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/dcc/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/facilities/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/geonet/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/gnss/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/net/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/security/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/vanetza/units/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/tools/proxy_fake_feed/cmake_install.cmake")
  include("/home/rrosmaninho/Repos/IT/vanetza/tools/socktap/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/rrosmaninho/Repos/IT/vanetza/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
