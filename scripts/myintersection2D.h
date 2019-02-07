#include <tuple>

#include <CGAL/intersections.h>

#include <boost/bind.hpp>
#include "writeobjects2D.h"

   template <class K>
   struct myIntersection_2
  {
   // possible return types for line-line and line-segment intersections
      typedef std::tuple<int,
                         typename K::Point_2,
                         typename K::Line_2>    result_ll;

      typedef std::tuple<int,
                         typename K::Point_2,
                         typename K::Segment_2> result_ls;

   // dummy instances
      typename K::Point_2    pdum;
      typename K::Line_2     ldum;
      typename K::Segment_2  sdum;

      result_ll intersection( typename K::Line_2 l0, typename K::Line_2 l1 )
     {
      // We do not know a priori what type the intersection is.
      // CGAL uses a wrapper to boost::variant to deal with this
         auto result = CGAL::intersection( l0, l1 );

         if( result ) // intersection exists
        {
            if( typename K::Point_2* p = boost::get<typename K::Point_2>(&*result) )
           {
               return std::make_tuple( 1, *p, ldum );
           }
            else
           {
               typename K::Line_2* l = boost::get<typename K::Line_2>(&*result);
               return std::make_tuple( 2, pdum, *l );
           }
        }
         return std::make_tuple( -1, pdum, ldum );
     }

      result_ls intersection( typename K::Line_2 l0, typename K::Segment_2 s1 )
     {
      // We do not know a priori what type the intersection is.
      // CGAL uses a wrapper to boost::variant to deal with this
         auto result = CGAL::intersection( l0, s1 );

         if( result ) // intersection exists
        {
            if( typename K::Point_2* p = boost::get<typename K::Point_2>(&*result) )
           {
               return std::make_tuple( 1, *p, sdum );
           }
            else
           {
               typename K::Segment_2* s = boost::get<typename K::Segment_2>(&*result);
               return std::make_tuple( 2, pdum, *s );
           }
        }
         return std::make_tuple( -1, pdum, sdum );
     }

      void write( typename K::Line_2 l0, typename K::Line_2 l1 )
     {
         Write_Line_2<K>  write_line;
         Write_Point_2<K> write_point;

         result_ll tuple_ll=intersection( l0, l1 );
   
         std::cout << "The lines ";
         write_line( l0 );
         std::cout << " & ";
         write_line( l1 );
   
         switch( std::get<0>(tuple_ll) )
        {
            case -1:
              {
               std::cout << " do not intersect." << std::endl;
               break;
              }
            case 1:
              {
               typename K::Point_2  p_intersect = std::get<1>(tuple_ll);
               std::cout << " intersect at point ";
               write_point( p_intersect );
               std::cout << std::endl;
               break;
              }
            case 2:
              {
               typename K::Line_2  l_intersect = std::get<2>(tuple_ll);
               std::cout << " intersect along the line ";
               write_line( l_intersect );
               std::cout << std::endl;
               break;
              }
        }

      return;
     }

      void write( typename K::Line_2 l0, typename K::Segment_2 s0 )
     {
         Write_Segment_2<K>  write_segment;
         Write_Point_2<K>    write_point;
         Write_Line_2<K>     write_line;

         result_ls tuple_ls=intersection( l0, s0 );
   
         std::cout << "The line ";
         write_line( l0 );
         std::cout << " & segment ";
         write_segment( s0 );
   
         switch( std::get<0>(tuple_ls) )
        {
            case -1:
              {
               std::cout << " do not intersect." << std::endl;
               break;
              }
            case 1:
              {
               typename K::Point_2  p_intersect = std::get<1>(tuple_ls);
               std::cout << " intersect at point ";
               write_point( p_intersect );
               std::cout << std::endl;
               break;
              }
            case 2:
              {
               typename K::Segment_2  s_intersect = std::get<2>(tuple_ls);
               std::cout << " intersect along the segment ";
               write_segment( s_intersect );
               std::cout << std::endl;
               break;
              }
        }

      return;
     }
  };

