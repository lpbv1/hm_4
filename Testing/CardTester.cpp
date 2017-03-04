//
// Created by telepatheticman on 3/3/17.
//

#include "CardTester.h"
#include "../Card.h"
#include <iostream>

void CardTester::testInvalids() {
    Card case0(4, 32);
    Card case1(4, 31);
    Card case2(4, 65);
    Card case3(2, 16);
    Card case4(16, 512);

    std::cout << "Test Suite: CardTester::testInvalids" << std::endl;
    if (case0.isValid()){
        std::cout << "case0 passed" << std::endl;
    }else{
        std::cout << "case0 failed: unexpectedly invalid" << std::endl;
    }
    if (!case1.isValid()){
        std::cout << "case1 passed" << std::endl;
    }else{
        std::cout << "case1 failed: unexpectedly valid" << std::endl;
    }
    if (!case2.isValid()){
        std::cout << "case2 passed" << std::endl;
    }else{
        std::cout << "case2 failed: unexpectedly valid" << std::endl;
    }
    if (!case3.isValid()){
        std::cout << "case3 passed" << std::endl;
    }else{
        std::cout << "case3 failed: unexpectedly valid" << std::endl;
    }
    if (!case4.isValid()){
        std::cout << "case4 passed" << std::endl;
    }else{
        std::cout << "case4 failed: unexpectedly valid" << std::endl;
    }
    std::cout << std::endl;
}