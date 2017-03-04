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
    if(isValid()) {
        numList[0] = rand() % m_maxNum + 1;
        for (int x = 1; x < m_size * m_size; x++) {
            int temp = rand() % m_maxNum + 1;
            while (checkUsed(numList, temp, x)) {
                temp = rand() % m_maxNum + 1;
            }
            numList[x] = temp;
        }
    }
}

Card::Card(){

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


int Card::getList(int index) const{
    return numList[index];
}

bool Card::isValid(){
    if(m_size > 15 || m_size < 3 || m_maxNum > 4*m_size*m_size || m_maxNum < 2*m_size*m_size){
        return false;
    }
    return true;
}