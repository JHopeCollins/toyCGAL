# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( Principal_component_analysis_example )

cmake_minimum_required(VERSION 2.8.10)

find_package(CGAL QUIET COMPONENTS Core )

if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )

  include( CGAL_CreateSingleSourceCGALProgram )

  include_directories (BEFORE "../../include")

  create_single_source_cgal_program( "barycenter.cpp" )
  create_single_source_cgal_program( "bounding_box.cpp" )
  create_single_source_cgal_program( "centroid.cpp" )
  create_single_source_cgal_program( "linear_least_squares_fitting_points_2.cpp" )
  create_single_source_cgal_program( "linear_least_squares_fitting_triangles_3.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

