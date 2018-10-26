list( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/libraries/fc/GitVersionGen" )
include( GetGitRevisionDescription )
get_git_head_revision(GIT_REFSPEC GYB_GIT_REVISION_SHA)
get_git_unix_timestamp(GYB_GIT_REVISION_UNIX_TIMESTAMP)
git_describe(GYB_GIT_REVISION_DESCRIPTION --tags)
if(NOT GYB_GIT_REVISION_DESCRIPTION)
    set(GYB_GIT_REVISION_DESCRIPTION "unknown")
endif(NOT GYB_GIT_REVISION_DESCRIPTION)

file(GLOB headers "include/GYB/utilities/*.hpp")

set(sources
   key_conversion.cpp
   string_escape.cpp
   tempdir.cpp
   words.cpp
   ${headers})

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/git_revision.cpp.in" "${CMAKE_CURRENT_BINARY_DIR}/git_revision.cpp" @ONLY)
list(APPEND sources "${CMAKE_CURRENT_BINARY_DIR}/git_revision.cpp")

add_library( GYB_utilities
             ${sources}
             ${HEADERS} )
target_link_libraries( GYB_utilities fc )
target_include_directories( GYB_utilities
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
if (USE_PCH)
  set_target_properties(GYB_utilities PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
  cotire(GYB_utilities)
endif(USE_PCH)

install( TARGETS
   GYB_utilities

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
