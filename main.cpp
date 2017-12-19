#include <iostream>
#include "fifo.h"
using namespace std;

int main(int argc, char** argv) {
  FIFO* fifo = new FIFO("ADRSADGEEAEGSS", 3);
  while (!(fifo->isFinish())) {
    cout << "Access number: " << fifo->accessNumber()
         << "\nFrame status: " << fifo->frameStatus();
    if (fifo->isPageFault()) cout << "\nPageFault: " << fifo->victimPage();
    cout << "\n\n";
    fifo->next();
  }
  return 0;
}