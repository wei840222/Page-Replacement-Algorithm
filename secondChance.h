#ifndef SECONDCHANCE_H
#define SECONDCHANCE_H

#include "repALG.h"

class SecondChance : public RepALG
{
  public:
    SecondChance(string s = "", int i = 1) : RepALG(s, i) {}
    void next() {}
};

#endif