#include <iostream>
#include <assert.h>

#include <CGAL/Gmpz.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include <CGAL/intersections.h>

#include <boost/bind.hpp>


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
typedef Kernel::Ray_2         Ray_2;

typedef CGAL::cpp11::result_of<Kernel::Intersect_2( Line_2, Line_2    )>::type result_ll;
typedef CGAL::cpp11::result_of<Kernel::Intersect_2( Line_2, Segment_2 )>::type result_ls;
typedef CGAL::cpp11::result_of<Kernel::Intersect_2( Ray_2,  Segment_2 )>::type result_rs;

   int main()
  {
      Point_2    p00(0,0), p55(5,5), p12(1,2), p21(2,1), p22(2,2);

      Line_2     l(  p00, p55 );
      Segment_2  s0( p00, p22 ), s1( p12, p21 );

//    With C++11 support
      auto result = CGAL::intersection( l, s1 );

//    Without C++11 support
//    result_ls   result = CGAL::intersection( l, s1 );


      if( result )
     {
         if( const Segment_2* s = boost::get<Segment_2>(&*result) )
        {
            std::cout << "intersection is a segment: "<< *s << std::endl;
        }
         else
        {
            const Point_2* p = boost::get<Point_2>(&*result);
            std::cout << "intersection is a point: "<< *p << std::endl;
        }
     }

      return 0;
  }
