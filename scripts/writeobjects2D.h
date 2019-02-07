#ifndef WRITEOBJECTS_2D_H
#define WRITEOBJECTS_2D_H

#include <iostream>

#include <CGAL/enum.h>

// functors for writing 2D objects to standard output.
// written as functors not functions to be in keeping with CGAL standard


   template <class K>
   struct Write_Point_2
  {
      inline void operator()( typename K::Point_2 p ){ write( p ); }

      inline void write( typename K::Point_2 p )
     {
         std::cout << "(" << p.x() << "," << p.y() << ")"; 
     }
  };


   template <class K>
   struct Write_Point_To_Point_2
  {
      Write_Point_2<K>   write_point;

      inline void operator()( typename K::Point_2 p0, typename K::Point_2 p1 ){ write( p0, p1 ); }

      inline void write( typename K::Point_2 p0, typename K::Point_2 p1 )
     {
         write_point( p0 );
         std::cout << "->";
         write_point( p1 );
     }
  };


   template <class K>
   struct Write_Line_2
  {
      Write_Point_To_Point_2<K>   write_point_to_point;

      inline void operator()( typename K::Line_2 l ){ write( l ); }

      inline void write( typename K::Line_2 l )
     {
         typename K::Vector_2  dir(l);

      // construct two points on line
         typename K::Point_2   p( l.point(0) );
         typename K::Point_2   q( p + dir );

         write_point_to_point( p, q );
     }
  };


   template <class K>
   struct Write_Segment_2
  {
      Write_Point_To_Point_2<K>   write_point_to_point;

      inline void operator()( typename K::Segment_2 s ){ write( s ); }

      inline void write( typename K::Segment_2 s )
     {
         write_point_to_point( s.source(), s.target() );
     }
  };


   template <class K>
   struct Write_Vector_2
  {
      Write_Point_To_Point_2<K>   write_point_to_point;

      inline void operator()( typename K::Vector_2 v ){ write( v ); }

      inline void write( typename K::Vector_2 v )
     {
         typename K::Point_2   p( CGAL::ORIGIN );
         typename K::Point_2   q( p + v );

         write_point_to_point( p, q );
     }
  };

#endif
