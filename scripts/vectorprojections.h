#define ENDL std::cout << std::endl

#ifndef VECTORPROJECTIONS_H
#define VECTORPROJECTIONS_H


// functor to project vector u onto vector v
   template <class K>
   struct Project_Vector_On_Vector
  {
      template <class Vector>
      inline Vector operator()( Vector u, Vector v ){ return project( u,v ); }

      template <class Vector>
      inline Vector project( Vector u, Vector v )
     {
         Vector p=v;

         p*= v*u;
         p/= v.squared_length();

         return p;
     }
  };


//functor to project vector v onto line l
   template <class K>
   struct Project_Vector_On_Line
  {
      Project_Vector_On_Vector<K>   project_vector_on_vector;

      template <class Vector, class Line>
      inline Vector operator()( Vector v, Line l ){ return project( v,l ); }

      template <class Vector, class Line>
      inline Vector project( Vector v, Line l )
     {
         Vector p=l.to_vector();
         return project_vector_on_vector( v, p );
     }
  };


// functor to project vector v onto plane p
   template <class K>
   struct Project_Vector_On_Plane
  {
      Project_Vector_On_Vector<K>   project_vector_on_vector;

      typedef typename K::Vector_3  Vector;
      typedef typename K::Plane_3  Plane;

      inline Vector operator()( Vector v, Plane p ){ return project( v,p ); }

      inline Vector project( Vector v, Plane p )
     {
         Vector n=p.orthogonal_vector();

         n = project_vector_on_vector( v, n );

         return v-n;
     }
  };

#endif
