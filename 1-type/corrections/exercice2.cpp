/*
  Exercice 2 - Manipulation de chaines de caractères

  Q1 - Construisez une variable de type chaine contenant 10 symboles #
  Q2 - Construisez une variable de type chaine contenant deux symboles # séparés par 8 espaces
  Q3 - En vous aidant des variables ci-dessus, affichez le motif suivant :

  ##########
  #        #
  #        #
  #        #
  ##########

  Q4 - En vous aidant du code précédent, construisez une variable de type chaine de caractère
  contenant ce motif et affichez la.
*/

#include <iostream>
#include <string>

int main(int, char**)
{
  // Q1
  std::string extreme(10,'#');
  std::cout << "extreme: " << extreme << "\n";

  //Q2
  std::string middle(10,' ');
  middle[0] = middle[9] = '#';
  std::cout << "middle: " << middle << "\n";

  //Q3
  std::cout << extreme << "\n";
  std::cout << middle << "\n";
  std::cout << middle << "\n";
  std::cout << middle << "\n";
  std::cout << extreme << "\n";

  // Q4
  std::string motif = extreme + "\n"
                    + middle + "\n"
                    + middle + "\n"
                    + middle + "\n"
                    + extreme;

  std::cout << motif << "\n";

  return 0;
}
