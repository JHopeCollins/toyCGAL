#define ENDL std::cout << std::endl

#include <iostream>
#include <assert.h>

#include <CGAL/Gmpz.h>

#include <CGAL/Cartesian.h>
#include <CGAL/Homogeneous.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

#include "writeobjects2D.h"
#include "writeobjects3D.h"

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

typedef Write_Point_2<Kernel>    WritePoint_2;
typedef Write_Point_3<Kernel>    WritePoint_3;
typedef Write_Plane_3<Kernel>    WritePlane_3;
typedef Write_Vector_3<Kernel>   WriteVector_3;

   int main()
  {
      const int   np=3;
      int         i,j,k;

      WritePlane_3   writeplane_3;
      WritePoint_3   writepoint_3;
      WritePoint_2   writepoint_2;

      Point_3  p[np][np][np];

      Point_2  q,r;
      Point_3  s,t;

      for( i=0; i<np; i++ )
     {
         for( j=0; j<np; j++ )
        {
            for( k=0; k<np; k++ )
           {
               p[i][j][k]= Point_3(i,j,k);
           }
        }
     }

      Plane_3  Pxy(  p[0][0][0], p[1][0][0], p[0][1][0] ),
               Pxz(  p[0][0][0], p[1][0][0], p[0][0][1] ),
               Pyz(  p[0][0][0], p[0][1][0], p[0][0][1] ),
               P111( p[1][0][0], p[0][1][0], p[0][0][1] );

      // std::cout << "xy  plane: "; writeplane_3( Pxy  ); ENDL;
      // std::cout << "xz  plane: "; writeplane_3( Pxz  ); ENDL;
      // std::cout << "yz  plane: "; writeplane_3( Pyz  ); ENDL;
      // std::cout << "111 plane: "; writeplane_3( P111 ); ENDL;

   // Plane_3.to_2d( q ) projects q on Plane_3 onto the xy plane
      for( i=0; i<np; i++ )
     {
         for( j=0; j<np; j++ )
        {
            q = Pxy.to_2d( p[i][j][0] );

            r = Point_2(i,j);

            assert( q==r );
        }
     }

   // Plane_3.to_2d( q ) projects q on Plane_3 onto a 2D plane
      for( k=0; k<np; k++ )
     {
         q = Pxz.to_2d( p[1][0][k] );

         // writepoint_3( p[1][0][k] );
         // writepoint_2( q ); ENDL;
     }

   // Plane_3.to_2d( q ) projects q onto the plane_3, then onto a 2D plane
      for( k=0; k<np; k++ )
     {
         q = Pxz.to_2d( p[1][0][k] );
         r = Pxz.to_2d( p[1][1][k] );

         assert( q==r );
     }

   // Where does origin of 2D plane map to on Plane_3?
      q = CGAL::ORIGIN;

      s = Pxy.to_3d(  q ); writepoint_3( s ); ENDL;
      s = Pxz.to_3d(  q ); writepoint_3( s ); ENDL;
      s = Pyz.to_3d(  q ); writepoint_3( s ); ENDL;
      s = P111.to_3d( q ); writepoint_3( s ); ENDL;

      return 0;
  }


