#include <iostream>
#include <assert.h>

#include <CGAL/Gmpz.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include "myintersection2D.h"
#include "writeobjects2D.h"

typedef CGAL::Gmpz                    ExactNumberType;
typedef double                      InexactNumberType;

typedef CGAL::Homogeneous<ExactNumberType>   K1;
typedef CGAL::Cartesian<InexactNumberType>   K2;

typedef CGAL::Exact_predicates_exact_constructions_kernel    K3;
typedef CGAL::Exact_predicates_inexact_constructions_kernel  K4;

typedef K4  Kernel;

typedef Kernel::Point_2       Point_2;
typedef Kernel::Segment_2     Segment_2;
typedef Kernel::Line_2        Line_2;
typedef Kernel::Ray_2         Ray_2;


typedef Write_Line_2<Kernel>     Write_Line;
typedef Write_Point_2<Kernel>    Write_Point;
typedef Write_Segment_2<Kernel>  Write_Segment;

typedef myIntersection_2<Kernel>  Intersection;

   int main()
  {

      Point_2    p00(0,0), p55(5,5), p12(1,2), p21(2,1), p22(2,2), p34(3,4);

      Line_2     l0( p00, p55 ), l1(p00,p22), l2(p12,p21), l3(p12,p34);
      Segment_2  s0( p00, p22 ), s1( p12, p21 );

      Write_Line        write_line;
      Write_Point       write_point;
      Write_Segment     write_segment;

      Intersection     intersection;

      intersection.write( l0, l0 );
      intersection.write( l0, l1 );
      intersection.write( l0, l2 );
      intersection.write( l0, l3 );

      intersection.write( l0, s0 );
      intersection.write( l0, s1 );

     return 0;
  }

