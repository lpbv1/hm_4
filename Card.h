//
// Created by telepatheticman on 3/2/2017.
//

#ifndef BINGO_CARD_H
#define BINGO_CARD_H

#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <windows.h>
//#include "Deck.h"

//class Deck;

class Card
{
private:
//    int m_size;
    std::vector<int> numList;
protected:
    int m_size;
    int m_minNum;
    int m_maxNum;

public:
    Card();
    Card(int size, int max);
    ~Card();
    int getSize();
    int getMin();
    int getMax();
    int getList(int index) const;


protected:
    bool checkUsed(std::vector<int> check, int num, int index);
};


#endif //BINGO_CARD_H
