/*
  Exercice 1 - Fraction

  Fournissez une implémentation d'une structure fraction représentant un nombre
  fractionnaire. Vous implémenterez sous forme de fonction ou d'opérateur surchargés les
  fonctionnalités suivantes:

  - addition fraction/fraction, entier/fraction, fraction/entier - ok
  - soustraction fraction/fraction, entier/fraction, fraction/entier - ok
  - multiplication fraction/fraction, entier/fraction, fraction/entier - ok
  - division fraction/fraction, entier/fraction, fraction/entier - ok
  - négation de fraction - ok
  - conversion de la fraction en nombre réel double précision - ok
  - insertion et extraction depuis un flux - ok
*/

#include <iostream>

struct Fraction
{
  int num, den;  
};

Fraction operator+ (Fraction f1, Fraction f2){
  return {f1.num*f2.den + f2.num*f1.den, f1.den*f2.den};
}
Fraction operator+ (Fraction f1, int i2){
  return {f1.num + f1.den*i2, f1.den};
}
Fraction operator+ (int i1, Fraction f2){
  return {f2.num + f2.den * i1, f2.den};
}

Fraction operator- (Fraction f1, Fraction f2){
  return {f1.num*f2.den - f2.num*f1.den, f1.den*f2.den};
}
Fraction operator- (Fraction f1, int i2){
  return {f1.num - f1.den*i2, f1.den};
}
Fraction operator- (int i1, Fraction f2){
  return {f2.num - f2.den*i1, f2.den};
}

Fraction operator* (Fraction f1, Fraction f2){
  return {f1.num*f2.num, f1.den*f2.den};
}
Fraction operator* (Fraction f1, int i2){
  return {f1.num*i2, f1.den};
}
Fraction operator* (int i1, Fraction f2){
  return {f2.num*i1, f2.den};
}

Fraction operator- (Fraction f1){
  return {-f1.num, f1.den};
}

Fraction invert (Fraction f1){
  return {f1.den, f1.num};
}
Fraction operator/ (Fraction f1, Fraction f2){
  f2 = invert(f2);
  return f1 * f2;
}
Fraction operator/ (Fraction f1, int i2){
  return {f1.num, f1.den*i2};
}
Fraction operator/ (int i1, Fraction f2){
  return {f2.num, f2.den*i1};
}

double convert (Fraction f1){
  return double(f1.num)/f1.den;
}

std::ostream& operator<< (std::ostream &o, const Fraction& f)
{
    return o << "(" << f.num << "/" << f.den << ")";
} 

int main(int, char**)
{
  Fraction x {1,3};
  Fraction y {2,7};
  Fraction z {2,3};

  std::cout << x + y << std::endl;
  std::cout << x << std::endl;
  std::cout << z - x << std::endl;
  std::cout << z / x << std::endl;
  std::cout << convert(x) << std::endl;
}
