/*
  Exercice 1 - Type de bases

  Le programme suivant calcule la moyenne de 10 valeurs num�riques.
  Le r�sultat est ensuite affich�.

  Q1 - Le r�sultat est il correct ?
  Q2 - Quelle est la source de l'erreur ?
  Q3 - Corrigez le code afin d'obtenir le bon r�sultat.
*/

#include <iostream>

int main(int, char**)
{
  float moyenne = 0;

  moyenne = moyenne + 3;
  moyenne = moyenne + 5;
  moyenne = moyenne + 1;
  moyenne = moyenne + 9;
  moyenne = moyenne + 4;
  moyenne = moyenne + 2;
  moyenne = moyenne + 8;
  moyenne = moyenne + 17;
  moyenne = moyenne + 9;
  moyenne = moyenne + 11;

  moyenne = moyenne / 10;

  std::cout << "La moyennes est: " << moyenne << "\n";

  return 0;
}
