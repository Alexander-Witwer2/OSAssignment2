#include <iostream>
#include <ifstream>
#include "BankerAlgorithm.hpp"
    
    Banker(ifstream feed){
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
                    feed >> available[i][j];
                }
    }
    need = max - allocated;
    }
    
    void bankAlgor(Banker baker){
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
                    std::cout << available[i][j];
                }
                
                for(int i = 0; i < procNum; ++i){
                    for(int j = 0; j < resNum; ++j){
                feed >> need[i][j];
            }
        }
                std::cout << std::endl;
    }  
    
    operator- (mat[][],rix[][]){
        output[procNum][resNum];
        for(int i = 0; i < procNum; ++i){
            for(int j = 0, j < resNum; ++j){
                output[i][j]=mat[i][j] - rix[i][j];
            }
        }
        return output;
    }


    operator+(mat[][],rix[][]){
        output[procNum][resNum];
        for(int i = 0; i < procNum; ++i){
            for(int j = 0, j < resNum; ++j){
                output[i][j]=mat[i][j] + rix[i][j];
            }
        }
        return output;
    }