//
// Created by telepatheticman on 3/3/17.
//

#include "DeckTester.h"
#include "../Deck.h"
#include <iostream>
#include <vector>
#include "../Card.h"

void DeckTester::testInvalids() {
    Deck case0(4, 4, 64);
    Deck case1(4, 4, 65);
    Deck case2(4, 4, 31);
    Deck case3(2, 4, 32);
    Deck case4(16, 4, 32);
    Deck case5(4, 2, 32);
    Deck case6(15, 10001, 4);
    std::cout << std::endl << "Test Suite: DeckTester::testInvalids" << std::endl;
    if(case0.isValid()){
        std::cout << "case0 passed" << std::endl;
    }else{
        std::cout << "case0 failed: unexpectedly invalid" << std::endl;
    }
    if(!case1.isValid()){
        std::cout << "case1 passed" << std::endl;
    }else{
        std::cout << "case1 failed: unexpectedly valid" << std::endl;
    }
    if(!case2.isValid()){
        std::cout << "case2 passed" << std::endl;
    }else{
        std::cout << "case2 failed: unexpectedly valid" << std::endl;
    }
    if(!case3.isValid()){
        std::cout << "case3 passed" << std::endl;
    }else{
        std::cout << "case3 failed: unexpectedly valid" << std::endl;
    }
    if(!case4.isValid()){
        std::cout << "case4 passed" << std::endl;
    }else{
        std::cout << "case4 failed: unexpectedly valid" << std::endl;
    }
    if(!case5.isValid()){
        std::cout << "case5 passed" << std::endl;
    }else{
        std::cout << "case5 failed: unexpectedly valid" << std::endl;
    }
    if(!case6.isValid()){
        std::cout << "case6 passed" << std::endl;
    }else{
        std::cout << "case6 failed: unexpectedly valid" << std::endl;
    }

    std::cout << std::endl;
}

void DeckTester::testDupes() {
    std::cout << "Test Suite: DeckTester::testDupes" << std::endl;
    int cards = 10000;
    int size = 15;
    int maxRange = 900;
    Deck test(size, cards, maxRange);
    std::vector<Card*> cardList = test.getCardList();
    std::vector<int> list;
    list.resize(size*size);
    int dupeCount = 0;
    for (int y = 0; y < cards; y++) {
        for (int x = 0; x < size * size; x++) {
            list[x] = cardList[y]->getList(x);
        }
        for (int x = 1; x < size * size; x++) {
            int temp = list[x];
            if (cardList[y]->checkUsed(list, temp, x - 1)) {
                dupeCount++;
            }
        }
    }
    if(dupeCount == 0){
        std::cout << "Passed" << std::endl;
    }else{
        std::cout << "Failed with " << std::to_string(dupeCount) << " dupes" << std::endl;
    }
    std::cout << std::endl;
}
