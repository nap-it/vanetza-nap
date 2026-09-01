if(NOT DEFINED ASN1C_OUTPUT_DIR)
    message(FATAL_ERROR "Missing ASN.1 output directory (ASN1C_OUTPUT_DIR)")
endif()

if(NOT DEFINED ASN1C_PREFIX OR ASN1C_PREFIX STREQUAL "")
    return()
endif()

string(LENGTH "${ASN1C_PREFIX}" _prefix_len)

file(GLOB _prefixed_files "${ASN1C_OUTPUT_DIR}/${ASN1C_PREFIX}*")
foreach(_file IN LISTS _prefixed_files)
    get_filename_component(_name "${_file}" NAME)
    string(SUBSTRING "${_name}" ${_prefix_len} -1 _stripped_name)
    get_filename_component(_dir "${_file}" DIRECTORY)
    file(RENAME "${_file}" "${_dir}/${_stripped_name}")
endforeach()
