#include "cMovie.h"

Movie::Movie() : Video()
{
  
}
string Movie::display()
{
  string txt="TITLE: "+ getName()+"\nID: "+getId()+"\nGENRE: "+getGenre()+"\nLENGTH: "+to_string(getLength())+"\nRATING: "+to_string(getRating())+"\nRATERS: "+to_string(getRaters());
  return txt;
}