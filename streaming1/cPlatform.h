#include <stdio.h>
#include <cstdio>
#include <sstream>
#include "fstream"

#include "cSerie.h"
#include "cMovie.h"

class Platform
{
  private:
    vector<Video*> videos;
    vector<Serie*> series;
  public:
    Platform();
    string display();
    void menu();    
};