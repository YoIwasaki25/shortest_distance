#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<array>
#include "short_distance.hpp"
#define CONSUMPTION_TAX 1.1

Distance::Distance(){}

Distance::~Distance(){}

st* Distance::search_ic(std::string args){                  
    int i = 0;
    int num;

    struct IC ic[256]; //読み込みファイルの　index+1 以上のサイズを持つこと
    struct IC *p;

    p = ic;

    std::string line;

    std::ifstream myFileStream("ic_list.csv");
    if(!myFileStream.is_open()){
        std::cout << "File failed to open" << std::endl;
    }
    while(getline(myFileStream, line)){
        std::stringstream ss(line);
        getline(ss, ic[i].route, ',');
        getline(ss, ic[i].nn_1, ',');
        getline(ss, ic[i].nn_2, ',');
        getline(ss, ic[i].distance, ',');
        getline(ss, ic[i].highway, ',');
        getline(ss, ic[i].node_1, ',');
        getline(ss, ic[i].node_2, ',');
        
        i++;
    }

    for (;;){
        if(p->nn_1 == ""){
            std::cout << "インターチェンジが見つかりません" << std::endl;
            break;
        }else if(p->nn_1 == args){
            num = std::stoi(p->route);
            break;        
        }
        p++;
    }
    return p;
}

double Distance::cost(double arg){
    return (150 + 24.6 * arg) * CONSUMPTION_TAX;  
}