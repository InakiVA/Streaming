#include "cPlatform.h"
//lineas a revisar y resolver: 357, 336, 229
Platform::Platform()
{
  videos.clear();
  series.clear();
  fstream moviesdata, seriesdata;
  int counter=0, eps=0;
  vector<string> lines;
  moviesdata.open("moviesdb.csv", ios::in);
  if(moviesdata.is_open())
  {
    string line;
    char a='A';
    while(getline(moviesdata, line))
      lines.push_back(line);        
    for (int i=1;i<lines.size();i++)//renglones
      {
        Movie* m = new Movie();
        line="";
        counter=0;
        for (int j=0;j<lines.at(i).size();j++)
          {    
            a=lines.at(i).at(j);
            if (j==lines.at(i).size()-1)
              {
                m->setRaters(stoi(line));
              }
            else if (a==',')
            {
              if (counter==0)
              {
                m->setId(line);
                counter +=1;
              }
              else if (counter==1)
              {
                m->setName(line);
                counter +=1;
              }
              else if (counter==2)
              {
                m->setLength(stoi(line));
                counter +=1;
              }
              else if (counter==3)
              {
                m->setGenre(line);
                counter +=1;
              }
              else if (counter==4)
              {
                m->setRating(stof(line));
              }              
              line="";
            }
            else line+=a;
          }  
        videos.push_back(m);
      }        
  }  
  moviesdata.close();
  lines.clear();
  vector<Episode*> episodes;
  seriesdata.open("seriesdb.csv", ios::in);
  if(seriesdata.is_open())
  {
    string line;
    char a='A';
    while(getline(seriesdata, line))
      lines.push_back(line);        
    for (int i=1;i<lines.size();i++)//renglones
      {
        Episode* e = new Episode();
        line="";
        counter=0;
        for (int j=0;j<lines.at(i).size();j++)
          {    
            a=lines.at(i).at(j);
            if (j==lines.at(i).size()-1)
              {
                e->setRaters(stoi(line));
              }
            else if (a==',')
            {
              if (counter==0)
              {
                e->setId(line);
                counter +=1;
              }
              else if (counter==1)
              {
                e->setSeries(line);
                counter +=1;
              }
              else if (counter==2)
              {
                e->setLength(stoi(line));
                counter +=1;
              }
              else if (counter==3)
              {
                e->setGenre(line);
                counter +=1;
              }
              else if (counter==4)
              {
                e->setEpnum(stoi(line));
                counter +=1;
              } 
              else if (counter==5)
              {
                e->setName(line);
                counter +=1;
              }
              else if (counter==6)
              {
                e->setSeason(stoi(line));
                counter +=1;
              }
              else if (counter==7)
              {
                e->setRating(stof(line));
              }              
              line="";
            }
            else line+=a;
          }         
        videos.push_back(e);
        episodes.push_back(e);        
      }     
  }
  seriesdata.close();
  Serie* s = new Serie();
  counter=0;
  string line=episodes.at(0)->getSeries();
  for (int i=0;i<episodes.size();i++)
  {        
    if(line==episodes.at(i)->getSeries())
    {
      s->addEpisode(episodes.at(i));      
    }
    else//cuando cambia de serie
    {
      counter++;
      eps=0;
      if (counter<10)
        s->setId("S0"+to_string(counter));
      else s->setId("S"+to_string(counter));
      s->setGenre(episodes.at(i-1)->getGenre());
      s->setName(episodes.at(i-1)->getSeries());
      for (int j=0;j<s->getEpisodes().size();j++)
        {
          if (eps<s->getEpisodes().at(j)->getSeason()) 
            eps=s->getEpisodes().at(j)->getSeason();
        }
      s->setSeasons(eps);
      series.push_back(s);
      s = new Serie();
      s->addEpisode(episodes.at(i));
      line=episodes.at(i)->getSeries();
    }
    if (i==episodes.size()-1)//último episodio
    {
      counter++;
      if (counter<10)
        s->setId("S0"+to_string(counter));
      else s->setId("S"+to_string(counter));
      s->setGenre(episodes.at(i)->getGenre());
      s->setName(episodes.at(i)->getSeries());
      for (int j=0;j<s->getEpisodes().size();j++)
        {
          if (eps<s->getEpisodes().at(j)->getSeason()) 
            eps=s->getEpisodes().at(j)->getSeason();
        }
      s->setSeasons(eps);  
      s->average();
      series.push_back(s);
    }
  }  
}
string Platform::display()
{
  string txt="MOVIES:\n";
  for (int i=0;i<videos.size();i++)    
  {
    if (videos.at(i)->getId().at(0)=='M')
    txt+=videos.at(i)->getId()+") "+videos.at(i)->getName()+"\n"; 
  }   
  txt+="\nSERIES:\n";
  for (int i=0;i<series.size();i++)    
  {    
    txt+=series.at(i)->getId()+") "+series.at(i)->getName()+"\n\tEPISODES:\n"; 
    for(int j=0;j<series.at(i)->getEpisodes().size();j++)
      {
        txt+="\t"+series.at(i)->getEpisodes().at(j)->getId()+") "+series.at(i)->getEpisodes().at(j)->getName()+"\n";
      }
  }   
  return txt;
}
void Platform::menu()
{
  vector<string> genres, vinput;
  bool in=false, in2;
  string genre, input="f";
  int xinput;
  float finput=9;
  for (int i=0;i<10;i++)
  {
    vinput.push_back(to_string(i));
  }
  while (in==false)
  {
      cout<<"\nMENU:\n1) Get information of a movie\n2) Get information of a series\n3) Get information of an episode\n4) Get all movies with a specific rating\n5) Get all episodes of a given series with a specific rating\n6) Get all movies of a specific genre\n7) Get all series of a specific genre\n8) Rate a movie\n9) Rate the episode of a given series\n0) Return\n";
    cin>>input;
    for(int i=0;i<vinput.size();i++)
      {
        if (input==vinput.at(i))
        {
          in=true;
          break;
        }
      }
    if (in==false) cout<<"INVALID OPTION"<<endl;
  }
  in=false;
  xinput=stoi(input);
  for (int i=0;i<series.size();i++)
  {
      series.at(i)->average();
  }  
  switch (xinput)
    {
      case 0:
        break;
      case 1:
        while(in==false)
        {
          cout<<"Give me the movie ID: ";
          cin>>input;
          for (int i=0;i<videos.size();i++)
          {
            if (input==videos.at(i)->getId()&&input.at(0)=='M')
            {
              cout<<videos.at(i)->display()<<endl;
              in=true;
              break;
            }
          }
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }
        break;
      case 2:
        while (in==false)
        {
          cout<<"Give me the series ID: ";
          cin>>input;
          for(int i=0;i<series.size();i++)
          {
            if(input==series.at(i)->getId())
            {
              cout<<series.at(i)->display()<<endl; 
              in=true;
              break;
            }
          }
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }        
        break;
      case 3:
        while(in==false)
        {
          cout<<"Give me the episode ID: ";
          cin>>input;
          for (int i=0;i<videos.size();i++)
          {
            if (input==videos.at(i)->getId()&&input.at(0)=='E')
            {
              cout<<videos.at(i)->display()<<endl;
              in=true;
              break;
            }
          }
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }        
        break;
      case 4:
        in=true;
        while(in==true)
        {
          cout<<"Give me the movie rating (0 to 5): ";
          cin>>input;
          for(int i=0;i<input.length();i++)
          {
            if(isdigit(input.at(i))==false&&input.at(i)!='.')
            {
              in=true;
              cout<<"INVALID OPTION"<<endl;
              break;
            }
            else in=false;
          }
          if(in==false)
          {
            finput=stof(input);
            if (finput<0||finput>5)
            {
              cout<<"Only from 0 to 5: "<<endl;
              in=true;
            }
          }          
        }
        for(int i=0;i<videos.size();i++)
        {
          if (videos.at(i)->getId().at(0)=='M'&&videos.at(i)->getRating()==finput)
          {
            cout<<videos.at(i)->display()<<endl;
            in=true;
          }            
        }
        if(in==false) cout<<"There are no movies with this rating"<<endl;
        break;
      case 5:
        while(in==false)
        {
          cout<<"Give me the series ID: ";
          cin>>input;
          for(int i=0;i<series.size();i++)
          {
            if (input==series.at(i)->getId())
            {
              xinput=i;
              in=true;
              break;
            }
          }
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }
        cout<<series.at(xinput)->allEpisodes()<<endl;
        in=true;
        while(in==true)
        {
          cout<<"Give me the episode rating (0 to 5): ";
          cin>>input;
          for(int i=0;i<input.length();i++)
          {
            if(isdigit(input.at(i))==false&&input.at(i)!='.')
            {
              in=true;
              cout<<"INVALID OPTION"<<endl;
              break;
            }
            else in=false;
          }
          if(in==false)
          {
            finput=stof(input);
            if (finput<0||finput>5)
            {
              cout<<"Only from 0 to 5: "<<endl;
              in=true;
            }
          }          
        }
        for (int j=0;j<series.at(xinput)->getEpisodes().size();j++)
        {
          if(series.at(xinput)->getEpisodes().at(j)->getRating()==finput) 
          {
            cout<<series.at(xinput)->getEpisodes().at(j)->display()<<endl;
            in=true;
          }              
        }
        if(in==false) cout<<"There are no episodes with this rating"<<endl;
        break;
      case 6:
        genres.clear();
        vinput.clear();
        genre=videos.at(0)->getGenre();
        genres.push_back(genre);
        for(int i=0;i<videos.size();i++)
        {
          if (videos.at(i)->getId().at(0)=='M')
          {
            in=false;
            genre=videos.at(i)->getGenre();
            for (int j=0;j<genres.size();j++)
            {
              if (genre==genres.at(j))
              {
                in=true;
                break;
              }   
            }
            if (in==false) genres.push_back(genre);
          }
        }
        in=false;
        cout<<"MOVIE GENRES:"<<endl;
        for (int i=0; i<genres.size();i++)
        {
          vinput.push_back(to_string(i+1));
          cout<<i+1<<") "<<genres.at(i)<<endl;
        }    
        while(in==false)
        {
          cout<<"Give me the movie genre number: ";
          cin>>input;
          for (int i=0;i<vinput.size();i++)
          {
            if(input==vinput.at(i))
            {
              in=true;
              break;
            }
          }
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }
        xinput=stoi(input);
        genre=genres.at(xinput-1);
        for(int i=0;i<videos.size();i++)
        {
          if(videos.at(i)->getId().at(0)=='M'&&videos.at(i)->getGenre()==genre)
            cout<<videos.at(i)->display()<<endl;
        }
        break;  
      case 7:    
        genres.clear();
        vinput.clear();
        genre=series.at(0)->getGenre();
        genres.push_back(genre);
        for(int i=0;i<series.size();i++)
        {          
          in=false;
          genre=series.at(i)->getGenre();
          for (int j=0;j<genres.size();j++)
          {
            if (genre==genres.at(j))
            {
              in=true;
              break;
            }   
          }
          if (in==false) genres.push_back(genre);
        }
        cout<<"SERIES GENRES:"<<endl;
        for (int i=0; i<genres.size();i++)
        {
          vinput.push_back(to_string(i+1));
          cout<<i+1<<") "<<genres.at(i)<<endl;
        } 
        in=false;
        while(in==false)
        {
          cout<<"Give me the series genre number: ";
          cin>>input;
          for (int i=0;i<vinput.size();i++)
          {
            if(input==vinput.at(i))
            {
              in=true;
              break;
            }
          }
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }
        xinput=stoi(input);
        genre=genres.at(xinput-1);
        for(int i=0;i<series.size();i++)
        {
          if(series.at(i)->getGenre()==genre)
            cout<<series.at(i)->display()<<endl;
        }
        break;
      case 8:
        while(in==false)
        {
          cout<<"Give me the movie ID: ";
          cin>>input;
          for (int i=0;i<videos.size();i++)
          {
            if (videos.at(i)->getId()==input&&input.at(0)=='M')
            {
              xinput=i;
              in=true;
              break;
            }
          }
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }
        //in=true;
        cout<<videos.at(xinput)->display()<<endl;
        while(in==true)
        {
          cout<<"Give new rating (0 to 5): ";
          cin>>input;
          for(int i=0;i<input.length();i++)
          {
            if(isdigit(input.at(i))==false&&input.at(i)!='.')
            {
              in=true;
              cout<<"INVALID OPTION"<<endl;
              break;
            }
            else in=false;
          }
          if(in==false)
          {
            finput=stof(input);
            if (finput<0||finput>5)
            {
              cout<<"Only from 0 to 5: "<<endl;
              in=true;
            }
          }
        }        
        videos.at(xinput)->setRaters(videos.at(xinput)->getRaters()+1);
        videos.at(xinput)->setRating((videos.at(xinput)->getRating()*(videos.at(xinput)->getRaters()-1)+finput)/videos.at(xinput)->getRaters());
        cout<<videos.at(xinput)->display()<<endl;
        break;
      case 9:
        while(in==false)
        {
          cout<<"Give me the series ID: ";
          cin>>input;
          for (int j=0;j<series.size();j++)
          {
            if(series.at(j)->getId()==input)
            {
              in=true;
              xinput=j;
              break;
            }
          }
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }
        in=false;
        while(in==false)
        {
          cout<<series.at(xinput)->allEpisodes()<<"Give me the episode ID: ";
          cin>>input;            
          for (int i=0;i<series.at(xinput)->getEpisodes().size();i++)
          {
            if (series.at(xinput)->getEpisodes().at(i)->getId()==input)
            {
              in=true;
              cout<<series.at(xinput)->getEpisodes().at(i)->display()<<endl;
              while(in==true)
              {
                cout<<"Give new rating (0 to 5): ";
                cin>>input;
                for(int i=0;i<input.length();i++)
                {
                  if(isdigit(input.at(i))==false&&input.at(i)!='.')
                  {
                    in=true;
                    cout<<"INVALID OPTION"<<endl;
                    break;
                  }
                  else in=false;
                }
                if(in==false)
                {
                  finput=stof(input);
                  if (finput<0||finput>5)
                  {
                    cout<<"Only from 0 to 5: "<<endl;
                    in=true;
                  }
                }
              }                
              in=true;
            series.at(xinput)->getEpisodes().at(i)->setRaters(series.at(xinput)->getEpisodes().at(i)->getRaters()+1);
            series.at(xinput)->getEpisodes().at(i)->setRating((series.at(xinput)->getEpisodes().at(i)->getRating()*(series.at(xinput)->getEpisodes().at(i)->getRaters()-1)+finput)/series.at(xinput)->getEpisodes().at(i)->getRaters());
            cout<<series.at(xinput)->getEpisodes().at(i)->display()<<endl;
            break;
            }          
          } 
          if (in==false) cout<<"INVALID OPTION"<<endl;
        }        
        break;
      }
}
    
