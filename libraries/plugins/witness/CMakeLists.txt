file(GLOB HEADERS "include/gyb/witness/*.hpp")

add_library( gyb_witness 
             witness.cpp
           )

target_link_libraries( gyb_witness gyb_chain gyb_app gyb_time )
target_include_directories( gyb_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   gyb_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
