#pragma once

#include "cEpisode.h"

class Serie
{
  private:
    string name, genre, id;
    int seasons, raters;//es de operator de episodes: suma de los raters de cada episodio
    float rating; //es de operator de episodes: promedio ponderado de episodios (considerar la cantidad de raters por cada episodio). 5 ratings de 5 al primer episodio, 1 rating de 0 al 2do episodio: (5*5+1*0)/6->cantidad de raters
    vector<Episode*> series;
  public:
    Serie();
    string display();
    string allEpisodes();
    void average();
    void setSeasons(int _i);
    void setName(string _s);
    void setGenre(string _s);
    void setId(string _s);
    void setRating(float _r);
    void setRaters(int _r);
    void addEpisode(Episode* _e);
    int getSeasons();
    string getName();
    string getGenre();
    string getId();
    float getRating();
    int getRaters();
    vector<Episode*> getEpisodes();
};