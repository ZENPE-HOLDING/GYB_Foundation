file(GLOB HEADERS "include/gyb/app/*.hpp")
file(GLOB EGENESIS_HEADERS "../egenesis/include/gyb/app/*.hpp")

add_library( gyb_app 
             api.cpp
             application.cpp
             database_api.cpp
             impacted.cpp
             plugin.cpp
             ${HEADERS}
             ${EGENESIS_HEADERS}
           )

# need to link gyb_debug_witness because plugins aren't sufficiently isolated #246
target_link_libraries( gyb_app gyb_market_history gyb_account_history gyb_chain fc gyb_db gyb_net gyb_time gyb_utilities gyb_debug_witness )
target_include_directories( gyb_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
                            "${CMAKE_CURRENT_SOURCE_DIR}/../egenesis/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   gyb_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
