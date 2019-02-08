#define ENDL std::cout << std::endl

#include <iostream>
#include <assert.h>

#include <CGAL/Gmpz.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include "writeobjects.h"

#include "vectorprojections.h"

typedef CGAL::Gmpz                    ExactNumberType;
typedef double                      InexactNumberType;

typedef CGAL::Homogeneous<ExactNumberType>   K1;
typedef CGAL::Cartesian<InexactNumberType>   K2;

typedef CGAL::Exact_predicates_exact_constructions_kernel    K3;
typedef CGAL::Exact_predicates_inexact_constructions_kernel  K4;

typedef K4  Kernel;

typedef Kernel::Point_2       Point_2;
typedef Kernel::Point_3       Point_3;
typedef Kernel::Plane_3       Plane_3;
typedef Kernel::Vector_3     Vector_3;

typedef Write_Point<Kernel>    WritePoint;
typedef Write_Line<Kernel>     WriteLine;
typedef Write_Vector<Kernel>   WriteVector;
typedef Write_Plane_3<Kernel>  WritePlane;

typedef Project_Vector_On_Vector<Kernel>  ProjectVectorOnVector;
typedef Project_Vector_On_Plane<Kernel>   ProjectVectorOnPlane;


   int main()
  {
      const int   np=3;
      int         i,j,k;
      double      a,b,c;

      WritePoint   writepoint;
      WriteLine    writeline;
      WritePlane   writeplane;
      WriteVector  writevector;

      ProjectVectorOnVector   projectVonV;
      ProjectVectorOnPlane    projectVonP;

      Point_3  pt[np][np][np];

      Point_2  q,r;
      Point_3  s,t;

      Vector_3 u,v;

      for( i=0; i<np; i++ )
     {
         for( j=0; j<np; j++ )
        {
            for( k=0; k<np; k++ )
           {
               a=(double)i;
               b=(double)j;
               c=(double)k;

               pt[i][j][k]= Point_3(a,b,c);
           }
        }
     }

      Plane_3  Pxy(  pt[0][0][0], pt[1][0][0], pt[0][1][0] ),
               Pxz(  pt[0][0][0], pt[1][0][0], pt[0][0][1] ),
               Pyz(  pt[0][0][0], pt[0][1][0], pt[0][0][1] ),
               P111( pt[1][0][0], pt[0][1][0], pt[0][0][1] );


      Plane_3  P=P111;
      std::cout << "working in plane: ";
      writeplane( P ); ENDL;

      // arbitrary point in R2
      q = Point_2( 1., 2. );
      std::cout << "start point_2: ";
      writepoint( q ); ENDL;

      // convert point onto one of planes
      s = P.to_3d( q );
      std::cout << "start point_3: ";
      writepoint( s ); ENDL;

      // arbitrary vector in R3
      u = Vector_3(2.,3.,1.);
      std::cout << "displacement vector_3: ";
      writevector( u ); ENDL;

      // project vector onto plane
      v = projectVonP( u, P );
      std::cout << "displacement vector_3 in plane: ";
      writevector( v ); ENDL;

      // increment point by projected vector
      t = s + v;
      std::cout << "displaced point_3: ";
      writepoint( t ); ENDL;

      // convert back to R2
      r = P.to_2d( t );
      std::cout << "displaced point_2: ";
      writepoint( r ); ENDL;

      return 0;
  }

