#ifndef MATRIX_H
#define MATRIX_H

/* a few matrix routines needed for bilinear mappings and their inverses
 *
 * 2x2 matrices:
 *  0  2
 *  1  3
 *
 * 3x3 matrices:
 *  0  3  6
 *  1  4  7
 *  2  5  8
 */

   template <class NumberType>
   inline NumberType determinant22( NumberType *a ){return a[0]*a[3] - a[2]*a[1]; };


   template <class NumberType>
   inline NumberType determinant22( NumberType a0, NumberType a1, NumberType a2, NumberType a3 ){ return a0*a3-a2*a1; };


   template <class NumberType>
   inline NumberType determinant33( NumberType *a )
  {
      NumberType  d[3], val;

      d[0]= determinant22( a[4], a[8], a[5], a[7] );
      d[1]= determinant22( a[3], a[8], a[5], a[6] );
      d[2]= determinant22( a[3], a[7], a[4], a[6] );

      val=  a[0]*d[0]
           -a[1]*d[1]
           +a[2]*d[2];

      return val;

  };


   template <class NumberType>
   inline void transpose22( NumberType *a, NumberType *b )
  {
      b[0]=a[0];
      b[1]=a[2];
      b[2]=a[1];
      b[3]=a[3];
  };


   template <class NumberType>
   inline void transpose33( NumberType *a, NumberType *b )
  {
      b[0]=a[0];
      b[4]=a[4];
      b[8]=a[8];

      b[3]=a[1];
      b[6]=a[2];
      b[7]=a[5];

      b[1]=a[3];
      b[2]=a[6];
      b[5]=a[7];
  };


   template <class NumberType>
   inline void cofactor_matrix22( NumberType *a, NumberType *b )
  {
      b[0]= a[3];
      b[1]=-a[2];
      b[2]=-a[1];
      b[3]= a[0];
  };


   template <class NumberType>
   inline void cofactor_matrix33( NumberType *a, NumberType *b )
  {
      b[0] = determinant22( a[4], a[5], a[7], a[8] );
      b[1] = determinant22( a[3], a[5], a[6], a[8] );
      b[2] = determinant22( a[3], a[4], a[6], a[7] );
      b[3] = determinant22( a[1], a[2], a[7], a[8] );
      b[4] = determinant22( a[0], a[2], a[6], a[8] );
      b[5] = determinant22( a[0], a[1], a[6], a[7] );
      b[6] = determinant22( a[1], a[2], a[4], a[5] );
      b[7] = determinant22( a[0], a[2], a[3], a[5] );
      b[8] = determinant22( a[0], a[1], a[3], a[4] );
  };


   template <class NumberType>
   inline void adjoint_matrix22( NumberType *a, NumberType *b )
  {
      NumberType  c[4];
      cofactor_matrix22( a, c );
      transpose22( c, b );
  };


   template <class NumberType>
   inline void adjoint_matrix33( NumberType *a, NumberType *b )
  {
      NumberType  c[9];
      cofactor_matrix33( a, c );
      transpose33( c, b );
  };


   template <class NumberType>
   inline void inverse_matrix22( NumberType *a, NumberType *b )
  {
      NumberType d=determinant22( a );
      adjoint_matrix22( a, b );
      for( int i=0; i<9; i++){ b[i]/=d; }
  };


   template <class NumberType>
   inline void inverse_matrix33( NumberType *a, NumberType *b )
  {
      NumberType d=determinant33( a );
      adjoint_matrix33( a, b );
      for( int i=0; i<4; i++){ b[i]/=d; }
  };


// A*x=b routines

   template <class NumberType>
   inline void Axb_22( NumberType *a, NumberType *x, NumberType *b )
  {
      b[0] = a[0]*x[0] + a[2]*x[1];
      b[1] = a[1]*x[0] + a[3]*x[1];
  };


   template <class NumberType>
   inline void Axb_33( NumberType *a, NumberType *x, NumberType *b )
  {
      b[0] = a[0]*x[0] + a[3]*x[1] + a[6]*x[2];
      b[1] = a[1]*x[0] + a[4]*x[1] + a[7]*x[2];
      b[2] = a[2]*x[0] + a[5]*x[1] + a[8]*x[2];
  };


   template <class NumberType>
   inline void Axb_32( NumberType *a, NumberType *x, NumberType *b )
  {
      b[0] = a[0]*x[0] + a[2]*x[1] + a[4]*x[2];
      b[1] = a[1]*x[0] + a[3]*x[1] + a[5]*x[2];
  };


   template <class NumberType>
   inline void Axb_23( NumberType *a, NumberType *x, NumberType *b )
  {
      b[0] = a[0]*x[0] + a[3]*x[1];
      b[1] = a[1]*x[0] + a[4]*x[1];
      b[2] = a[2]*x[0] + a[5]*x[1];
  };


#endif
