#include <iostream>
#include "random.h"

using namespace std;

void TEST()
{
  cout<<"Random algorithm test\n";
  Random *random = new Random("ADRSADGEEAEGSS", 3);
  cout<<"Access Sequence: "<<random->accessSequence()<<endl;
  cout<<"Frame Size: "<<random->frameSize()<<endl;
  cout<<"\nRunning:\n";
  while(!(random->isFinish())){
    cout<<"\tAccess Number: "<<random->accessNumber()<<endl;
    cout<<"\tFrame Status: "<<random->frameStatus()<<endl;
    cout<<"\tPage Fault: "<<random->isPageFault()<<endl;
    cout<<"\tVictim Page: "<<random->victimPage()<<endl;
    random->next();
    cout<<endl;
  }
}


int main(int argc, char **argv)
{
  TEST();
  return 0;
}