#include <iostream>

#include <CGAL/Gmpz.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include <CGAL/enum.h>
#include <CGAL/intersections.h>


typedef CGAL::Gmpz                    ExactNumberType;
typedef double                      InexactNumberType;

typedef CGAL::Homogeneous<ExactNumberType>   K1;
typedef CGAL::Cartesian<InexactNumberType>   K2;

typedef CGAL::Exact_predicates_exact_constructions_kernel    K3;
typedef CGAL::Exact_predicates_inexact_constructions_kernel  K4;

typedef K3  Kernel;

typedef Kernel::Point_2       Point_2;
typedef Kernel::Segment_2     Segment_2;
typedef Kernel::Line_2        Line_2;
typedef Kernel::Vector_2      Vector_2;


// Calculate if point p is on positive/negative side or on oriented line l and write to standard output
   void WriteOrientation( Line_2 l, Point_2 p )
  {
      Kernel   k;
   
      // using the typedef inside the Kernel
      Kernel::Oriented_side_2 OrientationTest1;
   
      // using the access member function of the Kernel instance
      Kernel::Oriented_side_2 OrientationTest2 = k.oriented_side_2_object();
   
      Vector_2   dir( l );
      Point_2   q( CGAL::ORIGIN + dir );
   
      std::cout << "(" << p.x() << "," << p.y() << ") is on ";

   // switch( k.oriented_side_2_object()( l, p ) )
   // switch( OrientationTest1(           l, p ) )
      switch( OrientationTest2(           l, p ) )
     {
         case CGAL::ON_NEGATIVE_SIDE:
            std::cout << "negative side of ";
            break;
   
         case CGAL::ON_POSITIVE_SIDE:
            std::cout << "positive side of ";
            break;
   
         case CGAL::ON_ORIENTED_BOUNDARY:
            break;
     }
      std::cout << "(" <<  "0"  << "," <<  "0"  << ")->"
                << "(" << q.x() << "," << q.y() << ")" << std::endl;
   
      return;
  }


// Print where a point is with respect to a line
   int main()
  {
      Kernel   k;

      Point_2  a(0,0), b(5,5);
      Point_2  c(2,1), d(1,2), e(2,2);

      Line_2   s(a,b);

      WriteOrientation( s, c );
      WriteOrientation( s, d );
      WriteOrientation( s, e );

      return 0;
  }   
