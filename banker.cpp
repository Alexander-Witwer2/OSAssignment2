#include <iostream>
#include <fstream>
#include "banker.hpp"

int main(){
    std::ifstream input("input.txt");

    if(!(input.is_open())) exit(EXIT_FAILURE);

    Banker money(input);
    money.print();
    money.bankAlgor();

    return 0;
}