/*
  Exercice 3 - Nuage de point

  Q1 - Impélmetez une structrue représentant un point 3D pondéré par un réel
  Q2  -Implémentez le sopérateurs nécessaires pour extraire et insérer une instance de cette
  structure dans un flux
  Q3 - Renseignez vous sur la fonction std::getline. Utilisez la pour lire un fichier texte contenant
  une quantité arbitraire de point pondéré. Cette fonction prendra en paramètre le nom du fichier à lire
  et renverra un std::vector de point 3D pondéré.
  Q4 - Implémentez une fonction calculant la distance entre deux points pondérés
  Q5 - Implémentez une fonction renvoyant le point le plus éloigné d'un point donné parmi tout les
  points stockés dans un std::vector de points pondérés
  Q6 - Implémentez une fonction renvoyant le point le plus proche d'un point donné parmi tout les
  points stockés dans un std::vector de points pondérés
  Q7 - Implémentez une fonction calculant le barycentre d'un ensemble de point stocké dans un
  std::vector
  Q8 - Implémentez une fonction calculant la distance entre le point le plus proche et le plus
  éloigné du baruycentre d'un ensemble de point

  Chaque fonction devra être testée en isolation afin de s'assurer de son fonctionnement correct.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h> 

//Q1
struct point{
  float x,y,z,w;
};

//Q2
std::ostream& operator<< (std::ostream &o, struct point &p)
{
  return o << "(" << p.x << ", " << p.y << ", " << p.z << " |" << p.w << ")\n";
}

std::istream& operator>> (std::istream& i, struct point &p)
{
  i >> p.x >> p.y >> p.z >> p.w;
  return i;
}

std::vector<point> readFile (std::string filename){
  std::vector<point> points;
  std::ifstream ifs(filename, std::ios::in);

  if(ifs){
    std::cout << "Lecture du fichier " << filename << "\n";
    std::string line;

    while ( std::getline(ifs, line) )
    {
      if (line.empty()){
        continue;
      }
      point p;
      std::istringstream iss(line);
      iss >> p;
      points.push_back(p);
    }

  }else{
    std::cout << "Erreur de lecture de " << filename << "\n";
  }

  return points;
}

float distance (point p1, point p2){
  float dx = p1.x - p2.x;
  float dy = p1.y - p2.y;
  float dz = p1.z - p2.z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

int main(int, char**)
{
  // point p;
  // std::cin >> p ;
  // std::cout << p << std::endl; 

  // auto points = readFile("test.txt");

  // for (auto i : points)
  //   std::cout << i ;

  point p1 {2,4,2,0};
  point p2 {1,3,23,2};

  std::cout << distance(p1,p2);
}
