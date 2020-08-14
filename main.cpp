#include<iostream>
#include<string>
#include "short_distance.hpp"

int main(){
    std::string input_start, input_end;
    double distance;
    double cst;
    struct IC* p; struct IC* q; struct IC* tmp;
    Distance dist;

    std::cout << "出発ICを入力してください" << std::endl;
    std::cin >> input_start;
    p = dist.search_ic(input_start);

    std::cout << "到着ICを入力してください" << std::endl;
    std::cin >> input_end;
    q = dist.search_ic(input_end);

    if (std::stoi(q->route) - std::stoi(p->route) < 0){
        tmp = p;
        p = q;
        q = tmp;
    
        for (;;){
            if (std::stod(p->route) == std::stod(q->route))
                break;
            distance += std::stod(p->distance);
            p++;
        }
        std::cout << p->nn_1 << "から" << q->nn_1 << "までの距離" << std::endl;
        
    }else{
        for (;;){
            if (std::stod(p->route) == std::stod(q->route))
                break;

            distance += std::stod(p->distance);
            p++;
        }
        std::cout << p->nn_1 << "から" << q->nn_1 << "までの距離" << std::endl;
    }
    
    std::cout << distance << "km" << std::endl;

    cst = dist.cost(distance);    

    std::cout << " 料金:　" << cst << "円" << std::endl;
    return 0;
}
