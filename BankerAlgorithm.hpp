#ifndef BANKERALGORITHM_HPP
#define BANKERALGORITHM_HPP

#include <iostream>
#include <ifstream>

class Banker {
    public:
    Banker(){};
    Banker(ifstream);

    bool flag[procNum];
    int allocated[procNum][resNum];
    int max[procNum][resNum];
    int need[procNum][resNum];
    int available[resNum];
    int procOrd[procNum];
 
    void bankAlgor(Banker);

    private:
    const int procNum = 5;
    const int resNum = 3;
}

    int operator+ (int[][], int[][]);
    int operator- (int[][], int[][]);

#endif BANKERALGORITHM_HPP