#include "cSerie.h"

Serie::Serie()
{
  name=genre=id="";
  seasons=0;
  rating=raters=0;//debe salir de operator de todos los episodios
  series.clear();
}
void Serie::average()
{
  Episode* e = new Episode();
  Episode super;
  e->setRaters(0);
  e->setRating(0);
  for (int i=0;i<series.size();i++)
    {
      super=*series.at(i);
      e=*e+super;
    }
  rating=e->getRating();  
  raters=e->getRaters(); 
}
string Serie::display()
{
  string txt="TITLE: "+name+"\nID: "+id+"\nGENRE: "+genre+"\nSEASONS: "+to_string(seasons)+"\nRATING: "+to_string(rating)+"\nRATERS: "+to_string(raters);
  return txt;
}
string Serie::allEpisodes()
{
  string txt="EPISODES:\n";
  for(int i=0; i<series.size();i++)
    {
      txt+=series.at(i)->getId()+") "+series.at(i)->getName()+"\n";
    }
  return txt;
}
void Serie::addEpisode(Episode* _e)
{
  series.push_back(_e);
}
void Serie::setSeasons(int _i)
{
  seasons=_i;
}
void Serie::setName(string _s)
{
  name=_s;
}
void Serie::setGenre(string _s)
{
  genre=_s;
}
void Serie::setId(string _s)
{
  id=_s;
}
void Serie::setRating(float _r)
{

  rating=_r;
}
void Serie::setRaters(int _r)
{
  raters=_r;
}
int Serie::getSeasons()
{
  return seasons;
}
string Serie::getName()
{
  return name;
}
string Serie::getGenre()
{
  return genre;
}
string Serie::getId()
{
  return id;
}
vector<Episode*> Serie::getEpisodes()
{
  return series;
}
float Serie::getRating()
{
  return rating;
}
int Serie::getRaters()
{
  return raters;
}