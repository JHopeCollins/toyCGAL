#include <iostream>
#include <string.h>

#include "quadtosquare.h"

   int main()
  {
      Quad_Square_Transform<double> map;

      double   x0[4]={ 0.0, 2.0, 4.0, 0.0 };
      double   y0[4]={ 0.0, 0.0, 4.0, 2.0 };

      double   p0[2]={ 0.0, 0.0 };
      double   p1[2]={ 1.0, 0.0 };
      double   p2[2]={ 1.0, 1.0 };
      double   p3[2]={ 0.0, 1.0 };

      double   q0[2]={ 0.0, 0.0 };
      double   q1[2]={ 0.0, 0.0 };
      double   q2[2]={ 0.0, 0.0 };
      double   q3[2]={ 0.0, 0.0 };


      int         i;


      map.set_quad_corners( x0, y0 );

      map.stdcout();

      map.s2q_map( p0, q0 );
      map.s2q_map( p1, q1 );
      map.s2q_map( p2, q2 );
      map.s2q_map( p3, q3 );

      std::cout << "q0: " << q0[0] << "," << q0[1] << std::endl;
      std::cout << "q1: " << q1[0] << "," << q1[1] << std::endl;
      std::cout << "q2: " << q2[0] << "," << q2[1] << std::endl;
      std::cout << "q3: " << q3[0] << "," << q3[1] << std::endl;

      map.q2s_map( q0, p0 );
      map.q2s_map( q1, p1 );
      map.q2s_map( q2, p2 );
      map.q2s_map( q3, p3 );

      std::cout << "p0: " << p0[0] << "," << p0[1] << std::endl;
      std::cout << "p1: " << p1[0] << "," << p1[1] << std::endl;
      std::cout << "p2: " << p2[0] << "," << p2[1] << std::endl;
      std::cout << "p3: " << p3[0] << "," << p3[1] << std::endl;

      return 0;
  }
