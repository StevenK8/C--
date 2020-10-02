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

std::string carre(std::string s, std::string s2);

int main(int, char**)
{
  // Q1
  std::string s = "##########";
  //Q2
  std::string s2 = "#        #";
  //Q3
  std::cout << carre(s,s2);
  // Q4
  std::string scarre = carre(s,s2);
  std::cout << scarre;


  return 0;
}

std::string carre(std::string s, std::string s2){
  std::string string;
  string += s + "\n";
  for (int i=0; i<3; i++){
    string += s2 + "\n";
  }
  string += s + "\n";
  return string;
}