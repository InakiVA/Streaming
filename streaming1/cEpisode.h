#include "cVideo.h"

class Episode : public Video
{
  private:
    int season, epnum;
    string seriesName;
  public:
    Episode();
    Episode* operator + (Episode& other)
    {
      Episode* result=new Episode();
      result->setRating((this->getRating()*this->getRaters()+other.getRating()*other.getRaters())/(this->getRaters()+other.getRaters())); 
      result->setRaters(this->getRaters()+other.getRaters());
      return result;
    }
    //aquí creo que hay que meter el operator + para sumar episodios en un super episodio y sacar el promedio ponderado al final (suma(raters*rating))/(suma raters) CREO que da promedio ponderado   
    string display();
    string getSeries();
    int getSeason();
    int getEpnum();
    void setSeries(string _s);
    void setSeason(int _i);
    void setEpnum(int _i);
};