//
// Created by Stephen Clyde on 2/16/17.
//

#include "Deck.h"

Deck::Deck(){

}

Deck::Deck(int cardSize, int cardCount, int numberMax) : Card()
{
    m_numCards = cardCount;
    m_maxNum = numberMax;
    m_minNum = 1;
    m_size = cardSize;
    if (isValid()) {
        cardList.resize(cardCount);
        for (int x = 0; x < m_numCards; x++) {
            cardList[x] = new Card(m_size, numberMax);
            //due to my low resolution clock, this line has been added in to ensure that random number
            //sets will(mostly) be different card too card. Remove for full speed.
            //Sleep(900);
        }
    }
}

Deck::~Deck() {
    for (int x = 0; x < cardList.size(); x++) {
        cardList[x] = nullptr;
        delete cardList[x];
    }

    //cardList = nullptr;
   // delete[]cardList;

}

//void Deck::print(std::ostream& out) const
//{

    // TODO: Implement
//}

void Deck::print(std::ostream& out, int cardIndex) const
{
    int loopMin;
    int loopMax;
    if(cardIndex == -1) {
        loopMin = 0;
        loopMax = m_numCards;
    }else if(cardIndex > -1 && cardIndex < m_numCards){
        loopMin = cardIndex;
        loopMax = cardIndex + 1;
    }else if(cardIndex < -1 || cardIndex >= m_numCards){
        out << "invalid index" << std::endl;
        return;
    }
    std::string lengthCheck = std::to_string(m_maxNum);
    int width = lengthCheck.size();
    std::string boarder = "+--";
    for (int x = 0; x < width; x++){
        boarder+="-";
    }
    for (int z = loopMin; z < loopMax; z++) {
        out << "Card: " << std::to_string(z) << std::endl;
        int min = 0;
        int max = m_size;
        for (int x = 0; x < m_size; x++) {
            for (int y = 0; y < m_size; y++) {
                out << boarder;
            }
            out << "+" << std::endl;
            for (int y = min; y < max; y++) {
                out << "|" << std::right << std::setw(width + 1) << std::to_string(cardList[z]->getList(y)) << " ";
            }
            out << "|" << std::endl;
            min += m_size;
            max += m_size;
        }
        for (int y = 0; y < m_size; y++) {
            out << boarder;
        }
        out << "+" << std::endl << std::endl;
    }

    // TODO: Implement
}

bool Deck::isValid(){
    if (m_size > 15 || m_size < 3){
        return false;
    }
    if (m_maxNum < m_size*m_size*2 || m_maxNum > m_size*m_size*2*2){
        return false;
    }
    if (m_numCards > 10000 || m_numCards < 3){
        return false;
    }
    return true;
}



