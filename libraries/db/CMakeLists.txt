file(GLOB HEADERS "include/gyb/db/*.hpp")
add_library( gyb_db undo_database.cpp index.cpp object_database.cpp ${HEADERS} )
target_link_libraries( gyb_db fc )
target_include_directories( gyb_db PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   gyb_db

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
