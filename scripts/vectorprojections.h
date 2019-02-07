#define ENDL std::cout << std::endl

#ifndef VECTORPROJECTIONS_H
#define VECTORPROJECTIONS_H


// functor to project vector u onto vector v
   template <class K>
   struct Project_Vector_On_Vector
  {
      typedef typename K::Vector_2  Vector;

      //template <class Vector>
      inline Vector operator()( Vector u, Vector v){ project( u, v ); }

      //template <class Vector>
      inline Vector project( Vector u, Vector v )
     {
         Vector p;

         std::cout << "0"; ENDL;

         p = v;
         std::cout << "1"; ENDL;
         p*= v*u;
         std::cout << "2"; ENDL;
         p/= v.squared_length();
         std::cout << "3"; ENDL;

         /*
         typename K::FT d;
         d = u*v;
         d/= v.squared_length();
         p = v*d;
         */

         std::cout << "4"; ENDL;
         return p;
     }
  };

// functor to project vector v onto plane p
   template <class K>
   struct Project_Vector_On_Plane
  {
      Project_Vector_On_Vector<K>   project_vector_on_vector;

      typedef typename K::Vector_3  Vector;
      typedef typename K::Plane_3  Plane;

      inline Vector operator()( Vector v, Plane p ){ project( v, p ); }

      inline Vector project( Vector v, Plane p )
     {
         Vector n=p.orthogonal_vector();

         n = project_vector_on_vector( v, n );

         return v-n;
     }
  };

#endif
