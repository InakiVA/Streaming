#include "cVideo.h"

Video::Video()
{

}
string Video::display()
{
  return "";
}
void Video::setId(string _i)
{
  id=_i;
}
void Video::setName(string _n)
{
  name=_n;
}
void Video::setGenre(string _g)
{
  genre=_g;
}
void Video::setLength(int _l)
{
  length=_l;
}
void Video::setRaters(int _r)
{
  raters=_r;
}
void Video::setRating(float _r)
{
  rating=_r;
}
string Video::getId()
{
  return id;
}
string Video::getName()
{
  return name;
}
string Video::getGenre()
{
  return genre;
}
int Video::getLength()
{
  return length;
}
int Video::getRaters()
{
  return raters;
}
float Video::getRating()
{
  return rating;
}