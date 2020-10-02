/*
  Exercice 1 - Avis de recherche

  Q1 - Remplissez le tableau data de valeurs réelles aléatoires comprises entre 1 et 20.
  Pour ce faire, consultez la documentation de std::rand.
  Q2 - Affichez le contenu du tableau ainsi rempli.
  Q3 - Ecrivez le code nécesaire pour parcourir le tableau data et insérer dans un tableau resultats
  les index des valeurs supérieurs à 15.
  Q4 - Affichez le tableau ainsi rempli et vérifiez vos résultats.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>

int main(int, char**)
{
  srand(time(NULL));

  std::vector<float> data(20);

  // Q1
  for (int i=0; i<20; i++){
    data[i] = std::rand()%20+1;
    std::cout << data[i] << " ";
  }
  std::cout << "\n";
  
  // Q2

  // Q3
  std::vector<float> resultat;
  for (auto v : data){
    if(v>15) {
      resultat.push_back(v);
    }
  }
  // Q4
  for (auto r : resultat){
    std::cout << r << " ";
  }


  return 0;
}
