#include <iostream>
#include "repALG.h"
#include "secondChance.h"
using namespace std;

int main(int argc, char **argv)
{
  int pageFaultCount = 0; //01234567890123
  RepALG *repALG = new SecondChance("EFABFCFDBCFCBAB", 3);
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
  cout << "Access number: " << repALG->accessNumber()
         << "\nFrame status: " << repALG->frameStatus();
  cout << "\n\n\nPage Fault:" << pageFaultCount << "\n";
  return 0;
}