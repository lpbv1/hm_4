//
// Created by Stephen Clyde on 2/16/17.
//

#ifndef BINGO_DECK_H
#define BINGO_DECK_H

#include <ostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
//#include <windows.h>
#include "Card.h"

// TODO: Extend this definition as you see fit

class Card;

class Deck : Card{
private:
    int m_numCards;
    std::vector<Card*> cardList;

public:
    Deck(int cardSize, int cardCount, int numberMax);
    Deck();
    ~Deck();
    std::vector<Card*> getCardList();

    //void print(std::ostream& out) const;
    void print(std::ostream& out, int cardIndex = -1) const;
    bool isValid();
};

#endif //BINGO_DECK_H
