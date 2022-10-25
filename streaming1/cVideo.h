#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Video
{
  protected:
    string id, name, genre;
    int length, raters;
    float rating;
  public:
    Video();
    virtual string display()=0;
    void setId(string _i);
    void setName(string _n);
    void setGenre(string _g);
    void setLength(int _l);
    void setRaters(int _r);
    void setRating(float _r);
    string getId();
    string getName();
    string getGenre();
    int getLength();
    int getRaters();
    float getRating();
};