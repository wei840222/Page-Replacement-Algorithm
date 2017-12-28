#include <iostream>
#include <string>
#include "repALG.h"
#include "fifo.h"
#include "lru.h"
#include "optimal.h"
#include "random.h"
#include "secondChance.h"
using namespace std;

int main(int argc, char **argv)
{
  int ALG, FRAMESIZE;
  string ACCESSSEQUENCE;
  cout << "Please choose Page Replacement Algorithm:\n1. FIFO\n2. LRU\n3. Second Chance\n4. Random\n5. Optimal\n";
  cin >> ALG;
  cout << "Please enter the frame size:";
  cin >> FRAMESIZE;
  cout << "Please enter the Access Sequence:";
  cin >> ACCESSSEQUENCE;

  RepALG *repALG;
  switch (ALG)
  {
  case 1:
    repALG = new FIFO(ACCESSSEQUENCE, FRAMESIZE);
    break;
  case 2:
    repALG = new LRU(ACCESSSEQUENCE, FRAMESIZE);
    break;
  case 3:
    repALG = new SecondChance(ACCESSSEQUENCE, FRAMESIZE);
    break;
  case 4:
    repALG = new Random(ACCESSSEQUENCE, FRAMESIZE);
    break;
  case 5:
    repALG = new Optimal(ACCESSSEQUENCE, FRAMESIZE);
    break;
  }

  int pageFaultCount = 0;
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
  cout << "\n\nPage Fault:" << pageFaultCount << "\n\n";
  return 0;
}