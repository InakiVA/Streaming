#include "cEpisode.h"

Episode::Episode() : Video()
{
  season=epnum=0;
  seriesName="";
}

string Episode::display()
{
  string txt="SERIES TITLE: "+ getSeries()+"\nEPISODE TITLE: "+ getName()+"\nSEASON: "+to_string(getSeason())+"\nEPISODE NUMBER: "+to_string(getEpnum())+"\nID: "+getId()+"\nGENRE: "+getGenre()+"\nLENGTH: "+to_string(getLength())+"\nRATING: "+to_string(getRating())+"\nRATERS: "+to_string(getRaters());
  return txt;
}
string Episode::getSeries()
{
  return seriesName;
}
int Episode::getEpnum()
{
  return epnum;
}
int Episode::getSeason()
{
  return season;
}
void Episode::setSeries(string _s)
{
  seriesName=_s;
}
void Episode::setSeason(int _i)
{
  season=_i;
}
void Episode::setEpnum(int _i)
{
  epnum=_i;
}