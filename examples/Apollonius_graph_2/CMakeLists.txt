# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Apollonius_graph_2_example )

cmake_minimum_required(VERSION 2.8.10)

find_package(CGAL QUIET COMPONENTS Core )

if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )

  include( CGAL_CreateSingleSourceCGALProgram )

  include_directories (BEFORE "../../include")

  create_single_source_cgal_program( "ag2_exact_traits.cpp" )
  create_single_source_cgal_program( "ag2_exact_traits_sqrt.cpp" )
  create_single_source_cgal_program( "ag2_filtered_traits_no_hidden.cpp" )
  create_single_source_cgal_program( "ag2_hierarchy.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

