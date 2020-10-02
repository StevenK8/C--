/*
  Exercice 2 - Tableau 2D

  On désire implémenter un tableau dynamique à deux dimensions. Pour se faire, on considérera
  qu'un tableau 2D se stocke dans un tableau dynamique standard et que, lorsque sa largeur
  et sa hauteur sont disponibles, on peut calculer la position linéaire n d'un élément de coordonnées
  (i,j) par la formule :

    n = i + j * largeur

  Q1 - Proposez une structure tableau2D qui suit cette spécification
  Q2 - Surcharger l'opérateur () pour accéder à l'élément (i,j) du tableau.
  Q3 - Surcharger l'opérateur d'insertion de flux afin d'affichez vos tableaux
  Q4 - Fournissez sous forme de fonction un moyen d'obtenir la valeur du nombre total
  d'éléments du tableau.
  Q5 - Implémentez les fonctions membres begin() et end() permettant d'utiliser votre structure dans
  une boucle for par interval
*/

#include <iostream>
#include <vector>

//Q1
struct Tableau2D{
  std::size_t hauteur, largeur;
  std::vector<int> tableau;

  Tableau2D(int hauteur, int largeur) : hauteur(hauteur), largeur(largeur), tableau(hauteur * largeur) {}
  Tableau2D() : hauteur(0), largeur(0), tableau(0) {}

//Q2
  int operator() (std::size_t const &i, std::size_t const &j) const;
  int& operator() (std::size_t const &i, std::size_t const &j);

  auto begin() {return tableau.begin();}
  auto end() {return tableau.end();}
};

//Q2
int Tableau2D::operator() (std::size_t const & i, std::size_t const & j)const{
  return tableau[i+j * largeur];
}

int& Tableau2D::operator() (std::size_t const &i, std::size_t const &j){
  return tableau[i+j * largeur];
}

//Q3
std::ostream& operator<< (std::ostream &o, Tableau2D& t)
{
  for (std::size_t i=0; i<t.hauteur; i++){ // Pour chaque ligne
    for (std::size_t j=0; j<t.largeur; j++){ // Pour chaque élément
      o << t(i,j) << " ";
    }
    o << "\n";
  }
  return o; 
}

//Q4
int sum (Tableau2D& t)
{
  int nb = 0;
  for (std::size_t i = 0; i<t.hauteur; i++){ // Pour chaque ligne
    for (std::size_t j = 0; j<t.largeur; j++){ // Pour chaque élément
      nb+=t(i,j);
    }
  }
  return nb; 
}

void print(Tableau2D t){
  for (auto it = t.begin(); it != t.end(); ++it){
    std::cout << *it << std::endl;
  }
}

int main(int, char**)
{
  Tableau2D t = {2,4};
  t(0,0) = 6;
  t(1,0) = 3;
  t(1,3) = 5;
  t(0,3) = 1;
  std::cout << t;
  std::cout << sum(t);
}
