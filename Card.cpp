//
// Created by telepatheticman on 3/2/2017.
//

#include "Card.h"




Card::Card(int size, int max){
    m_size = size;
    numList.resize(m_size*m_size);
    m_maxNum = max;
    m_minNum = 1;
    auto since_epoch = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto nanos = since_epoch / std::chrono::nanoseconds(1);
    srand(nanos);
    numList[0] = rand() % m_maxNum + 1;
    for (int x = 1; x < m_size*m_size; x++){
        int temp = rand() % m_maxNum + 1;
        while(checkUsed(numList, temp, x)){
            temp = rand() % m_maxNum + 1;
        }
        numList[x] = temp;
    }
}

Card::Card(){

}

Card::~Card(){
//    numList = nullptr;
//    delete[]numList;
}

bool Card::checkUsed(std::vector<int> check, int num, int y){
    bool used = false;
    for (int x = 0; x < y; x++){
        if (check[x] == num){
            used = true;
            return used;
        }
    }
    return used;
}

int Card::getSize(){
    return m_size;
}

int Card::getMin(){
    return m_minNum;
}

int Card::getMax(){
    return m_maxNum;
}

int Card::getList(int index) const{
    return numList[index];
}