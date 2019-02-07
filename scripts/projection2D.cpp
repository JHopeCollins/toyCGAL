#include <iostream>

#include <CGAL/Gmpz.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

#include <CGAL/enum.h>


typedef CGAL::Gmpz                    NumberType;
typedef CGAL::Homogeneous<NumberType> K1;

typedef CGAL::Exact_predicates_exact_constructions_kernel K2;

typedef K2  Kernel;

typedef Kernel::Point_2       Point_2;
typedef Kernel::Segment_2     Segment_2;
typedef Kernel::Line_2        Line_2;


// Show different ways of calling construct_projected_point_2 method
int main()
  {
   Kernel      k;

   Point_2     a(0, 0), b(5, 5);
   Point_2     p(2, 4);
   Point_2     l, m, n, o;

   Line_2      s(a, b);

   std::cout << "a: " << a.x() << " " << a.y() << std::endl;
   std::cout << "b: " << b.x() << " " << b.y() << std::endl;

   // using the typedef inside the Kernel
   Kernel::Construct_projected_point_2 construct_projected_point_2_m;

   m = construct_projected_point_2_m( s, p );

   // using the access member function of the Kernel instance
   Kernel::Construct_projected_point_2 construct_projected_point_2_n = k.construct_projected_point_2_object();

   n = construct_projected_point_2_n( s, p );

   // calling the access member function directly from Kernel instance
   l = k.construct_projected_point_2_object()( s, p );

   assert( !CGAL::collinear( a, b, p ) );
   assert(  CGAL::collinear( a, b, l ) );
   assert(  CGAL::collinear( a, b, m ) );
   assert(  CGAL::collinear( a, b, n ) );

   std::cout << "l: " << l.x() << " " << l.y() << std::endl;
   std::cout << "m: " << m.x() << " " << m.y() << std::endl;
   std::cout << "n: " << n.x() << " " << n.y() << std::endl;

   return 0;
  }

