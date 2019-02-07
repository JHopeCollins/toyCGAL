#ifndef WRITEOBJECTS_3D_H
#define WRITEOBJECTS_3D_H

#include <iostream>

#include <CGAL/enum.h>

// functors for writing 2D objects to standard output.
// written as functors not functions to be in keeping with CGAL standard


   template <class K>
   struct Write_Point_3
  {
      inline void operator()( typename K::Point_3 p ){ write( p ); }

      inline void write( typename K::Point_3 p )
     {
         std::cout << "(" << p.x() << "," << p.y() << "," << p.z() << ")"; 
     }
  };


   template <class K>
   struct Write_Point_To_Point_3
  {
      Write_Point_3<K>   write_point;

      inline void operator()( typename K::Point_3 p0, typename K::Point_3 p1 ){ write( p0, p1 ); }

      inline void write( typename K::Point_3 p0, typename K::Point_3 p1 )
     {
         write_point( p0 );
         std::cout << "->";
         write_point( p1 );
     }
  };


   template <class K>
   struct Write_Line_3
  {
      Write_Point_To_Point_3<K>   write_point_to_point;

      inline void operator()( typename K::Line_3 l ){ write( l ); }

      inline void write( typename K::Line_3 l )
     {
         typename K::Vector_3  dir(l);

      // construct two points on line
         typename K::Point_3   p( l.point(0) );
         typename K::Point_3   q( p + dir );

         write_point_to_point( p, q );
     }
  };


   template <class K>
   struct Write_Segment_3
  {
      Write_Point_To_Point_3<K>   write_point_to_point;

      inline void operator()( typename K::Segment_3 s ){ write( s ); }

      inline void write( typename K::Segment_3 s )
     {
         write_point_to_point( s.source(), s.target() );
     }
  };


   template <class K>
   struct Write_Vector_3
  {
      Write_Point_To_Point_3<K>   write_point_to_point;

      inline void operator()( typename K::Vector_3 v ){ write( v ); }

      inline void write( typename K::Vector_3 v )
     {
         typename K::Point_3   p( CGAL::ORIGIN );
         typename K::Point_3   q( p + v );

         write_point_to_point( p, q );
     }
  };


   template <class K>
   struct Write_Plane_3
  {
      Write_Point_3<K>   write_point;

      inline void operator()( typename K::Plane_3 pl ){ write( pl ); }

      inline void write( typename K::Plane_3 pl )
     {
         typename K::Vector_3 t0( pl.base1() ),
                              t1( pl.base2() );

         typename K::Point_3  p( pl.point() );
         typename K::Point_3  q( p+t0 ),
                              r( p+t1 );

         write_point( p );
         std::cout << "-";
         write_point( q );
         std::cout << "-";
         write_point( r );
     }

  };

#endif
