#ifndef QUADTOSQUARE_H
#define QUADTOSQUARE_H

#include <iostream>
#include "matrix.h"

/* struct to represent the transformation between an arbitrary 2D quadrilateral and the unit square
 *
 *    3---2
 *    |   |
 *    0---1
 */

   template <class NumberType>
   struct Quad_Square_Transform
  {
      const NumberType     one=1;

      NumberType  x[4],y[4];   // coordinates of quad corners

      NumberType  s2q_transform[9]; // transformation matrix from quad to square
      NumberType  q2s_transform[9]; // transformation matrix from quad to square

   // constructor
      Quad_Square_Transform()
     {
         memset( x, 0, 4*sizeof(NumberType) );
         memset( y, 0, 4*sizeof(NumberType) );

         memset( s2q_transform, 0, 9*sizeof(NumberType) );
         memset( q2s_transform, 0, 9*sizeof(NumberType) );
     }

      void set_quad_corners( NumberType *x0, NumberType *y0 )
     {
         for( int i=0; i<4; i++ ){ x[i]=x0[i]; y[i]=y0[i]; }

         calculate_s2q();
         calculate_q2s();
     }

   // calculate the perspective matrix representing the projective mapping from unit square to quadrilateral
      void calculate_s2q()
     {
         NumberType  dx1, dx2, dx3, dy1, dy2, dy3;
         NumberType  a11, a21, a31, a12, a22, a32, a13, a23, a33;
         NumberType  num, den;

         dx1 = x[1] - x[2];
         dx2 = x[3] - x[2];
         dx3 = x[0] - x[1] + x[2] - x[3];

         dy1 = y[1] - y[2];
         dy2 = y[3] - y[2];
         dy3 = y[0] - y[1] + y[2] - y[3];

         num = determinant22( dx3, dy3, dx2, dy2 );
         den = determinant22( dx1, dy1, dx2, dy2 );
         a13 = num / den;

         num = determinant22( dx1, dy1, dx3, dy3 );
         den = determinant22( dx1, dy1, dx2, dy2 );
         a23 = num / den;

         a33 = 0;

         a11 = x[1] - x[0] + a13*x[1];
         a21 = x[3] - x[0] + a23*x[3];
         a31 = x[0];

         a12 = y[1] - y[0] + a13*y[1];
         a22 = y[3] - y[0] + a23*y[3];
         a32 = y[0];

         s2q_transform[0]=a11;
         s2q_transform[1]=a21;
         s2q_transform[2]=a31;
         s2q_transform[3]=a12;
         s2q_transform[4]=a22;
         s2q_transform[5]=a32;
         s2q_transform[6]=a13;
         s2q_transform[7]=a23;
         s2q_transform[8]=a33;

         return;
     }

   // calculate the perspective matrix representing the projective mapping from quadrilateral to unit square
      void calculate_q2s(){ adjoint_matrix33( s2q_transform, q2s_transform ); }

   // bilinear interpolation from the unit square onto a quadrilateral
      void s2q_interpolate( NumberType *xs, NumberType *xq )
     {
         NumberType  u=xs[0], v=xs[1];
         NumberType  w[4];

         u=xs[0];
         v=xs[1];

         w[0] = ( one-u )*( one-v );
         w[1] =       u  *( one-v );
         w[2] =       u  *      v  ;
         w[3] = ( one-u )*      v  ;

         xq[0]= w[0]*x[0] + w[1]*x[1] + w[2]*x[2] + w[3]*x[3];
         xq[1]= w[0]*y[0] + w[1]*y[1] + w[2]*y[2] + w[3]*y[3];

         return;
     }

   // map from the unit square onto the quadrilateral using the projective mapping matrix and homogeneous coordinates
      void s2q_map( NumberType *xs, NumberType *xq )
     {
         NumberType  xsh[3];
         NumberType  xqh[3];
         NumberType   At[9];

         xsh[0]=xs[0];
         xsh[1]=xs[1];
         xsh[2]=one;

         transpose33( s2q_transform, At );

         Axb_33( At, xsh, xqh );

         xq[0]=xqh[0]/( xqh[2] + 0.000000001 );
         xq[1]=xqh[1]/( xqh[2] + 0.000000001 );
     }

   // map from the quadrilateral onto the unit square using the projective mapping matrix and homogeneous coordinates
      void q2s_map( NumberType *xq, NumberType *xs )
     {
         NumberType  xqh[3];
         NumberType  xsh[3];
         NumberType   At[9];

         xqh[0]=xq[0];
         xqh[1]=xq[1];
         xqh[2]=one;

         transpose33( q2s_transform, At );

         Axb_33( At, xqh, xsh );

         xs[0]=xsh[0]/xsh[2];
         xs[1]=xsh[1]/xsh[2];
     }

   // print transform to standard outpuf
      void stdcout()
     {
         std::cout << "QST.one: " << one << std::endl;

         std::cout << "QST.p0: (" << x[0] << "," << y[0] << ")" << std::endl;
         std::cout << "QST.p1: (" << x[1] << "," << y[1] << ")" << std::endl;
         std::cout << "QST.p2: (" << x[2] << "," << y[2] << ")" << std::endl;
         std::cout << "QST.p3: (" << x[3] << "," << y[3] << ")" << std::endl;

         std::cout << "QST.s2q: (";
         for( int i=0; i<8; i++ ){ std::cout << s2q_transform[i] << ","; }
         std::cout << s2q_transform[8] << ")" << std::endl;

         std::cout << "QST.q2s: (";
         for( int i=0; i<8; i++ ){ std::cout << q2s_transform[i] << ","; }
         std::cout << q2s_transform[8] << ")" << std::endl;
     }
  };

#endif
