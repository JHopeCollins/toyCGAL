#define ENDL std::cout << std::endl

#include <iostream>
#include <assert.h>

#include <CGAL/Gmpz.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include "writeobjects2D.h"
#include "writeobjects3D.h"

#include "vectorprojections.h"

typedef CGAL::Gmpz                    ExactNumberType;
typedef double                      InexactNumberType;

typedef CGAL::Homogeneous<ExactNumberType>   K1;
typedef CGAL::Cartesian<InexactNumberType>   K2;

typedef CGAL::Exact_predicates_exact_constructions_kernel    K3;
typedef CGAL::Exact_predicates_inexact_constructions_kernel  K4;

typedef K2  Kernel;

typedef Kernel::Point_2       Point_2;
typedef Kernel::Point_3       Point_3;
typedef Kernel::Plane_3       Plane_3;
typedef Kernel::Vector_2     Vector_2;
typedef Kernel::Vector_3     Vector_3;

typedef Write_Point_2<Kernel>    WritePoint_2;
typedef Write_Point_3<Kernel>    WritePoint_3;
typedef Write_Plane_3<Kernel>    WritePlane_3;
typedef Write_Vector_2<Kernel>   WriteVector_2;
typedef Write_Vector_3<Kernel>   WriteVector_3;

typedef Project_Vector_On_Vector<Kernel>  ProjectVectorOnVector;
typedef Project_Vector_On_Plane<Kernel>   ProjectVectorOnPlane;

   int main()
  {
      WritePlane_3   writeplane_3;
      WritePoint_3   writepoint_3;
      WritePoint_2   writepoint_2;
      WriteVector_2  writevector_2;
      WriteVector_3  writevector_3;

      ProjectVectorOnVector   projectVonV;
      ProjectVectorOnPlane    projectVonP;
      Vector_2 u(0.,1.), v(1.,1.), w;

      std::cout << "u: ";
      writevector_2( u ); ENDL;

      std::cout << "v: ";
      writevector_2( v ); ENDL;

      typename Kernel::FT d;
      d =u*v;
      d/=u.squared_length();
      w =u*d;
      writevector_2( w ); ENDL;

      w = u;
      w*= u*v;
      w/= u.squared_length();
      writevector_2( w ); ENDL;

      w=projectVonV( v, u );
      std::cout << "5"; ENDL;
      writevector_2( v ); ENDL;
      std::cout << "6"; ENDL;
      writevector_2( u ); ENDL;
      std::cout << "w: ";
      writevector_2( w ); ENDL;
      std::cout << "7"; ENDL;

/*
      w=projectVonV( u, v );
      std::cout << "w: ";
      writevector_2( w ); ENDL;
*/

      return 0;
  }

