#include <iostream>
#include "repALG.h"
#include "lru.h"
using namespace std;

int main(int argc, char **argv)
{
  int pageFaultCount = 0; //01234567890123
  RepALG *repALG = new LRU("ADRSADGEEAEGSS", 3);
  while (!(repALG->isFinish()))
  {
    cout << "Access number: " << repALG->accessNumber()
         << "\nFrame status: " << repALG->frameStatus();
    if (repALG->isPageFault())
    {
      pageFaultCount++;
      cout << "\nPageFault: " << repALG->victimPage();
    }
    cout << "\n\n";
    repALG->next();
  }
  cout << "\nPage Fault:" << pageFaultCount << "\n";
  return 0;
}