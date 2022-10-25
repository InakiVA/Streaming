#include "cPlatform.h"

int main() 
{
  Platform* p = new Platform();
  cout<<p->display();
  int xinput=1;
  while (xinput==1)
    {
      p->menu(); 
      cout<<"Press 1 to continue, anything else to exit: ";
      cin>>xinput;
    }   
  return 0;
}
