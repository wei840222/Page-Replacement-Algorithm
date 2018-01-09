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
  char CONTINUE;
  cout << "*************************************************************************************************\n"
       << "**********************                                                     **********************\n"
       << "**********************   Page Fault Replacement Algorithm Implementation   **********************\n"
       << "**********************                                                     **********************\n"
       << "**********************         106598018 萬俊瑋 & 106598042 陳彥霖         **********************\n"
       << "**********************                                                     **********************\n"
       << "*************************************************************************************************\n";
  do
  {
    do
    {
      cout << "Please choose Page Replacement Algorithm\n";
      cout << "1.FIFO 2.LRU 3.Second Chance 4.Random 5.Optimal\n";
      cout << "Your choice:";
      cin >> ALG;
    } while (ALG < 1 || ALG > 5);
    do
    {
      cout << "Please enter the frame size:";
      cin >> FRAMESIZE;
    } while (FRAMESIZE < 1);
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
    cout << "\nNo\tFrame status\tVictimPage\n";
    while (!(repALG->isFinish()))
    {
      cout << repALG->accessNumber() << "\t" << repALG->frameStatus() << "\t\t" << repALG->victimPage() << "\n";
      repALG->next();
    }
    cout << "Do you want to enter next test case?(y/n)";
    cin >> CONTINUE;
    //cout << CONTINUE;
  } while (CONTINUE == 'Y' || CONTINUE == 'y');
  return 0;
}