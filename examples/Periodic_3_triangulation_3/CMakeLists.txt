# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Periodic_3_triangulation_3_example )

cmake_minimum_required(VERSION 2.8.10)

find_package(CGAL QUIET COMPONENTS Core )

if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )

  include( CGAL_CreateSingleSourceCGALProgram )

  include_directories (BEFORE "../../include")

  create_single_source_cgal_program( "colored_vertices.cpp" )
  create_single_source_cgal_program( "covering.cpp" )
  create_single_source_cgal_program( "find_conflicts.cpp" )
  create_single_source_cgal_program( "geometric_access.cpp" )
  create_single_source_cgal_program( "large_point_set.cpp" )
  create_single_source_cgal_program( "periodic_adding_handles.cpp" )
  create_single_source_cgal_program( "simple_example.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

