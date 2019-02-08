#define ENDL std::cout << std::endl

#include <iostream>
#include <assert.h>

#include <CGAL/Gmpz.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include "writeobjects.h"

#include "vectorprojections.h"

typedef CGAL::Gmpz                    ExactNumberType;
typedef double                      InexactNumberType;

typedef CGAL::Homogeneous<ExactNumberType>   K1;
typedef CGAL::Cartesian<InexactNumberType>   K2;

typedef CGAL::Exact_predicates_exact_constructions_kernel    K3;
typedef CGAL::Exact_predicates_inexact_constructions_kernel  K4;

typedef K2  Kernel;

typedef Kernel::Line_2         Line_2;
typedef Kernel::Point_2       Point_2;
typedef Kernel::Vector_2     Vector_2;

typedef Kernel::Line_3         Line_3;
typedef Kernel::Point_3       Point_3;
typedef Kernel::Plane_3       Plane_3;
typedef Kernel::Vector_3     Vector_3;

typedef Write_Point<Kernel>      WritePoint;
typedef Write_Line<Kernel>       WriteLine;
typedef Write_Vector<Kernel>     WriteVector;
typedef Write_Plane_3<Kernel>    WritePlane;

typedef Project_Vector_On_Vector<Kernel>  ProjectVectorOnVector;
typedef Project_Vector_On_Plane<Kernel>   ProjectVectorOnPlane;
typedef Project_Vector_On_Line<Kernel>    ProjectVectorOnLine;

   int main()
  {
      WritePoint     writepoint;
      WriteLine      writeline;
      WriteVector    writevector;

      ProjectVectorOnVector   projectVonV;
      ProjectVectorOnLine     projectVonL;
      ProjectVectorOnPlane    projectVonP;

      Point_2  p2(0.,1.);
      Point_3  p3(0.,1.,2.);

      Vector_2 u(0.,1.), v(1.,1.), w;

      Line_2   p( CGAL::ORIGIN, u ),
               q( CGAL::ORIGIN, v );

      std::cout << "p2:";
      writepoint( p2 ); ENDL;

      std::cout << "p3:";
      writepoint( p3 ); ENDL;

      std::cout << "u: ";
      writevector( u ); ENDL;

      std::cout << "v: ";
      writevector( v ); ENDL;

      w = projectVonV( v, u );

      std::cout << "w: ";
      writevector( w ); ENDL;

      std::cout << "p: ";
      writeline( p ); ENDL;

      std::cout << "q: ";
      writeline( q ); ENDL;

      w = projectVonL( v, p );

      std::cout << "w: ";
      writevector( w ); ENDL;

      return 0;
  }

