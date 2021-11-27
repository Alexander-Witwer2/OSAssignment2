#include <iostream>
#include <ifstream>
#include "BankerAlgorithm.hpp"

int main(){
    ifstream input("inputAllocation.txt");

    if(input.is_open())
        std::cout << "file is open.\n";
    else std::cout << {
        "file is unable to open\n";
        return 0;
        }

    Banker money(input);

    bankAlgor(money);
}