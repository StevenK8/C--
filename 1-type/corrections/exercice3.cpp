/*
  Exercice 3 - Manipulation de tableaux de taille fixe

  Q1 - Utilisez std::array pour définir un tableau de 3 éléments de type double
  Q2 - Utilisez std::array pour définir un tableau de 3 éléments de type tableau de 3 doubles
  Q3 - Définissez un alias de type nommé vec3 pour le type vecteur de 3 éléments de type double
  Q4 - Utilisez le type ainsi défini pour créer une variable v contenant le vecteur suivant:

  | 2.5 |
  | 0.6 |
  | 1.1 |

  Q5 - Définissez un alias de type nommé mat33 pour le type matrice de 3x3 éléments de type double
  Q6 - Utilisez le type ainsi défini pour créer une variable m contenant la matrice suivante :

  | 1 2 1 |
  | 2 4 6 |
  | 1 2 0 |

  Q7 - Calculez le produit de la matrice m et du vecteur v ainsi défini dans un vecteur res
  Q8 - Vérifiez votre résultat
*/

#include <iostream>
#include <array>

int main(int, char**)
{
  // Q1
  std::array<double,3> t3;

  //Q2
  std::array<std::array<double,3>, 3> t33;

  //Q3
  using vec3 =  std::array<double,3>;

  // Q4
  vec3 v = {2.5, 0.6, 1.1 };

  // Q5
  using mat33 =  std::array<vec3,3>;

  // Q6
  mat33 m = { 1,2,1
            , 2,4,6
            , 1,2,0
            };

  // Q7
  vec3 res = {};

  res[0] = v[0]*m[0][0] + v[1]*m[0][1] + v[2]*m[0][2];
  res[1] = v[0]*m[1][0] + v[1]*m[1][1] + v[2]*m[1][2];
  res[2] = v[0]*m[2][0] + v[1]*m[2][1] + v[2]*m[2][2];

  // Q8
  std::cout << res[0] << "\n";
  std::cout << res[1] << "\n";
  std::cout << res[2] << "\n";

  return 0;
}
