
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was VanetzaConfig.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

# Temporarily extend module path for bundled find package scripts
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

include(CMakeFindDependencyMacro)
include(MacroFindDependencyComponents)

find_dependency_components(Boost VERSION 1.74 COMPONENTS date_time;program_options;system)
find_dependency(GeographicLib 1.51)
find_dependency(Threads)

if(TRUE)
    find_dependency(CryptoPP 8.4.0)
endif()

if()
    string(REGEX REPLACE "[a-z]+" "" OPENSSL_VERSION_WITHOUT_PATCH )
    # workaround for old CMake versions before 3.3
    if("${CMAKE_VERSION}" VERSION_LESS 3.3)
        function(fix_openssl_found variable access value)
            set(OpenSSL_FOUND ${value} PARENT_SCOPE)
        endfunction()
        variable_watch(OPENSSL_FOUND fix_openssl_found)
    endif()
    find_dependency(OpenSSL ${OPENSSL_VERSION_WITHOUT_PATCH})
endif()

if(TRUE)
    find_dependency(Threads)
endif()

# Restore previous module path
list(REMOVE_AT CMAKE_MODULE_PATH -1)

include("${CMAKE_CURRENT_LIST_DIR}/CompatBoostTargets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/CompatOpenSSLTargets.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/VanetzaTargets.cmake")

set_and_check(VANETZA_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")
