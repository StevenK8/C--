/*
  Exercice 2 - Nuage de point II - Le retour

  Q1 - A partir de votre solution de l'exercice struct-3, réimplémentez chaque fonction
  manipulant le nuage de point sous forme d'algorithme. Justifiez vos choix et vérifiez
  le bon comportement de votre nouvelle version.

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <numeric>

struct Point3D
{
  float x=0, y=0, z=0;
  float w=0;
};

std::ostream& operator<< (std::ostream& os, struct Point3D &p)
{
     return os <<'(' << p.x << ',' << p.y << ',' << p.z << '|' << p.w <<')';
}

std::istream& operator>> (std::istream& is, struct Point3D &p)
{
     is >> p.x >> p.y >> p.z >> p.w;
     return is;
}


std::vector<Point3D> load(std::string fname)
{
  std::ifstream file_stream(fname, std::ios::in);
  std::vector<Point3D> vectorBuild;

  if(file_stream)
  {
    std::cout << "[INFO] ~ Construction d'un vecteur de point3D à partir de : " << fname << ".\n";
    std::string ligne;

    while(std::getline(file_stream, ligne))
    {
      Point3D inputP;
      std::istringstream iss(ligne);
      iss >> inputP;
      vectorBuild.push_back(inputP);
    }
  }
  else
  {
    std::cout << "[ERROR] ~ Impossible d'ouvrir le fichier : " << fname << ".\n";
  }

  return vectorBuild;
}


float distance(Point3D p1, Point3D p2){
  const float dx = p2.x - p1.x;
  const float dy = p2.y - p1.y;
  const float dz = p2.z - p1.z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}


Point3D furthermost(std::vector<Point3D> cloud, Point3D ref)
{
  // Quid si nuage est vide ?
  // min et max_element utilise une relation d'ordre identique
  // pas besoin de changer le < en >
  return *std::max_element( cloud.begin(),cloud.end()
                          , [&ref](auto p1, auto p2)
                            {
                              return distance(p1, ref) < distance(p2, ref);
                            }
                          );
}


Point3D closest(std::vector<Point3D> cloud, Point3D ref)
{
  // Quid si nuage est vide ?
  return *std::min_element( cloud.begin(),cloud.end()
                          , [&ref](auto p1, auto p2)
                            {
                              return distance(p1, ref) < distance(p2, ref);
                            }
                          );
}

Point3D barycenter(std::vector<Point3D> cloud)
{
  auto b = std::accumulate( cloud.begin(), cloud.end(), Point3D{0,0,0,0}
                          , [](auto acc, auto elem)
                            {
                              return Point3D{ acc.x + elem.x*elem.w
                                            , acc.y + elem.y*elem.w
                                            , acc.z + elem.z*elem.w
                                            , acc.w + elem.w
                                            };
                            }
                          );

  b.x /= b.w;
  b.y /= b.w;
  b.z /= b.w;

  return b;
}

auto cloud_extreme(std::vector<Point3D> cloud)
{
  Point3D p_barycenter = barycenter(cloud);
  Point3D p_furthermost = furthermost(cloud, p_barycenter);
  Point3D p_closest = closest(cloud, p_barycenter);
  return distance(p_furthermost, p_closest);
}

int main(int, char**)
{
  Point3D p;
  std::cout << p.x << p.y << std::endl;
}
