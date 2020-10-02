/*
  Exercice 2 - Tableau 2D

  On désire implémenter un tableau dynamique à deux dimensions. Pour ce faire, on considérera
  qu'un tableau 2D se stocke dans un tableau dynamique standard et que, lorsque sa largeur
  et sa hauteur sont disponibles, on peut calculer la position linéaire n d'un élément de coordonnées
  (i,j) par la formule :

    n = i + j * largeur

  Q1 - Proposez une structure tableau2D qui suit cette spécification.
  Q2 - Surchargez l'opérateur () pour accéder à l'élément (i,j) du tableau.
  Q3 - Surchargez l'opérateur d'insertion de flux afin d'affichez vos tableaux
  Q4 - Fournissez sous forme de fonction un moyen d'obtenir la valeur du nombre total
  d'éléments du tableau.
  Q5 - Implémentez les fonctions membres begin() et end() permettant d'utiliser votre structure dans
  une boucle for par interval
*/

#include <iostream>
#include <vector>
#include <numeric>

// Q1
struct Tableau2D {
  std::size_t height, width;
  std::vector<int> v;

  Tableau2D() : height(0), width(0), v(0) {} 
  Tableau2D(int height, int width) : height(height), width(width), v(height*width) {}

  // Q2
  int& operator() (std::size_t const & i, std::size_t const & j);
  int operator() (std::size_t const & i, std::size_t const & j) const;


  // Q5
  auto begin() {return v.begin();}
  auto end() {return v.end();}
};


// Q2
int& Tableau2D::operator() (std::size_t const & i, std::size_t const & j){
    return v[i+j*height];
}

int Tableau2D::operator() (std::size_t const & i, std::size_t const & j) const{
    return v[i+j*height];
}

// Q3
std::ostream& operator<< (std::ostream& os, Tableau2D const& tab){
  for (std::size_t j = 0; j < tab.width; ++j)
  {
    for (std::size_t i = 0; i < tab.height; ++i)
    {
      os << tab(i, j) << ' ';
    }
    os << '\n';
  }
  return os;
}

// Q4
int sum(Tableau2D tab)
{
  int acc = 0;
  for (std::size_t i = 0; i < tab.v.size(); ++i)
  {
    acc += tab.v[i];
  }
  return acc;
}

// Q4 when Q5 already done
int sum_after_Q5(Tableau2D tab)
{
  int acc = 0;
  for (auto e : tab)
  {
    acc += e;
  }
  return acc;
}

// Q4 bis using STL (requires #include <numeric>)
int sum_stl(Tableau2D tab)
{
  return std::accumulate(tab.v.begin(), tab.v.end(), 0);
  // also possible :
  // return std::accumulate(tab.begin(), tab.end(), 0);
}



int main(int, char**)
{

  Tableau2D tab (2,4);
  std::cout << tab(0,0) << std::endl;
  tab(0, 0) = 3;
  std::cout << tab(0,0) << std::endl;

  std::cout << tab;
  tab(0, 1) = 1;
  tab(1, 1) = 2;

  std::cout << std::endl;
  std::cout << tab << std::endl;
  std::cout << sum(tab) << std::endl;
  std::cout << sum_after_Q5(tab) << std::endl;
  std::cout << sum_stl(tab) << std::endl;

  auto e = tab.begin()+2;
  std::cout << *e << std::endl;
}
