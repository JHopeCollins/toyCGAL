#ifndef WRITEOBJECTS_H
#define WRITEOBJECTS_H

#include <iostream>

#include <CGAL/enum.h>

// functors for writing 2D objects to standard output.
// written as functors not functions to be in keeping with CGAL standard


   template <class K>
   struct Write_Point
  {
      template <class Point>
      inline void operator()( Point p ){ write( p ); }

      template <class Point>
      inline void write( Point p )
     {
         auto  current_coordinate = p.cartesian_begin();
         auto  last_coordinate    = p.cartesian_end();

         last_coordinate--;

         std::cout << "(";
         while( current_coordinate != last_coordinate )
        {
            std::cout << *current_coordinate++ << ",";
        }
         std::cout << *current_coordinate;
         std::cout << ")";
     }
  };


   template <class K>
   struct Write_Point_To_Point
  {
      Write_Point<K>   write_point;

      template <class Point>
      inline void operator()( Point p0, Point p1 ){ write( p0, p1 ); }

      template <class Point>
      inline void write( Point p0, Point p1 )
     {
         write_point( p0 );
         std::cout << "->";
         write_point( p1 );
     }
  };


   template <class K>
   struct Write_Line
  {
      Write_Point_To_Point<K>   write_point_to_point;

      template <class Line>
      inline void operator()( Line l ){ write( l ); }

      template <class Line>
      inline void write( Line l )
     {
         write_point_to_point( l.point(0), l.point(0)+l.to_vector() );
     }
  };


   template <class K>
   struct Write_Segment
  {
      Write_Point_To_Point<K>   write_point_to_point;

      template <class Segment>
      inline void operator()( Segment s ){ write( s ); }

      template <class Segment>
      inline void write( Segment s )
     {
         write_point_to_point( s.source(), s.target() );
     }
  };


   template <class K>
   struct Write_Vector
  {
      Write_Point_To_Point<K>   write_point_to_point;

      template <class Vector>
      inline void operator()( Vector v ){ write( v ); }

      template <class Vector>
      inline void write( Vector v )
     {
         auto     q=CGAL::ORIGIN + v;
         auto     p=q-v;

         write_point_to_point( p, q );
     }
  };


   template <class K>
   struct Write_Plane_3
  {
      Write_Point<K>   write_point;

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
