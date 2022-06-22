set_property(DIRECTORY PROPERTY EXCLUDE_FROM_ALL 1)

function(add_third_party_library cmake_folder)
    if (ARGN)
        set(base_folders ${ARGN})
    else()
        set(base_folders ${cmake_folder})
    endif()

    foreach(base_folder ${base_folders})
        # Some typos in the code
        if(NOT IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${base_folder}")
            message(FATAL_ERROR "No such base folder '${base_folder}' (for '${cmake_folder}' cmake folder). Typo in the base folder name?")
        endif()

        file(GLOB third_party_files "${base_folder}/*")
        if (NOT third_party_files)
            message(STATUS "Submodule ${base_folder} is missing or empty. Fix it and rerun:")
            message(STATUS "    git submodule update --init")
            return()
        endif()
    endforeach()
    
    message(STATUS "Adding third party library ${base_folders} (configuring with ${cmake_folder})")
    add_subdirectory(${cmake_folder})
endfunction()

add_third_party_library(googletest-cmake googletest)