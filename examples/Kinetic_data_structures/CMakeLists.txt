# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Kinetic_data_structures_example )

cmake_minimum_required(VERSION 2.8.10)

find_package(CGAL QUIET COMPONENTS Core )

if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )

  include( CGAL_CreateSingleSourceCGALProgram )

  include_directories (BEFORE "../../include")

  create_single_source_cgal_program( "Kinetic_Delaunay_triangulation_2.cpp" )
  create_single_source_cgal_program( "Kinetic_Delaunay_triangulation_3.cpp" )
  create_single_source_cgal_program( "Kinetic_insert_event.cpp" )
  create_single_source_cgal_program( "Kinetic_regular_triangulation_3.cpp" )
  create_single_source_cgal_program( "Kinetic_sort.cpp" )
  create_single_source_cgal_program( "Kinetic_sweepline.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

