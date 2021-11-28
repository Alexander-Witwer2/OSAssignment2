#ifndef BANKER_HPP
#define BANKER_HPP

#include <iostream>
#include <fstream>

class Banker{
    public:     
    static constexpr int resNum = 3;
    static constexpr int procNum = 5;
    
    bool flag[procNum];
    int allocated[procNum][resNum];
    int max[procNum][resNum];
    int need[procNum][resNum];
    int available[resNum];
    int procOrd[procNum];

    Banker(){};
    Banker(std::ifstream& feed){
        while(!feed.eof()){
        for(int i = 0; i < procNum; ++i){
            for(int j = 0; j < resNum; ++j){
                feed >> allocated[i][j];
            }
        }
            for(int i = 0; i < procNum; ++i){
                for(int j = 0; j < resNum; ++j){
                    feed >> max[i][j];
                }
            }
                for(int i = 0; i < resNum; ++i){
                    feed >> available[i];
                }
    }
    need[procNum][resNum] = subMultArr(allocated,max);
    }

    void bankAlgor(){
        for(int i = 0; i < procNum; ++i){
            for(int j = 0; j < resNum; ++j){
                std::cout << allocated[i][j];
            }
            std::cout << std::endl;
        }
            for(int i = 0; i < procNum; ++i){
                for(int j = 0; j < resNum; ++j){
                    std::cout << max[i][j];
                }
                std::cout << std::endl;
            }
                for(int i = 0; i < resNum; ++i){
                    std::cout << available[i];
                }
                
                for(int i = 0; i < procNum; ++i){
                    for(int j = 0; j < resNum; ++j){
                        std::cout << need[i][j];
            }
        }
                std::cout << std::endl;
    }

    int addMultArr (int mat[procNum][resNum],int rix[procNum][resNum]){
        int output[procNum][resNum];
        for(int i = 0; i < procNum; ++i){
            for(int j = 0; j < resNum; ++j){
                output[i][j]=mat[i][j] - rix[i][j];
            }
        }
        return output[procNum][resNum];
    }
    int subMultArr (int mat[procNum][resNum],int rix[procNum][resNum]){
        int output[procNum][resNum];
        for(int i = 0; i < procNum; ++i){
            for(int j = 0; j < resNum; ++j){
                output[i][j]=mat[i][j] + rix[i][j];
            }
        }
        return output[procNum][resNum];
    }
};

#endif