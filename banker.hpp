#ifndef BANKER_HPP
#define BANKER_HPP

#include <iostream>
#include <fstream>

class Banker{
    public:     
    static constexpr int resNum = 3;
    static constexpr int procNum = 5;
    
    int allocated[procNum][resNum];
    int max[procNum][resNum];
    int need[procNum][resNum];
    int available[resNum];

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
        calculateNeed(need,max,allocated);
    }

    bool bankAlgor(){
        bool flag[procNum] = {0};
        int procOrd[procNum];
        int count = 0;
        int work[resNum];
        for(int i = 0; i < resNum; ++i){
            work[i] = available[i];
        }

        bool found;
        while(count < procNum){
        found = false;
            for(int i = 0; i < procNum; i++){
                if(flag[i] == 0){
                    int j;
                    for(j = 0; j < resNum; ++j){
                        if(need[i][j] > work[j]) break;
                        }
                        if(j == resNum){
                            for (int k = 0 ; k < resNum ; k++)
                            work[k] += allocated[i][k];
                            
                        procOrd[count] = i+1;
                        count++;
                        flag[i]= 1;

                        found = true;
                        }
                }
            }
            if (found == false)
                    {
                        std::cout << "System is not in safe state";
                        return false;
                    }
        }
    std::cout << "System is in safe state.\nSafe"
        " sequence is: ";
    for (int i = 0; i < procNum; i++)
        std::cout << procOrd[i] << " ";
  
    return true;
    }

    void print(){
        for(int i = 0; i < procNum; ++i){
            for(int j = 0; j < resNum; ++j){
                std::cout << allocated[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
            for(int i = 0; i < procNum; ++i){
                for(int j = 0; j < resNum; ++j){
                    std::cout << max[i][j] << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
                for(int i = 0; i < resNum; ++i){
                    std::cout << available[i] << " ";
                }
                    std::cout << std::endl;

                std::cout << std::endl;
                for(int i = 0; i < procNum; ++i){
                    for(int j = 0; j < resNum; ++j){
                        std::cout << need[i][j] << " ";
            }
            std::cout << std::endl;
        }
            std::cout << std::endl;
    }

    void addMultArr (int output[procNum][resNum],int mat[procNum][resNum],int rix[procNum][resNum]){
        for(int i = 0; i < procNum; ++i){
            for(int j = 0; j < resNum; ++j){
                output[i][j]=mat[i][j] + rix[i][j];
            }
        }
    }
    void calculateNeed (int output[procNum][resNum],int mat[procNum][resNum],int rix[procNum][resNum]){
        for(int i = 0; i < procNum; ++i){
            for(int j = 0; j < resNum; ++j){
                output[i][j]=mat[i][j] - rix[i][j];
            }
        }
    }
};

#endif