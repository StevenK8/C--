/*
  Exercice 3 - Nuage de points

  Q1 - Implémentez une structure représentant un point 3D pondéré par un réel.
  Q2 - Implémentez les opérateurs nécessaires pour extraire et insérer une instance de cette
  structure dans un flux.
  Q3 - Renseignez vous sur la fonction std::getline. Utilisez la pour lire un fichier texte contenant
  une quantité arbitraire de points pondérés. Cette fonction prendra en paramètre le nom du fichier à lire
  et renverra un std::vector de point 3D pondéré.
  Q4 - Implémentez une fonction calculant la distance entre deux points pondérés
  Q5 - Implémentez une fonction renvoyant le point le plus éloigné d'un point donné parmi tous les
  points stockés dans un std::vector de points pondérés.
  Q6 - Implémentez une fonction renvoyant le point le plus proche d'un point donné parmi tous les
  points stockés dans un std::vector de points pondérés.
  Q7 - Implémentez une fonction calculant le barycentre d'un ensemble de point stocké dans un
  std::vector.
  Q8 - Implémentez une fonction calculant la distance entre le point le plus proche et le plus
  éloigné du barycentre d'un ensemble de points.

  Chaque fonction devra être testée en isolation afin de s'assurer de son fonctionnement correct.
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <limits>

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
  Point3D furthermost;
  auto max_dist = 0.f;
  for (auto p : cloud)
  {
    const auto d = distance(p, ref);
    if (d > max_dist)
    {
      furthermost = p;
      max_dist = d;
    }
  }
  return furthermost;
}


Point3D closest(std::vector<Point3D> cloud, Point3D ref)
{
  Point3D closest;
  auto min_dist = std::numeric_limits<double>::infinity();

  for (auto p : cloud)
  {
    const auto d = distance(p, ref);
    if (d < min_dist)
    {
      closest = p;
      min_dist = d;
    }
  }
  return closest;
}

Point3D barycenter(std::vector<Point3D> cloud)
{
  float bx = 0, by = 0, bz = 0, bw = 0;
  for(auto p : cloud)
  {
    bx += p.x * p.w;
    by += p.y * p.w;
    bz += p.z * p.w;
    bw += p.w;
  }
  bx = bx / bw;
  by = by / bw;
  bz = bz / bw;

  Point3D barycenter = {bx,by,bz,bw};
  return barycenter;
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
  

  auto points = load("test.txt");

  for (auto i : points)
    std::cout << i ;
}
